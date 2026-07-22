#include "wayland.hpp"

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

void WlrLayershell::setExclusiveZone(qint32 zone) {
	if (this->mExclusiveZone == zone) return;
	this->mExclusiveZone = zone;
	if (this->mPanel) this->mPanel->setProperty("exclusiveZone", zone);
	emit this->exclusiveZoneChanged();
}

void WlrLayershell::setExclusionMode(int mode) {
	if (this->mExclusionMode == mode) return;
	this->mExclusionMode = mode;
	if (this->mPanel) this->mPanel->setProperty("exclusionMode", mode);
	emit this->exclusionModeChanged();
}

void WlrLayershell::setMargins(Margins margins) {
	if (this->mMargins == margins) return;
	this->mMargins = margins;
	if (this->mPanel) this->mPanel->setProperty("margins", QVariant::fromValue(margins));
	emit this->marginsChanged();
}

} // namespace qs::mac::wayland
