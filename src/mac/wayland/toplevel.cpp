#include "toplevel.hpp"

#include <qobject.h>
#include <qstring.h>

#include "../nigiri/connection.hpp"
#include "../nigiri/window.hpp"

namespace qs::mac::wayland {

using qs::nigiri::NigiriIpc;
using qs::nigiri::NigiriWindow;

Toplevel::Toplevel(NigiriWindow* window, MacToplevelManager* manager)
    : QObject(manager)
    , mWindow(window)
    , mManager(manager) {
	QObject::connect(window, &NigiriWindow::appIdChanged, this, &Toplevel::appIdChanged);
	QObject::connect(window, &NigiriWindow::titleChanged, this, &Toplevel::titleChanged);
	QObject::connect(window, &NigiriWindow::activeChanged, this, &Toplevel::activatedChanged);
}

QString Toplevel::appId() const { return this->mWindow->bindableAppId().value(); }
QString Toplevel::title() const { return this->mWindow->bindableTitle().value(); }
bool Toplevel::activated() const { return this->mWindow->bindableActive().value(); }

void Toplevel::activate() { this->mWindow->activate(); }

void Toplevel::close() {
	this->mManager->dispatch(
	    QStringLiteral("close-window id=%1").arg(this->mWindow->bindableId().value())
	);
}

void Toplevel::setFullscreen(bool fullscreen) {
	if (!fullscreen) return;
	// The compositor's fullscreen acts on a window reference, niri-style.
	this->mManager->dispatch(
	    QStringLiteral("fullscreen-window id=%1").arg(this->mWindow->bindableId().value())
	);
}

void Toplevel::fullscreenOn(QuickshellScreenInfo* /*screen*/) { this->setFullscreen(true); }

// No macOS analogue: maximization/minimization state is not part of the
// compositor's vocabulary, and the rectangle hint has no consumer.
void Toplevel::setMaximized(bool /*maximized*/) {}
void Toplevel::setMinimized(bool /*minimized*/) {}
void Toplevel::setRectangle(QObject* /*window*/, QRect /*rect*/) {}
void Toplevel::unsetRectangle() {}

MacToplevelManager::MacToplevelManager(): mIpc(NigiriIpc::instance()) {
	auto* windows = this->mIpc->windows();

	QObject::connect(
	    windows,
	    &UntypedObjectModel::objectInsertedPost,
	    this,
	    &MacToplevelManager::onWindowInserted
	);
	QObject::connect(
	    windows,
	    &UntypedObjectModel::objectRemovedPost,
	    this,
	    &MacToplevelManager::onWindowRemoved
	);
	QObject::connect(
	    this->mIpc,
	    &NigiriIpc::focusedWindowIdChanged,
	    this,
	    &MacToplevelManager::updateActiveToplevel
	);

	// Windows that arrived before this singleton was first touched.
	for (auto* window: windows->valueList()) {
		this->onWindowInserted(window, this->mToplevels.valueList().length());
	}
	this->updateActiveToplevel();
}

MacToplevelManager* MacToplevelManager::instance() {
	static auto* instance = new MacToplevelManager(); // NOLINT
	return instance;
}

void MacToplevelManager::dispatch(const QString& action) { this->mIpc->dispatch(action); }

void MacToplevelManager::onWindowInserted(QObject* object, qsizetype /*index*/) {
	auto* window = qobject_cast<NigiriWindow*>(object);
	if (window == nullptr || this->mByWindow.contains(window)) return;

	auto* toplevel = new Toplevel(window, this);
	this->mByWindow.insert(window, toplevel);
	this->mToplevels.insertObject(toplevel);
	this->updateActiveToplevel();
}

void MacToplevelManager::onWindowRemoved(QObject* object, qsizetype /*index*/) {
	auto* toplevel = this->mByWindow.take(object);
	if (toplevel == nullptr) return;

	if (this->mActiveToplevel == toplevel) {
		this->mActiveToplevel = nullptr;
		emit this->activeToplevelChanged();
	}
	this->mToplevels.removeObject(toplevel);
	emit toplevel->closed();
	toplevel->deleteLater();
}

void MacToplevelManager::updateActiveToplevel() {
	Toplevel* active = nullptr;
	for (auto* toplevel: this->mToplevels.valueList()) {
		if (toplevel->activated()) {
			active = toplevel;
			break;
		}
	}
	if (this->mActiveToplevel == active) return;
	this->mActiveToplevel = active;
	emit this->activeToplevelChanged();
}

ToplevelManager::ToplevelManager(QObject* parent): QObject(parent) {
	QObject::connect(
	    MacToplevelManager::instance(),
	    &MacToplevelManager::activeToplevelChanged,
	    this,
	    &ToplevelManager::activeToplevelChanged
	);
}

} // namespace qs::mac::wayland
