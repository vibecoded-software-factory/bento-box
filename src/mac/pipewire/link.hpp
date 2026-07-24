#pragma once

#include <qlist.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qqmllist.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "node.hpp"

namespace qs::mac::pipewire {

///! The state of a pipewire link.
/// CoreAudio has no link graph, so no link ever exists on macOS - the enum
/// and its values (pipewire's pw_link_state, link.h:44-53) resolve so shell
/// code compiled against upstream's names loads unchanged.
class PwLinkState: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : qint8 {
		Error = -2,
		Unlinked = -1,
		Init = 0,
		Negotiating = 1,
		Allocating = 2,
		Paused = 3,
		Active = 4,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::pipewire::PwLinkState::Enum value);
};

///! A connection between pipewire nodes.
/// Note that there is one link per *channel* of a connection between nodes.
/// You usually want @@PwLinkGroup. Never instantiated on macOS (CoreAudio
/// has no link graph); the type exists for binding compatibility.
class PwLink: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The pipewire object id of the link.
	Q_PROPERTY(quint32 id READ id CONSTANT);
	/// The node that is *receiving* information. (the sink)
	Q_PROPERTY(qs::mac::pipewire::PwNode* target READ target CONSTANT);
	/// The node that is *sending* information. (the source)
	Q_PROPERTY(qs::mac::pipewire::PwNode* source READ source CONSTANT);
	/// The current state of the link.
	Q_PROPERTY(qs::mac::pipewire::PwLinkState::Enum state READ state NOTIFY stateChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("PwLinks cannot be created directly");

public:
	explicit PwLink(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] static quint32 id() { return 0; }
	[[nodiscard]] static PwNode* target() { return nullptr; }
	[[nodiscard]] static PwNode* source() { return nullptr; }
	[[nodiscard]] static PwLinkState::Enum state() { return PwLinkState::Unlinked; }

signals:
	void stateChanged();
};

///! A group of connections between pipewire nodes.
/// A group of connections between pipewire nodes, one per source->target
/// pair. Never instantiated on macOS; see @@PwLink.
class PwLinkGroup: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The node that is *receiving* information. (the sink)
	Q_PROPERTY(qs::mac::pipewire::PwNode* target READ target CONSTANT);
	/// The node that is *sending* information. (the source)
	Q_PROPERTY(qs::mac::pipewire::PwNode* source READ source CONSTANT);
	/// The current state of the link group.
	Q_PROPERTY(qs::mac::pipewire::PwLinkState::Enum state READ state NOTIFY stateChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("PwLinkGroups cannot be created directly");

public:
	explicit PwLinkGroup(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] static PwNode* target() { return nullptr; }
	[[nodiscard]] static PwNode* source() { return nullptr; }
	[[nodiscard]] static PwLinkState::Enum state() { return PwLinkState::Unlinked; }

signals:
	void stateChanged();
};

///! Tracks non-monitor link connections to a given node.
/// On macOS the link graph does not exist, so @@linkGroups is always empty;
/// the creatable type and its properties resolve so upstream configs load.
class PwNodeLinkTracker: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The node to track connections to.
	Q_PROPERTY(qs::mac::pipewire::PwNode* node READ node WRITE setNode NOTIFY nodeChanged);
	/// Link groups connected to the given node, excluding monitors.
	/// Always empty on macOS.
	Q_PROPERTY(QQmlListProperty<qs::mac::pipewire::PwLinkGroup> linkGroups READ linkGroups NOTIFY linkGroupsChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit PwNodeLinkTracker(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] PwNode* node() const { return this->mNode; }
	void setNode(PwNode* node);

	[[nodiscard]] QQmlListProperty<PwLinkGroup> linkGroups();

signals:
	void nodeChanged();
	void linkGroupsChanged();

private:
	PwNode* mNode = nullptr;
	QList<PwLinkGroup*> mEmpty;
};

} // namespace qs::mac::pipewire
