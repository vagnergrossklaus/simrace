#ifndef STREAMERPROJECTCARS2READER_H
#define STREAMERPROJECTCARS2READER_H

#include <simrace-projectcars/simrace-projectcars_global.h>

#include <simrace-core/reader/streamerreader.h>

using simrace::core::StreamerReader;
using simrace::core::Vehicle;

SIMRACE_PROJECTCARS_NAMEPACE_BEGIN

class StreamerProjectCars2Reader : public StreamerReader {
  using StreamerReader::StreamerReader;

public:
  void read(const QByteArray &data, Vehicle *vehicle);
};

SIMRACE_PROJECTCARS_NAMEPACE_END

#endif // STREAMERPROJECTCARS2READER_H
