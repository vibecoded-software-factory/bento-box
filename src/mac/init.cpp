#include <qguiapplication.h>
#include <qlist.h>
#include <qqml.h>
#include <qstring.h>

#include "../core/plugin.hpp"
#include "../windowmanager/windowmanager.hpp"
#include "compositor.hpp"
#include "panel_window.hpp"
#include "wayland/wayland.hpp"

namespace {

// The cocoa PanelWindow backend, mirroring WaylandPlugin/X11Plugin: it applies
// on the macOS ("cocoa") QPA platform and overlay-registers PanelWindow so an
// unqualified `import Quickshell` resolves PanelWindow to the AppKit backend.
class MacPlugin: public QsEnginePlugin {
	QList<QString> dependencies() override { return {"window"}; }

	bool applies() override { return QGuiApplication::platformName() == "cocoa"; }

	// Before the QML root exists, and so before any shell can probe for the
	// compositor. init() rather than registerTypes() because this orders
	// startup, it does not register anything - and plugin init() runs first.
	void init() override { qs::mac::awaitCompositorSocket(); }

	void registerTypes() override {
		// The WlrLayershell-backed interface, so the Quickshell.Wayland
		// attached object resolves to the backing window on every PanelWindow
		// (upstream registers its WaylandPanelInterface the same way).
		qmlRegisterType<qs::mac::wayland::WaylandPanelInterface>(
		    "Quickshell._CocoaOverlay",
		    1,
		    0,
		    "PanelWindow"
		);

		qmlRegisterModuleImport(
		    "Quickshell",
		    QQmlModuleImportModuleAny,
		    "Quickshell._CocoaOverlay",
		    QQmlModuleImportLatest
		);

		// The core Quickshell.WindowManager singleton resolves its instance
		// through a provider a compositor plugin installs; on Wayland that is
		// WaylandWindowManager. macOS has no foreign-toplevel source, so install
		// a plain (empty-windowsets) instance - otherwise WindowManager::instance()
		// invokes an unset std::function and the shell aborts the moment a config
		// reads WindowManager.windowsets.
		qs::wm::WindowManager::setProvider([]() { return new qs::wm::WindowManager(); });
	}
};

QS_REGISTER_PLUGIN(MacPlugin);

} // namespace
