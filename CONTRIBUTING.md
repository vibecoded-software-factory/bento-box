# Contributing

Thanks for looking. bento-box is a port of
[quickshell](https://github.com/quickshell-mirror/quickshell) to macOS: the same
QML API, backed by AppKit instead of Wayland. **API compatibility is the
feature** — a shell written against quickshell should run unchanged — so the
rules below are mostly about not breaking that contract.

## Build and run

The macOS backend builds with the Linux backends switched off (they have no
libraries here). Qt comes from Homebrew:

```sh
brew install qt ninja
cmake -B build -G Ninja \
  -DCMAKE_PREFIX_PATH="$(brew --prefix qt)" \
  -DWAYLAND=OFF -DX11=OFF -DI3=OFF \
  -DCRASH_HANDLER=OFF -DUSE_JEMALLOC=OFF
cmake --build build

./build/src/quickshell -p /path/to/your/shell.qml
```

To see a service's own logs, enable its category, e.g.
`QT_LOGGING_RULES='quickshell.mac.*=true'`.

## The gate

Nothing lands without all three:

1. A **warning-free** build.
2. The QML **API still matches** the Linux service the module stands in for. A
   config binds to that API; if a property or signal drifts, the config breaks.
3. A **live verification**. Reading the code is not enough for a UI or service
   backend: paste what you actually observed — a screenshot of the panel, a
   service query, a log line, or a before/after measurement. The PR should say
   what you saw.

The build runs in CI. The live check is yours.

## Behaviour comes from quickshell

This is a port, not a rewrite. The ~44k lines of portable Qt keep coming from
[upstream](https://github.com/quickshell-mirror/quickshell) — the `upstream`
remote points at it; rebase, don't reinvent. Only the platform bindings under
`src/mac/` are ours. When a service exposes an API, that API is defined by the
Linux one it mirrors (D-Bus MPRIS, UPower, PipeWire, ...): match it, and cite it
when it is not obvious.

When macOS makes something impossible, that is a finding worth writing down in
[`PORT.md`](PORT.md) — but measure it first. More than one apparent limitation
turned out not to exist once someone tested it.

## Constraints that are not up for discussion

- **Public, documented APIs.** The one private framework in play (MediaRemote,
  for now-playing) is reached only through Apple's own entitled system helper,
  never linked directly. No SIP changes, no synthetic keystrokes injected into
  other apps.
- **Respect the licenses.** The project is **LGPL-3** (inherited from quickshell,
  which it contains) and cannot be relicensed. Keep upstream copyright and
  attribution intact. Vendored third-party code keeps its own license (e.g.
  `mediaremote-adapter` is BSD-3); before adding a dependency, check the license
  is compatible and preserve its notice.

## Pull requests

One change per branch, opened against `dev`:

```
feat/… · fix/… · perf/… · refactor/… · docs/… · test/… · ci/… · chore/…
```

Commit subjects and the PR title follow **Conventional Commits**
(`type(scope): subject`, at most 72 chars) — CI checks both. Merges are
squash-only, so the PR title becomes the commit that lands; write it as the
message you want in the history, and let the body explain **why**, including what
you verified. macOS code lives in `src/mac/<service>/`, one module per service.

[`AGENTS.md`](AGENTS.md) is the map of the repo — the layout, the conventions,
and how the port is structured. Read it before a non-trivial change.
