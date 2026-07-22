#pragma once
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qstring.h>
// macOS stub for Quickshell.Services.Pam (Linux auth). No PAM on macOS; inert
// stub for binding compatibility (DMS's lock screen auth is a no-op here).
namespace qs::mac::pam {
namespace PamResult { // NOLINT
Q_NAMESPACE; QML_ELEMENT;
enum Enum : quint8 { Success = 0, Failed = 1, Error = 2, MaxTries = 3 };
Q_ENUM_NS(Enum);
}
class PamContext: public QObject {
	Q_OBJECT;
	Q_PROPERTY(bool active READ active NOTIFY activeChanged);
	Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged);
	Q_PROPERTY(QString config READ config WRITE setConfig NOTIFY configChanged);
	Q_PROPERTY(QString configDirectory READ configDir WRITE setConfigDir NOTIFY configChanged);
	QML_ELEMENT;
public:
	explicit PamContext(QObject* p = nullptr): QObject(p) {}
	[[nodiscard]] bool active() const { return false; }
	[[nodiscard]] QString user() const { return mUser; }
	void setUser(const QString& u) { mUser = u; emit userChanged(); }
	[[nodiscard]] QString config() const { return mConfig; }
	void setConfig(const QString& c) { mConfig = c; emit configChanged(); }
	[[nodiscard]] QString configDir() const { return mConfigDir; }
	void setConfigDir(const QString& c) { mConfigDir = c; emit configChanged(); }
	Q_INVOKABLE bool start() { return false; }
	Q_INVOKABLE void abort() {}
	Q_INVOKABLE void respond(const QString& = {}) {}
signals:
	void activeChanged(); void userChanged(); void configChanged();
	void completed(qs::mac::pam::PamResult::Enum result);
	void pamMessage(const QString& message, bool isError, bool responseRequired, bool responseVisible);
private: QString mUser, mConfig, mConfigDir;
};
} // namespace
