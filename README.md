# bento-box

A port of [quickshell](https://github.com/quickshell-mirror/quickshell) to
**macOS** — the same QML API, backed by AppKit instead of Wayland.

The goal is to run [DankMaterialShell](https://github.com/AvengeMedia/DankMaterialShell)
on macOS. DMS is written against quickshell's API, so **API compatibility is the
feature**: the ~44k lines of portable Qt keep coming from upstream, and only the
platform bindings are rewritten. See [`PORT.md`](PORT.md) for the milestones, the
mapping from Wayland/Linux services to their macOS counterparts, and what has
been verified.

macOS-specific code lives under `src/mac/` (a `PanelWindow` on AppKit, the
`Quickshell.Nigiri` compositor integration, and the `Mpris` / `UPower` /
`Pipewire` / `SystemTray` / `Bluetooth` services backed by MediaRemote /
IOKit / CoreAudio / IOBluetooth).

## This is a fork, not a rewrite

`upstream` is a real remote pointing at quickshell, and the history is intact so
the fork can be rebased on it. **quickshell is licensed under the GNU LGPL 3, and
so is this fork** — see [Licensing](#licensing). All original quickshell
copyright and attribution is preserved.

## Licensing

- **This project: GNU LGPL 3.0**, inherited from quickshell (see [`LICENSE`](LICENSE)
  and [`LICENSE-GPL`](LICENSE-GPL)). It cannot be relicensed away from the LGPL
  while it contains quickshell's code.
- **Vendored [`mediaremote-adapter`](src/mac/mpris/mediaremote-adapter/)**
  (from [ungive/mediaremote-adapter](https://github.com/ungive/mediaremote-adapter))
  is **BSD 3-Clause**; its `LICENSE` and attribution are kept in that directory.
  BSD-3 is compatible with the LGPL.
- Apple system frameworks (IOKit, CoreAudio, IOBluetooth, MediaRemote, …) are
  used through their public/host APIs and impose no license of their own.

<sub>Unless you explicitly state otherwise, any contribution submitted for
inclusion shall be licensed as above (LGPL 3), without any additional terms or
conditions.</sub>

---

## Credit

Built on [**quickshell**](https://github.com/quickshell-mirror/quickshell) by
outfoxxed and contributors ([website](https://quickshell.outfoxxed.me),
[source](https://git.outfoxxed.me/quickshell/quickshell)). This fork keeps
`upstream` as a real remote and rebases on it; all of its copyright and license
notices are preserved. Licensed under the GNU LGPL 3.
