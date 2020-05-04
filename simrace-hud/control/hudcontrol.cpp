#include "hudcontrol.h"

#include <simrace-core/domain/vehicle.h>
#include <simrace-demo/handler/streamerdemohandler.h>
#include <simrace-projectcars/handler/streamerudpprojectcars2handler.h>

using simrace::demo::StreamerDemoHandler;
using simrace::projectcars::StreamerUDPProjectCars2Handler;

HudControl::HudControl(QObject *parent)
    : QObject(parent), _vehicle(new Vehicle()),
      _vehicleController(new StreamerDemoHandler(_vehicle)) {}

HudControl::~HudControl() { stop(); }

void HudControl::start() {
  emit vehicleChanged(_vehicle);
  _vehicleController.start();
}

void HudControl::stop() { _vehicleController.stop(); }
