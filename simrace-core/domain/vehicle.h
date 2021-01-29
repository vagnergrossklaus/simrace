#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>

#include <simrace-core/simrace-core_global.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class Engine;
class Transmission;
class Vehicle : public QObject {
  Q_OBJECT
  Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
  Q_PROPERTY(int fuel READ fuel WRITE setFuel NOTIFY fuelChanged)
  Q_PROPERTY(Engine *engine READ engine WRITE setEngine NOTIFY engineChanged)
  Q_PROPERTY(Transmission *transmission READ transmission WRITE setTransmission
                 NOTIFY transmissionChanged)
public:
  Vehicle(QObject *parent = nullptr);

  int speed() const;
  void setSpeed(int speed);

  float fuel() const;
  void setFuel(float fuel);

  Engine *engine() const;
  void setEngine(Engine *engine);

  Transmission *transmission() const;
  void setTransmission(Transmission *transmission);

private:
  int _speed = 0;
  float _fuel = 0.0;
  Engine *_engine;
  Transmission *_transmission = nullptr;

signals:
  void speedChanged();
  void fuelChanged();
  void engineChanged();
  void transmissionChanged();
};

SIMRACE_CORE_NAMEPACE_END

#endif // VEHICLE_H
