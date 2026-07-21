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

void configurePanelWindow(QWindow* window, bool aboveWindows) {
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

	// Above ordinary windows sits at the status-bar level (over normal windows,
	// below the system menu bar and Mission Control) - the closest macOS analogue
	// to WlrLayer.Top. Below sits under everything, for background layers.
	// Qt's WindowStaysOnTopHint already lifts it to the floating level; this
	// overrides that with the level the panel actually wants.
	nsWindow.level = aboveWindows ? NSStatusWindowLevel : kCGDesktopWindowLevel;
}

} // namespace qs::mac
