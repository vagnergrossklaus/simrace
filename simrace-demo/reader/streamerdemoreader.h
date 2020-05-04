#ifndef STREAMERDEMOREADER_H
#define STREAMERDEMOREADER_H

#include <simrace-demo/simrace-demo_global.h>

#include <simrace-core/reader/streamerreader.h>

using simrace::core::StreamerReader;
using simrace::core::Vehicle;

SIMRACE_DEMO_NAMEPACE_BEGIN

class StreamerDemoReader : public StreamerReader {
public:
  StreamerDemoReader();

  virtual void read(const QByteArray &data, Vehicle *);
};

SIMRACE_DEMO_NAMEPACE_END

#endif // STREAMERDEMOREADER_H
