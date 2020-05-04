#include "streamerudpprojectcars2handler.h"

#include <math.h>

#include <simrace-core/domain/engine.h>
#include <simrace-core/domain/transmission.h>
#include <simrace-core/domain/vehicle.h>

#include <simrace-projectcars/reader/streamerprojectcars2reader.h>

SIMRACE_PROJECTCARS_NAMEPACE_BEGIN

StreamerUDPProjectCars2Handler::StreamerUDPProjectCars2Handler(Vehicle *vehicle,
                                                               QObject *parent)
    : StreamerUDPHandler(vehicle, new StreamerProjectCars2Reader(),
                         SMS_UDP_PORT, parent) {

  memset(&_packetHeader, 0, sizeof(PacketBase));
  memset(&_telemetry, 0, sizeof(sTelemetryData));
}

void StreamerUDPProjectCars2Handler::read(const QByteArray &data) {

  memcpy(&_packetHeader, data.data(), sizeof(PacketBase));

  switch (_packetHeader.mPacketType) {
  case eCarPhysics:
    memcpy(&_telemetry, data.data(), sizeof(sParticipantsData));
  }

  vehicle()->setSpeed(_telemetry.sSpeed * 3.6);
  vehicle()->engine()->setRpm(_telemetry.sRpm);
  vehicle()->engine()->setMaxRpm(_telemetry.sMaxRpm);
  vehicle()->engine()->setMaxDisplayRpm(
      round((_telemetry.sMaxRpm + 1000) / 1000) * 100);
  switch (_telemetry.sGearNumGears) {
  case 96:
    vehicle()->transmission()->setGear('N');
    break;
  case 111:
    vehicle()->transmission()->setGear('R');
    break;
  default:
    vehicle()->transmission()->setGear(_telemetry.sGearNumGears - 48);
    break;
  }
}

SIMRACE_PROJECTCARS_NAMEPACE_END
