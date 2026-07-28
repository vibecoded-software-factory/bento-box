#pragma once

#include <QtQuick/qquickitem.h>
#include <qcolor.h>
#include <qdebug.h>
#include <qobject.h>
#include <qpointer.h>
#include <qqmlcomponent.h>
#include <qqmlintegration.h>
#include <qqmllist.h>
#include <qstring.h>
#include <qtimer.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "../../core/qmlscreen.hpp"
#include "../../core/region.hpp"
#include "../../core/reload.hpp"
#include "../../core/types.hpp"
#include "../../window/panelinterface.hpp"
#include "../panel_window.hpp"

// macOS shim for Quickshell.Wayland.
//
// DankMaterialShell (and most quickshell configs) reach for wlroots layer-shell
// directly - `PanelWindow { WlrLayershell.layer: WlrLayer.Top; ... }` - even
// though the portable `PanelWindow` already exists. There is no Wayland on
// macOS, but the SAME intent maps cleanly onto the AppKit panel backend: the
// layer is whether the panel floats above windows, exclusiveZone/exclusionMode
// are already first-class on the panel, and keyboardFocus is focusability. So,
// like upstream, `WlrLayershell` here is a REAL creatable window (a
// MacPanelWindow subclass carrying the layer vocabulary), the PanelWindow
// overlay backs every panel with one (WaylandPanelInterface below), and the
// attached object IS that backing window - every window property resolves
// through it, exactly upstream's shape (wlr_layershell.cpp:163-169).
// WlSessionLock has no macOS analogue (the system owns the lock screen) and is
// an inert stub for binding compatibility.
namespace qs::mac::wayland {

///! WlrLayershell layer.
namespace WlrLayer { // NOLINT
Q_NAMESPACE;
QML_ELEMENT;
enum Enum : quint8 {
	Background = 0,
	Bottom = 1,
	Top = 2,
	Overlay = 3,
};
Q_ENUM_NS(Enum);
} // namespace WlrLayer

///! WlrLayershell keyboard focus mode.
namespace WlrKeyboardFocus { // NOLINT
Q_NAMESPACE;
QML_ELEMENT;
enum Enum : quint8 {
	None = 0,
	Exclusive = 1,
	OnDemand = 2,
};
Q_ENUM_NS(Enum);
} // namespace WlrKeyboardFocus

///! Wlroots layershell window
/// Decorationless window that can be attached to the screen edges using the [zwlr_layer_shell_v1] protocol.
///
/// #### Attached object
/// `WlrLayershell` works as an attached object of @@Quickshell.PanelWindow which you should use instead if you can,
/// as it is platform independent.
///
/// ```qml
/// PanelWindow {
///   // When PanelWindow is backed with WlrLayershell this will work
///   WlrLayershell.layer: WlrLayer.Bottom
/// }
/// ```
///
/// On macOS this is the AppKit panel backend (MacPanelWindow) carrying the
/// layer-shell vocabulary; every PanelWindow is backed by one, and the
/// attached object IS the backing window, like upstream.
///
/// [zwlr_layer_shell_v1]: https://wayland.app/protocols/wlr-layer-shell-unstable-v1
class WlrLayershell: public qs::mac::MacPanelWindow {
	QSDOC_BASECLASS(PanelWindowInterface);
	// clang-format off
	Q_OBJECT;
	/// The shell layer the window sits in. Defaults to `WlrLayer.Top`.
	Q_PROPERTY(qs::mac::wayland::WlrLayer::Enum layer READ layer WRITE setLayer NOTIFY layerChanged);
	/// Similar to the class property of windows. Can be used to identify the window to external tools.
	/// INERT on macOS: stored so reads round-trip, forwarded nowhere.
	Q_PROPERTY(QString namespace READ ns WRITE setNamespace NOTIFY namespaceChanged);
	/// The degree of keyboard focus taken. Defaults to `KeyboardFocus.None`.
	Q_PROPERTY(qs::mac::wayland::WlrKeyboardFocus::Enum keyboardFocus READ keyboardFocus WRITE setKeyboardFocus NOTIFY keyboardFocusChanged);
	QML_ATTACHED(WlrLayershell);
	QML_ELEMENT;
	// clang-format on

public:
	// DMS writes `WlrLayershell.layer: WlrLayershell.Overlay` in four
	// places. Upstream's WlrLayershell declares NO such enum - there the
	// lookup evaluates to undefined and the assignment is a tolerated
	// runtime no-op. Re-exporting WlrLayer's values here (same numbering)
	// is a deliberate SUPERSET so the spelling actually resolves; it cannot
	// collide with upstream configs because the names match WlrLayer's.
	enum Layer : quint8 {
		Background = 0,
		Bottom = 1,
		Top = 2,
		Overlay = 3,
	};
	Q_ENUM(Layer);

