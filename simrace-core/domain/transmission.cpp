#include "transmission.h"

SIMRACE_CORE_NAMEPACE_BEGIN

Transmission::Transmission(QObject *parent) : QObject(parent) {}

QChar Transmission::gear() const { return _gear; }

void Transmission::setGear(QChar gear) {
  _gear = gear;
  emit gearChanged();
}

int Transmission::gears() const { return _gears; }

void Transmission::setGears(int gears) { _gears = gears; }

SIMRACE_CORE_NAMEPACE_END
