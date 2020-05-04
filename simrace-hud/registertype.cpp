#include "registertype.h"

#include <QQmlEngine>

#include <simrace-core/domain/engine.h>
#include <simrace-core/domain/transmission.h>
#include <simrace-core/domain/vehicle.h>

#include "control/hudcontrol.h"

using simrace::core::Engine;
using simrace::core::Transmission;
using simrace::core::Vehicle;

RegisterType::RegisterType() {}

void RegisterType::registerType() {
  qmlRegisterType<Engine>("Simrace.Core.Domain.Engine", 1, 0, "Engine");
  qmlRegisterType<Vehicle>("Simrace.Core.Domain.Vehicle", 1, 0, "Vehicle");
  qmlRegisterType<Transmission>("Simrace.Core.Domain.Transmission", 1, 0,
                                "Transmission");
  qmlRegisterType<HudControl>("HudControl", 1, 0, "HudControl");

  qRegisterMetaType<Engine *>("Engine*");
  qRegisterMetaType<Transmission *>("Transmission*");
  qRegisterMetaType<Vehicle *>("Vehicle*");
}
