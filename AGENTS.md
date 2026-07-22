# AGENTS.md

Instructions for any coding agent working in this repository.

**Read [`PORT.md`](PORT.md) before touching anything.** It is the map: the
milestones, the Wayland→macOS mapping, and — for every service already ported —
exactly what was implemented, what macOS cannot do, and what was verified. It is
not a summary; it exists so an agent that reads only these two files still has
the rules that never bend.

Everything that ships is in **English**: code, comments, commit messages,
documentation.

## The rules that do not bend

1. **Never fake a result.** Do not call anything done, working, tested or at
   parity unless you just checked. If you did not run it, say so plainly. A
   truthful "I have not verified this" always beats a confident false "it
   works". The user must never be the one who discovers a claim was false.

2. **Verification here means logs or numbers, not reading code.** A ported
   service is verified by running the built `quickshell` against a small QML
   config that dumps the properties, and comparing them to ground truth from the
   OS (`pmset -g batt`, `osascript … volume`, `system_profiler SPBluetoothDataType`,
   the real now-playing). A change is proven by that comparison, with its before
   and after — never by "the code looks right".

3. **quickshell's API is the specification.** The whole point of the port is
   that [DankMaterialShell](https://github.com/AvengeMedia/DankMaterialShell)
   binds unchanged, so **API compatibility is the feature**. A macOS service
   must expose the *same* QML surface (element names, property names, enums,
   method signatures) as its Linux counterpart under `src/services/` — read that
   header first and mirror it. Changing the surface costs a rewrite of the shell
   and is not allowed without a reason that is written down.

4. **Be honest about what macOS cannot do.** When a platform has no equivalent
   for a Linux capability (a system tray others publish, per-device bluetooth
   battery, pipewire's link graph), expose the property for binding
   compatibility but make it inert, and say so in a comment and in `PORT.md`. A
   truthful stub beats a fake value.

5. **Respect the licenses.** This project is **LGPL 3** (inherited from
   quickshell — it contains quickshell's code and cannot be relicensed). Keep
   upstream copyright and attribution intact. Vendored third-party code keeps
   its own license and attribution (e.g. `mediaremote-adapter` is BSD-3); before
   adding any dependency, check its license is compatible and preserve its
   notice.

## Working in this repo

- **Never commit to `dev` or `main` directly.** One branch and one PR per
  change. Merges are **squash-only**, so the PR title becomes the commit that
  lands — it must follow **Conventional Commits** (`feat(macos): …`,
  `fix(macos): …`, `docs(port): …`), subject ≤ 72 chars. Merge when CI is green,
  then delete the branch.
- macOS code lives in `src/mac/<service>/`; each service is its own
  `qt_add_qml_module` registering the same URI the Linux module uses. Linux/DBus
  services stay switched off in the macOS build (`SERVICE_* OFF`), so there is no
  clash.
- Keep the build **warning-free**.
- `upstream` points at quickshell. Portable Qt keeps coming from there; rebase,
  don't reinvent.
