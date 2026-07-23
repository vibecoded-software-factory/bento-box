#pragma once

#include <QtQuick/qquickitem.h>
#include <qcolor.h>
#include <qobject.h>
#include <qpointer.h>
#include <qqmlintegration.h>
#include <qqmllist.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "../../core/types.hpp"

// macOS shim for Quickshell.Wayland.
//
// DankMaterialShell (and most quickshell configs) reach for wlroots layer-shell
// directly - `PanelWindow { WlrLayershell.layer: WlrLayer.Top; ... }` - even
// though the portable `PanelWindow` already exists. There is no Wayland on
// macOS, but the SAME intent maps cleanly onto our AppKit PanelWindow: the
// layer is whether the panel floats above windows, exclusiveZone/exclusionMode
// are already first-class on PanelWindow, and keyboardFocus is focusability. So
// this is not a dead stub - the WlrLayershell attached object forwards each
// property onto the PanelWindow it is attached to. WlSessionLock has no macOS
// analogue (the system owns the lock screen) and is an inert stub for binding
// compatibility.
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

///! Wlroots layershell configuration, as an attached object of PanelWindow.
/// On macOS each property is forwarded onto the PanelWindow it is attached to,
/// mapping the wlroots layer-shell vocabulary onto the AppKit panel.
class WlrLayershell: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(qs::mac::wayland::WlrLayer::Enum layer READ layer WRITE setLayer NOTIFY layerChanged);
	Q_PROPERTY(QString namespace READ ns WRITE setNamespace NOTIFY namespaceChanged);
	Q_PROPERTY(qs::mac::wayland::WlrKeyboardFocus::Enum keyboardFocus READ keyboardFocus WRITE setKeyboardFocus NOTIFY keyboardFocusChanged);
	Q_PROPERTY(qint32 exclusiveZone READ exclusiveZone WRITE setExclusiveZone NOTIFY exclusiveZoneChanged);
	Q_PROPERTY(int exclusionMode READ exclusionMode WRITE setExclusionMode NOTIFY exclusionModeChanged);
	Q_PROPERTY(Margins margins READ margins WRITE setMargins NOTIFY marginsChanged);
	// clang-format on
	QML_ELEMENT;
	QML_ATTACHED(WlrLayershell);
	QML_UNCREATABLE("WlrLayershell is only available as an attached object");

public:
	// Shells write `WlrLayershell.layer: WlrLayershell.Overlay` - the layer
	// values looked up on the attached type itself, not only on WlrLayer. A
	// missing enum key evaluates to undefined and errors the whole document,
	// so re-export the values here with the same numbering as WlrLayer.
	enum Layer : quint8 {
		Background = 0,
		Bottom = 1,
		Top = 2,
		Overlay = 3,
	};
	Q_ENUM(Layer);

	explicit WlrLayershell(QObject* parent = nullptr);
	static WlrLayershell* qmlAttachedProperties(QObject* object);

	[[nodiscard]] WlrLayer::Enum layer() const { return this->mLayer; }
	void setLayer(WlrLayer::Enum layer);
	[[nodiscard]] QString ns() const { return this->mNamespace; }
	void setNamespace(const QString& ns);
	[[nodiscard]] WlrKeyboardFocus::Enum keyboardFocus() const { return this->mKeyboardFocus; }
	void setKeyboardFocus(WlrKeyboardFocus::Enum focus);
	[[nodiscard]] qint32 exclusiveZone() const { return this->mExclusiveZone; }
	void setExclusiveZone(qint32 zone);
	[[nodiscard]] int exclusionMode() const { return this->mExclusionMode; }
	void setExclusionMode(int mode);
	[[nodiscard]] Margins margins() const { return this->mMargins; }
	void setMargins(Margins margins);

signals:
	void layerChanged();
	void namespaceChanged();
	void keyboardFocusChanged();
	void exclusiveZoneChanged();
	void exclusionModeChanged();
	void marginsChanged();

private:
	// The PanelWindow this is attached to, whose properties we drive.
	QPointer<QObject> mPanel;
	WlrLayer::Enum mLayer = WlrLayer::Top;
	QString mNamespace;
	WlrKeyboardFocus::Enum mKeyboardFocus = WlrKeyboardFocus::None;
	qint32 mExclusiveZone = 0;
	int mExclusionMode = 0;
	Margins mMargins;
};

