#ifndef STREAMERUDPPROJECTCARS2HANDLER_H
#define STREAMERUDPPROJECTCARS2HANDLER_H

#include <simrace-projectcars/simrace-projectcars_global.h>

#include <simrace-core/handler/udp/streamerudphandler.h>

#include <simrace-projectcars/SMS_UDP_Definitions.hpp>

using simrace::core::StreamerUDPHandler;
using simrace::core::Vehicle;

SIMRACE_PROJECTCARS_NAMEPACE_BEGIN

class StreamerUDPProjectCars2Handler : public StreamerUDPHandler {
public:
  StreamerUDPProjectCars2Handler(Vehicle *vehicle, QObject *parent = nullptr);

  void read(const QByteArray &data) override;

private:
  PacketBase _packetHeader;
  sTelemetryData _telemetry;
};

SIMRACE_PROJECTCARS_NAMEPACE_END

#endif // STREAMERUDPPROJECTCARS2HANDLER_H
