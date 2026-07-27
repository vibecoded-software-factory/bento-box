#!/bin/bash
# Build, install and (re)start bento as a launchd agent.
#
# Safe to re-run: it is the normal way to pick up a code change.
#
# Like nigiri's script, the whole thing exists to protect the TCC grants, which
# macOS keys to the app's code signature rather than to its path. Two rules,
# both learned the hard way:
#
#   - Ship a real .app BUNDLE. An unbundled binary is a second-class TCC
#     citizen: grants pin to per-build hashes and running it from a terminal
#     silently borrows the terminal's grant. A bundle is keyed by bundle id, so
#     it is one row in the panel and `tccutil reset <service> dev.bento` works.
#   - Sign with a STABLE identity. `codesign --sign -` (ad-hoc) mints a new
#     identity on every build, so every install drops Screen Recording,
#     Microphone and the rest. This script never ad-hoc signs: it creates a
#     self-signed certificate on first run and reuses it forever.
#
# Bento needs two things in the bundle that nigiri does not:
#
#   - Contents/Frameworks/MediaRemoteAdapter.framework, which the MPRIS service
#     locates relative to its own executable (src/mac/mpris/service.cpp) and
#     hands to the system perl. Without it there is no media player state.
#   - The NS*UsageDescription strings in Info.plist. macOS hard-CRASHES a
#     launchd-run app that touches a TCC-protected API with no usage string -
#     which is why an unbundled build "worked" from a terminal (the terminal was
#     the responsible process) and aborted as an agent.

set -euo pipefail

CERT_CN="bento codesign"
BUNDLE_ID="dev.bento"
APP="$HOME/Applications/Bento.app"
PLIST="$HOME/Library/LaunchAgents/$BUNDLE_ID.plist"
KEYCHAIN="$HOME/Library/Keychains/login.keychain-db"
BUILD_DIR="build-release"
LOG="/tmp/bento.log"

step() { printf '\033[1m==>\033[0m %s\n' "$*"; }
ok()   { printf '    \033[32mok\033[0m %s\n' "$*"; }
warn() { printf '    \033[33mwarning\033[0m %s\n' "$*" >&2; }
die()  { printf '\n\033[31merror\033[0m %s\n' "$*" >&2; exit 1; }

cd "$(dirname "$0")/.."
REPO="$PWD"

# The shell bento runs. Not a build artefact - it is the user's choice of
# configuration, so it is overridable and only defaulted.
#
# The default is the shell root ASSEMBLED by dms-darwin's Glue/install.sh, not
# a path inside the DankMaterialShell checkout: that checkout is third-party and
# read-only, so nothing of ours lives in it. The staging root is symlinks into
# it plus our own entry point. Run that script first, or point
# BENTO_SHELL_QML at whatever shell you actually want.
SHELL_QML="${BENTO_SHELL_QML:-$HOME/.local/share/dms-darwin/shell/shell-macos.qml}"

# Sockets and paths handed to the agent. Same reasoning: environment, not build
# output. They are written into the plist because a launchd agent inherits
# almost nothing, and NIRI_SOCKET in particular is what makes the shell find the
# compositor without being told.
DMS_SOCKET="${DMS_SOCKET:-/tmp/dms-darwin.sock}"
NIRI_SOCKET="${NIRI_SOCKET:-/tmp/nigiri-msg.sock}"
XDG_RUNTIME_DIR="${XDG_RUNTIME_DIR:-$HOME/.local/state/dms-run}"
AGENT_PATH="${BENTO_AGENT_PATH:-$HOME/.local/bin:/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin}"

# ---------------------------------------------------------------- preflight

[ "$(id -u)" -ne 0 ] || die "do not run this as root - the agent and its grants belong to your user."
[ "$(uname -s)" = "Darwin" ] || die "this script is macOS only (this is $(uname -s))."

command -v cmake >/dev/null 2>&1 || die "cmake not found. brew install cmake"
command -v ninja >/dev/null 2>&1 || die "ninja not found. brew install ninja"
command -v codesign >/dev/null 2>&1 || die "codesign not found (Command Line Tools are incomplete)."

