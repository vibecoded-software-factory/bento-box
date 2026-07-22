#pragma once

#include <qobject.h>
#include <qqmlintegration.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"

// The macOS system tray stub.
//
// The Linux service receives tray icons that other apps publish over
// StatusNotifierItem (D-Bus). macOS has no supported equivalent: apps create
// NSStatusItems directly and there is NO public API to enumerate another app's
// status items. A real implementation would have to scrape the menu bar with
// private CoreGraphics/SkyLight APIs and capture each icon with
// ScreenCaptureKit (the approach Ice/Bartender take) - which needs Screen
// Recording permission, cannot be sandboxed, and leans on private APIs.
//
// So this module exists only to provide the `Quickshell.Services.SystemTray`
// QML surface so a shell that imports it binds without error; `items` is always
// empty. On macOS the system already shows these items in its own menu bar.
namespace qs::mac::systemtray {

///! Status of a SystemTrayItem.
namespace Status { // NOLINT
Q_NAMESPACE;
QML_ELEMENT;

enum Enum : quint8 {
	Passive = 0,
	Active = 1,
	NeedsAttention = 2,
};
Q_ENUM_NS(Enum);
} // namespace Status

///! Category of a SystemTrayItem.
namespace Category { // NOLINT
Q_NAMESPACE;
QML_ELEMENT;

enum Enum : quint8 {
	Hardware = 0,
	SystemServices = 1,
	ApplicationStatus = 2,
	Communications = 3,
};
Q_ENUM_NS(Enum);
} // namespace Category

///! A system tray icon.
/// The macOS counterpart of the Linux `SystemTrayItem`. Provided for API
/// compatibility only - macOS cannot enumerate other apps' tray items, so
/// `SystemTray.items` is always empty and this type is never instantiated.
class SystemTrayItem: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString id READ id CONSTANT);
	Q_PROPERTY(QString title READ title CONSTANT);
	Q_PROPERTY(qs::mac::systemtray::Status::Enum status READ status CONSTANT);
	Q_PROPERTY(qs::mac::systemtray::Category::Enum category READ category CONSTANT);
	Q_PROPERTY(QString icon READ icon CONSTANT);
	Q_PROPERTY(QString tooltipTitle READ tooltipTitle CONSTANT);
	Q_PROPERTY(QString tooltipDescription READ tooltipDescription CONSTANT);
	Q_PROPERTY(bool hasMenu READ hasMenu CONSTANT);
	Q_PROPERTY(bool onlyMenu READ onlyMenu CONSTANT);
	// The Linux service exposes a DBusMenuHandle here; macOS has no equivalent,
	// so the property is present (for binding compatibility) but always null.
	Q_PROPERTY(QObject* menu READ menu CONSTANT);
	// clang-format on
	QML_NAMED_ELEMENT(SystemTrayItem);
	QML_UNCREATABLE("SystemTrayItems can only be acquired from SystemTray");

public:
	explicit SystemTrayItem(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] QString id() const { return {}; }
	[[nodiscard]] QString title() const { return {}; }
	[[nodiscard]] Status::Enum status() const { return Status::Passive; }
	[[nodiscard]] Category::Enum category() const { return Category::ApplicationStatus; }
	[[nodiscard]] QString icon() const { return {}; }
	[[nodiscard]] QString tooltipTitle() const { return {}; }
	[[nodiscard]] QString tooltipDescription() const { return {}; }
	[[nodiscard]] bool hasMenu() const { return false; }
	[[nodiscard]] bool onlyMenu() const { return false; }
	[[nodiscard]] QObject* menu() const { return nullptr; }

	Q_INVOKABLE void activate() {}
	Q_INVOKABLE void secondaryActivate() {}
	Q_INVOKABLE void scroll(qint32 delta, bool horizontal) const;
	Q_INVOKABLE void display(QObject* parentWindow, qint32 relativeX, qint32 relativeY);
};

///! System tray.
/// The macOS counterpart of the Linux `SystemTray` singleton. `items` is always
/// empty - macOS provides no way to enumerate other apps' tray icons (see the
/// module comment).
class SystemTray: public QObject {
	Q_OBJECT;
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::systemtray::SystemTrayItem>*);
	Q_PROPERTY(UntypedObjectModel* items READ items CONSTANT);
	QML_ELEMENT;
	QML_SINGLETON;

public:
	explicit SystemTray(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] ObjectModel<SystemTrayItem>* items() { return &this->mItems; }

private:
	ObjectModel<SystemTrayItem> mItems {this};
};

} // namespace qs::mac::systemtray
