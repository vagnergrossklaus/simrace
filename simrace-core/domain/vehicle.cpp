#include "vehicle.h"

#include "engine.h"
#include "transmission.h"

SIMRACE_CORE_NAMEPACE_BEGIN

Vehicle::Vehicle(QObject *parent)
    : QObject(parent), _engine(new Engine()),
      _transmission(new Transmission()) {}

int Vehicle::speed() const { return _speed; }

void Vehicle::setSpeed(int speed) {
  _speed = speed;
  emit speedChanged();
}

Engine *Vehicle::engine() const { return _engine; }

void Vehicle::setEngine(Engine *engine) {
  _engine = engine;
  emit engineChanged();
}

Transmission *Vehicle::transmission() const { return _transmission; }

void Vehicle::setTransmission(Transmission *transmission) {
  _transmission = transmission;
  emit transmissionChanged();
}

float Vehicle::fuel() const { return _fuel; }

void Vehicle::setFuel(float fuel) {
  _fuel = fuel;
  emit fuelChanged();
}

SIMRACE_CORE_NAMEPACE_END
