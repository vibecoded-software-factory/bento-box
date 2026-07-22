#include "bridge.hpp"

#import <AppKit/AppKit.h>
#import <objc/runtime.h>
#include <qwindow.h>

namespace qs::mac {

namespace {

// While true, our swizzled -[NSApplication isActive] reports the app as active.
// Set only for the duration of a QNSView hover callback (see below). Main-thread
// only, so a plain global is safe.
BOOL gBentoForceActive = NO; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

// Let a shell's bar show hover while it is NOT the frontmost app.
//
// Qt already tracks with NSTrackingActiveAlways, but every QNSView mouse handler
// (mouseMovedImpl:/mouseEnteredImpl:/mouseExitedImpl:) opens with
// `if (!NSApp.active) return;` and deliberately drops the callback while the app
// is inactive - which a shell always is. In Wayland a layer surface gets the
// pointer regardless of focus; to match that we wrap those three handlers so
// NSApp.active reads true for their duration only, letting the event through
// without otherwise pretending the shell is frontmost.
//
// Swizzled once (the QNSView class is shared by every panel). If Qt renames the
// private impl selectors in a future version, the missing-method guard makes
// this a silent no-op rather than a crash.
void bentoInstallInactiveHoverWorkaround(NSView* view) {
	static dispatch_once_t once;
	dispatch_once(&once, ^{
		Method isActive = class_getInstanceMethod([NSApplication class], @selector(isActive));
		if (isActive != nullptr) {
			IMP original = method_getImplementation(isActive);
			IMP replacement = imp_implementationWithBlock(^BOOL(id self) {
				if (gBentoForceActive) return YES;
				return ((BOOL (*)(id, SEL)) original)(self, @selector(isActive));
			});
			method_setImplementation(isActive, replacement);
		}

		Class cls = [view class];
		for (NSString* name in @[ @"mouseMovedImpl:", @"mouseEnteredImpl:", @"mouseExitedImpl:" ]) {
			SEL sel = NSSelectorFromString(name);
			Method m = class_getInstanceMethod(cls, sel);
			if (m == nullptr) continue;
			IMP original = method_getImplementation(m);
			IMP replacement = imp_implementationWithBlock(^(id self, NSEvent* event) {
				BOOL previous = gBentoForceActive;
				gBentoForceActive = YES;
				((void (*)(id, SEL, NSEvent*)) original)(self, sel, event);
				gBentoForceActive = previous;
			});
			method_setImplementation(m, replacement);
		}
	});
}

} // namespace

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
	                            | NSWindowCollectionBehaviorStationary
	                            | NSWindowCollectionBehaviorIgnoresCycle;

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
	nsWindow.acceptsMouseMovedEvents = YES;

	// Hover without activation: Qt drops mouse callbacks while the shell is not
	// the frontmost app (see the workaround's comment). A bar is a layer
	// surface and must receive the pointer regardless.
	if (NSView* view = nsWindow.contentView) {
		bentoInstallInactiveHoverWorkaround(view);
	}

	// Above ordinary windows sits at the status-bar level (over normal windows,
	// below the system menu bar and Mission Control) - the closest macOS analogue
	// to WlrLayer.Top. Qt's WindowStaysOnTopHint already lifts it to the floating
	// level; this overrides that with the level the panel actually wants. Below
	// sits just under the normal level.
	nsWindow.level = aboveWindows ? NSStatusWindowLevel : (NSNormalWindowLevel - 1);
}

} // namespace qs::mac
