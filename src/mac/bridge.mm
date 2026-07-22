#include "bridge.hpp"

#import <AppKit/AppKit.h>

#include <qwindow.h>

namespace qs::mac {

// QWindow::winId() returns the NSView* on the cocoa QPA; its `.window` is the
// NSWindow Qt created for us. reinterpret_cast, not a Qt native interface,
// because the native-interface API for cocoa is not shipped in a public header
// - this cast is the same one Qt's own cocoa integration documents.
static NSWindow* nsWindowFor(QWindow* window) {
	if (window == nullptr) return nil;
	auto handle = window->winId();
	if (handle == 0) return nil;
	auto* view = reinterpret_cast<NSView*>(handle); // NOLINT(performance-no-int-to-ptr)
	return view.window;
}

void configurePanelWindow(QWindow* window, bool aboveWindows, bool desktopBackground) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil) {
		static bool warned = false;
		if (!warned) {
			warned = true;
			NSLog(@"[bento] configurePanelWindow: no native NSWindow yet; skipping");
		}
		return;
	}

	// On every Space, and pinned there across Space switches - a layer surface
	// belongs to the output, not to a workspace. ignoresCycle keeps it out of
	// Cmd-` window cycling.
	nsWindow.collectionBehavior = NSWindowCollectionBehaviorCanJoinAllSpaces
	    | NSWindowCollectionBehaviorStationary | NSWindowCollectionBehaviorIgnoresCycle;

	if (desktopBackground) {
		// A shell's wallpaper layer. macOS draws the desktop itself, so this
		// surface has no place: it can only sit over the user's windows and hide
		// them. It cannot be pushed underneath by level either - Qt's cocoa QPA
		// keeps resetting a non-floating window's level back to normal, undoing
		// any below-normal level we set. So make it invisible and click-through
		// instead: the real desktop shows, the shell keeps rendering into it
		// harmlessly, and the chosen wallpaper is put on the OS through
		// Quickshell.Mac.Desktop.
		nsWindow.alphaValue = 0.0;
		nsWindow.ignoresMouseEvents = YES;
		return;
	}

	nsWindow.alphaValue = 1.0;
	nsWindow.ignoresMouseEvents = NO;

	// Above ordinary windows sits at the status-bar level (over normal windows,
	// below the system menu bar and Mission Control) - the closest macOS analogue
	// to WlrLayer.Top. Qt's WindowStaysOnTopHint already lifts it to the floating
	// level; this overrides that with the level the panel actually wants. Below
	// sits just under the normal level.
	nsWindow.level = aboveWindows ? NSStatusWindowLevel : (NSNormalWindowLevel - 1);
}

} // namespace qs::mac
