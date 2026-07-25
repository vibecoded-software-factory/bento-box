#include "panel_window.hpp"
#include <algorithm>
#include <map>

#include <qcoreevent.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qqmlengine.h>
#include <qquickwindow.h>
#include <qrect.h>
#include <qscreen.h>
#include <qtimer.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <unistd.h>

#include "../core/generation.hpp"
#include "../core/qmlscreen.hpp"
#include "../core/types.hpp"
#include "../window/panelinterface.hpp"
#include "../window/proxywindow.hpp"
#include "bridge.hpp"
#include "compositor.hpp"

namespace qs::mac {

namespace {
QString nextReservationId() {
	static int counter = 0;
	return QStringLiteral("bento-%1").arg(counter++);
}
} // namespace

// Upstream X11's XPanelStack, verbatim (x11/panel_window.cpp:26-80): the
// per-generation list of visible panels, in creation order, that the
// same-edge stacking loop in updateDimensions walks.
class MacPanelStack {
public:
	static MacPanelStack* instance() {
		static MacPanelStack* stack = nullptr; // NOLINT

		if (stack == nullptr) {
			stack = new MacPanelStack();
		}

		return stack;
	}

	[[nodiscard]] const QList<MacPanelWindow*>& panels(MacPanelWindow* panel) {
		return this->mPanels[EngineGeneration::findObjectGeneration(panel)];
	}

	void addPanel(MacPanelWindow* panel) {
		panel->engineGeneration = EngineGeneration::findObjectGeneration(panel);
		auto& panels = this->mPanels[panel->engineGeneration];
		if (!panels.contains(panel)) {
			panels.push_back(panel);
		}
	}

	void removePanel(MacPanelWindow* panel) {
		if (!panel->engineGeneration) return;

		auto& panels = this->mPanels[panel->engineGeneration];
		if (panels.removeOne(panel)) {
			if (panels.isEmpty()) {
				this->mPanels.erase(panel->engineGeneration);
			}

			// from the bottom up, update all panels
			for (auto* panel: panels) {
				panel->updateDimensions();
			}
		}
	}

