#pragma once
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qvariant.h>
#include "../../core/doc.hpp"
#include "../../core/model.hpp"
// macOS stub for Quickshell.I3 (sway/i3 IPC). Multi-compositor shells import it
// unconditionally; inert on macOS, where the compositor is nigiri.
namespace qs::mac::i3 {
class I3Workspace: public QObject { Q_OBJECT; QML_ELEMENT; QML_UNCREATABLE("i3 is not the compositor on macOS");
public: explicit I3Workspace(QObject* p = nullptr): QObject(p) {} };
class I3: public QObject {
	Q_OBJECT;
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::i3::I3Workspace>*);
	Q_PROPERTY(UntypedObjectModel* workspaces READ workspaces CONSTANT);
	QML_NAMED_ELEMENT(I3); QML_SINGLETON;
public:
	explicit I3(QObject* p = nullptr): QObject(p) {}
	[[nodiscard]] ObjectModel<I3Workspace>* workspaces() { return &this->mWorkspaces; }
	Q_INVOKABLE void dispatch(const QString& = {}) {}
private: ObjectModel<I3Workspace> mWorkspaces {this};
};
} // namespace
