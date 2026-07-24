#pragma once

#include <qhash.h>
#include <qlist.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "node.hpp"

namespace qs::mac::pipewire {

///! Access to the system audio devices and their volumes.
/// The macOS counterpart of the Linux `Pipewire` service, backed by CoreAudio.
/// Exposes the same audio surface (nodes, default sink/source, preferred
/// sink/source) so DMS's audio widgets bind unchanged. The link graph has no
/// CoreAudio equivalent, so `links`/`linkGroups` are always empty.
class Pipewire: public QObject {
	Q_OBJECT;
	// clang-format off
	/// All audio nodes present on the system (one per CoreAudio device direction).
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::pipewire::PwNode>*);
	Q_PROPERTY(UntypedObjectModel* nodes READ nodes CONSTANT);
	/// Always empty on macOS - CoreAudio exposes no link graph.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::pipewire::PwNode>*);
	Q_PROPERTY(UntypedObjectModel* links READ links CONSTANT);
	/// Always empty on macOS - CoreAudio exposes no link graph.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::pipewire::PwNode>*);
	Q_PROPERTY(UntypedObjectModel* linkGroups READ linkGroups CONSTANT);
	/// The default audio sink (output) or `null`.
	Q_PROPERTY(qs::mac::pipewire::PwNode* defaultAudioSink READ defaultAudioSink NOTIFY defaultAudioSinkChanged);
	/// The default audio source (input) or `null`.
	Q_PROPERTY(qs::mac::pipewire::PwNode* defaultAudioSource READ defaultAudioSource NOTIFY defaultAudioSourceChanged);
	/// The preferred default audio sink. Upstream this is a HINT pipewire may
	/// not honor; macOS's set-default is imperative and immediate, so there is
	/// no pending state and the configured value always equals
	/// @@defaultAudioSink - but it NOTIFYs through its own signal (upstream
	/// qml.hpp:115: defaultConfiguredAudioSinkChanged) so handlers attach.
	Q_PROPERTY(qs::mac::pipewire::PwNode* preferredDefaultAudioSink READ defaultAudioSink WRITE setPreferredDefaultAudioSink NOTIFY defaultConfiguredAudioSinkChanged);
	/// The input counterpart of @@preferredDefaultAudioSink, same macOS
	/// no-pending-state mapping.
	Q_PROPERTY(qs::mac::pipewire::PwNode* preferredDefaultAudioSource READ defaultAudioSource WRITE setPreferredDefaultAudioSource NOTIFY defaultConfiguredAudioSourceChanged);
	/// True once the initial device sync has completed.
	Q_PROPERTY(bool ready READ isReady NOTIFY readyChanged);
	// clang-format on
	QML_ELEMENT;
	QML_SINGLETON;

public:
	explicit Pipewire(QObject* parent = nullptr);
	~Pipewire() override;
	Q_DISABLE_COPY_MOVE(Pipewire);

	static Pipewire* instance();

	[[nodiscard]] ObjectModel<PwNode>* nodes() { return &this->mNodes; }
	[[nodiscard]] ObjectModel<PwNode>* links() { return &this->mEmpty; }
	[[nodiscard]] ObjectModel<PwNode>* linkGroups() { return &this->mEmpty; }

	[[nodiscard]] PwNode* defaultAudioSink() const { return this->mDefaultSink; }
	[[nodiscard]] PwNode* defaultAudioSource() const { return this->mDefaultSource; }
	void setPreferredDefaultAudioSink(PwNode* node);
	void setPreferredDefaultAudioSource(PwNode* node);

	[[nodiscard]] bool isReady() const { return this->mReady; }

	// Called from the CoreAudio listener trampoline (already marshalled to the
	// main thread).
	void update();

signals:
	void defaultAudioSinkChanged();
	void defaultAudioSourceChanged();
	// The configured-preference signals, upstream's names: on macOS actual
	// and configured move together, so these fire alongside the two above.
	void defaultConfiguredAudioSinkChanged();
	void defaultConfiguredAudioSourceChanged();
	void readyChanged();

private:
	[[nodiscard]] PwNode* findNode(quint32 deviceId, bool input) const;
	void setListeners(bool add);
	void setDeviceVolumeListeners(quint32 deviceId, bool input, bool add);

	ObjectModel<PwNode> mNodes {this};
	ObjectModel<PwNode> mEmpty {this};
	QHash<quint64, PwNode*> mByKey; // key = deviceId<<1 | input
	PwNode* mDefaultSink = nullptr;
	PwNode* mDefaultSource = nullptr;
	quint32 mListenedSink = 0; // device currently carrying volume/mute listeners
	quint32 mListenedSource = 0;
	bool mReady = false;
};

///! Binds pipewire objects. A no-op on macOS.
/// On Linux, objects must be bound before some properties are valid. CoreAudio
/// devices are always fully available, so this tracker only holds the list to
/// keep the API compatible; binding is unnecessary.
class PwObjectTracker: public QObject {
	Q_OBJECT;
	Q_PROPERTY(QList<QObject*> objects READ objects WRITE setObjects NOTIFY objectsChanged);
	QML_ELEMENT;

public:
	explicit PwObjectTracker(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] QList<QObject*> objects() const { return this->mObjects; }
	void setObjects(const QList<QObject*>& objects) {
		this->mObjects = objects;
		emit this->objectsChanged();
	}

signals:
	void objectsChanged();

private:
	QList<QObject*> mObjects;
};

} // namespace qs::mac::pipewire
