#include "engine.h"

SIMRACE_CORE_NAMEPACE_BEGIN

Engine::Engine(QObject *parent) : QObject(parent) {}

int Engine::rpm() const { return _rpm; }

void Engine::setRpm(int rpm) {
  _rpm = rpm;
  emit rpmChanged();
}

int Engine::maxRpm() const { return _maxRpm; }

void Engine::setMaxRpm(int maxRpm) {
  _maxRpm = maxRpm;
  emit maxRpmChanged();
}

int Engine::maxDisplayRpm() const { return _maxDisplayRpm; }

void Engine::setMaxDisplayRpm(int maxDisplayRpm) {
  _maxDisplayRpm = maxDisplayRpm;
  emit maxDisplayRpmChanged();
}

float Engine::oilPressure() const { return _oilPressure; }

void Engine::setOilPressure(float oilPressure) {
  _oilPressure = oilPressure;
  emit oilPressureChanged();
}

float Engine::oilTemperature() const { return _oilTemperature; }

void Engine::setOilTemperature(float oilTemperature) {
  _oilTemperature = oilTemperature;
  emit oilPressureChanged();
}

SIMRACE_CORE_NAMEPACE_END
