#pragma once

#include <qobject.h>
#include <qqmlintegration.h>
#include <qstring.h>

namespace qs::mac {

// Quickshell.Mac.Desktop - set the real macOS desktop wallpaper.
//
// On Wayland a shell paints its own wallpaper onto a background layer surface;
// macOS owns the desktop, so bento suppresses that surface (see the background
// layer handling in the panel backend) and a shell drives the OS wallpaper
// through here instead. Backed by NSWorkspace.setDesktopImageURL, per screen.
class MacDesktop: public QObject {
	Q_OBJECT;
	QML_NAMED_ELEMENT(Desktop);
	QML_SINGLETON;

public:
	explicit MacDesktop(QObject* parent = nullptr): QObject(parent) {}

	// Set the wallpaper on every screen. `path` is a filesystem path or a
	// file:// URL. Returns false if the image could not be applied to any
	// screen - a missing file, or a colour string a shell stored where an image
	// path was expected (macOS can only show an image file, not a solid colour,
	// through this API).
	Q_INVOKABLE bool setWallpaper(const QString& path);
};

} // namespace qs::mac