///! Idle monitor. Inert stub (never reports idle) for binding compatibility;
/// a real macOS backing would read IOKit's HID idle time.
class IdleMonitor: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(bool isIdle READ isIdle NOTIFY isIdleChanged);
	Q_PROPERTY(bool respected READ respected CONSTANT);
	Q_PROPERTY(bool respectInhibitors READ respectInhibitors WRITE setRespectInhibitors NOTIFY respectInhibitorsChanged);
	Q_PROPERTY(qreal timeout READ timeout WRITE setTimeout NOTIFY timeoutChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit IdleMonitor(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] bool enabled() const { return this->mEnabled; }
	void setEnabled(bool enabled) {
		if (this->mEnabled == enabled) return;
		this->mEnabled = enabled;
		emit this->enabledChanged();
	}
	[[nodiscard]] bool isIdle() const { return false; }
	[[nodiscard]] bool respected() const { return false; }
	[[nodiscard]] bool respectInhibitors() const { return this->mRespectInhibitors; }
	void setRespectInhibitors(bool value) {
		if (this->mRespectInhibitors == value) return;
		this->mRespectInhibitors = value;
		emit this->respectInhibitorsChanged();
	}
	[[nodiscard]] qreal timeout() const { return this->mTimeout; }
	void setTimeout(qreal timeout) {
		if (this->mTimeout == timeout) return;
		this->mTimeout = timeout;
		emit this->timeoutChanged();
	}

signals:
	void enabledChanged();
	void isIdleChanged();
	void timeoutChanged();
	void respectInhibitorsChanged();

private:
	bool mEnabled = false;
	bool mRespectInhibitors = false;
	qreal mTimeout = 0;
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
	void setWindow(QObject* window) {
		if (this->mWindow == window) return;
		this->mWindow = window;
		emit this->windowChanged();
	}

signals:
	void enabledChanged();
	void windowChanged();

private:
	bool mEnabled = false;
	QObject* mWindow = nullptr;
	// IOPMAssertionID; 0 is kIOPMNullAssertionID (typed loosely so the
	// header stays IOKit-free).
	quint32 mAssertion = 0;
};

///! Keyboard-shortcuts inhibitor. Inert stub - on Wayland it stops the
/// compositor from acting on shortcuts while e.g. recording a keybind; macOS
/// has no analogue the shell could drive.
class ShortcutInhibitor: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(QObject* window READ window WRITE setWindow NOTIFY windowChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit ShortcutInhibitor(QObject* parent = nullptr): QObject(parent) {}
	[[nodiscard]] bool enabled() const { return this->mEnabled; }
	void setEnabled(bool enabled) {
		if (this->mEnabled == enabled) return;
		this->mEnabled = enabled;
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

private:
	bool mEnabled = false;
	QObject* mWindow = nullptr;
};

// Toplevel, ToplevelManager and ScreencopyView are REAL on macOS - see
// toplevel.hpp (compositor-IPC-fed window list) and screencopy.hpp
// (ScreenCaptureKit) in this module.

///! Session lock. No macOS analogue - inert stub for binding compatibility.
/// Declares a default property so lock documents can nest their surfaces in
/// it the way they do on Wayland; the children are held but never shown.
class WlSessionLock: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool locked READ locked WRITE setLocked NOTIFY lockedChanged);
	Q_PROPERTY(bool secure READ secure CONSTANT);
	Q_PROPERTY(QQmlListProperty<QObject> data READ data);
	Q_CLASSINFO("DefaultProperty", "data");
	// clang-format on
	QML_ELEMENT;

public:
	explicit WlSessionLock(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] bool locked() const { return this->mLocked; }
	void setLocked(bool locked) {
		if (this->mLocked == locked) return;
		this->mLocked = locked;
		emit this->lockedChanged();
	}
	[[nodiscard]] bool secure() const { return false; }
	[[nodiscard]] QQmlListProperty<QObject> data() {
		return QQmlListProperty<QObject>(this, &this->mData);
	}

signals:
	void lockedChanged();

private:
	bool mLocked = false;
	QList<QObject*> mData;
};

///! Per-screen session-lock surface. Inert stub - it is never shown (macOS
/// owns the lock screen), but it accepts content and the properties lock
/// documents bind, so those documents still load.
class WlSessionLockSurface: public QQuickItem {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QObject* screen READ screen CONSTANT);
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit WlSessionLockSurface(QQuickItem* parent = nullptr): QQuickItem(parent) {}

	[[nodiscard]] QObject* screen() const { return nullptr; }
	[[nodiscard]] QColor color() const { return this->mColor; }
	void setColor(QColor color) {
		if (this->mColor == color) return;
		this->mColor = color;
		emit this->colorChanged();
	}

signals:
	void colorChanged();

private:
	QColor mColor;
};

} // namespace qs::mac::wayland
