#include "bridge.hpp"

#import <AppKit/AppKit.h>
#import <QuartzCore/QuartzCore.h>
#import <objc/runtime.h>
#include <qhash.h>
#include <qregion.h>
#include <qwindow.h>

namespace qs::mac {

namespace {

// Defined with the input-mask state further down; declared here so
// configurePanelWindow can consult it without reordering the file.
bool windowHasInputMask(NSWindow* window);

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

void configurePanelWindow(
    QWindow* window,
    bool aboveWindows,
    bool desktopBackground,
    bool overlay
) {
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
	// Cmd-` window cycling. An Overlay layer additionally joins fullscreen
	// Spaces (FullScreenAuxiliary) - upstream's "usually renders over
	// fullscreen windows" - while Top deliberately does not, matching
	// upstream's "below fullscreen windows" for the Top layer.
	NSWindowCollectionBehavior behavior = NSWindowCollectionBehaviorCanJoinAllSpaces
	                                    | NSWindowCollectionBehaviorStationary
	                                    | NSWindowCollectionBehaviorIgnoresCycle;
	if (overlay) behavior |= NSWindowCollectionBehaviorFullScreenAuxiliary;
	nsWindow.collectionBehavior = behavior;

	// No system drop shadow. macOS derives a window's shadow from the alpha
	// mask of its surface, and on a borderless transparent window it keeps the
	// shape captured at the FIRST paint - -[NSWindow invalidateShadow] has not
	// reliably rebuilt it since 10.12 (rdar://27121204). A panel whose QML
	// draws a rounded rectangle inside a square surface therefore wears the
	// SQUARE shadow for the rest of its life: a dark band with 90-degree outer
	// corners hugging the rounded body, which is what every popout, dash and
	// modal here was framed with.
	//
	// Nothing is lost by dropping it. A wlr-layer-shell surface has no
	// compositor-drawn shadow either, so upstream never had one, and the shell
	// draws its own in QML (DankCommon's elevation shader) with the correct
	// rounded geometry.
	//
	// Removing this one makes the shell's OWN elevation shadow visible for the
	// first time - it was always drawn, just dominated. That second shadow is
	// NOT a bug and must not be "fixed" here: it follows the rounded corners
	// and is a user setting (m3ElevationEnabled and friends). The cheap way to
	// tell them apart when a report comes in: profile the pixels across the
	// panel boundary. The window shadow leaves a band DARKER THAN BOTH the
	// backdrop and the panel's fill; the elevation shadow only ever falls off
	// monotonically between them. See port-docs/MACOS-SHADOWS-AND-ELEVATION.md.
	nsWindow.hasShadow = NO;

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
	// Only force the window interactive when no input mask governs it - a
	// reconfig (level change, visibility flip) must never clobber the
	// mask-driven ignoresMouseEvents the pointer tracking just computed.
	if (!windowHasInputMask(nsWindow)) {
		nsWindow.ignoresMouseEvents = NO;
	}
	nsWindow.acceptsMouseMovedEvents = YES;

	// Hover without activation: Qt drops mouse callbacks while the shell is not
	// the frontmost app (see the workaround's comment). A bar is a layer
	// surface and must receive the pointer regardless.
	if (NSView* view = nsWindow.contentView) {
		bentoInstallInactiveHoverWorkaround(view);
	}

	// The WlrLayer ladder, in NSWindow levels: Overlay sits at the pop-up-menu
	// level (above the status level, still below the screen saver) and joins
	// fullscreen Spaces - upstream's over-fullscreen semantics. Top sits at
	// the status-bar level (over normal windows, below the system menu bar and
	// Mission Control) - upstream's below-fullscreen Top. Qt's
	// WindowStaysOnTopHint already lifts the window to the floating level;
	// this overrides it with the level the panel actually wants. Below sits
	// just under the normal level.
	nsWindow.level = overlay      ? NSPopUpMenuWindowLevel
	               : aboveWindows ? NSStatusWindowLevel
	                              : (NSNormalWindowLevel - 1);
}

namespace {
// The app that was frontmost before an exclusive-keyboard panel took focus,
// and which panel took it. Main-thread only. Stored as a pid, not as the
// NSRunningApplication: this file compiles without ARC, so keeping the
// autoreleased object would leave a dangling pointer once the pool drains -
// the next grab/yield then messages freed memory and the process dies
// (doesNotRecognizeSelector abort, or a Code Signature Invalid kill when the
// stale isa leads execution into an unmapped page). A pid is weak by value:
// if the app quit meanwhile, the lookup below just returns nil.
pid_t gPreviousAppPid = -1;     // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
void* gKeyboardOwner = nullptr; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
} // namespace

void takeKeyboardForPanel(QWindow* window, void* owner) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil) return;

