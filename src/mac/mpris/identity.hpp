#pragma once

#include <qstring.h>

namespace qs::mac::mpris {

// The human-readable app name for a bundle identifier ("Spotify" for
// "com.spotify.client"), the same value MPRIS Identity carries upstream.
// Falls back to the identifier when the app cannot be resolved.
QString humanIdentityForBundleId(const QString& bundleId);

// Opens a uri WITH the given app (targeted NSWorkspace open) - the MPRIS
// OpenUri semantic. Returns false when the app cannot be resolved.
bool openUriWithBundleId(const QString& bundleId, const QString& uri);

} // namespace qs::mac::mpris
