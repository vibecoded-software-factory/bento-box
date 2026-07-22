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
	// Top/Overlay float above ordinary windows; Background/Bottom do not.
	if (this->mPanel) this->mPanel->setProperty("aboveWindows", layer >= WlrLayer::Top);
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
	if (this->mPanel) this->mPanel->setProperty("focusable", focus != WlrKeyboardFocus::None);
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

} // namespace qs::mac::wayland
