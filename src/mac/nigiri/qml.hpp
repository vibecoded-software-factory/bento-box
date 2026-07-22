#pragma once

#include <qjsonobject.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/model.hpp"
#include "connection.hpp"
#include "window.hpp"
#include "workspace.hpp"

namespace qs::nigiri {

///! Live state of the nigiri tiling window manager.
/// The macOS counterpart of `Quickshell.Hyprland`'s `Hyprland` singleton:
/// nigiri's workspaces and focus, driven by its event stream, plus a way to
/// send it commands. Bind a workspace bar to `Nigiri.workspaces.values`.
class NigiriIpcQml: public QObject {
	Q_OBJECT;
	// clang-format off
	/// All workspaces, ordered by strip position. Iterate `.values`.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::nigiri::NigiriWorkspace>*);
	Q_PROPERTY(UntypedObjectModel* workspaces READ workspaces CONSTANT);
	/// All windows. Iterate `.values`.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::nigiri::NigiriWindow>*);
	Q_PROPERTY(UntypedObjectModel* windows READ windows CONSTANT);
	/// The focused workspace, or null.
	Q_PROPERTY(qs::nigiri::NigiriWorkspace* focusedWorkspace READ focusedWorkspace NOTIFY focusedWorkspaceChanged);
	/// The focused window, or null.
	Q_PROPERTY(qs::nigiri::NigiriWindow* activeWindow READ activeWindow NOTIFY activeWindowChanged);
	/// The focused window's id, or 0 if none.
	Q_PROPERTY(qint32 focusedWindowId READ focusedWindowId NOTIFY focusedWindowIdChanged);
	// clang-format on
	QML_NAMED_ELEMENT(Nigiri);
	QML_SINGLETON;

public:
	explicit NigiriIpcQml(QObject* parent = nullptr);

	[[nodiscard]] UntypedObjectModel* workspaces() const;
	[[nodiscard]] UntypedObjectModel* windows() const;
	[[nodiscard]] NigiriWorkspace* focusedWorkspace() const;
	[[nodiscard]] NigiriWindow* activeWindow() const;
	[[nodiscard]] qint32 focusedWindowId() const;

	/// Send an action to nigiri, e.g. `Nigiri.dispatch("focus-workspace 2")`.
	/// Accepts any action nigiri's IPC understands.
	Q_INVOKABLE void dispatch(const QString& action);

signals:
	void focusedWorkspaceChanged();
	void activeWindowChanged();
	void focusedWindowIdChanged();
	/// Emitted for every event on the stream: the event name and its payload.
	void rawEvent(const QString& name, const QJsonObject& data);
};

} // namespace qs::nigiri
