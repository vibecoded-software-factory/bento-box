#include "wayland.hpp"

#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <IOKit/pwr_mgt/IOPMLib.h>
#include <qobject.h>
#include <qquickwindow.h>
#include <qregion.h>
#include <qvariant.h>
#include <qwindow.h>

#include "../../window/windowinterface.hpp"
#include "../bridge.hpp"

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

// Wayland's ext-idle-notify-v1 has the compositor fire a notification once no
// input has arrived for `timeout`, and a "resumed" event on the next input.
// macOS has no such push API, so the monitor samples the system-wide idle
// clock (CGEventSourceSecondsSinceLastEventType, the same value `ioreg
// HIDIdleTime` and `pmset` read) once a second and crosses the boundary
// itself. One second is well under any real DMS timeout (min lock/sleep
// timers are tens of seconds) and is what the desktop-idle daemons on macOS
// poll at.
IdleMonitor::IdleMonitor(QObject* parent): QObject(parent) {
	this->mPollTimer.setInterval(1000);
	QObject::connect(&this->mPollTimer, &QTimer::timeout, this, &IdleMonitor::poll);
	this->rearm();
}

void IdleMonitor::rearm() {
	bool active = this->mEnabled && this->mTimeout > 0;
	if (active) {
		if (!this->mPollTimer.isActive()) this->mPollTimer.start();
		// Sample once promptly so a monitor armed on an already-idle session
		// reports without waiting a full interval - but via the event loop,
		// not synchronously: rearm() runs from QML property setters during
		// component construction, before onIsIdleChanged is connected, so a
		// synchronous flip here would be emitted into the void and the state
		// would then look unchanged to every later poll.
		QTimer::singleShot(0, this, &IdleMonitor::poll);
	} else {
		this->mPollTimer.stop();
		// Inert monitor is never idle: upstream destroys the notification
		// when disabled, and IdleService gates its handlers on enabled but
		// still expects isIdle to fall back to false.
		if (this->mIsIdle) {
			this->mIsIdle = false;
			emit this->isIdleChanged();
		}
	}
}

bool IdleMonitor::inhibited() {
	// PreventUserIdleDisplaySleep / NoDisplaySleep are exactly the assertions
	// our IdleInhibitor (and `caffeinate -d`, media playback, etc.) raise.
	// While one is held the display would never idle-sleep, so a Wayland
	// idle-notify honoring inhibitors must not fire either.
	CFDictionaryRef assertions = nullptr;
	if (IOPMCopyAssertionsStatus(&assertions) != kIOReturnSuccess || assertions == nullptr) {
		return false;
	}

	auto held = [&](CFStringRef type) {
		auto* value = static_cast<CFNumberRef>(CFDictionaryGetValue(assertions, type));
		int count = 0;
		if (value != nullptr) CFNumberGetValue(value, kCFNumberIntType, &count);
		return count > 0;
	};

	bool result =
	    held(kIOPMAssertionTypePreventUserIdleDisplaySleep) || held(kIOPMAssertionTypeNoDisplaySleep);
	CFRelease(assertions);
	return result;
}

void IdleMonitor::poll() {
	if (!this->mEnabled || this->mTimeout <= 0) return;

	if (this->mRespectInhibitors && IdleMonitor::inhibited()) {
		// Treated as continuous activity: an inhibited session resumes.
		if (this->mIsIdle) {
			this->mIsIdle = false;
			emit this->isIdleChanged();
		}
		return;
	}

	double idleSeconds = CGEventSourceSecondsSinceLastEventType(
	    kCGEventSourceStateCombinedSessionState,
	    kCGAnyInputEventType
	);

	bool nowIdle = idleSeconds >= this->mTimeout;
	if (nowIdle != this->mIsIdle) {
		this->mIsIdle = nowIdle;
		emit this->isIdleChanged();
	}
}

BackgroundEffect* BackgroundEffect::qmlAttachedProperties(QObject* object) {
	// Upstream's resolution, unchanged (wayland/background_effect/qml.cpp:26):
	// a shell attaches to either the proxy window or the interface in front of
	// it, and both have to reach the same backing window.
	auto* proxyWindow = qobject_cast<ProxyWindowBase*>(object);

	if (proxyWindow == nullptr) {
		if (auto* iface = qobject_cast<WindowInterface*>(object)) {
			proxyWindow = iface->proxyWindow();
		}
	}

	if (proxyWindow == nullptr) return nullptr;
	return new BackgroundEffect(proxyWindow);
}

BackgroundEffect::BackgroundEffect(ProxyWindowBase* window)
    : QObject(nullptr)
    , proxyWindow(window) {
	QObject::connect(
	    this->proxyWindow,
	    &ProxyWindowBase::windowConnected,
	    this,
	    &BackgroundEffect::onWindowConnected
	);

	QObject::connect(
	    this->proxyWindow,
	    &QObject::destroyed,
	    this,
	    &BackgroundEffect::onProxyWindowDestroyed
	);

	// A shell that attaches after the window is already up gets no
	// windowConnected, so cover that entry too.
	if (this->proxyWindow->backingWindow() != nullptr) this->onWindowConnected();
}

void BackgroundEffect::setBlurRegion(PendingRegion* region) {
	if (region == this->mBlurRegion) return;

	if (this->mBlurRegion != nullptr) {
		QObject::disconnect(this->mBlurRegion, nullptr, this, nullptr);
	}

	this->mBlurRegion = region;

	if (region != nullptr) {
		QObject::connect(region, &QObject::destroyed, this, &BackgroundEffect::onBlurRegionDestroyed);
		QObject::connect(region, &PendingRegion::changed, this, &BackgroundEffect::updateBlurRegion);
	}

	emit this->blurRegionChanged();
	this->updateBlurRegion();
}

void BackgroundEffect::onBlurRegionDestroyed() {
	this->mBlurRegion = nullptr;
	emit this->blurRegionChanged();
	this->updateBlurRegion();
}

void BackgroundEffect::onProxyWindowDestroyed() {
	this->proxyWindow = nullptr;
	this->mBlurRegion = nullptr;
}

void BackgroundEffect::onWindowConnected() {
	auto* window = this->proxyWindow->backingWindow();
	if (window == nullptr) return;

	// A hidden surface blurs nothing, and the native view only exists once the
	// window has a handle - so both edges have to re-run this. UniqueConnection
	// because a window can be reconnected across a reload.
	QObject::connect(
	    window,
	    &QWindow::visibleChanged,
	    this,
	    &BackgroundEffect::updateBlurRegion,
	    Qt::UniqueConnection
	);

	QObject::connect(
	    this->proxyWindow,
	    &ProxyWindowBase::polished,
	    this,
	    &BackgroundEffect::updateBlurRegion,
	    Qt::UniqueConnection
	);

	this->updateBlurRegion();
}

void BackgroundEffect::updateBlurRegion() {
	if (this->proxyWindow == nullptr) return;
	auto* window = this->proxyWindow->backingWindow();
	if (window == nullptr) return;

	// A null region is the shell asking for the blur to go away, and so is an
	// invisible window - the native side treats both as "remove it and give the
	// window its opacity back", so neither needs a separate path here.
	auto active = this->mBlurRegion != nullptr && window->isVisible();
	auto region = active ? this->mBlurRegion->build() : QRegion();

	qs::mac::applyBackgroundBlur(window, region, active);
}

} // namespace qs::mac::wayland