[ -f "$SHELL_QML" ] || die "the shell QML does not exist: $SHELL_QML
Point BENTO_SHELL_QML at it, e.g.
    BENTO_SHELL_QML=/path/to/shell-macos.qml $0"

# Resolved before it reaches the plist. The default is written relative to this
# repo, and launchd would take the `..` literally forever after - a path that
# still works but records where the script happened to run from rather than
# where the shell is.
SHELL_QML="$(cd "$(dirname "$SHELL_QML")" && pwd -P)/$(basename "$SHELL_QML")"

# Qt is found through CMAKE_PREFIX_PATH; ask brew rather than hardcoding, and
# fall back to the path the existing build tree was configured with.
QT_PREFIX="${QT_PREFIX:-$(brew --prefix qt 2>/dev/null || echo /opt/homebrew/opt/qt)}"
[ -d "$QT_PREFIX/lib/cmake/Qt6" ] || die "Qt 6 not found at $QT_PREFIX. brew install qt, or set QT_PREFIX."

# ------------------------------------------------------------------- build

# Every option whose backend is Linux-only, turned off explicitly.
#
# CMakeLists.txt defaults them ON (WAYLAND, X11, I3, BLUETOOTH, NETWORK and
# every SERVICE_*), because upstream quickshell targets Linux. Leaving them at
# their defaults on macOS configures a build for backends that are not there -
# wayland-scanner, D-Bus, PipeWire, PAM, polkit.
#
# This list is not an optimization, it is the macOS build. It used to live only
# in dms-darwin's Glue/install.sh, so this script "worked" purely because that
# other script had already written a CMakeCache.txt with the flags in it; a
# clean clone configured the Linux-flavoured build instead. Passing them here
# makes this script self-sufficient.
#
# Note SERVICE_MPRIS=OFF still yields MediaRemoteAdapter.framework: the macOS
# media integration is a separate module (src/mac/CMakeLists.txt adds mpris
# unconditionally), and only the D-Bus MPRIS service is switched off.
#
# An ARRAY, expanded as "${MAC_OPTIONS[@]}": a plain string would have to rely
# on word-splitting to become separate flags, which silently produces one giant
# malformed -D argument under any shell that does not split (zsh, notably) and
# leaves every option at its Linux default.
MAC_OPTIONS=(
    -DWAYLAND=OFF -DX11=OFF -DI3=OFF -DBLUETOOTH=OFF -DNETWORK=OFF
    -DCRASH_HANDLER=OFF -DUSE_JEMALLOC=OFF
    -DSERVICE_MPRIS=OFF -DSERVICE_PIPEWIRE=OFF -DSERVICE_UPOWER=OFF
    -DSERVICE_STATUS_NOTIFIER=OFF -DSERVICE_NOTIFICATIONS=OFF
    -DSERVICE_PAM=OFF -DSERVICE_POLKIT=OFF -DSERVICE_GREETD=OFF
)

# Configured on EVERY run, not just when the cache is missing. cmake is a no-op
# when nothing changed, and re-asserting the options is what stops a cache left
# behind by another script (or an experiment) from silently deciding what this
# build contains.
step "Configuring ($BUILD_DIR, Release)"
cmake -GNinja -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH="$QT_PREFIX" "${MAC_OPTIONS[@]}" >/dev/null \
    || die "cmake could not configure the build."
ok "configured against Qt at $QT_PREFIX"

step "Building (release)"
cmake --build "$BUILD_DIR" || die "the build failed."
BIN="$BUILD_DIR/src/quickshell"
FRAMEWORK="$BUILD_DIR/src/mac/mpris/mediaremote-adapter/MediaRemoteAdapter.framework"
[ -x "$BIN" ] || die "the build reported success but $BIN is missing."
[ -d "$FRAMEWORK" ] || die "the build reported success but $FRAMEWORK is missing."
ok "$(du -h "$BIN" | cut -f1) at $BIN"

# ------------------------------------------------- signing identity: find or create