	explicit WlrLayershell(QObject* parent = nullptr): MacPanelWindow(parent) {}

	static WlrLayershell* qmlAttachedProperties(QObject* object);

	[[nodiscard]] WlrLayer::Enum layer() const { return this->mLayer; }
	void setLayer(WlrLayer::Enum layer);

	[[nodiscard]] QString ns() const { return this->mNamespace; }
	void setNamespace(const QString& ns);

	[[nodiscard]] WlrKeyboardFocus::Enum keyboardFocus() const { return this->mKeyboardFocus; }
	void setKeyboardFocus(WlrKeyboardFocus::Enum focus);

	// Upstream's conversions (wlr_layershell.cpp:136-146): a write to the
	// panel's aboveWindows/focusable is a write to layer/keyboardFocus, so
	// direct panel writes reflect into attached reads - real shared state.
	void setAboveWindows(bool aboveWindows) override;
	void setFocusable(bool focusable) override;

signals:
	void layerChanged();
	void namespaceChanged();
	void keyboardFocusChanged();

private:
	WlrLayer::Enum mLayer = WlrLayer::Top;
	// Upstream's default (wlr_layershell.hpp:193).
	QString mNamespace = "quickshell";
	WlrKeyboardFocus::Enum mKeyboardFocus = WlrKeyboardFocus::None;
};

// The PanelWindow backend registered on macOS: a MacPanelInterface whose
// window is a WlrLayershell, mirroring upstream's WaylandPanelInterface
// owning a WlrLayershell (wlr_layershell.cpp:171-186). This is what makes
// the attached object resolve on every PanelWindow. Registered by the cocoa
// overlay plugin (src/mac/init.cpp), not as a QML element of this module.
class WaylandPanelInterface: public qs::mac::MacPanelInterface {
	Q_OBJECT;

public:
	explicit WaylandPanelInterface(QObject* parent = nullptr)
	    : MacPanelInterface(new WlrLayershell(), parent) {}
};

///! Idle monitor. Inert stub (never reports idle) for binding compatibility;
/// a real macOS backing would read IOKit's HID idle time.
class IdleMonitor: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(bool isIdle READ isIdle NOTIFY isIdleChanged);
	Q_PROPERTY(bool respectInhibitors READ respectInhibitors WRITE setRespectInhibitors NOTIFY respectInhibitorsChanged);
	Q_PROPERTY(qreal timeout READ timeout WRITE setTimeout NOTIFY timeoutChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit IdleMonitor(QObject* parent = nullptr);

	[[nodiscard]] bool enabled() const { return this->mEnabled; }
	void setEnabled(bool enabled) {
		if (this->mEnabled == enabled) return;
		this->mEnabled = enabled;
		this->rearm();
		emit this->enabledChanged();
	}
	[[nodiscard]] bool isIdle() const { return this->mIsIdle; }
	[[nodiscard]] bool respectInhibitors() const { return this->mRespectInhibitors; }
	void setRespectInhibitors(bool value) {
		if (this->mRespectInhibitors == value) return;
		this->mRespectInhibitors = value;
		this->rearm();
		emit this->respectInhibitorsChanged();
	}
	[[nodiscard]] qreal timeout() const { return this->mTimeout; }
	void setTimeout(qreal timeout) {
		if (this->mTimeout == timeout) return;
		this->mTimeout = timeout;
		this->rearm();
		emit this->timeoutChanged();
	}

signals:
	void enabledChanged();
	void isIdleChanged();
	void timeoutChanged();
	void respectInhibitorsChanged();

private slots:
	// Sample the OS idle clock and flip isIdle across the timeout boundary.
	void poll();

private:
	// (Re)configure the poll timer after any input property changes and
	// reset the idle state when the monitor goes inert (disabled/timeout<=0),
	// matching upstream where clearing the monitor drops isIdle to false.
	void rearm();
	// True while an idle-sleep power assertion is held by any process (our
	// own IdleInhibitor, caffeinate, a video app...). Wayland's monitor is
	// suppressed by idle inhibitors; respectInhibitors maps that to here.
	static bool inhibited();

	// Upstream defaults BOTH to true (idle_notify/monitor.hpp:69-71).
	bool mEnabled = true;
	bool mRespectInhibitors = true;
	qreal mTimeout = 0;
	bool mIsIdle = false;
	QTimer mPollTimer;
};

///! Idle inhibitor. Prevents the display from sleeping while enabled.
/// On Wayland this is zwp_idle_inhibit for a visible surface; on macOS it
/// holds a power-management assertion (the same mechanism as `caffeinate
/// -d`), released on disable or teardown. The `window` association is
/// accepted for compatibility; the inhibit is driven by `enabled` alone.
class IdleInhibitor: public QObject {
	Q_OBJECT;
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(QObject* window READ window WRITE setWindow NOTIFY windowChanged);
	QML_ELEMENT;

public:
	explicit IdleInhibitor(QObject* parent = nullptr): QObject(parent) {}
	~IdleInhibitor() override;
	Q_DISABLE_COPY_MOVE(IdleInhibitor);