	void updateLowerDimensions(MacPanelWindow* exclude) {
		if (!exclude->engineGeneration) return;
		auto& panels = this->mPanels[exclude->engineGeneration];

		// update all panels lower than the one we start from
		auto found = false;
		for (auto* panel: panels) {
			if (panel == exclude) found = true;
			else if (found) panel->updateDimensions(false);
		}
	}

private:
	std::map<EngineGeneration*, QList<MacPanelWindow*>> mPanels;
};

MacPanelWindow::MacPanelWindow(QObject* parent): ProxyWindowBase(parent) {
	this->mReservationId = nextReservationId();

	// The single edge the anchors leave free on an axis - the edge to reserve
	// against. Zero (no unique edge) means the panel is not edge-anchored and
	// reserves nothing.
	this->bcExclusionEdge.setBinding([this] { return this->bAnchors.value().exclusionEdge(); });

	// The zone's VALUE carries the wlr-layer-shell meaning, because that is the
	// contract the shells binding this API are written against, and on macOS
	// this class is the one that positions the surface. Per the protocol
	// (wlr-layer-shell-unstable-v1.xml, set_exclusive_zone): a NEGATIVE zone
	// means "do not move me to accommodate other surfaces, extend to the edges
	// I am anchored to", 0 means "move me clear of other surfaces' zones", and
	// a positive zone reserves that much. So Ignore is -1 like the Wayland
	// backend (wlr_layershell.cpp:18-21), NOT X11's 0: X11 feeds the value to a
	// _NET_WM_STRUT_PARTIAL, which cannot be negative, so that backend never
	// had to represent "do not move me" at all. updateDimensions reads the SIGN
	// to decide whether to stack, which is what makes a shell's
	// `exclusiveZone: -1` behave here the way it does under a compositor.
	// Auto still follows X11 (BOTH margins on the anchored axis) where the
	// Wayland backend adds only the reverse-edge margin; not reconciled here.
	this->bcExclusiveZone.setBinding([this]() -> qint32 {
		switch (this->bExclusionMode.value()) {
		case ExclusionMode::Ignore: return -1;
		case ExclusionMode::Normal: return this->bExclusiveZone;
		case ExclusionMode::Auto:
			auto edge = this->bcExclusionEdge.value();
			auto margins = this->bMargins.value();
			if (edge == Qt::TopEdge || edge == Qt::BottomEdge) {
				return this->bImplicitHeight + margins.top + margins.bottom;
			} else if (edge == Qt::LeftEdge || edge == Qt::RightEdge) {
				return this->bImplicitWidth + margins.left + margins.right;
			} else {
				return 0;
			}
		}
		return 0;
	});
}

MacPanelWindow::~MacPanelWindow() {
	// Upstream removes the panel from the stack in the destructor too - the
	// remaining panels re-place themselves without this one's zone.
	MacPanelStack::instance()->removePanel(this);
	// Give the space back - a panel that goes away must not leave the layout
	// permanently shrunk.
	sendCompositorMessage(QStringLiteral("action clear-zone %1").arg(this->mReservationId));
	// Shells destroy a modal's window on close, so the hide path's deferred
	// yield never runs - give app focus back here too. No-op unless this
	// panel holds the keyboard grab.
	qs::mac::yieldKeyboardFromPanel(this);
	if (this->window != nullptr) {
		qs::mac::clearInputMask(this->window);
	}
}

void MacPanelWindow::connectWindow() {
	this->ProxyWindowBase::connectWindow();

	this->updateScreen();

	// Decorationless, like a layer surface. Set before the window is shown so
	// AppKit builds the NSWindow borderless from the start.
	this->window->setFlag(Qt::FramelessWindowHint);
	this->updateAboveWindows();
	this->updateFocusable();
	this->updateDimensions();

	// The NSWindow only exists once the backing window is created; reapply the
	// native config every time it (re)appears so collectionBehavior and level
	// survive a show. applyNativeConfig no-ops until the handle exists.
	QObject::connect(
	    this->window,
	    &QQuickWindow::visibleChanged,
	    this,
	    &MacPanelWindow::applyNativeConfig
	);
	// Visibility also gates the compositor reservation (an unmapped surface
	// reserves nothing) - re-send it on every show/hide.
	QObject::connect(
	    this->window,
	    &QQuickWindow::visibleChanged,
	    this,
	    &MacPanelWindow::updateReservation
	);
	// The layer (aboveWindows) can change AFTER the window is shown - a shell
	// sets WlrLayershell.layer in a binding, and a background layer must drop to
	// the desktop level. Reapply the native config on that change too, or the
	// wallpaper stays above the windows and hides them (only their overlays show).
	QObject::connect(
	    this,
	    &MacPanelWindow::aboveWindowsChanged,
	    this,
	    &MacPanelWindow::applyNativeConfig
	);

	// Stack membership follows visibility, like upstream's updatePanelStack
	// (x11/panel_window.cpp:133-152, 319-325): only visible panels occupy a
	// slot in the same-edge stacking order.
	QObject::connect(
	    this->window,
	    &QQuickWindow::visibleChanged,
	    this,
	    &MacPanelWindow::updatePanelStack
	);
	this->updatePanelStack();

	this->applyNativeConfig();
	// Send the initial reservation now that the panel is configured; later
	// changes drive it through the bcExclusiveZone/bcExclusionEdge bindings.
	this->updateReservation();

	// Re-assert an active reservation on a slow heartbeat. The compositor holds
	// struts in memory, so if it restarts it forgets this panel's zone - and
	// nothing here would otherwise re-send it, since our bindings only fire on a
	// change. A cleared panel has nothing to re-assert, so the heartbeat is a
	// no-op unless we currently reserve space.
	if (this->mReservationHeartbeat == nullptr) {
		this->mReservationHeartbeat = new QTimer(this);
		this->mReservationHeartbeat->setInterval(3000);
		QObject::connect(this->mReservationHeartbeat, &QTimer::timeout, this, [this]() {
			if (this->bcExclusiveZone.value() > 0
			    && this->bcExclusionEdge.value() != static_cast<Qt::Edge>(0) && this->window != nullptr
			    && this->window->isVisible())
			{
				this->updateReservation();
			}
		});
		this->mReservationHeartbeat->start();
	}
}

void MacPanelWindow::onPolished() {
	this->ProxyWindowBase::onPolished();
	if (this->window != nullptr) {
		qs::mac::applyInputMask(this->window, this->window->mask(), this->mask() != nullptr);
		qs::mac::assertPanelLevel(this->window, this->bAboveWindows.value(), this->mOverlay);
	}
}

void MacPanelWindow::trySetWidth(qint32 implicitWidth) {
	// Blocked when both horizontal anchors are set: the width is the screen's.
	if (!this->bAnchors.value().horizontalConstraint()) {
		this->ProxyWindowBase::trySetWidth(implicitWidth);
		this->updateDimensions();
	}
}

void MacPanelWindow::trySetHeight(qint32 implicitHeight) {
	if (!this->bAnchors.value().verticalConstraint()) {
		this->ProxyWindowBase::trySetHeight(implicitHeight);
		this->updateDimensions();
	}
}

void MacPanelWindow::setScreen(QuickshellScreenInfo* screen) {
	this->ProxyWindowBase::setScreen(screen);
	this->updateScreen();
}

void MacPanelWindow::updateScreen() {
	auto* newScreen =
	    this->mScreen ? this->mScreen : (this->window ? this->window->screen() : nullptr);

	if (newScreen == this->mTrackedScreen) return;

	if (this->mTrackedScreen != nullptr) {
		QObject::disconnect(this->mTrackedScreen, nullptr, this, nullptr);
	}

	this->mTrackedScreen = newScreen;

	if (this->mTrackedScreen != nullptr) {
		QObject::connect(
		    this->mTrackedScreen,
		    &QScreen::geometryChanged,
		    this,
		    &MacPanelWindow::updateDimensionsSlot
		);
	}

	this->updateDimensions();
}

// Pin the window to the tracked screen per anchors + margins. Pure Qt, and the
void MacPanelWindow::updatePanelStack() {
	if (this->window != nullptr && this->window->isVisible()) {
		MacPanelStack::instance()->addPanel(this);
	} else {
		MacPanelStack::instance()->removePanel(this);
	}
	// Membership changed: this panel's own placement must account for the
	// zones now below it.
	this->updateDimensions();
}

// same rule as X11's XPanelWindow::updateDimensions minus the compositor
// exclusion loop (macOS has no cross-window exclusion; see the class comment):
//   - two opposite anchors force that dimension to the screen's, insetting by
//     the two margins;
//   - one anchor pins to that edge at the implicit size;
//   - no anchor on an axis centres on it.
void MacPanelWindow::updateDimensions(bool propagate) {
	if (this->window == nullptr || this->mTrackedScreen == nullptr) return;

	auto screenGeometry = this->mTrackedScreen->geometry();

	// Upstream X11's own-process stacking loop (x11/panel_window.cpp:245-266):
	// shrink the screen by the exclusive zones of same-layer, same-screen
	// panels below this one, so same-edge panels stack instead of overlapping.
	// This needs no compositor - it is pure bookkeeping over this process' own
	// panels.
	//
	// The GATE is the protocol's, not X11's: a surface whose zone is negative
	// asked not to be moved for anyone else's zone, so it keeps the whole
	// screen. X11 gates on `mode != Ignore`, which cannot see the difference -
	// a shell that writes `exclusiveZone: -1` leaves the mode at Normal
	// (wlr_layershell.hpp:148-151), and under a compositor that -1 reaches the
	// wire and the surface is left alone. Gating on the mode moved every such
	// surface down by the bar's zone instead.
	if (this->bcExclusiveZone.value() >= 0) {
		for (auto* panel: MacPanelStack::instance()->panels(this)) {
			// we only care about windows below us
			if (panel == this) break;

			// we only care about windows in the same layer
			if (panel->bAboveWindows != this->bAboveWindows) continue;

			if (panel->mTrackedScreen != this->mTrackedScreen) continue;

			auto edge = panel->bcExclusionEdge.value();
			// A negative zone reserves nothing - it is the "do not move me"
			// signal, not a reservation. Without the clamp it would GROW the
			// screen rect by a pixel per such panel below us.
			auto exclusiveZone = std::max(0, panel->bcExclusiveZone.value());

			screenGeometry.adjust(
			    edge == Qt::LeftEdge ? exclusiveZone : 0,
			    edge == Qt::TopEdge ? exclusiveZone : 0,
			    edge == Qt::RightEdge ? -exclusiveZone : 0,
			    edge == Qt::BottomEdge ? -exclusiveZone : 0
			);
		}
	}

	auto geometry = QRect();

	auto anchors = this->bAnchors.value();
	auto margins = this->bMargins.value();

	if (anchors.horizontalConstraint()) {
		geometry.setX(screenGeometry.x() + margins.left);
		geometry.setWidth(screenGeometry.width() - margins.left - margins.right);
	} else {
		if (anchors.mLeft) {
			geometry.setX(screenGeometry.x() + margins.left);
		} else if (anchors.mRight) {
			geometry.setX(
			    screenGeometry.x() + screenGeometry.width() - this->implicitWidth() - margins.right
			);
		} else {
			geometry.setX(screenGeometry.x() + screenGeometry.width() / 2 - this->implicitWidth() / 2);
		}

		geometry.setWidth(this->implicitWidth());
	}

	if (anchors.verticalConstraint()) {
		geometry.setY(screenGeometry.y() + margins.top);
		geometry.setHeight(screenGeometry.height() - margins.top - margins.bottom);
	} else {
		if (anchors.mTop) {
			geometry.setY(screenGeometry.y() + margins.top);
		} else if (anchors.mBottom) {
			geometry.setY(
			    screenGeometry.y() + screenGeometry.height() - this->implicitHeight() - margins.bottom
			);
		} else {
			geometry.setY(screenGeometry.y() + screenGeometry.height() / 2 - this->implicitHeight() / 2);
		}

		geometry.setHeight(this->implicitHeight());
	}

	this->mIntendedGeometry = geometry;
	this->window->setGeometry(geometry);
	// Qt's setGeometry alone can leave the native frame clamped below the
	// menu-bar strip when it ran while the window was still at the normal
	// level (see assertPanelFrame); push the intended frame through natively.
	assertPanelFrame(this->window, geometry);

	// A zone change here moves every panel stacked above it (upstream
	// x11/panel_window.cpp:398).
	if (propagate) MacPanelStack::instance()->updateLowerDimensions(this);
}

void MacPanelWindow::updateAboveWindows() {
	if (this->window == nullptr) return;

	auto above = this->bAboveWindows.value();
	// Qt's cocoa QPA maps these to an NSWindow level; applyNativeConfig then
	// refines the exact level (status-bar vs desktop).
	this->window->setFlag(Qt::WindowStaysOnBottomHint, !above);
	this->window->setFlag(Qt::WindowStaysOnTopHint, above);
	this->applyNativeConfig();
}

void MacPanelWindow::updateFocusable() {
	if (this->window == nullptr) return;
	this->window->setFlag(Qt::WindowDoesNotAcceptFocus, !this->bFocusable);
}

void MacPanelWindow::setOverlay(bool overlay) {
	if (this->mOverlay == overlay) return;
	this->mOverlay = overlay;
	this->applyNativeConfig();
}

void MacPanelWindow::setDesktopBackground(bool desktopBackground) {
	if (this->mDesktopBackground == desktopBackground) return;
	this->mDesktopBackground = desktopBackground;
	this->applyNativeConfig();
}

void MacPanelWindow::setExclusiveKeyboard(bool exclusiveKeyboard) {
	// A shell flips keyboardFocus on an already-visible modal; the change must
	// reapply the native config even though visibility did not change.
	if (this->mExclusiveKeyboard == exclusiveKeyboard) return;
	this->mExclusiveKeyboard = exclusiveKeyboard;
	this->applyNativeConfig();
}

void MacPanelWindow::applyNativeConfig() {
	if (this->window == nullptr) return;
	// Deferred: Qt applies its own window flags (and thus level) during show;
	// running after that settles lets the panel's level and collectionBehavior
	// win instead of being overwritten by Qt's flag application.
	auto* window = this->window;
	auto above = this->bAboveWindows.value();
	// A shell's background (wallpaper) layer is suppressed on macOS - the OS
	// owns the desktop. Driven by the WlrLayershell window subclass.
	auto background = this->mDesktopBackground;
	// A Wayland exclusive keyboard grab (launcher, modal): macOS only routes
	// keys to the active app's key window, so showing such a panel must take
	// app focus and hiding it must give focus back. Driven from here because
	// applyNativeConfig already runs on every visibility change.
	auto exclusiveKeyboard = this->mExclusiveKeyboard;
	auto overlay = this->mOverlay;
	QTimer::singleShot(0, this, [this, window, above, background, exclusiveKeyboard, overlay]() {
		qs::mac::configurePanelWindow(window, above, background, overlay);
		// The panel was shown (and possibly clamped out of the menu-bar strip)
		// before this deferred config raised its level; re-assert the intended
		// frame now that the level permits the true screen edge.
		assertPanelFrame(window, this->mIntendedGeometry);
		if (exclusiveKeyboard) {
			if (window->isVisible()) {
				qs::mac::takeKeyboardForPanel(window, this);
			} else {
				qs::mac::yieldKeyboardFromPanel(this);
			}
		}
	});
}

// Declare (or drop) this panel's reserved strip to the compositor. This is the
// macOS stand-in for a wl_layer surface's exclusive zone: there is no protocol,
// so the request goes over the compositor's control socket. Best-effort - if no
// compositor is listening the panel just draws without reserved space.
void MacPanelWindow::updateReservation() {
	// An unmapped layer surface has no exclusive zone (Wayland semantics).
	// Shells keep their popouts/modals alive and merely toggle visibility, so
	// without this gate a CLOSED popout kept reserving its whole width/height
	// forever (heartbeat included) - silently shrinking the compositor's
	// tiling area and re-tiling every window on each open/close.
	bool visible = this->window != nullptr && this->window->isVisible();
	auto zone = visible ? this->bcExclusiveZone.value() : 0;
	QString edge;
	switch (this->bcExclusionEdge.value()) {
	case Qt::TopEdge: edge = QStringLiteral("top"); break;
	case Qt::BottomEdge: edge = QStringLiteral("bottom"); break;
	case Qt::LeftEdge: edge = QStringLiteral("left"); break;
	case Qt::RightEdge: edge = QStringLiteral("right"); break;
	default: edge = QString(); break;
	}

	QString message;
	if (zone <= 0 || edge.isEmpty()) {
		message = QStringLiteral("action clear-zone %1").arg(this->mReservationId);
	} else {
		// Pass our pid so the compositor drops the reservation if we die
		// without clearing it (a crash or a hard kill) - the destructor's
		// clear-zone only runs on a clean exit.
		message = QStringLiteral("action reserve-zone %1 %2 %3 %4")
		              .arg(this->mReservationId, edge)
		              .arg(zone)
		              .arg(::getpid());
	}

	if (sendCompositorMessage(message)) {
		this->mReservationRetries = 0;
		return;
	}

	// The send did not land - at startup the compositor maps several panels at
	// once and refuses connections in bursts while it adopts them on its single
	// thread. Re-send the CURRENT reservation state a moment later, once it has
	// drained, so the strut is not silently lost. Bounded, and always re-derived
	// from the live bindings (not the stale message above), so a value that
	// changed meanwhile still converges - and if no compositor is really there,
	// it simply gives up after a few tries.
	if (this->mReservationRetries >= kMaxReservationRetries) return;
	this->mReservationRetries++;
	QTimer::singleShot(500, this, &MacPanelWindow::updateReservation);
}

// MacPanelInterface

MacPanelInterface::MacPanelInterface(QObject* parent)
    : MacPanelInterface(new MacPanelWindow(), parent) {}

MacPanelInterface::MacPanelInterface(MacPanelWindow* panel, QObject* parent)
    : PanelWindowInterface(parent)
    , panel(panel) {
	panel->setParent(this);
	this->connectSignals();

	// clang-format off
	QObject::connect(this->panel, &MacPanelWindow::anchorsChanged, this, &MacPanelInterface::anchorsChanged);
	QObject::connect(this->panel, &MacPanelWindow::marginsChanged, this, &MacPanelInterface::marginsChanged);
	QObject::connect(this->panel, &MacPanelWindow::exclusiveZoneChanged, this, &MacPanelInterface::exclusiveZoneChanged);
	QObject::connect(this->panel, &MacPanelWindow::exclusionModeChanged, this, &MacPanelInterface::exclusionModeChanged);
	QObject::connect(this->panel, &MacPanelWindow::aboveWindowsChanged, this, &MacPanelInterface::aboveWindowsChanged);
	QObject::connect(this->panel, &MacPanelWindow::focusableChanged, this, &MacPanelInterface::focusableChanged);
	// clang-format on
}

void MacPanelInterface::onReload(QObject* oldInstance) {
	QQmlEngine::setContextForObject(this->panel, QQmlEngine::contextForObject(this));

	auto* old = qobject_cast<MacPanelInterface*>(oldInstance);
	this->panel->reload(old != nullptr ? old->panel : nullptr);
}

ProxyWindowBase* MacPanelInterface::proxyWindow() const { return this->panel; }

// NOLINTBEGIN
#define proxyPair(type, get, set)                                                                  \
	type MacPanelInterface::get() const { return this->panel->get(); }                               \
	void MacPanelInterface::set(type value) { this->panel->set(value); }

proxyPair(Anchors, anchors, setAnchors);
proxyPair(Margins, margins, setMargins);
proxyPair(qint32, exclusiveZone, setExclusiveZone);
proxyPair(ExclusionMode::Enum, exclusionMode, setExclusionMode);
proxyPair(bool, focusable, setFocusable);
proxyPair(bool, aboveWindows, setAboveWindows);

#undef proxyPair
// NOLINTEND

} // namespace qs::mac
