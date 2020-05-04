#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <QObject>

#include <simrace-core/simrace-core_global.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class Transmission : public QObject {
  Q_OBJECT
  Q_PROPERTY(QChar gear READ gear WRITE setGear NOTIFY gearChanged)
public:
  Transmission(QObject *parent = nullptr);

  QChar gear() const;
  void setGear(QChar gear);

  int gears() const;
  void setGears(int gears);

private:
  QChar _gear = 0;
  int _gears = 0;

signals:
  void gearChanged();
};

SIMRACE_CORE_NAMEPACE_END

#endif // TRANSMISSION_H