	[[nodiscard]] bool enabled() const { return this->mEnabled; }
	void setEnabled(bool enabled);
	[[nodiscard]] QObject* window() const { return this->mWindow; }
	void setWindow(QObject* window);

signals:
	void enabledChanged();
	void windowChanged();

private slots:
	// Upstream is active only while the bound window has a surface
	// (idle_inhibit/inhibitor.hpp:33-37): here that maps to the window
	// being set AND visible - the assertion follows both.
	void updateAssertion();

private:
	[[nodiscard]] bool windowEligible() const;

	bool mEnabled = false;
	QObject* mWindow = nullptr;
	// IOPMAssertionID; 0 is kIOPMNullAssertionID (typed loosely so the
	// header stays IOKit-free).
	quint32 mAssertion = 0;
};

///! Keyboard-shortcuts inhibitor. Inert stub - on Wayland it stops the
/// compositor from acting on shortcuts while e.g. recording a keybind; macOS
/// has no analogue the shell could drive.
///! Background blur effect for Wayland surfaces.
/// Applies background blur behind a @@Quickshell.QsWindow or subclass,
/// as an attached object, using the [ext-background-effect-v1] Wayland protocol.
///
/// On Wayland the compositor does the blurring, asked over the protocol. macOS
/// has no such protocol and no compositor to ask, so the window blurs its own
/// backdrop instead: an `NSVisualEffectView` in `behindWindow` blending mode
/// sits under the Qt content, masked to @@blurRegion
/// (`qs::mac::applyBackgroundBlur`). The observable result is the same, which
/// is what lets a shell written against the protocol work here unchanged.
///
/// [ext-background-effect-v1]: https://wayland.app/protocols/ext-background-effect-v1
class BackgroundEffect: public QObject {
	Q_OBJECT;
	// clang-format off
	/// Region to blur behind the surface. Set to null to remove blur.
	Q_PROPERTY(PendingRegion* blurRegion READ blurRegion WRITE setBlurRegion NOTIFY blurRegionChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("BackgroundEffect can only be used as an attached object.");
	QML_ATTACHED(BackgroundEffect);

public:
	explicit BackgroundEffect(ProxyWindowBase* window);

	static BackgroundEffect* qmlAttachedProperties(QObject* object);

	[[nodiscard]] PendingRegion* blurRegion() const { return this->mBlurRegion; }
	void setBlurRegion(PendingRegion* region);

signals:
	void blurRegionChanged();

private slots:
	void onWindowConnected();
	void onProxyWindowDestroyed();
	void onBlurRegionDestroyed();
	/// Re-derive the mask and push it to the native view.
	///
	/// Driven by the region's own `changed`, by the window's visibility and by
	/// every polish: a blur region is normally bound to an item's geometry, and
	/// polish is where that geometry is settled for the frame - the same hook
	/// the input mask already uses.
	void updateBlurRegion();

private:
	ProxyWindowBase* proxyWindow = nullptr;
	PendingRegion* mBlurRegion = nullptr;
};

class ShortcutInhibitor: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(QObject* window READ window WRITE setWindow NOTIFY windowChanged);
	/// Upstream: true while the compositor honors the inhibit
	/// (inhibitor.hpp:43). Nothing can be inhibited on macOS, so always
	/// false - and the compositor-side `cancelled()` can never fire.
	Q_PROPERTY(bool active READ active NOTIFY activeChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit ShortcutInhibitor(QObject* parent = nullptr): QObject(parent) {}
	[[nodiscard]] static bool active() { return false; }
	[[nodiscard]] bool enabled() const { return this->mEnabled; }
	void setEnabled(bool enabled) {
		if (this->mEnabled == enabled) return;
		this->mEnabled = enabled;
		if (enabled)
			qWarning() << "ShortcutInhibitor: compositor shortcuts are not inhibitable on macOS";
		emit this->enabledChanged();
	}
	[[nodiscard]] QObject* window() const { return this->mWindow; }
	void setWindow(QObject* window) {
		if (this->mWindow == window) return;
		this->mWindow = window;
		emit this->windowChanged();
	}

signals:
	void enabledChanged();
	void windowChanged();
	void activeChanged();
	/// Fired by the compositor when it revokes the inhibit; unreachable on
	/// macOS, present so `onCancelled:` handlers resolve.
	void cancelled();

private:
	bool mEnabled = false;
	QObject* mWindow = nullptr;
};

// Toplevel, ToplevelManager and ScreencopyView are REAL on macOS - see
// toplevel.hpp (compositor-IPC-fed window list) and screencopy.hpp
// (ScreenCaptureKit) in this module.

///! Session lock. No macOS analogue - inert stub with upstream's surface
/// (session_lock.hpp:57-97): `surface` takes a QQmlComponent (a nested
/// WlSessionLockSurface auto-wraps into one, which is how shells write it)
/// and is the default property; nothing is ever instantiated or shown -
/// macOS owns the lock screen (the shell locks via its custom locker).
class WlSessionLock: public Reloadable {
	Q_OBJECT;
	// clang-format off
	/// Controls the lock state.
	Q_PROPERTY(bool locked READ isLocked WRITE setLocked NOTIFY lockStateChanged);
	/// The compositor lock state. Always false on macOS (nothing locks here).
	Q_PROPERTY(bool secure READ isSecure NOTIFY secureStateChanged);
	/// The surface that will be created for each screen. Must create a @@WlSessionLockSurface$.
	Q_PROPERTY(QQmlComponent* surface READ surfaceComponent WRITE setSurfaceComponent NOTIFY surfaceComponentChanged);
	// clang-format on
	QML_ELEMENT;
	Q_CLASSINFO("DefaultProperty", "surface");

public:
	explicit WlSessionLock(QObject* parent = nullptr): Reloadable(parent) {}