	// Only remember the previous app when the shell is NOT already active -
	// two exclusive panels in a row must not overwrite the real restore target
	// with the shell itself.
	if (!NSApp.active) {
		NSRunningApplication* frontmost = NSWorkspace.sharedWorkspace.frontmostApplication;
		if (frontmost != nil
		    && frontmost.processIdentifier != NSProcessInfo.processInfo.processIdentifier)
		{
			gPreviousAppPid = frontmost.processIdentifier;
		}
	}
	gKeyboardOwner = owner;

	NSLog(@"[bento] keyboard grab: taking app focus (previous pid=%d)", gPreviousAppPid);
	[NSApp activateIgnoringOtherApps:YES];
	[nsWindow makeKeyAndOrderFront:nil];
}

void yieldKeyboardFromPanel(void* owner) {
	if (gKeyboardOwner != owner) return;
	gKeyboardOwner = nullptr;

	pid_t previousPid = gPreviousAppPid;
	gPreviousAppPid = -1;
	NSRunningApplication* previous =
	    previousPid > 0 ? [NSRunningApplication runningApplicationWithProcessIdentifier:previousPid]
	                    : nil;
	NSLog(@"[bento] keyboard grab: yielding app focus (restore=%@)", previous.localizedName);
	if (previous != nil && !previous.terminated) {
		[previous activateWithOptions:0];
	}
}

namespace {

// Input-region emulation state: per-NSWindow mask (window-local, top-left
// coords) and the app-wide pointer monitors that keep ignoresMouseEvents in
// step with the cursor. Main-thread only. configurePanelWindow consults this
// table so a reconfig never clobbers a mask-driven ignoresMouseEvents.
QHash<NSWindow*, QRegion>& inputMasks() {
	static QHash<NSWindow*, QRegion> masks;
	return masks;
}
id gLocalMoveMonitor = nil;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
id gGlobalMoveMonitor = nil; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

bool windowHasInputMask(NSWindow* window) { return inputMasks().contains(window); }

// The cursor moved (anywhere): each masked window ignores mouse events
// exactly while the cursor is OUTSIDE its mask, so by the time a click
// arrives the window server already routes it to the right window.
void refreshInputMasksAt(NSPoint screenPoint) {
	for (auto it = inputMasks().constBegin(); it != inputMasks().constEnd(); ++it) {
		NSWindow* nsWindow = it.key();
		NSRect frame = nsWindow.frame;
		auto localX = screenPoint.x - frame.origin.x;
		auto localTopY = NSMaxY(frame) - screenPoint.y;
		bool inside = it.value().contains(QPoint((int) localX, (int) localTopY));
		if (nsWindow.ignoresMouseEvents == inside) {
			nsWindow.ignoresMouseEvents = !inside;
		}
	}
}

void ensurePointerMonitors() {
	if (gLocalMoveMonitor != nil) return;
	NSEventMask mask = NSEventMaskMouseMoved | NSEventMaskLeftMouseDragged;
	gLocalMoveMonitor =
	    [NSEvent addLocalMonitorForEventsMatchingMask:mask
	                                          handler:^NSEvent*(NSEvent* event) {
		                                          refreshInputMasksAt(NSEvent.mouseLocation);
		                                          return event;
	                                          }];
	// The global monitor sees moves delivered to OTHER apps - which is
	// exactly where the cursor lives while a masked window is ignoring
	// events; without it the window could never win events back.
	gGlobalMoveMonitor =
	    [NSEvent addGlobalMonitorForEventsMatchingMask:mask
	                                           handler:^(NSEvent* event) {
		                                           (void) event;
		                                           refreshInputMasksAt(NSEvent.mouseLocation);
	                                           }];
}

} // namespace

void applyInputMask(QWindow* window, const QRegion& region, bool active) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil) return;

	// An EMPTY active mask means "no input at all" - Qt already maps that to
	// WindowTransparentForInput/ignoresMouseEvents; nothing to track.
	if (!active || region.isEmpty()) {
		if (inputMasks().remove(nsWindow) > 0 && active == false) {
			nsWindow.ignoresMouseEvents = NO;
		}
		return;
	}

	inputMasks()[nsWindow] = region;
	ensurePointerMonitors();
	refreshInputMasksAt(NSEvent.mouseLocation);
}

