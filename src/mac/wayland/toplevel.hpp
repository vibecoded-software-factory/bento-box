#pragma once

#include <qhash.h>
#include <qlist.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qrect.h>
#include <qtmetamacros.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "../../core/qmlscreen.hpp"

namespace qs::nigiri {
class NigiriIpc;
class NigiriWindow;
} // namespace qs::nigiri

namespace qs::mac::wayland {

class MacToplevelManager;

///! Window from another application.
/// A window/toplevel from another application, retrievable from the
/// @@ToplevelManager. On macOS these mirror the compositor's window list over
/// its IPC socket - the same vocabulary a Wayland compositor exposes through
/// zwlr-foreign-toplevel-management, minus the states macOS cannot deliver.
class Toplevel: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString appId READ appId NOTIFY appIdChanged);
	Q_PROPERTY(QString title READ title NOTIFY titleChanged);
	/// Parent toplevel if this toplevel is a modal/dialog. Always null on
	/// macOS - the compositor does not report parenthood.
	Q_PROPERTY(qs::mac::wayland::Toplevel* parent READ parentToplevel NOTIFY parentChanged);
	/// If the window is currently activated or focused.
	Q_PROPERTY(bool activated READ activated NOTIFY activatedChanged);
	/// Screens the toplevel is visible on. Currently empty on macOS (queued
	/// behind the multi-monitor milestone).
	Q_PROPERTY(QList<QuickshellScreenInfo*> screens READ screens NOTIFY screensChanged);
	/// Maximization state. Requests are forwarded to the compositor and may
	/// be ignored.
	Q_PROPERTY(bool maximized READ maximized WRITE setMaximized NOTIFY maximizedChanged);
	/// Minimization state. macOS windows under the compositor do not
	/// minimize; requests are ignored.
	Q_PROPERTY(bool minimized READ minimized WRITE setMinimized NOTIFY minimizedChanged);
	/// Fullscreen state. Requests are forwarded to the compositor and may be
	/// ignored.
	Q_PROPERTY(bool fullscreen READ fullscreen WRITE setFullscreen NOTIFY fullscreenChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("Toplevels must be acquired from the ToplevelManager.");

public:
	explicit Toplevel(qs::nigiri::NigiriWindow* window, MacToplevelManager* manager);

	/// Request that this toplevel is activated.
	Q_INVOKABLE void activate();
	/// Request that this toplevel is closed.
	Q_INVOKABLE void close();
	/// Request fullscreen on a specific screen. Screen selection is not
	/// supported on macOS; forwards a plain fullscreen request.
	Q_INVOKABLE void fullscreenOn(QuickshellScreenInfo* screen);
	/// Visual-representation hint used by Wayland compositors for minimize
	/// animations. No macOS analogue; accepted and ignored.
	Q_INVOKABLE void setRectangle(QObject* window, QRect rect);
	Q_INVOKABLE void unsetRectangle();

	[[nodiscard]] QString appId() const;
	[[nodiscard]] QString title() const;
	[[nodiscard]] Toplevel* parentToplevel() const { return nullptr; }
	[[nodiscard]] bool activated() const;
	[[nodiscard]] QList<QuickshellScreenInfo*> screens() const { return {}; }
	[[nodiscard]] bool maximized() const { return false; }
	void setMaximized(bool maximized);
	[[nodiscard]] bool minimized() const { return false; }
	void setMinimized(bool minimized);
	[[nodiscard]] bool fullscreen() const { return false; }
	void setFullscreen(bool fullscreen);

	// The compositor-side window this mirrors; ScreencopyView resolves its
	// capture target (pid + title) through this.
	[[nodiscard]] qs::nigiri::NigiriWindow* backingWindow() const { return this->mWindow; }

signals:
	void closed();
	void appIdChanged();
	void titleChanged();
	void parentChanged();
	void activatedChanged();
	void screensChanged();
	void maximizedChanged();
	void minimizedChanged();
	void fullscreenChanged();

private:
	qs::nigiri::NigiriWindow* mWindow;
	MacToplevelManager* mManager;

	friend class MacToplevelManager;
};

// Backend: wraps the compositor IPC's window model into Toplevels, mirroring
// the upstream ToplevelManager backend the QML singleton fronts.
class MacToplevelManager: public QObject {
	Q_OBJECT;

public:
	[[nodiscard]] ObjectModel<Toplevel>* toplevels() { return &this->mToplevels; }
	[[nodiscard]] Toplevel* activeToplevel() const { return this->mActiveToplevel; }

	void dispatch(const QString& action);

	static MacToplevelManager* instance();

signals:
	void activeToplevelChanged();

private slots:
	void onWindowInserted(QObject* object, qsizetype index);
	void onWindowRemoved(QObject* object, qsizetype index);
	void updateActiveToplevel();

private:
	explicit MacToplevelManager();

	qs::nigiri::NigiriIpc* mIpc;
	ObjectModel<Toplevel> mToplevels {this};
	QHash<QObject*, Toplevel*> mByWindow;
	Toplevel* mActiveToplevel = nullptr;
};

///! Exposes a list of Toplevels.
/// Exposes windows from other applications as @@Toplevel$s. On macOS the list
/// mirrors the compositor's window list over its IPC socket.
class ToplevelManager: public QObject {
	Q_OBJECT;
	// clang-format off
	/// All toplevel windows exposed by the compositor.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::wayland::Toplevel>*);
	Q_PROPERTY(UntypedObjectModel* toplevels READ toplevels CONSTANT);
	/// Active toplevel or null.
	Q_PROPERTY(qs::mac::wayland::Toplevel* activeToplevel READ activeToplevel NOTIFY activeToplevelChanged);
	// clang-format on
	QML_NAMED_ELEMENT(ToplevelManager);
	QML_SINGLETON;

public:
	explicit ToplevelManager(QObject* parent = nullptr);

	[[nodiscard]] static UntypedObjectModel* toplevels() {
		return MacToplevelManager::instance()->toplevels();
	}
	[[nodiscard]] static Toplevel* activeToplevel() {
		return MacToplevelManager::instance()->activeToplevel();
	}

signals:
	void activeToplevelChanged();
};

} // namespace qs::mac::wayland
