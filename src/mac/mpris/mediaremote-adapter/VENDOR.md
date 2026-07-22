# Vendored: mediaremote-adapter

Source: https://github.com/ungive/mediaremote-adapter (BSD 3-Clause, see LICENSE)
Revision: 3ac3d4bdf862c7b5399b4fba4df5689f5c38609a

Only the framework sources, public header and the perl loader (`bin/`) are
vendored; the upstream test client and build files are dropped in favour of a
slim CMakeLists that builds just `MediaRemoteAdapter.framework`. The framework
is loaded at runtime by the entitled system perl (`com.apple.perl5`), which is
how it reaches Apple's restricted MediaRemote framework - the same
entitled-binary approach the osascript path used, but compiled so it can call
the block-based `MRMediaRemoteGetNowPlayingInfo` that carries album artwork.
