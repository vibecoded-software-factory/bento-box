#pragma once
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
// macOS stub for Quickshell.Services.Polkit. No polkit on macOS; inert.
namespace qs::mac::polkit {
class PolkitAgent: public QObject {
	Q_OBJECT;
	Q_PROPERTY(bool registered READ registered CONSTANT);
	QML_ELEMENT;

public:
	explicit PolkitAgent(QObject* p = nullptr): QObject(p) {}
	[[nodiscard]] bool registered() const { return false; }
	Q_INVOKABLE void registerAgent() {}
};
class Polkit: public QObject {
	Q_OBJECT;
	Q_PROPERTY(bool available READ available CONSTANT);
	QML_NAMED_ELEMENT(Polkit);
	QML_SINGLETON;

public:
	explicit Polkit(QObject* p = nullptr): QObject(p) {}
	[[nodiscard]] bool available() const { return false; }
};
} // namespace qs::mac::polkit
