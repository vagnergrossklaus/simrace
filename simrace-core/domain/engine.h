#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#include <simrace-core/simrace-core_global.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class Engine : public QObject {
  Q_OBJECT
  Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
  Q_PROPERTY(int maxRpm READ maxRpm WRITE setMaxRpm NOTIFY maxRpmChanged)
  Q_PROPERTY(int maxDisplayRpm READ maxDisplayRpm WRITE setMaxDisplayRpm NOTIFY
                 maxDisplayRpmChanged)
public:
  Engine(QObject *parent = nullptr);

  int rpm() const;
  void setRpm(int rpm);

  int maxRpm() const;
  void setMaxRpm(int maxRpm);

  int maxDisplayRpm() const;
  void setMaxDisplayRpm(int maxDisplayRpm);

private:
  int _rpm = 0;
  int _maxRpm = 0;
  int _maxDisplayRpm = 0;

signals:
  void rpmChanged();
  void maxRpmChanged();
  void maxDisplayRpmChanged();
};

SIMRACE_CORE_NAMEPACE_END

#endif // ENGINE_H
