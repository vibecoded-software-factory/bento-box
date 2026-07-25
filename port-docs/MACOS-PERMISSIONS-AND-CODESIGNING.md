# macOS permissions and code signing — how not to break the user's desktop

Read this **before** replacing the binary of any app that holds a TCC grant
(Accessibility, Screen Recording, Input Monitoring). Both `Nigiri.app` and
`Bento.app` do.

This document exists because an agent broke both grants, put the user in a
permission-prompt loop for an hour, and gave them the wrong pane to fix it.
Every rule below is written from that failure.

---

## The one thing to understand

**macOS keys a TCC grant to the app's code signature, not to its path.**

Replace the executable inside a `.app` and the bundle's signature is void, so
the app must be re-signed. If you re-sign with a *different identity than
before*, macOS sees a different app, and **every permission the user had
granted is silently gone**.

`codesign --sign -` (ad-hoc) produces a **new identity every single time**. So
ad-hoc signing means the grant dies on every rebuild, forever.

---

## Rule 1 — never ad-hoc sign an app that holds a grant

Both apps have a dedicated self-signed certificate in the login keychain:

| App | Identity | Bundle identifier |
|---|---|---|
| `~/Applications/Nigiri.app` | `nigiri codesign` | `dev.nigiri` |
| `~/Applications/Bento.app` | `bento codesign` | `dev.bento` |

Always sign with those:

```sh
codesign --force --sign "nigiri codesign" --identifier dev.nigiri ~/Applications/Nigiri.app
codesign --force --sign "bento codesign"  --identifier dev.bento  ~/Applications/Bento.app
```

`nigiri/scripts/install.sh` already does this and falls back to ad-hoc with a
warning when the certificate is missing. **If you see that warning, stop and
create the certificate — do not proceed with the ad-hoc fallback.** bento has
no equivalent script; sign it by hand with the command above.

## Rule 2 — check for identities the right way

```sh
security find-identity -v -p codesigning     # correct
security find-identity -v                    # WRONG - different policy, can print "0 valid identities"
```

The agent that caused this incident ran the second form, read "0 valid
identities found", concluded the certificates did not exist, and ad-hoc signed
on top of two perfectly good certificates that were sitting right there.
**Always pass `-p codesigning`.**

## Rule 3 — creating the certificate, if it really is missing

Two non-obvious failures will bite you, both of them silent-ish:

1. OpenSSL 3 writes PKCS#12 files that macOS's `security import` rejects.
   Pass `-legacy -macalg sha1 -keypbe PBE-SHA1-3DES -certpbe PBE-SHA1-3DES`.
2. `security import` fails on an **empty** p12 password with the misleading
   error `MAC verification failed during PKCS12 import (wrong password?)`.
   Use a real password.

```sh
cd "$(mktemp -d)"
openssl req -x509 -newkey rsa:2048 -keyout cs.key -out cs.crt -days 3650 -nodes \
  -subj "/CN=bento codesign" \
  -addext "basicConstraints=critical,CA:false" \
  -addext "keyUsage=critical,digitalSignature" \
  -addext "extendedKeyUsage=critical,codeSigning"

openssl pkcs12 -export -out cs.p12 -inkey cs.key -in cs.crt \
  -name "bento codesign" -passout pass:CHANGEME \
  -legacy -macalg sha1 -keypbe PBE-SHA1-3DES -certpbe PBE-SHA1-3DES

security import cs.p12 -k ~/Library/Keychains/login.keychain-db \
  -P CHANGEME -T /usr/bin/codesign -A

security add-trusted-cert -r trustRoot -p codeSign \
  -k ~/Library/Keychains/login.keychain-db cs.crt

security find-identity -v -p codesigning        # must now list it
```

The certificate is created **once** and then reused for the life of the
machine. Creating a second certificate with the same common name does not
help and makes `find-identity` ambiguous.

## Rule 4 — you cannot grant TCC from code. Do not try.

The database is protected by SIP. `tccutil` can only **reset** permissions,
never grant them. Full Disk Access does not change this. There is no API, no
plist, no defaults key. **A human must click the toggle.** Design the workflow
around that fact instead of burning the user's time discovering it.

What you *can* do is make it necessary only once — which is exactly what Rule 1
buys you.

## Rule 5 — know which pane you are asking for

They are separate lists and granting one does nothing for the other.

| Prompt / symptom | Pane | URL to open it |
|---|---|---|
| `universalAccessAuthWarn` process appears | **Accessibility** | `x-apple.systempreferences:com.apple.preference.security?Privacy_Accessibility` |
| "would like to record this computer's screen and audio" | **Screen Recording** | `x-apple.systempreferences:com.apple.preference.security?Privacy_ScreenCapture` |

`universalAccessAuthWarn` is the **Accessibility** prompt — the name comes from
the UniversalAccess framework and says nothing about screen recording. Identify
the pane from the running process, not from a guess.

Which app needs what here:

- **nigiri** — Accessibility (moves other apps' windows; without it nothing
  works). Screen Recording only for the overview's live previews.
- **bento** — Screen Recording. Accessibility only for the keyboard grab.

To find out whether an app actually has Accessibility, ask it to do something
that requires it rather than reading the GUI:

```sh
nigiri msg windows          # returns windows  => nigiri has Accessibility
```

## Rule 6 — a stale entry must be removed, not re-ticked

After the signature changes, the existing row in the list is bound to the old
identity and **ticking it does nothing**. Tell the user to select it, press
`−`, then `+`, and re-add the bundle path. Re-adding without removing leaves
the dead entry in charge and the prompt keeps coming back.

## Rule 7 — killing the process does not stop the prompt

Both apps run under launchd with `KeepAlive`. `kill` / `pkill` just makes
launchd respawn them a second later, they ask for the permission again, and the
dialog returns — which reads to the user as the prompt being unkillable.

```sh
U=$(id -u)
launchctl bootout   gui/$U/dev.bento                                   # stop for real
launchctl bootstrap gui/$U ~/Library/LaunchAgents/dev.bento.plist      # start again
```

Use `bootout` whenever you need the app to stay down. `dev.nigiri` is the same.

## Rule 8 — order of operations when swapping a binary

1. `launchctl bootout` the agent.
2. Copy the new binary in. **Build the same configuration that is installed** —
   check the size first; `build/` is debug and roughly 4x the size of
   `build-release/`.
3. Re-sign with the app's own identity (Rule 1).
4. `launchctl bootstrap` the agent.
5. Verify it actually renders before doing anything else: a process that is
   alive but owns no windows is a broken build, not a slow start.

```sh
# does it own anything on screen?
osascript -e 'tell application "System Events" to return name of every process' >/dev/null
```

## Rule 9 — if the user is stuck in a prompt loop, stop everything first

Frustration compounds. `bootout` the agent, kill the dialog, confirm both are
gone, and *only then* explain. Do not keep investigating while a modal dialog
is stealing the user's focus every few seconds.

```sh
U=$(id -u)
launchctl bootout gui/$U/dev.bento
pkill -9 -f universalAccessAuthWarn
```

---

## Post-incident checklist

- [ ] `security find-identity -v -p codesigning` lists `nigiri codesign` and `bento codesign`
- [ ] `codesign -dv ~/Applications/Nigiri.app` does **not** say `Signature=adhoc`
- [ ] `codesign -dv ~/Applications/Bento.app` does **not** say `Signature=adhoc`
- [ ] `nigiri msg windows` returns windows
- [ ] bento owns windows on screen (the bar is visible)
- [ ] no `universalAccessAuthWarn` process is running
