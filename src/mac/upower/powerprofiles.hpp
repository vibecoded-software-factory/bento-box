#pragma once

#include <utility>

#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>

namespace qs::mac::upower {

///! Power profile exposed by the PowerProfiles service.
/// See @@PowerProfiles.
class PowerProfile: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		/// This profile will limit system performance in order to save power.
		PowerSaver = 0,
		/// This profile is the default, and will attempt to strike a balance
		/// between performance and power consumption.
		Balanced = 1,
		/// This profile will maximize performance at the cost of power consumption.
		Performance = 2,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::upower::PowerProfile::Enum profile);
};

///! Reason for performance degradation exposed by the PowerProfiles service.
/// See @@PowerProfiles.degradationReason for more information.
class PerformanceDegradationReason: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		/// Performance has not been degraded in a way power-profiles-daemon can detect.
		None = 0,
		/// Performance has been reduced due to the computer's lap detection function,
		/// which attempts to keep the computer from getting too hot while on your lap.
		LapDetected = 1,
		/// Performance has been reduced due to high system temperatures.
		HighTemperature = 2,
	};
	Q_ENUM(Enum);

	// clang-format off
	Q_INVOKABLE static QString toString(qs::mac::upower::PerformanceDegradationReason::Enum reason);
	// clang-format on
};

// Same value type as upstream's powerProfileHold; on macOS the holds list is
// always empty (macOS has no application profile holds), but the type must
// exist so bindings and role lookups resolve.
class PowerProfileHold {
	Q_GADGET;
	QML_VALUE_TYPE(powerProfileHold);
	Q_PROPERTY(qs::mac::upower::PowerProfile::Enum profile MEMBER profile CONSTANT);
	Q_PROPERTY(QString applicationId MEMBER applicationId CONSTANT);
	Q_PROPERTY(QString reason MEMBER reason CONSTANT);

public:
	explicit PowerProfileHold() = default;
	explicit PowerProfileHold(PowerProfile::Enum profile, QString applicationId, QString reason)
	    : profile(profile)
	    , applicationId(std::move(applicationId))
	    , reason(std::move(reason)) {}

	PowerProfile::Enum profile = PowerProfile::Balanced;
	QString applicationId;
	QString reason;

	[[nodiscard]] bool operator==(const PowerProfileHold& other) const;
};

QDebug& operator<<(QDebug& debug, const PowerProfileHold& hold);

///! Provides access to the Power Profiles service.
/// The macOS counterpart of the Linux power-profiles-daemon interface, backed
/// by `NSProcessInfo`. Same QML surface, honestly mapped:
///
/// - @@profile is `PowerSaver` while macOS Low Power Mode is enabled and
///   `Balanced` otherwise, tracking the system live. It cannot be SET from
///   here: macOS offers no public API to switch Low Power Mode (only the
///   Settings app and root-only `pmset`), so writes log an error like
///   upstream does when power-profiles-daemon is unreachable.
/// - @@hasPerformanceProfile is always false (macOS has no performance
///   profile), which also makes upstream's own "cannot request performance
///   profile" refusal apply verbatim.
/// - @@degradationReason maps the system thermal state: `serious` or worse
///   means macOS is throttling for heat, which is exactly upstream's
///   `HighTemperature`. `LapDetected` cannot occur.
/// - @@holds is always empty (no application profile holds on macOS).
class PowerProfilesQml: public QObject {
	Q_OBJECT;
	QML_NAMED_ELEMENT(PowerProfiles);
	QML_SINGLETON;
	// clang-format off
	/// The current power profile.
	///
	/// This property may be set to change the system's power profile, however
	/// it cannot be set to `Performance` unless @@hasPerformanceProfile is true.
	/// (On macOS the write is refused with an error: Low Power Mode has no
	/// public setter.)
	Q_PROPERTY(qs::mac::upower::PowerProfile::Enum profile READ default WRITE setProfile NOTIFY profileChanged BINDABLE bindableProfile);
	/// If the system has a performance profile. Always false on macOS.
	Q_PROPERTY(bool hasPerformanceProfile READ default NOTIFY hasPerformanceProfileChanged BINDABLE bindableHasPerformanceProfile);
	/// If the system detects degraded performance, the reason for the
	/// degradation will be present here. On macOS this reflects the thermal
	/// state: `HighTemperature` while the system is thermally throttling.
	Q_PROPERTY(qs::mac::upower::PerformanceDegradationReason::Enum degradationReason READ default NOTIFY degradationReasonChanged BINDABLE bindableDegradationReason);
	/// Power profile holds created by other applications. Always empty on
	/// macOS (there is no hold mechanism).
	Q_PROPERTY(QList<qs::mac::upower::PowerProfileHold> holds READ default NOTIFY holdsChanged BINDABLE bindableHolds);
	// clang-format on

signals:
	void profileChanged();
	void hasPerformanceProfileChanged();
	void degradationReasonChanged();
	void holdsChanged();

public:
	explicit PowerProfilesQml(QObject* parent = nullptr);
	~PowerProfilesQml() override;
	Q_DISABLE_COPY_MOVE(PowerProfilesQml);

	[[nodiscard]] QBindable<PowerProfile::Enum> bindableProfile() const { return &this->bProfile; }

	static void setProfile(PowerProfile::Enum profile);

	[[nodiscard]] QBindable<bool> bindableHasPerformanceProfile() const {
		return &this->bHasPerformanceProfile;
	}

	[[nodiscard]] QBindable<PerformanceDegradationReason::Enum> bindableDegradationReason() const {
		return &this->bDegradationReason;
	}

	[[nodiscard]] QBindable<QList<PowerProfileHold>> bindableHolds() const { return &this->bHolds; }

private:
	void refresh();

	// Opaque tokens for the two NSNotificationCenter observers.
	void* mPowerStateObserver = nullptr;
	void* mThermalStateObserver = nullptr;

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(PowerProfilesQml, PowerProfile::Enum, bProfile, PowerProfile::Balanced, &PowerProfilesQml::profileChanged);
	Q_OBJECT_BINDABLE_PROPERTY(PowerProfilesQml, bool, bHasPerformanceProfile, &PowerProfilesQml::hasPerformanceProfileChanged);
	Q_OBJECT_BINDABLE_PROPERTY(PowerProfilesQml, PerformanceDegradationReason::Enum, bDegradationReason, &PowerProfilesQml::degradationReasonChanged);
	Q_OBJECT_BINDABLE_PROPERTY(PowerProfilesQml, QList<PowerProfileHold>, bHolds, &PowerProfilesQml::holdsChanged);
	// clang-format on
};

} // namespace qs::mac::upower
