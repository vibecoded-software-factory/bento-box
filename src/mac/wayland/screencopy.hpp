#pragma once

#include <QtQuick/qquickitem.h>
#include <qimage.h>
#include <qobject.h>
#include <qpointer.h>
#include <qqmlintegration.h>
#include <qsize.h>
#include <qtimer.h>
#include <qtmetamacros.h>

namespace qs::mac::wayland {

///! A view of a captured window.
/// Displays a live-ish view of another application's window.
/// On macOS the pixels come from ScreenCaptureKit, which requires the
/// **Screen Recording** permission - without it the view stays empty.
///
/// Mirrors the Wayland ScreencopyView interface: set @@captureSource to a
/// @@Toplevel; @@live re-captures on an interval, otherwise call
/// @@captureFrame() for one-shots.
class ScreencopyView: public QQuickItem {
	Q_OBJECT;
	// clang-format off
	/// The object to capture. A @@Toplevel (other sources are not yet
	/// supported on macOS and render nothing).
	Q_PROPERTY(QObject* captureSource READ captureSource WRITE setCaptureSource NOTIFY captureSourceChanged);
	/// If the mouse cursor should be painted. Accepted for compatibility.
	Q_PROPERTY(bool paintCursor READ paintCursor WRITE setPaintCursor NOTIFY paintCursorChanged);
	/// If true, the capture refreshes on an interval; otherwise a single
	/// frame is grabbed per source change / captureFrame() call.
	Q_PROPERTY(bool live READ live WRITE setLive NOTIFY liveChanged);
	/// If the view has a frame to display.
	Q_PROPERTY(bool hasContent READ hasContent NOTIFY hasContentChanged);
	/// Size of the source image.
	Q_PROPERTY(QSize sourceSize READ sourceSize NOTIFY sourceSizeChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit ScreencopyView(QQuickItem* parent = nullptr);

	/// Capture a single frame.
	Q_INVOKABLE void captureFrame();

	[[nodiscard]] QObject* captureSource() const { return this->mCaptureSource; }
	void setCaptureSource(QObject* source);
	[[nodiscard]] bool paintCursor() const { return this->mPaintCursor; }
	void setPaintCursor(bool value);
	[[nodiscard]] bool live() const { return this->mLive; }
	void setLive(bool live);
	[[nodiscard]] bool hasContent() const { return !this->mFrame.isNull(); }
	[[nodiscard]] QSize sourceSize() const { return this->mFrame.size(); }

signals:
	void captureSourceChanged();
	void paintCursorChanged();
	void liveChanged();
	void hasContentChanged();
	void sourceSizeChanged();

protected:
	QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData* data) override;

private:
	// Kick an async ScreenCaptureKit capture for the current source; the
	// completion lands back on the main thread via onFrame.
	void requestCapture();
	void onFrame(const QImage& frame);

	QPointer<QObject> mCaptureSource;
	bool mPaintCursor = false;
	bool mLive = false;
	QImage mFrame;
	bool mFrameDirty = false;
	QTimer mRefresh;
	// Guards stale async completions: bumped on every source change so a
	// late frame from the previous window is dropped.
	int mGeneration = 0;
};

} // namespace qs::mac::wayland
