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

SIMRACE_CORE_NAMEPACE_END
