#include "desktop.hpp"

#import <AppKit/AppKit.h>
#include <qfileinfo.h>
#include <qstring.h>

namespace qs::mac {

bool MacDesktop::setWallpaper(const QString& path) {
	if (path.isEmpty()) return false;

	// Accept a plain filesystem path or a file:// URL; a shell may hand us
	// either. A non-file value (a solid-colour string like "#1e1e2e") has no
	// NSWorkspace equivalent, so it falls through to a failed lookup and we
	// return false rather than guessing.
	NSURL* url = nil;
	if (path.startsWith(QStringLiteral("file:"))) {
		url = [NSURL URLWithString:path.toNSString()];
	} else {
		QFileInfo info(path);
		if (!info.exists() || !info.isFile()) return false;
		url = [NSURL fileURLWithPath:info.absoluteFilePath().toNSString()];
	}
	if (url == nil) return false;

	NSWorkspace* workspace = [NSWorkspace sharedWorkspace];
	// Aspect-fill and crop the overflow, the way a shell's own wallpaper layer
	// draws it, rather than letterboxing.
	NSDictionary* options = @{
		NSWorkspaceDesktopImageScalingKey : @(NSImageScaleProportionallyUpOrDown),
		NSWorkspaceDesktopImageAllowClippingKey : @YES,
	};

	bool anyApplied = false;
	for (NSScreen* screen in [NSScreen screens]) {
		NSError* error = nil;
		if ([workspace setDesktopImageURL:url forScreen:screen options:options error:&error]) {
			anyApplied = true;
		} else if (error != nil) {
			NSLog(@"[bento] setDesktopImageURL failed: %@", error.localizedDescription);
		}
	}
	return anyApplied;
}

} // namespace qs::mac
