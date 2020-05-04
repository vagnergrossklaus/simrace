#include "vehiclecontroller.h"

#include <simrace-core/handler/streamerhandler.h>

SIMRACE_CORE_NAMEPACE_BEGIN

VehicleController::VehicleController(StreamerHandler *handler)
    : _handler(handler) {}

void VehicleController::start() { _handler->start(); }

void VehicleController::stop() { _handler->stop(); }

SIMRACE_CORE_NAMEPACE_END
