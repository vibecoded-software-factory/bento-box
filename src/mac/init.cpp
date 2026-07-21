#include <qguiapplication.h>
#include <qlist.h>
#include <qqml.h>
#include <qstring.h>

#include "../core/plugin.hpp"
#include "panel_window.hpp"

namespace {

// The cocoa PanelWindow backend, mirroring WaylandPlugin/X11Plugin: it applies
// on the macOS ("cocoa") QPA platform and overlay-registers PanelWindow so an
// unqualified `import Quickshell` resolves PanelWindow to the AppKit backend.
class MacPlugin: public QsEnginePlugin {
	QList<QString> dependencies() override { return {"window"}; }

	bool applies() override { return QGuiApplication::platformName() == "cocoa"; }

	void registerTypes() override {
		qmlRegisterType<qs::mac::MacPanelInterface>("Quickshell._CocoaOverlay", 1, 0, "PanelWindow");

		qmlRegisterModuleImport(
		    "Quickshell",
		    QQmlModuleImportModuleAny,
		    "Quickshell._CocoaOverlay",
		    QQmlModuleImportLatest
		);
	}
};

QS_REGISTER_PLUGIN(MacPlugin);

} // namespace
