#ifndef VEHICLECONTROLLER_H
#define VEHICLECONTROLLER_H

#include <simrace-core/simrace-core_global.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class StreamerHandler;
class VehicleController {
public:
  VehicleController(StreamerHandler *handler);

  void start();
  void stop();

private:
  StreamerHandler *_handler = nullptr;
};

SIMRACE_CORE_NAMEPACE_END

#endif // VEHICLECONTROLLER_H
