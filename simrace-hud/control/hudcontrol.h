#ifndef HUDCONTROL_H
#define HUDCONTROL_H

#include <QObject>

#include <simrace-core/controller/vehiclecontroller.h>
#include <simrace-core/domain/vehicle.h>

using simrace::core::Vehicle;
using simrace::core::VehicleController;

class HudControl : public QObject {
  Q_OBJECT
public:
  HudControl(QObject *parent = nullptr);
  virtual ~HudControl();

public slots:
  void start();
  void stop();

private:
  Vehicle *_vehicle = nullptr;
  VehicleController _vehicleController;

signals:
  void vehicleChanged(Vehicle *vehicle);
};

#endif // HUDCONTROL_H
