#ifndef STREAMERDEMOHANDLER_H
#define STREAMERDEMOHANDLER_H

#include <QRandomGenerator>
#include <QTimer>

#include <simrace-demo/simrace-demo_global.h>

#include <simrace-core/handler/streamerhandler.h>

using simrace::core::StreamerHandler;
using simrace::core::Vehicle;

SIMRACE_DEMO_NAMEPACE_BEGIN

class StreamerDemoHandler : public StreamerHandler {
public:
  StreamerDemoHandler(Vehicle *vehicle, QObject *parent = nullptr);

  void start();
  void stop();
  void read(const QByteArray &data);

private:
  int _gear = 0;
  int _gearTarget = 0;
  int _rpm = 0;
  int _speed = 0;
  bool _breake = false;
  bool _throttle = false;
  QTimer _timer;
  QRandomGenerator _random;

private slots:
  void onTimeout();
};

SIMRACE_DEMO_NAMEPACE_END

#endif // STREAMERDEMOHANDLER_H
