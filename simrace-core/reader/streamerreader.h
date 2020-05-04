#ifndef STREAMERREADER_H
#define STREAMERREADER_H

#include <simrace-core/simrace-core_global.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class Vehicle;
class StreamerReader {
public:
  StreamerReader();

  virtual void read(const QByteArray &data, Vehicle *telemetry) = 0;
};

SIMRACE_CORE_NAMEPACE_END

#endif // STREAMERREADER_H
