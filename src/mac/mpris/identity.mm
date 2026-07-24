#include "identity.hpp"

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

namespace qs::mac::mpris {

// MPRIS `Identity` is "a friendly name to identify the media player"
// (upstream player.hpp:100-101 carries it verbatim from the player's DBus
// Identity). MediaRemote only hands us the bundle identifier, so resolve it
// the way the OS names the app: the running application's localizedName
// (the now-playing app is by definition running), falling back to the
// bundle's display name on disk, falling back to the identifier itself
// rather than inventing anything.
QString humanIdentityForBundleId(const QString& bundleId) {
	if (bundleId.isEmpty()) return bundleId;
	@autoreleasepool {
		auto* nsBundleId = bundleId.toNSString();

		auto* running = [NSRunningApplication runningApplicationsWithBundleIdentifier:nsBundleId];
		if (running.count > 0 && running.firstObject.localizedName != nil) {
			return QString::fromNSString(running.firstObject.localizedName);
		}

		auto* url = [NSWorkspace.sharedWorkspace URLForApplicationWithBundleIdentifier:nsBundleId];
		if (url != nil) {
			auto* bundle = [NSBundle bundleWithURL:url];
			NSString* name = bundle.infoDictionary[@"CFBundleDisplayName"];
			if (name == nil) name = bundle.infoDictionary[(NSString*) kCFBundleNameKey];
			if (name != nil) return QString::fromNSString(name);
		}
	}
	return bundleId;
}

bool openUriWithBundleId(const QString& bundleId, const QString& uri) {
	if (bundleId.isEmpty() || uri.isEmpty()) return false;
	@autoreleasepool {
		auto* appUrl =
		    [NSWorkspace.sharedWorkspace URLForApplicationWithBundleIdentifier:bundleId.toNSString()];
		if (appUrl == nil) return false;
		auto* target = [NSURL URLWithString:uri.toNSString()];
		if (target == nil) return false;
		auto* config = [NSWorkspaceOpenConfiguration configuration];
		[NSWorkspace.sharedWorkspace openURLs:@[ target ]
		                 withApplicationAtURL:appUrl
		                        configuration:config
		                    completionHandler:nil];
		return true;
	}
}

} // namespace qs::mac::mpris
