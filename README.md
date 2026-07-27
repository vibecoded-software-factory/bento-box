# bento-box

**A macOS port of [quickshell](https://github.com/outfoxxed/quickshell)** — the
QML runtime for building desktop shells.

Upstream quickshell is Wayland-native: layer surfaces, D-Bus services, PipeWire,
`/proc`. bento keeps the QML API and reimplements the platform underneath it on
AppKit, CoreAudio, IOBluetooth and the rest, so a shell written for quickshell
loads and runs on macOS.

It is a **runtime, not a shell**. It ships no bar and no widgets — you point it
at a QML entry point and it renders that:

```sh
bento -p /path/to/shell.qml
```

The shell this port exists for is
[DankMaterialShell](https://github.com/AvengeMedia/DankMaterialShell), wired up
by [dms-darwin](https://github.com/vibecoded-software-factory/dms-darwin) — but
nothing here is specific to it.

## What is ported, and what is not

macOS does not have equivalents for everything, and where it does not, the
module still registers its QML types so a shell importing it binds without
error — it just reports nothing. That is deliberate: a shell should degrade, not
fail to load.

| Area | On macOS |
|---|---|
| `PanelWindow` | Real, on AppKit. Panels reserve space through the compositor (below), macOS having no layer shell. |
| `Quickshell.Mac.Desktop` | Real — reads and sets the desktop wallpaper. |
| MPRIS / media | Real, via a MediaRemote adapter framework loaded by the system perl. |
| PipeWire / audio | Real, backed by CoreAudio. |
| Bluetooth | Real, via IOBluetooth. |
| nigiri IPC | Real — workspaces and windows from a niri-shaped socket. |
| **Notifications** | **Stub.** macOS has no public API for one app to receive another's notifications; the only route is scraping a private database. `trackedNotifications` is always empty. |
| **System tray** | **Stub** — no StatusNotifierItem host on macOS. |
| **PAM / polkit** | **Stub** — authentication and privilege prompts are system-owned. |
| **UPower** | No public API for the equivalent state. |
| **Hyprland / i3** | **Stub** — those compositors do not run here. |

## Requirements

- **macOS** with the Xcode Command Line Tools. bento declares no deployment
  target of its own; the rest of the stack it is built for targets macOS 13+.
- `brew install cmake ninja qt`

## Build and install

```sh
./Scripts/install.sh
```

Builds release, installs `~/Applications/Bento.app`, and registers the launchd
agent `dev.bento`. Re-run it after any change — that is the normal workflow.

It needs a shell to run. Point it at one:

```sh
BENTO_SHELL_QML=/path/to/shell.qml ./Scripts/install.sh
```

The default is the staging root that dms-darwin's `Glue/install.sh` assembles,
so in the DankMaterialShell setup you normally run **that** script and it calls
this one for you. See [dms-darwin's
README](https://github.com/vibecoded-software-factory/dms-darwin#install) for
the full install order.

> [!IMPORTANT]
> Install with the script, not by running the binary. macOS keys TCC grants
> (Screen Recording, Bluetooth, Microphone) to a **code signature**: an ad-hoc
> signature mints a new identity every build and silently drops every grant.
> The script creates a stable self-signed certificate once and reuses it, and
> refuses to fall back to ad-hoc. Running the binary from a terminal is worse —
> it borrows the terminal's grants, so permission bugs vanish in testing.

**Logs** are at `/tmp/bento.log`.

### Development builds

```sh
just build          # debug, into build/
just run -p shell.qml
just test
just fmt
```

The Linux-only options (`WAYLAND`, `X11`, `I3`, `BLUETOOTH`, `NETWORK`, every
`SERVICE_*`) default to **ON**, because upstream targets Linux. `Scripts/install.sh`
turns them off explicitly; a hand-run `cmake` needs the same treatment or it
will try to build backends that are not there.

## Compositor integration

macOS has no layer shell, so a panel cannot declare an exclusive zone. Instead
bento asks a running tiling compositor to reserve the space over its control
socket — `action reserve-zone <id> <edge> <size>`, released with `clear-zone`
(`src/mac/panel_window.cpp`). Without a compositor listening, panels simply draw
without reserved space.

`$NIGIRI_SOCKET` names that socket. **Setting it also asks bento to wait for the
compositor before loading any QML** (`src/mac/compositor.cpp`,
`awaitCompositorSocket`): a shell typically probes for its compositor once at
startup and latches the result, and launchd has no way to order one agent after
another, so at login bento would otherwise routinely win a race it needs to
lose. The wait ends the moment the socket appears; `$BENTO_COMPOSITOR_WAIT_MS`
caps it (0 disables).

## Layout

```
src/
├── mac/          The AppKit backend: panels, desktop, compositor IPC,
│                 and the macOS-native service backends.
├── core/         Engine, QML scanner, reload — shared with upstream.
├── io/           Sockets, processes, file access.
├── services/     The Linux service implementations (built off on macOS).
└── window/ ui/ widgets/
```

## License

LGPL-3.0 ([LICENSE](LICENSE)), with [LICENSE-GPL](LICENSE-GPL), following
upstream quickshell.
