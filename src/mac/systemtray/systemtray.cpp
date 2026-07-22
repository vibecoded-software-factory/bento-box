#include "systemtray.hpp"

namespace qs::mac::systemtray {

// No-ops: with no items to act on, these exist only for API compatibility.
void SystemTrayItem::scroll(qint32 /*delta*/, bool /*horizontal*/) const {}
void SystemTrayItem::
    display(QObject* /*parentWindow*/, qint32 /*relativeX*/, qint32 /*relativeY*/) {}

} // namespace qs::mac::systemtray