# The CERTIFICATE store, not `security find-identity -p codesigning`: the latter
# lists only TRUSTED identities and would miss a perfectly usable untrusted one.
cert_hashes() {
    security find-certificate -c "$CERT_CN" -a -Z "$KEYCHAIN" 2>/dev/null \
        | awk '/^SHA-1 hash:/ { print $3 }'
}

create_certificate() {
    step "Creating the '$CERT_CN' signing certificate (first run only)"
    local dir password
    dir=$(mktemp -d)
    # `security import` fails on an EMPTY p12 password with the misleading
    # error "MAC verification failed during PKCS12 import (wrong password?)".
    password=$(openssl rand -hex 16)

    openssl req -x509 -newkey rsa:2048 -keyout "$dir/key.pem" -out "$dir/cert.pem" \
        -days 3650 -nodes -subj "/CN=$CERT_CN" \
        -addext "basicConstraints=critical,CA:false" \
        -addext "keyUsage=critical,digitalSignature" \
        -addext "extendedKeyUsage=critical,codeSigning" 2>/dev/null \
        || die "openssl could not generate the certificate."

    # OpenSSL 3 writes PKCS#12 files that macOS's `security import` rejects;
    # the -legacy/PBE flags produce the older format it accepts.
    openssl pkcs12 -export -out "$dir/cert.p12" -inkey "$dir/key.pem" -in "$dir/cert.pem" \
        -name "$CERT_CN" -passout "pass:$password" \
        -legacy -macalg sha1 -keypbe PBE-SHA1-3DES -certpbe PBE-SHA1-3DES 2>/dev/null \
        || die "openssl could not package the certificate (PKCS#12)."

    # -T /usr/bin/codesign pre-authorizes codesign to use the private key, so
    # signing never raises a keychain dialog. No other program is granted it.
    security import "$dir/cert.p12" -k "$KEYCHAIN" -P "$password" -T /usr/bin/codesign >/dev/null \
        || die "could not import the certificate into $KEYCHAIN."

    rm -rf "$dir"
    ok "certificate created (self-signed, 10 years, this machine only)"
}

# Newline-separated rather than an array: macOS ships bash 3.2, which has no
# `mapfile`/`readarray`. Everything here must run on the stock shell.
HASHES=$(cert_hashes)
if [ -z "$HASHES" ]; then
    create_certificate
    HASHES=$(cert_hashes)
    [ -n "$HASHES" ] || die "the certificate was created but cannot be found in $KEYCHAIN."
fi
HASH_COUNT=$(printf '%s\n' "$HASHES" | grep -c .)

if [ "$HASH_COUNT" -gt 1 ]; then
    # Two certificates with the same name make `codesign --sign "$CERT_CN"` fail
    # with "ambiguous", and the only signature that still succeeds is ad-hoc -
    # which is exactly what destroys the grants. Refuse, and say which to keep:
    # the OLDEST, since that is the one the existing grants were issued against.
    printf '\n\033[31merror\033[0m several certificates are named "%s":\n\n' "$CERT_CN" >&2
    printf '%s\n' "$HASHES" | sed 's/^/    /' >&2
    printf '\nKeep the one your grants were issued against - the OLDEST.
Check their dates with:

    security find-certificate -c "%s" -a -p "%s" | \\
      openssl storeutl -noout -text /dev/stdin | grep -E "Not Before|SHA1"

Then delete the others and run this script again:

    security delete-certificate -Z <sha1> "%s"
' "$CERT_CN" "$KEYCHAIN" "$KEYCHAIN" >&2
    exit 1
fi

IDENTITY=$(printf '%s\n' "$HASHES" | head -1)
ok "signing identity $IDENTITY"

# ------------------------------------------------------------------ install

# Stop the agent BEFORE the binary is replaced. Copying over the executable of a
# running process can corrupt its image, and launchd's KeepAlive would restart
# it mid-swap.
step "Stopping the agent"
launchctl bootout "gui/$(id -u)/$BUNDLE_ID" 2>/dev/null || true
for _ in 1 2 3 4 5 6 7 8 9 10; do
    pgrep -f "$APP/Contents/MacOS/bento" >/dev/null 2>&1 || break
    sleep 0.3
