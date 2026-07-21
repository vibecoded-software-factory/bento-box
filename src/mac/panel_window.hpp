#pragma once

#include <qobject.h>
#include <qpointer.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qscreen.h>
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

	QPointer<QScreen> mTrackedScreen = nullptr;

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MacPanelWindow, bool, bAboveWindows, true, &MacPanelWindow::aboveWindowsChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, bool, bFocusable, &MacPanelWindow::focusableChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, Anchors, bAnchors, &MacPanelWindow::anchorsChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, Margins, bMargins, &MacPanelWindow::marginsChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MacPanelWindow, qint32, bExclusiveZone, &MacPanelWindow::exclusiveZoneChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MacPanelWindow, ExclusionMode::Enum, bExclusionMode, ExclusionMode::Auto, &MacPanelWindow::exclusionModeChanged);

	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bAboveWindows, updateAboveWindows, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bAnchors, updateDimensionsSlot, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bMargins, updateDimensionsSlot, onValueChanged);
	QS_BINDING_SUBSCRIBE_METHOD(MacPanelWindow, bFocusable, updateFocusable, onValueChanged);
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
