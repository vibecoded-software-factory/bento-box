#include "wayland.hpp"

#include <IOKit/pwr_mgt/IOPMLib.h>
#include <qobject.h>
#include <qvariant.h>

namespace qs::mac::wayland {

WlrLayershell::WlrLayershell(QObject* parent): QObject(parent), mPanel(parent) {}

WlrLayershell* WlrLayershell::qmlAttachedProperties(QObject* object) {
	return new WlrLayershell(object);
}

void WlrLayershell::setLayer(WlrLayer::Enum layer) {
	if (this->mLayer == layer) return;
	this->mLayer = layer;
	if (this->mPanel) {
		// The Background layer is a shell's wallpaper. macOS owns the desktop, so
		// the panel backend suppresses that surface (invisible + click-through)
		// rather than drawing it over the user's windows. Flag it before
		// aboveWindows, whose change reapplies the native config and must see it.
		this->mPanel->setProperty("bentoDesktopBackground", layer == WlrLayer::Background);
		// Top/Overlay float above ordinary windows; Background/Bottom do not.
		this->mPanel->setProperty("aboveWindows", layer >= WlrLayer::Top);
	}
	emit this->layerChanged();
}

void WlrLayershell::setNamespace(const QString& ns) {
	if (this->mNamespace == ns) return;
	this->mNamespace = ns;
	emit this->namespaceChanged();
}

void WlrLayershell::setKeyboardFocus(WlrKeyboardFocus::Enum focus) {
	if (this->mKeyboardFocus == focus) return;
	this->mKeyboardFocus = focus;
	if (this->mPanel) {
		this->mPanel->setProperty("focusable", focus != WlrKeyboardFocus::None);
		// Exclusive is a keyboard GRAB on Wayland - the compositor routes keys
		// to the surface no matter what. macOS routes keys only to the active
		// app's key window, so the panel backend must actively take (and later
		// give back) app focus for these panels. OnDemand panels get focus the
		// macOS-native way: when clicked.
		this->mPanel->setProperty("bentoExclusiveKeyboard", focus == WlrKeyboardFocus::Exclusive);
	}
	emit this->keyboardFocusChanged();
}

// NO equality guard on the exclusion setters: the shim's own initial value (0)
// is not what the panel holds (the panel defaults to ExclusionMode::Auto,
// which RESERVES space computed from anchors+size). A shell writing
// `WlrLayershell.exclusiveZone: 0` to opt out of reservation used to hit the
// guard and never reach the panel - leaving a hidden 480px slideout silently
// reserving its whole width and squeezing the compositor's tiling area. Every
// explicit write must reach the panel, equal-looking or not.
void WlrLayershell::setExclusiveZone(qint32 zone) {
	bool changed = this->mExclusiveZone != zone;
	this->mExclusiveZone = zone;
	if (this->mPanel) this->mPanel->setProperty("exclusiveZone", zone);
	if (changed) emit this->exclusiveZoneChanged();
}

void WlrLayershell::setExclusionMode(int mode) {
	bool changed = this->mExclusionMode != mode;
	this->mExclusionMode = mode;
	if (this->mPanel) this->mPanel->setProperty("exclusionMode", mode);
	if (changed) emit this->exclusionModeChanged();
}

void WlrLayershell::setMargins(Margins margins) {
	if (this->mMargins == margins) return;
	this->mMargins = margins;
	if (this->mPanel) this->mPanel->setProperty("margins", QVariant::fromValue(margins));
	emit this->marginsChanged();
}

// The macOS idle inhibit: a display-sleep power assertion, held while
// enabled. kIOPMAssertionTypePreventUserIdleDisplaySleep matches the Wayland
// semantic (a visible inhibiting surface keeps the output awake) and shows
// up attributed to this process in `pmset -g assertions`.
void IdleInhibitor::setEnabled(bool enabled) {
	if (this->mEnabled == enabled) return;
	this->mEnabled = enabled;

	if (enabled && this->mAssertion == kIOPMNullAssertionID) {
		IOPMAssertionID assertion = kIOPMNullAssertionID;
		if (IOPMAssertionCreateWithName(
		        kIOPMAssertionTypePreventUserIdleDisplaySleep,
		        kIOPMAssertionLevelOn,
		        CFSTR("Shell idle inhibit"),
		        &assertion
		    )
		    == kIOReturnSuccess)
		{
			this->mAssertion = assertion;
		}
	} else if (!enabled && this->mAssertion != kIOPMNullAssertionID) {
		IOPMAssertionRelease(this->mAssertion);
		this->mAssertion = kIOPMNullAssertionID;
	}

	emit this->enabledChanged();
}

IdleInhibitor::~IdleInhibitor() {
	// An inhibitor must never outlive its owner - a destroyed toggle that
	// left the display insomniac would be undebuggable from the outside.
	if (this->mAssertion != kIOPMNullAssertionID) {
		IOPMAssertionRelease(this->mAssertion);
	}
}

} // namespace qs::mac::wayland