	void onReload(QObject* /*oldInstance*/) override {}

	[[nodiscard]] bool isLocked() const { return this->mLocked; }
	void setLocked(bool locked) {
		if (this->mLocked == locked) return;
		this->mLocked = locked;
		// `locked` is the client's REQUESTED state (upstream semantics);
		// `secure` stays false - nothing locks here.
		if (locked) qWarning() << "WlSessionLock: no session-lock surface on macOS; secure stays false";
		emit this->lockStateChanged();
	}
	[[nodiscard]] static bool isSecure() { return false; }

	[[nodiscard]] QQmlComponent* surfaceComponent() const { return this->mSurfaceComponent; }
	void setSurfaceComponent(QQmlComponent* surfaceComponent) {
		if (this->mSurfaceComponent == surfaceComponent) return;
		this->mSurfaceComponent = surfaceComponent;
		emit this->surfaceComponentChanged();
	}

signals:
	void lockStateChanged();
	void secureStateChanged();
	void surfaceComponentChanged();

private:
	bool mLocked = false;
	QQmlComponent* mSurfaceComponent = nullptr;
};

///! Per-screen session-lock surface. Inert stub with upstream's surface
/// (session_lock.hpp:105-145): never shown (macOS owns the lock screen),
/// but content loads into a real contentItem so `anchors.fill: parent`
/// children resolve like they do upstream.
class WlSessionLockSurface: public Reloadable {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QQuickItem* contentItem READ contentItem);
	/// If the surface has been made visible. Never true on macOS.
	Q_PROPERTY(bool visible READ isVisible NOTIFY visibleChanged);
	Q_PROPERTY(qint32 width READ width NOTIFY widthChanged);
	Q_PROPERTY(qint32 height READ height NOTIFY heightChanged);
	/// The screen that the surface is displayed on. Always null on macOS
	/// (the surface is never displayed).
	Q_PROPERTY(QuickshellScreenInfo* screen READ screen NOTIFY screenChanged);
	/// The background color of the window. Defaults to white.
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged);
	Q_PROPERTY(QQmlListProperty<QObject> data READ data);
	// clang-format on
	QML_NAMED_ELEMENT(WlSessionLockSurface);
	Q_CLASSINFO("DefaultProperty", "data");

public:
	explicit WlSessionLockSurface(QObject* parent = nullptr)
	    : Reloadable(parent)
	    , mContentItem(new QQuickItem()) {
		this->mContentItem->setParent(this);
	}

