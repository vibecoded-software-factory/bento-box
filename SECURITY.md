# Security

bento-box is a desktop shell backend: it reads media, audio, and Bluetooth state
from the system and renders panels. The most sensitive part is how it reads
now-playing media — through an entitled system helper — so a flaw there is worth
reporting carefully.

## Reporting a vulnerability

Please report privately, not as a public issue:

- **[Open a private security advisory](https://github.com/vibecoded-software-factory/bento-box/security/advisories/new)**
  on this repository.

Please include the macOS version, what bento was doing, and the smallest
reproduction you have. You will get an acknowledgement; this is a small project,
so please allow for a human response time rather than an SLA.

## Scope

Things that would count:

- Anything that lets code outside bento use the entitled MediaRemote helper, or
  that widens what that helper reaches beyond reading now-playing metadata.
- Now-playing content, audio/Bluetooth device data, or captured album art
  leaving the process, being written somewhere world-readable, or outliving the
  panel that needed it.
- The compositor control socket accepting instructions from somewhere it
  shouldn't, or exposing state beyond the local user.
- A config (QML) being turned into privilege it should not have through a
  platform binding.

Things that are working as designed:

- The Mpris backend reads now-playing metadata and writes album art to a
  per-user temporary file so a panel can display it. The file is the artwork the
  system already exposes to the now-playing UI.
- The audio backend can change the default input/output device — that is what a
  volume/output control does.
- bento talks to a local tiling compositor over a Unix socket to request
  reserved screen space. The socket is the user's own session.

## What bento deliberately does not do

- **No private frameworks linked directly.** MediaRemote is reached only through
  Apple's own signed, entitled `perl`, loading a compiled adapter — bento never
  carries the entitlement itself. No SkyLight/CGS symbols, no SIP changes.
- **No synthetic keystrokes** injected into other applications.
- **No network access, and no telemetry.**
- **No unvetted dependencies:** upstream quickshell (LGPL-3) and a small vendored
  BSD-3 adapter, nothing else beyond Apple's SDK and Qt.
