## What and why

<!-- What changes, and the reason. If it adds or changes a service, say which
     quickshell/Linux API it mirrors - this is a port, and the API is what
     existing configs bind to. -->

## How it was verified

<!-- Reading the code is not enough for a UI/service backend. Paste what you
     actually observed: a screenshot of the panel, a service query, a log line
     with the relevant logging category on, or a before/after measurement. -->

- [ ] Builds clean (`cmake --build build`, macOS backend)
- [ ] Checked live on the real desktop (say what you saw, above)
- [ ] The QML API still matches the Linux service it stands in for
- [ ] License headers / vendored-dependency licenses respected (LGPL-3 core)
