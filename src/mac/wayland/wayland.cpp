#include "wayland.hpp"

#include <IOKit/pwr_mgt/IOPMLib.h>
#include <qobject.h>
#include <qvariant.h>

namespace qs::mac::wayland {

WlrLayershell* WlrLayershell::qmlAttachedProperties(QObject* object) {
	// Upstream: the attached object IS the WlrLayershell window backing the
	// PanelWindow, and null for anything else (wlr_layershell.cpp:163-169).
	if (auto* iface = qobject_cast<qs::mac::MacPanelInterface*>(object)) {
		return qobject_cast<WlrLayershell*>(iface->proxyWindow());
	}
	return nullptr;
}

void WlrLayershell::setLayer(WlrLayer::Enum layer) {
	if (this->mLayer == layer) return;
	this->mLayer = layer;
	// The Background layer is a shell's wallpaper. macOS owns the desktop, so
	// the panel backend suppresses that surface (invisible + click-through)
	// rather than drawing it over the user's windows. Flag it before
	// aboveWindows, whose change reapplies the native config and must see it.
	this->setDesktopBackground(layer == WlrLayer::Background);
	// Overlay renders over fullscreen apps (upstream's Overlay semantics);
	// Top floats above ordinary windows but below fullscreen ones.
	this->setOverlay(layer == WlrLayer::Overlay);
	// Top/Overlay float above ordinary windows; Background/Bottom do not
	// (upstream: aboveWindows() == layer > Bottom, wlr_layershell.cpp:136).
	this->MacPanelWindow::setAboveWindows(layer > WlrLayer::Bottom);
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
	// Exclusive is a keyboard GRAB on Wayland - the compositor routes keys
	// to the surface no matter what. macOS routes keys only to the active
	// app's key window, so the panel backend must actively take (and later
	// give back) app focus for these panels. OnDemand panels get focus the
	// macOS-native way: when clicked.
	this->setExclusiveKeyboard(focus == WlrKeyboardFocus::Exclusive);
	this->MacPanelWindow::setFocusable(focus != WlrKeyboardFocus::None);
	emit this->keyboardFocusChanged();
}

void WlrLayershell::setAboveWindows(bool aboveWindows) {
	// Upstream's conversion, verbatim (wlr_layershell.cpp:138-140).
	this->setLayer(aboveWindows ? WlrLayer::Top : WlrLayer::Bottom);
}

void WlrLayershell::setFocusable(bool focusable) {
	// Upstream's conversion, verbatim (wlr_layershell.cpp:144-146).
	this->setKeyboardFocus(focusable ? WlrKeyboardFocus::OnDemand : WlrKeyboardFocus::None);
}

// The macOS idle inhibit: a display-sleep power assertion, held while
// enabled. kIOPMAssertionTypePreventUserIdleDisplaySleep matches the Wayland
// semantic (a visible inhibiting surface keeps the output awake) and shows
// up attributed to this process in `pmset -g assertions`.
void IdleInhibitor::setEnabled(bool enabled) {
	if (this->mEnabled == enabled) return;
	this->mEnabled = enabled;
	this->updateAssertion();
	emit this->enabledChanged();
}

void IdleInhibitor::setWindow(QObject* window) {
	if (this->mWindow == window) return;
	if (this->mWindow != nullptr) QObject::disconnect(this->mWindow, nullptr, this, nullptr);
	this->mWindow = window;
	if (window != nullptr) {
		// The panel's visibility drives the inhibit like upstream's surface
		// lifetime does; runtime connect so any window interface works.
		QObject::connect(window, SIGNAL(visibleChanged()), this, SLOT(updateAssertion()));
		QObject::connect(window, &QObject::destroyed, this, &IdleInhibitor::updateAssertion);
	}
	this->updateAssertion();
	emit this->windowChanged();
}

bool IdleInhibitor::windowEligible() const {
	// Upstream: "Must be set to a non null value to enable the inhibitor",
	// and the inhibit lives only while the window has a surface - the macOS
	// reading is "set and visible".
	if (this->mWindow == nullptr) return false;
	auto visible = this->mWindow->property("visible");
	return !visible.isValid() || visible.toBool();
}

void IdleInhibitor::updateAssertion() {
	bool shouldHold = this->mEnabled && this->windowEligible();

	if (shouldHold && this->mAssertion == kIOPMNullAssertionID) {
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
	} else if (!shouldHold && this->mAssertion != kIOPMNullAssertionID) {
		IOPMAssertionRelease(this->mAssertion);
		this->mAssertion = kIOPMNullAssertionID;
	}
}

IdleInhibitor::~IdleInhibitor() {
	// An inhibitor must never outlive its owner - a destroyed toggle that
	// left the display insomniac would be undebuggable from the outside.
	if (this->mAssertion != kIOPMNullAssertionID) {
		IOPMAssertionRelease(this->mAssertion);
	}
}

BackgroundEffect* BackgroundEffect::qmlAttachedProperties(QObject* object) {
	// Values are stored so bindings hold; there is no ext-background-effect-v1
	// on macOS to forward them to.
	return new BackgroundEffect(object);
}

void BackgroundEffect::setBlurRegion(PendingRegion* region) {
	if (region == this->mBlurRegion) return;
	this->mBlurRegion = region;
	emit this->blurRegionChanged();
}

} // namespace qs::mac::wayland
