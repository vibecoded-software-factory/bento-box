#pragma once

#include <QtQuick/qquickitem.h>
#include <qobject.h>
#include <qpointer.h>
#include <qqmlintegration.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"

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
	// clang-format on
	QML_ELEMENT;
	QML_ATTACHED(WlrLayershell);
	QML_UNCREATABLE("WlrLayershell is only available as an attached object");

public:
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

signals:
	void layerChanged();
	void namespaceChanged();
	void keyboardFocusChanged();
	void exclusiveZoneChanged();
	void exclusionModeChanged();

private:
	// The PanelWindow this is attached to, whose properties we drive.
	QPointer<QObject> mPanel;
	WlrLayer::Enum mLayer = WlrLayer::Top;
	QString mNamespace;
	WlrKeyboardFocus::Enum mKeyboardFocus = WlrKeyboardFocus::None;
	qint32 mExclusiveZone = 0;
	int mExclusionMode = 0;
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

///! Idle inhibitor. Inert stub (a real backing would prevent display sleep).
class IdleInhibitor: public QObject {
	Q_OBJECT;
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(QObject* window READ window WRITE setWindow NOTIFY windowChanged);
	QML_ELEMENT;

public:
	explicit IdleInhibitor(QObject* parent = nullptr): QObject(parent) {}
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

///! A foreign toplevel (another app's window). Inert stub; the real window list
/// is the compositor's job (see Quickshell.Nigiri).
class Toplevel: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString appId READ appId NOTIFY appIdChanged);
	Q_PROPERTY(QString title READ title NOTIFY titleChanged);
	Q_PROPERTY(bool activated READ activated NOTIFY activatedChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("Toplevels are acquired from ToplevelManager");

public:
	explicit Toplevel(QObject* parent = nullptr): QObject(parent) {}
	[[nodiscard]] QString appId() const { return {}; }
	[[nodiscard]] QString title() const { return {}; }
	[[nodiscard]] bool activated() const { return false; }
	Q_INVOKABLE void activate() {}
	Q_INVOKABLE void close() {}

signals:
	void appIdChanged();
	void titleChanged();
	void activatedChanged();
};

///! Foreign-toplevel manager. Inert stub - the toplevel list is the
/// compositor's job (see Quickshell.Nigiri); empty here.
class ToplevelManager: public QObject {
	Q_OBJECT;
	// clang-format off
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::wayland::Toplevel>*);
	Q_PROPERTY(UntypedObjectModel* toplevels READ toplevels CONSTANT);
	Q_PROPERTY(qs::mac::wayland::Toplevel* activeToplevel READ activeToplevel NOTIFY activeToplevelChanged);
	// clang-format on
	QML_NAMED_ELEMENT(ToplevelManager);
	QML_SINGLETON;

public:
	explicit ToplevelManager(QObject* parent = nullptr): QObject(parent) {}
	[[nodiscard]] ObjectModel<Toplevel>* toplevels() { return &this->mToplevels; }
	[[nodiscard]] Toplevel* activeToplevel() const { return nullptr; }

signals:
	void activeToplevelChanged();

private:
	ObjectModel<Toplevel> mToplevels {this};
};

///! A live view of a captured window/screen. Inert stub - renders nothing
/// (macOS window capture would be ScreenCaptureKit); keeps the overview from
/// erroring.
class ScreencopyView: public QQuickItem {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QObject* captureSource READ captureSource WRITE setCaptureSource NOTIFY captureSourceChanged);
	Q_PROPERTY(bool live READ live WRITE setLive NOTIFY liveChanged);
	Q_PROPERTY(bool paintCursor READ paintCursor WRITE setPaintCursor NOTIFY paintCursorChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit ScreencopyView(QQuickItem* parent = nullptr): QQuickItem(parent) {}
	[[nodiscard]] QObject* captureSource() const { return this->mCaptureSource; }
	void setCaptureSource(QObject* source) {
		if (this->mCaptureSource == source) return;
		this->mCaptureSource = source;
		emit this->captureSourceChanged();
	}
	[[nodiscard]] bool live() const { return this->mLive; }
	void setLive(bool live) {
		if (this->mLive == live) return;
		this->mLive = live;
		emit this->liveChanged();
	}
	[[nodiscard]] bool paintCursor() const { return this->mPaintCursor; }
	void setPaintCursor(bool value) {
		if (this->mPaintCursor == value) return;
		this->mPaintCursor = value;
		emit this->paintCursorChanged();
	}

signals:
	void captureSourceChanged();
	void liveChanged();
	void paintCursorChanged();

private:
	QObject* mCaptureSource = nullptr;
	bool mLive = false;
	bool mPaintCursor = false;
};

///! Session lock. No macOS analogue - inert stub for binding compatibility.
class WlSessionLock: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool locked READ locked WRITE setLocked NOTIFY lockedChanged);
	Q_PROPERTY(bool secure READ secure CONSTANT);
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

signals:
	void lockedChanged();

private:
	bool mLocked = false;
};

} // namespace qs::mac::wayland