done
if pgrep -f "$APP/Contents/MacOS/bento" >/dev/null 2>&1; then
    pkill -f "$APP/Contents/MacOS/bento" 2>/dev/null || true
    sleep 1
fi
ok "stopped"

step "Installing $APP"
mkdir -p "$APP/Contents/MacOS" "$APP/Contents/Frameworks"
cp "$BIN" "$APP/Contents/MacOS/bento"

# Replaced wholesale rather than copied over: a framework is a tree of symlinks
# and a stale file left inside it fails `codesign --verify --strict`. `cp -a`
# because the symlinks ARE the structure - resolving them produces a bundle
# macOS will not load.
rm -rf "$APP/Contents/Frameworks/MediaRemoteAdapter.framework"
cp -a "$FRAMEWORK" "$APP/Contents/Frameworks/MediaRemoteAdapter.framework"

cat > "$APP/Contents/Info.plist" <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleIdentifier</key><string>$BUNDLE_ID</string>
    <key>CFBundleName</key><string>Bento</string>
    <key>CFBundleExecutable</key><string>bento</string>
    <key>CFBundlePackageType</key><string>APPL</string>
    <key>CFBundleVersion</key><string>1.0</string>
    <key>CFBundleShortVersionString</key><string>1.0</string>
    <key>LSUIElement</key><true/>
    <!-- macOS hard-CRASHES a launchd-run app that touches a TCC-protected API
         with no usage-description string (this is why it "worked" from a
         terminal but not as an agent: the terminal was the responsible process).
         The bar reads Bluetooth device state, so it needs this or it aborts. -->
    <key>NSBluetoothAlwaysUsageDescription</key><string>DankMaterialShell shows Bluetooth device status in the bar.</string>
    <key>NSAppleEventsUsageDescription</key><string>DankMaterialShell controls desktop features.</string>
    <!-- The audio visualizer (cava) captures audio input; on macOS any input
         capture (even a loopback like BlackHole) needs Microphone access. -->
    <key>NSMicrophoneUsageDescription</key><string>DankMaterialShell visualizes audio in the bar.</string>
    <key>NSDownloadsFolderUsageDescription</key><string>DankMaterialShell reads its own files, installed under Downloads.</string>
</dict>
</plist>
EOF
ok "bundle written (binary + MediaRemoteAdapter.framework)"

# Nested code first, container second. codesign will not seal a framework that
# is itself unsigned, and `--deep` is deprecated precisely because it hides
# which part failed.
#
# Sign by HASH, never by name: the name is ambiguous the moment a second
# certificate shares it, and codesign's failure mode there is to refuse.
step "Signing"
codesign --force --sign "$IDENTITY" \
    "$APP/Contents/Frameworks/MediaRemoteAdapter.framework" >/dev/null 2>&1 \
    || die "codesign failed on MediaRemoteAdapter.framework."
codesign --force --sign "$IDENTITY" --identifier "$BUNDLE_ID" "$APP" >/dev/null 2>&1 \
    || die "codesign failed with identity $IDENTITY. The app is NOT installed correctly - do not start it."

# Verify what actually landed. A signature that is ad-hoc, or carries the wrong
# identifier, or does not pin our certificate, means the grants will not survive
# - that is a hard failure, not a warning.
codesign --verify --strict "$APP" 2>/dev/null || die "the signature did not verify."
sig_info=$(codesign -dv "$APP" 2>&1)
case "$sig_info" in
    *"Signature=adhoc"*) die "the app ended up ad-hoc signed - every TCC grant would die on each rebuild." ;;
esac
case "$sig_info" in
    *"Identifier=$BUNDLE_ID"*) ;;
    *) die "the signature carries the wrong identifier (expected $BUNDLE_ID)." ;;
