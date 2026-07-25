# Shadows on macOS: two of them, and only one is a bug

Panels here can end up with **two** shadows stacked. They look similar at a
glance and they are not the same thing. Diagnosing one as the other cost a
whole session, so this is written down.

| | What it is | Shape | Verdict |
|---|---|---|---|
| **1. Window shadow** | macOS/AppKit draws it for the `NSWindow` | **Square**, 90° outer corners, ignores the rounded content | **A bug. Fixed in `src/mac/bridge.mm`** |
| **2. Elevation shadow** | The shell draws it in QML (DankCommon's elevation shader) | Follows the panel's rounded corners | **Not a bug.** Upstream behaviour, a user preference |

## 1. The window shadow — the square black frame

AppKit derives a window's shadow from the **alpha mask of its surface**, and on
a borderless transparent window it keeps the shape captured at the **first
paint**. `-[NSWindow invalidateShadow]` has not reliably rebuilt it since 10.12
([rdar://27121204](https://github.com/lionheart/openradar-mirror/issues/15223)).

A panel that draws a rounded rectangle inside a square surface therefore wears
the **square** shadow for the rest of its life: a dark band whose outer corners
are 90° while the body it hugs is rounded. That is the "black frame around
every popout" symptom, and the square corner is its signature — a legitimate
shadow always follows the shape it belongs to.

`configurePanelWindow` (`src/mac/bridge.mm`) now sets `nsWindow.hasShadow = NO`
for every panel surface. Nothing is lost: a wlr-layer-shell surface gets no
compositor-drawn shadow either, so upstream never had one.

**Do not re-enable it.** If a panel ever needs a shadow, it belongs in QML,
where the geometry is known.

## 2. The elevation shadow — expected, and a preference

With #1 removed, the shell's own Material 3 elevation shadow becomes visible
for the first time. It was always being drawn; the square one simply dominated
it. Symptoms of *this* one:

- a soft, monotonic darkening of roughly 6–15 px around the panel
- it **follows the rounded corners**
- measured across the boundary, no pixel is darker than the panel's own fill —
  the falloff goes wallpaper → panel with no dark minimum in between

That last point is the cheap test. A square window shadow produces a band
**darker than both** the backdrop and the panel; an elevation shadow does not.

It is controlled entirely from the shell's settings, and defaults to on
upstream:

```
m3ElevationEnabled              # the global gate - everything below reads it
m3ElevationOpacity              # default 30
m3ElevationIntensity            # default 12
m3ElevationLightDirection       # default "top"
popoutElevationEnabled          # per-surface
modalElevationEnabled
notificationPopupShadowEnabled
barElevationEnabled
```

Note the per-surface flags all hang off `Theme.elevationEnabled`, which reads
the global — so turning individual ones off while the global is on only affects
those surfaces, and turning the global off overrides all of them. That
asymmetry is why the effect can look "fixed on some panels and not others"
while a change is only half applied.

**These live in the user's settings file, not in this repository.** Resetting
or reinstalling the shell's configuration restores the upstream default (on).
That is not a regression.

## Do not put comments in `settings.json`

It is plain JSON, and the shell rewrites the whole file from its QML properties
on every settings change (`SettingsData.qml`, `saveSettings()` →
`JSON.stringify(Store.toJson(root))`). Any key that is not a known property is
silently dropped on the next write. Document behaviour here instead.
