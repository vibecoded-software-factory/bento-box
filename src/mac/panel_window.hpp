#pragma once

#include <qnamespace.h>
#include <qobject.h>
#include <qpointer.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qrect.h>
#include <qscreen.h>
#include <qstring.h>
#include <qtclasshelpermacros.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../core/doc.hpp"
#include "../core/util.hpp"
#include "../window/panelinterface.hpp"
#include "../window/proxywindow.hpp"

namespace qs::mac {

// The macOS PanelWindow backend. Mirrors the X11 XPanelWindow: a
// ProxyWindowBase that pins an ordinary QQuickWindow to a screen edge
// according to anchors + margins, and reconfigures the native NSWindow (level,
// all-Spaces behaviour, non-activating) through the AppKit bridge.
//
// What is NOT here, deliberately: a compositor exclusion zone. wlroots and X11
// reserve space so maximized windows avoid the panel; macOS exposes no public
// API for that (only the system Dock and menu bar reserve space). The
// exclusiveZone / exclusionMode properties exist because the PanelWindow
// interface requires them, but they do not move other windows on macOS. See
// updateExclusion.
class MacPanelWindow: public ProxyWindowBase {
	QSDOC_BASECLASS(PanelWindowInterface);
	Q_OBJECT;
	// clang-format off
	QSDOC_HIDE Q_PROPERTY(Anchors anchors READ anchors WRITE setAnchors NOTIFY anchorsChanged);
	QSDOC_HIDE Q_PROPERTY(qint32 exclusiveZone READ exclusiveZone WRITE setExclusiveZone NOTIFY exclusiveZoneChanged);
	QSDOC_HIDE Q_PROPERTY(ExclusionMode::Enum exclusionMode READ exclusionMode WRITE setExclusionMode NOTIFY exclusionModeChanged);
	QSDOC_HIDE Q_PROPERTY(Margins margins READ margins WRITE setMargins NOTIFY marginsChanged);
	QSDOC_HIDE Q_PROPERTY(bool aboveWindows READ aboveWindows WRITE setAboveWindows NOTIFY aboveWindowsChanged);
	QSDOC_HIDE Q_PROPERTY(bool focusable READ focusable WRITE setFocusable NOTIFY focusableChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit MacPanelWindow(QObject* parent = nullptr);
	~MacPanelWindow() override;
	Q_DISABLE_COPY_MOVE(MacPanelWindow);

	void connectWindow() override;
	void trySetWidth(qint32 implicitWidth) override;
	void trySetHeight(qint32 implicitHeight) override;
	void setScreen(QuickshellScreenInfo* screen) override;

	[[nodiscard]] bool aboveWindows() const { return this->bAboveWindows; }
	void setAboveWindows(bool aboveWindows) { this->bAboveWindows = aboveWindows; }

	[[nodiscard]] Anchors anchors() const { return this->bAnchors; }
	void setAnchors(Anchors anchors) { this->bAnchors = anchors; }

	[[nodiscard]] qint32 exclusiveZone() const { return this->bExclusiveZone; }
	void setExclusiveZone(qint32 exclusiveZone) {
		Qt::beginPropertyUpdateGroup();
		this->bExclusiveZone = exclusiveZone;
		this->bExclusionMode = ExclusionMode::Normal;
		Qt::endPropertyUpdateGroup();
	}

	[[nodiscard]] ExclusionMode::Enum exclusionMode() const { return this->bExclusionMode; }
	void setExclusionMode(ExclusionMode::Enum exclusionMode) { this->bExclusionMode = exclusionMode; }

	[[nodiscard]] Margins margins() const { return this->bMargins; }
	void setMargins(Margins margins) { this->bMargins = margins; }

	[[nodiscard]] bool focusable() const { return this->bFocusable; }
	void setFocusable(bool focusable) { this->bFocusable = focusable; }

signals:
	QSDOC_HIDE void anchorsChanged();
	QSDOC_HIDE void exclusiveZoneChanged();
	QSDOC_HIDE void exclusionModeChanged();
	QSDOC_HIDE void marginsChanged();
	QSDOC_HIDE void aboveWindowsChanged();
	QSDOC_HIDE void focusableChanged();

private slots:
	void updateDimensionsSlot() { this->updateDimensions(); }

private:
	void updateScreen();
	void updateDimensions();
	void updateAboveWindows();
	void updateFocusable();
	void applyNativeConfig();
	void updateReservation();

	QPointer<QScreen> mTrackedScreen = nullptr;
	// The frame updateDimensions last computed from anchors + margins - the
	// panel's true target, independent of any window-server clamp applied to
	// the native frame while the window was still at the normal level.
	QRect mIntendedGeometry;
	// Stable per-panel id for the compositor reservation, so this panel sets
	// and clears its own strut. Assigned once in the constructor.
	QString mReservationId;
	// Bounded self-heal for a reservation that could not be delivered (the
	// compositor busy at startup): re-sent on a short delay, up to this many
	// times, then given up as "no compositor". Reset to zero on a clean send.
	static constexpr int kMaxReservationRetries = 10;
	int mReservationRetries = 0;
	// Periodically re-asserts an active reservation, so a compositor that
	// restarted (and lost its in-memory struts) picks it back up within a few
	// seconds instead of leaving the panel overlapping the windows until it is
	// itself restarted. Created lazily in connectWindow.
	QTimer* mReservationHeartbeat = nullptr;

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MacPanelWindow, bool, bAboveWindows, true, &MacPanelWindow::aboveWindowsChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, bool, bFocusable, &MacPanelWindow::focusableChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, Anchors, bAnchors, &MacPanelWindow::anchorsChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, Margins, bMargins, &MacPanelWindow::marginsChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, qint32, bExclusiveZone, &MacPanelWindow::exclusiveZoneChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MacPanelWindow, ExclusionMode::Enum, bExclusionMode, ExclusionMode::Auto, &MacPanelWindow::exclusionModeChanged);

	// Computed, exactly as the X11/wlroots backends compute their exclusive
	// zone: Ignore -> 0, Normal -> the set value, Auto -> the panel's own
	// extent on its single anchored edge plus that edge's margins. The edge is
	// the one edge left free on an axis by the anchors.
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, qint32, bcExclusiveZone);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, Qt::Edge, bcExclusionEdge);

	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bAboveWindows, updateAboveWindows, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bAnchors, updateDimensionsSlot, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bMargins, updateDimensionsSlot, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bFocusable, updateFocusable, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bcExclusiveZone, updateReservation, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bcExclusionEdge, updateReservation, onValueChanged);
	// clang-format on
};

class MacPanelInterface: public PanelWindowInterface {
	Q_OBJECT;

public:
	explicit MacPanelInterface(QObject* parent = nullptr);

	void onReload(QObject* oldInstance) override;

	[[nodiscard]] ProxyWindowBase* proxyWindow() const override;

	// NOLINTBEGIN
	[[nodiscard]] Anchors anchors() const override;
	void setAnchors(Anchors anchors) override;

	[[nodiscard]] Margins margins() const override;
	void setMargins(Margins margins) override;

	[[nodiscard]] qint32 exclusiveZone() const override;
	void setExclusiveZone(qint32 exclusiveZone) override;

	[[nodiscard]] ExclusionMode::Enum exclusionMode() const override;
	void setExclusionMode(ExclusionMode::Enum exclusionMode) override;

	[[nodiscard]] bool aboveWindows() const override;
	void setAboveWindows(bool aboveWindows) override;

	[[nodiscard]] bool focusable() const override;
	void setFocusable(bool focusable) override;
	// NOLINTEND

private:
	MacPanelWindow* panel;
};

} // namespace qs::mac
