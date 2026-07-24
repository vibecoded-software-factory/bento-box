#include "link.hpp"

namespace qs::mac::pipewire {

QString PwLinkState::toString(PwLinkState::Enum value) {
	// pipewire's pw_link_state_as_string, string for string
	// (src/pipewire/introspect.c) - upstream delegates to it directly.
	switch (value) {
	case Error: return "error";
	case Unlinked: return "unlinked";
	case Init: return "init";
	case Negotiating: return "negotiating";
	case Allocating: return "allocating";
	case Paused: return "paused";
	case Active: return "active";
	default: return "invalid-state";
	}
}

void PwNodeLinkTracker::setNode(PwNode* node) {
	if (node == this->mNode) return;
	this->mNode = node;
	emit this->nodeChanged();
}

QQmlListProperty<PwLinkGroup> PwNodeLinkTracker::linkGroups() {
	return QQmlListProperty<PwLinkGroup>(this, &this->mEmpty);
}

} // namespace qs::mac::pipewire
