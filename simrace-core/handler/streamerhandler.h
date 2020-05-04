#ifndef STREAMERHANDLER_H
#define STREAMERHANDLER_H

#include <QMap>
#include <QObject>

#include <simrace-core/simrace-core_global.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class Vehicle;
class StreamerReader;
class StreamerHandler : public QObject {
  Q_OBJECT
public:
  StreamerHandler(Vehicle *vehicle, StreamerReader *reader,
                  QObject *parent = nullptr);

  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void read(const QByteArray &data) = 0;

protected:
  Vehicle *vehicle() const;
  StreamerReader *reader() const;

private:
  Vehicle *_vehicle = nullptr;
  StreamerReader *_reader = nullptr;
};

SIMRACE_CORE_NAMEPACE_END

#endif // STREAMERHANDLER_H
