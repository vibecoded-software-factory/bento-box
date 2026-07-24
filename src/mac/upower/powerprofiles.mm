#include "powerprofiles.hpp"

#import <Foundation/Foundation.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qloggingcategory.h>

namespace qs::mac::upower {

namespace {
Q_LOGGING_CATEGORY(logPowerProfiles, "quickshell.service.powerprofiles", QtWarningMsg);
}

QString PowerProfile::toString(PowerProfile::Enum profile) {
	switch (profile) {
	case PowerProfile::PowerSaver: return QStringLiteral("PowerSaver");
	case PowerProfile::Balanced: return QStringLiteral("Balanced");
	case PowerProfile::Performance: return QStringLiteral("Performance");
	default: return QStringLiteral("Invalid");
	}
}

QString PerformanceDegradationReason::toString(PerformanceDegradationReason::Enum reason) {
	switch (reason) {
	case PerformanceDegradationReason::LapDetected: return QStringLiteral("LapDetected");
	case PerformanceDegradationReason::HighTemperature: return QStringLiteral("HighTemperature");
	default: return QStringLiteral("Invalid");
	}
}

bool PowerProfileHold::operator==(const PowerProfileHold& other) const {
	return other.profile == this->profile && other.applicationId == this->applicationId
	    && other.reason == this->reason;
}

QDebug& operator<<(QDebug& debug, const PowerProfileHold& hold) {
	auto saver = QDebugStateSaver(debug);
	debug.nospace() << "PowerProfileHold(profile=" << PowerProfile::toString(hold.profile)
	                << ", applicationId=" << hold.applicationId << ", reason=" << hold.reason << ")";
	return debug;
}

PowerProfilesQml::PowerProfilesQml(QObject* parent): QObject(parent) {
	this->refresh();

	auto* center = NSNotificationCenter.defaultCenter;
	// The blocks hop to the main queue, and refresh() only touches bindable
	// properties owned by this object - same thread as QML reads them.
	this->mPowerStateObserver = (__bridge_retained void*) [center
	    addObserverForName:NSProcessInfoPowerStateDidChangeNotification
	                object:nil
	                 queue:NSOperationQueue.mainQueue
	            usingBlock:^(NSNotification*) { this->refresh(); }];
	this->mThermalStateObserver = (__bridge_retained void*) [center
	    addObserverForName:NSProcessInfoThermalStateDidChangeNotification
	                object:nil
	                 queue:NSOperationQueue.mainQueue
	            usingBlock:^(NSNotification*) { this->refresh(); }];
}

PowerProfilesQml::~PowerProfilesQml() {
	auto* center = NSNotificationCenter.defaultCenter;
	if (this->mPowerStateObserver != nullptr) {
		[center removeObserver:(__bridge_transfer id) this->mPowerStateObserver];
	}
	if (this->mThermalStateObserver != nullptr) {
		[center removeObserver:(__bridge_transfer id) this->mThermalStateObserver];
	}
}

void PowerProfilesQml::refresh() {
	auto* info = NSProcessInfo.processInfo;

	// Low Power Mode IS macOS's power-saver profile; there is no third state,
	// so everything else is Balanced (hasPerformanceProfile stays false).
	this->bProfile = info.lowPowerModeEnabled ? PowerProfile::PowerSaver : PowerProfile::Balanced;

	// Thermal state `serious` or worse means macOS is actively reducing
	// performance for heat - upstream's HighTemperature, semantics intact.
	// (`LapDetected` has no macOS signal and can never occur.)
	auto throttling = info.thermalState >= NSProcessInfoThermalStateSerious;
	this->bDegradationReason = throttling ? PerformanceDegradationReason::HighTemperature
	                                      : PerformanceDegradationReason::None;
}

void PowerProfilesQml::setProfile(PowerProfile::Enum profile) {
	// Mirrors upstream's own refusals (powerprofiles.cpp:106-118): the
	// performance guard is upstream's verbatim; the rest is macOS's honest
	// limit - Low Power Mode has no public setter (Settings.app or root-only
	// `pmset -a lowpowermode` are the only writers).
	if (profile == PowerProfile::Performance) {
		qCCritical(
		    logPowerProfiles
		) << "Cannot request performance profile as it is not present for this device.";
		return;
	}

	qCCritical(
	    logPowerProfiles
	) << "Cannot set power profile: macOS offers no public API to change Low Power Mode "
	     "(use System Settings > Battery).";
}

} // namespace qs::mac::upower
