#include "panel_window.hpp"

#include <unistd.h>

#include <qnamespace.h>
#include <qobject.h>
#include <qqmlengine.h>
#include <qquickwindow.h>
#include <qrect.h>
#include <qscreen.h>
#include <qtimer.h>
#include <qtmetamacros.h>
#include <qtypes.h>

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

MacPanelWindow::MacPanelWindow(QObject* parent): ProxyWindowBase(parent) {
	this->mReservationId = nextReservationId();

	// The single edge the anchors leave free on an axis - the edge to reserve
	// against. Zero (no unique edge) means the panel is not edge-anchored and
	// reserves nothing.
	this->bcExclusionEdge.setBinding([this] { return this->bAnchors.value().exclusionEdge(); });

	// niri/wlroots/X11's exclusive-zone rule, verbatim: Ignore reserves
	// nothing, Normal reserves the set amount, Auto reserves the panel's own
	// size on the anchored axis plus that edge's margins.
	this->bcExclusiveZone.setBinding([this]() -> qint32 {
		switch (this->bExclusionMode.value()) {
		case ExclusionMode::Ignore: return 0;
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
	// Give the space back - a panel that goes away must not leave the layout
	// permanently shrunk.
	sendCompositorMessage(QStringLiteral("action clear-zone %1").arg(this->mReservationId));
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

	this->applyNativeConfig();
	// Send the initial reservation now that the panel is configured; later
	// changes drive it through the bcExclusiveZone/bcExclusionEdge bindings.
	this->updateReservation();
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
// same rule as X11's XPanelWindow::updateDimensions minus the compositor
// exclusion loop (macOS has no cross-window exclusion; see the class comment):
//   - two opposite anchors force that dimension to the screen's, insetting by
//     the two margins;
//   - one anchor pins to that edge at the implicit size;
//   - no anchor on an axis centres on it.
void MacPanelWindow::updateDimensions() {
	if (this->window == nullptr || this->mTrackedScreen == nullptr) return;

	auto screenGeometry = this->mTrackedScreen->geometry();
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

	this->window->setGeometry(geometry);
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

void MacPanelWindow::applyNativeConfig() {
	if (this->window == nullptr) return;
	// Deferred: Qt applies its own window flags (and thus level) during show;
	// running after that settles lets the panel's level and collectionBehavior
	// win instead of being overwritten by Qt's flag application.
	auto* window = this->window;
	auto above = this->bAboveWindows.value();
	QTimer::singleShot(0, this, [window, above]() { qs::mac::configurePanelWindow(window, above); });
}

// Declare (or drop) this panel's reserved strip to the compositor. This is the
// macOS stand-in for a wl_layer surface's exclusive zone: there is no protocol,
// so the request goes over the compositor's control socket. Best-effort - if no
// compositor is listening the panel just draws without reserved space.
void MacPanelWindow::updateReservation() {
	auto zone = this->bcExclusiveZone.value();
	QString edge;
	switch (this->bcExclusionEdge.value()) {
	case Qt::TopEdge: edge = QStringLiteral("top"); break;
	case Qt::BottomEdge: edge = QStringLiteral("bottom"); break;
	case Qt::LeftEdge: edge = QStringLiteral("left"); break;
	case Qt::RightEdge: edge = QStringLiteral("right"); break;
	default: edge = QString(); break;
	}

	if (zone <= 0 || edge.isEmpty()) {
		sendCompositorMessage(QStringLiteral("action clear-zone %1").arg(this->mReservationId));
	} else {
		// Pass our pid so the compositor drops the reservation if we die
		// without clearing it (a crash or a hard kill) - the destructor's
		// clear-zone only runs on a clean exit.
		sendCompositorMessage(QStringLiteral("action reserve-zone %1 %2 %3 %4")
		                          .arg(this->mReservationId, edge)
		                          .arg(zone)
		                          .arg(::getpid()));
	}
}

// MacPanelInterface

MacPanelInterface::MacPanelInterface(QObject* parent)
    : PanelWindowInterface(parent)
    , panel(new MacPanelWindow(this)) {
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