	void onReload(QObject* /*oldInstance*/) override {}

	[[nodiscard]] QQuickItem* contentItem() const { return this->mContentItem; }
	[[nodiscard]] static bool isVisible() { return false; }
	[[nodiscard]] static qint32 width() { return 0; }
	[[nodiscard]] static qint32 height() { return 0; }
	[[nodiscard]] static QuickshellScreenInfo* screen() { return nullptr; }
	[[nodiscard]] QColor color() const { return this->mColor; }
	void setColor(QColor color) {
		if (this->mColor == color) return;
		this->mColor = color;
		emit this->colorChanged();
	}
	[[nodiscard]] QQmlListProperty<QObject> data() {
		return QQmlListProperty<QObject>(
		    this,
		    nullptr,
		    &WlSessionLockSurface::dataAppend,
		    nullptr,
		    nullptr,
		    nullptr
		);
	}

signals:
	void visibleChanged();
	void widthChanged();
	void heightChanged();
	void screenChanged();
	void colorChanged();

private:
	static void dataAppend(QQmlListProperty<QObject>* prop, QObject* obj) {
		auto* self = static_cast<WlSessionLockSurface*>(prop->object);
		obj->setParent(self);
		// Visual children land in the contentItem, upstream's structure -
		// `anchors.fill: parent` inside the surface keeps resolving.
		if (auto* item = qobject_cast<QQuickItem*>(obj)) {
			item->setParentItem(self->mContentItem);
		}
	}

	QQuickItem* mContentItem;
	// Upstream defaults to white (session_lock.hpp:186).
	QColor mColor = Qt::white;
};

} // namespace qs::mac::wayland
