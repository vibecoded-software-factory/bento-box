#include "notifications.hpp"

#include <qstring.h>

namespace qs::mac::notifications {

QString NotificationUrgency::toString(NotificationUrgency::Enum value) {
	switch (value) {
	case Low: return "Low";
	case Normal: return "Normal";
	case Critical: return "Critical";
	default: return "Unknown";
	}
}

QString NotificationCloseReason::toString(NotificationCloseReason::Enum value) {
	switch (value) {
	case Expired: return "Expired";
	case Dismissed: return "Dismissed";
	case CloseRequested: return "CloseRequested";
	default: return "Unknown";
	}
}

} // namespace qs::mac::notifications