esac
requirement=$(codesign -d -r- "$APP" 2>&1 | grep '^designated' || true)
case "$requirement" in
    *"certificate leaf"*) ok "signature pinned to the certificate (the grants survive rebuilds)" ;;
    *) die "the designated requirement does not pin a certificate: $requirement" ;;
esac

# ------------------------------------------------------------------- launch

step "Writing the launch agent"
mkdir -p "$(dirname "$PLIST")" "$XDG_RUNTIME_DIR"
cat > "$PLIST" <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key><string>$BUNDLE_ID</string>
    <key>ProgramArguments</key>
    <array>
        <string>$APP/Contents/MacOS/bento</string>
        <string>-p</string>
        <string>$SHELL_QML</string>
    </array>
    <key>EnvironmentVariables</key>
    <dict>
        <key>DMS_SCREENSHOT_EDITOR</key><string>open -a Preview %path%</string>
        <key>DMS_SOCKET</key><string>$DMS_SOCKET</string>
        <key>NIGIRI_SOCKET</key><string>$NIRI_SOCKET</string>
        <key>NIRI_SOCKET</key><string>$NIRI_SOCKET</string>
        <key>PATH</key><string>$AGENT_PATH</string>
        <key>XDG_RUNTIME_DIR</key><string>$XDG_RUNTIME_DIR</string>
    </dict>
    <key>RunAtLoad</key><true/>
    <key>KeepAlive</key>
    <dict>
        <key>SuccessfulExit</key><false/>
    </dict>
    <key>StandardOutPath</key><string>$LOG</string>
    <key>StandardErrorPath</key><string>$LOG</string>
    <key>ProcessType</key><string>Interactive</string>
</dict>
</plist>
EOF
# KeepAlive on FAILURE only, so a crash respawns while a deliberate quit stays
# quit. NIRI_SOCKET is exported under both names because the two halves of the
# shell read different ones: the C++ NigiriIpc reads NIGIRI_SOCKET, DMS's QML
# CompositorService reads NIRI_SOCKET.
#
# Nothing here orders this agent after the compositor: launchd has no such
# primitive. The two clients handle it differently, and only one of them can.
#
#   - The C++ NigiriIpc reconnects on its own 3s heartbeat, so it needs no help.
#   - The shell's detection CANNOT recover: it fires once, 100ms after the QML
#     root loads, and latches "unknown" for the life of the process if the
#     socket is not there yet. The shell is third-party and read-only, so the
#     fix lives on our side - bento waits for $NIGIRI_SOCKET to appear before
#     loading any QML (mac/compositor.cpp, awaitCompositorSocket). That is why
#     NIGIRI_SOCKET is set here even though NIRI_SOCKET is what the shell reads:
#     setting it is what asks bento to wait at all.
ok "$PLIST"

step "Starting"
launchctl bootstrap "gui/$(id -u)" "$PLIST" \
    || die "launchctl could not start the agent. Check $LOG"

started=false
for _ in $(seq 1 20); do
    if pgrep -f "$APP/Contents/MacOS/bento" >/dev/null 2>&1; then started=true; break; fi
    sleep 0.25
done
$started || die "the agent did not come up. Check $LOG"
ok "running (log: $LOG)"

# A process that is alive but never loaded its shell is not working, and saying
# "installed" there would be a lie. The QML engine says so itself.
step "Checking the shell loaded"
loaded=false
for _ in $(seq 1 24); do
    if grep -q "Configuration Loaded" "$LOG" 2>/dev/null; then loaded=true; break; fi
    sleep 0.5
done

echo
if $loaded; then
    printf '\033[32mbento is installed and running.\033[0m\n'
    compositor=$(grep "Detected .* via\|No compositor detected" "$LOG" 2>/dev/null | tail -1 || true)
    [ -n "$compositor" ] && printf 'Compositor: %s\n' "${compositor##*] }"
else
    printf '\033[33mbento is running, but the shell has not reported loading yet.\033[0m\n'
    printf 'Check the log:\n    tail -50 %s\n' "$LOG"
fi
printf 'Shell: %s\n' "$SHELL_QML"
printf 'Re-run this script after a code change; nothing else needs it.\n'
