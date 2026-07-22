#include "screencopy.hpp"

#import <CoreGraphics/CoreGraphics.h>
#import <ScreenCaptureKit/ScreenCaptureKit.h>

#include <QtQuick/qquickwindow.h>
#include <QtQuick/qsgsimpletexturenode.h>
#include <qimage.h>
#include <qloggingcategory.h>
#include <qmetaobject.h>
#include <qobject.h>

#include "../nigiri/window.hpp"
#include "toplevel.hpp"

namespace {
Q_LOGGING_CATEGORY(logScreencopy, "quickshell.mac.screencopy");

// Resolve the CGWindowID for a compositor window (pid + title). The
// compositor's IPC has no notion of CGWindowIDs, but the window server can be
// asked for the on-screen windows of a pid; the title disambiguates multiple
// windows of one app, falling back to the pid's frontmost.
CGWindowID windowIdFor(pid_t pid, const QString& title) {
	auto* list = (__bridge_transfer NSArray*) CGWindowListCopyWindowInfo(
	    kCGWindowListOptionOnScreenOnly | kCGWindowListExcludeDesktopElements, kCGNullWindowID
	);
	CGWindowID fallback = kCGNullWindowID;
	for (NSDictionary* entry in list) {
		if ([entry[(id) kCGWindowOwnerPID] intValue] != pid) continue;
		if ([entry[(id) kCGWindowLayer] intValue] != 0) continue;
		auto windowId = (CGWindowID) [entry[(id) kCGWindowNumber] unsignedIntValue];
		if (fallback == kCGNullWindowID) fallback = windowId;
		NSString* name = entry[(id) kCGWindowName];
		if (name != nil && QString::fromNSString(name) == title) return windowId;
	}
	return fallback;
}

// One async ScreenCaptureKit screenshot of a CGWindowID, delivered as a
// QImage on the main thread. Fails soft (empty image) when the window is
// gone or Screen Recording permission is missing.
void captureWindow(CGWindowID windowId, std::function<void(QImage)> deliver) {
	[SCShareableContent getShareableContentExcludingDesktopWindows:YES
	                                           onScreenWindowsOnly:YES
	                                             completionHandler:^(
	                                                 SCShareableContent* content, NSError* error
	                                             ) {
		if (error != nil || content == nil) {
			qCWarning(logScreencopy)
			    << "shareable content unavailable (Screen Recording permission?):"
			    << QString::fromNSString(error.localizedDescription);
			dispatch_async(dispatch_get_main_queue(), ^{ deliver(QImage()); });
			return;
		}
		SCWindow* target = nil;
		for (SCWindow* window in content.windows) {
			if (window.windowID == windowId) {
				target = window;
				break;
			}
		}
		if (target == nil) {
			dispatch_async(dispatch_get_main_queue(), ^{ deliver(QImage()); });
			return;
		}
		auto* filter = [[SCContentFilter alloc] initWithDesktopIndependentWindow:target];
		auto* config = [[SCStreamConfiguration alloc] init];
		config.width = (size_t) (target.frame.size.width * filter.pointPixelScale);
		config.height = (size_t) (target.frame.size.height * filter.pointPixelScale);
		config.showsCursor = NO;
		[SCScreenshotManager captureImageWithFilter:filter
		                              configuration:config
		                          completionHandler:^(CGImageRef image, NSError* captureError) {
			if (captureError != nil || image == nil) {
				dispatch_async(dispatch_get_main_queue(), ^{ deliver(QImage()); });
				return;
			}
			// Copy into a QImage while the CGImage is alive.
			auto width = CGImageGetWidth(image);
			auto height = CGImageGetHeight(image);
			QImage frame((int) width, (int) height, QImage::Format_ARGB32_Premultiplied);
			frame.fill(Qt::transparent);
			CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
			CGContextRef ctx = CGBitmapContextCreate(
			    frame.bits(), width, height, 8, frame.bytesPerLine(), colorSpace,
			    kCGImageAlphaPremultipliedFirst | kCGBitmapByteOrder32Host
			);
			CGColorSpaceRelease(colorSpace);
			if (ctx != nullptr) {
				CGContextDrawImage(ctx, CGRectMake(0, 0, width, height), image);
				CGContextRelease(ctx);
			}
			dispatch_async(dispatch_get_main_queue(), ^{ deliver(frame); });
		}];
	}];
}

} // namespace

namespace qs::mac::wayland {

ScreencopyView::ScreencopyView(QQuickItem* parent): QQuickItem(parent) {
	this->setFlag(QQuickItem::ItemHasContents);
	// Live refresh cadence: thumbnails, not video - 500ms keeps a dozen
	// overview tiles cheap while still reading as "live".
	this->mRefresh.setInterval(500);
	QObject::connect(&this->mRefresh, &QTimer::timeout, this, &ScreencopyView::captureFrame);
}

void ScreencopyView::setCaptureSource(QObject* source) {
	if (this->mCaptureSource == source) return;
	this->mCaptureSource = source;
	this->mGeneration++;
	emit this->captureSourceChanged();
	this->captureFrame();
}

void ScreencopyView::setPaintCursor(bool value) {
	if (this->mPaintCursor == value) return;
	this->mPaintCursor = value;
	emit this->paintCursorChanged();
}

void ScreencopyView::setLive(bool live) {
	if (this->mLive == live) return;
	this->mLive = live;
	if (live) this->mRefresh.start();
	else this->mRefresh.stop();
	emit this->liveChanged();
	if (live) this->captureFrame();
}

void ScreencopyView::captureFrame() { this->requestCapture(); }

void ScreencopyView::requestCapture() {
	auto* toplevel = qobject_cast<Toplevel*>(this->mCaptureSource.data());
	if (toplevel == nullptr) return;
	auto* backing = toplevel->backingWindow();
	if (backing == nullptr) return;

	auto pid = (pid_t) backing->bindablePid().value();
	auto title = backing->bindableTitle().value();
	auto windowId = windowIdFor(pid, title);
	if (windowId == kCGNullWindowID) return;

	auto generation = this->mGeneration;
	QPointer<ScreencopyView> self(this);
	captureWindow(windowId, [self, generation](const QImage& frame) {
		if (self.isNull() || self->mGeneration != generation) return;
		self->onFrame(frame);
	});
}

void ScreencopyView::onFrame(const QImage& frame) {
	if (frame.isNull()) return;
	bool hadContent = this->hasContent();
	bool sizeChanged = frame.size() != this->mFrame.size();
	this->mFrame = frame;
	this->mFrameDirty = true;
	if (!hadContent) emit this->hasContentChanged();
	if (sizeChanged) emit this->sourceSizeChanged();
	this->update();
}

QSGNode* ScreencopyView::updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* /*data*/) {
	auto* node = static_cast<QSGSimpleTextureNode*>(oldNode);

	if (this->mFrame.isNull()) {
		delete node;
		return nullptr;
	}

	if (node == nullptr) {
		node = new QSGSimpleTextureNode();
		node->setOwnsTexture(true);
		this->mFrameDirty = true;
	}

	if (this->mFrameDirty && this->window() != nullptr) {
		node->setTexture(this->window()->createTextureFromImage(this->mFrame));
		this->mFrameDirty = false;
	}

	node->setRect(this->boundingRect());
	return node;
}

} // namespace qs::mac::wayland
