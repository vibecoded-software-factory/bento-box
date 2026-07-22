#pragma once

#include <qjsonobject.h>
#include <qlocalsocket.h>
#include <qobject.h>
#include <qproperty.h>
#include <qtmetamacros.h>

#include "../../core/model.hpp"
#include "../../core/streamreader.hpp"
#include "workspace.hpp"

namespace qs::nigiri {

// Backend singleton for the nigiri integration. Not a QML type - the QML
// facade (NigiriIpcQml) forwards to it. Mirrors HyprlandIpc: one persistent
// event socket read with a StreamReader, an ObjectModel of workspaces updated
// in place from the event stream, and a one-shot request socket for commands.
//
// Transport differs from Hyprland: nigiri speaks niri's JSON line protocol on a
// single unix socket (`event-stream` to subscribe, `action <line>` to command),
// not two `NAME>>DATA` sockets. The event stream replays the current state on
// subscribe, so no separate snapshot poll is needed.
class NigiriIpc: public QObject {
	Q_OBJECT;

public:
	static NigiriIpc* instance();

	[[nodiscard]] ObjectModel<NigiriWorkspace>* workspaces() { return &this->mWorkspaces; }
	[[nodiscard]] QBindable<NigiriWorkspace*> bindableFocusedWorkspace() {
		return &this->bFocusedWorkspace;
	}
	[[nodiscard]] QBindable<qint32> bindableFocusedWindowId() { return &this->bFocusedWindowId; }

	// Send an action to nigiri (e.g. "focus-workspace 2"). Fire-and-forget over
	// a one-shot request socket.
	void dispatch(const QString& action);

signals:
	void focusedWorkspaceChanged();
	void focusedWindowIdChanged();
	// Every parsed event, name and payload, for QML that wants the raw stream.
	void rawEvent(const QString& name, const QJsonObject& data);

private slots:
	void onEventSocketState(QLocalSocket::LocalSocketState state);
	void onEventSocketReady();

private:
	explicit NigiriIpc();

	static QString socketPath();
	void connectToNigiri();
	void handleEvent(const QString& name, const QJsonObject& data);
	void applyWorkspaces(const QJsonArray& array);
	NigiriWorkspace* findWorkspaceById(qint32 id, bool createIfMissing);

	QLocalSocket mEventSocket;
	StreamReader mEventReader;
	ObjectModel<NigiriWorkspace> mWorkspaces {this};

	Q_OBJECT_BINDABLE_PROPERTY(
	    NigiriIpc,
	    NigiriWorkspace*,
	    bFocusedWorkspace,
	    &NigiriIpc::focusedWorkspaceChanged
	);
	Q_OBJECT_BINDABLE_PROPERTY(
	    NigiriIpc,
	    qint32,
	    bFocusedWindowId,
	    &NigiriIpc::focusedWindowIdChanged
	);
};

} // namespace qs::nigiri
