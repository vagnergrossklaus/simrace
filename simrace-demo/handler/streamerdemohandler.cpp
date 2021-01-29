#include "streamerdemohandler.h"

#include <simrace-core/domain/engine.h>
#include <simrace-core/domain/transmission.h>
#include <simrace-core/domain/vehicle.h>

#include <simrace-demo/reader/streamerdemoreader.h>

SIMRACE_DEMO_NAMEPACE_BEGIN

StreamerDemoHandler::StreamerDemoHandler(Vehicle *vehicle, QObject *parent)
    : StreamerHandler(vehicle, new StreamerDemoReader(), parent) {
  QObject::connect(&_timer, &QTimer::timeout, this,
                   &StreamerDemoHandler::onTimeout);
  _gear = 0;
  _rpm = 1500;
  _speed = 0;
  _fuel = 50.0;

  _random.securelySeeded();
}

void StreamerDemoHandler::start() {
  read("");
  _timer.start(500);
}

void StreamerDemoHandler::stop() { _timer.stop(); }

void StreamerDemoHandler::read(const QByteArray & /*data*/) {
  vehicle()->setSpeed(_speed);
  vehicle()->setFuel(_fuel);
  vehicle()->engine()->setRpm(_rpm);
  vehicle()->engine()->setMaxRpm(8000);
  vehicle()->engine()->setOilPressure(1);
  vehicle()->transmission()->setGear(QString::number(_gear).at(0));
  vehicle()->transmission()->setGears(6);
}

void StreamerDemoHandler::onTimeout() {
  if (_gear == _gearTarget || _gear < 1 ||
      _gear > vehicle()->transmission()->gears()) {
    do {
      _gearTarget = _random.bounded(vehicle()->transmission()->gears()) + 1;
    } while (_gear == _gearTarget);
    _throttle = _gear < _gearTarget;
    _breake = _gear > _gearTarget;
  }

  if (_throttle && _gear < _gearTarget) {
    _rpm += 1000;
    _speed += 10;
    if (_rpm > vehicle()->engine()->maxRpm()) {
      _gear += 1;
      _rpm = 5000;
    }
  } else if (_breake && _gear > _gearTarget) {
    _rpm -= 2000;
    _speed -= 20;
    if (_rpm < 3000) {
      _gear -= 1;
      _rpm = vehicle()->engine()->maxRpm() - 1000;
    }
  }

  _gear = _gear < 1 ? 1
          : _gear > vehicle()->transmission()->gears()
              ? vehicle()->transmission()->gears()
              : _gear;

  _rpm = _rpm < 1500                            ? 1500
         : _rpm > vehicle()->engine()->maxRpm() ? vehicle()->engine()->maxRpm()
                                                : _rpm;

  _speed = _speed < 20 ? 20 : _speed;

  if (_fuel > 0) {
    _fuel -= 0.0000001 * _rpm;
    _fuel = qMax(_fuel, 0.0f);
  } else {
    _rpm = 0;
    _speed = 0;
    _gear = 0;
    stop();
  }

  read("");
}

SIMRACE_DEMO_NAMEPACE_END