void clearInputMask(QWindow* window) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil) return;
	inputMasks().remove(nsWindow);
}

void assertPanelLevel(QWindow* window, bool aboveWindows, bool overlay) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil) return;
	NSWindowLevel target = overlay      ? NSPopUpMenuWindowLevel
	                     : aboveWindows ? NSStatusWindowLevel
	                                    : (NSNormalWindowLevel - 1);
	if (nsWindow.level != target) nsWindow.level = target;
}

void assertPanelFrame(QWindow* window, const QRect& geometry) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil || geometry.isEmpty()) return;

	// Qt's global coordinate space is the AppKit one flipped around the primary
	// screen's top edge: qtY counts down from the primary screen's top, nsY
	// counts up from its bottom. AppKit gives the primary screen origin (0,0),
	// so the flip is a single subtraction against its frame height.
	NSScreen* primary = NSScreen.screens.firstObject;
	if (primary == nil) return;

	NSRect target = NSMakeRect(
	    geometry.x(),
	    NSMaxY(primary.frame) - geometry.y() - geometry.height(),
	    geometry.width(),
	    geometry.height()
	);

	if (NSEqualRects(nsWindow.frame, target)) return;
	[nsWindow setFrame:target display:YES];
}

namespace {

// The blur view per window, so an update reuses one instead of stacking a new
// NSVisualEffectView under the content on every region change.
QHash<NSWindow*, NSVisualEffectView*>& blurViews() {
	static QHash<NSWindow*, NSVisualEffectView*> views; // NOLINT
	return views;
}

} // namespace

void applyBackgroundBlur(QWindow* window, const QRegion& region, bool active) {
	NSWindow* nsWindow = nsWindowFor(window);
	if (nsWindow == nil) return;
	NSView* content = nsWindow.contentView;
	if (content == nil) return;

	NSVisualEffectView* effect = blurViews().value(nsWindow, nil);

	if (!active || region.isEmpty()) {
		if (effect != nil) {
			[effect removeFromSuperview];
			blurViews().remove(nsWindow);
		}
		return;
	}

	// `behindWindow` blending samples what is BEHIND the window, so the window
	// must stop claiming it is opaque or the window server never composites
	// anything under it to sample.
	nsWindow.opaque = NO;
	nsWindow.backgroundColor = NSColor.clearColor;

	if (effect == nil) {
		effect = [[NSVisualEffectView alloc] initWithFrame:content.bounds];
		effect.blendingMode = NSVisualEffectBlendingModeBehindWindow;
		// HUD rather than a semantic material: the shell picks its own tint in
		// QML (Theme drops the surface alpha when BlurService.enabled), so the
		// effect view is asked for blur and as little colour as possible.
		effect.material = NSVisualEffectMaterialHUDWindow;
		// Active regardless of app focus. A shell surface is almost never in
		// the frontmost app, and the default follows window activation, which
		// would leave the bar un-blurred exactly when it is being looked at.
		effect.state = NSVisualEffectStateActive;
		effect.autoresizingMask = NSViewWidthSizable | NSViewHeightSizable;
		effect.wantsLayer = YES;
		// Below every sibling: Qt's render view has to draw ON TOP of it.
		[content addSubview:effect positioned:NSWindowBelow relativeTo:nil];
		blurViews().insert(nsWindow, effect);
	}

	effect.frame = content.bounds;

	// Qt hands the region in its own top-left-origin space; an unflipped
	// NSView counts from the bottom, so each rect is mirrored about the
	// content height. Using the rects rather than boundingRect is what keeps a
	// rounded Region's corners - QRegion approximates the curve with a stack of
	// spans, and the mask reproduces it.
	CGFloat height = content.bounds.size.height;
	CGMutablePathRef path = CGPathCreateMutable();
	for (const auto& rect: region) {
		CGPathAddRect(
		    path,
		    nullptr,
		    CGRectMake(rect.x(), height - rect.y() - rect.height(), rect.width(), rect.height())
		);
	}
	auto* mask = [CAShapeLayer layer];
	mask.path = path;
	CGPathRelease(path);
	effect.layer.mask = mask;
}

} // namespace qs::mac
