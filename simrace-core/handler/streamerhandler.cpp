#include "streamerhandler.h"

SIMRACE_CORE_NAMEPACE_BEGIN

StreamerHandler::StreamerHandler(Vehicle *vehicle, StreamerReader *reader,
                                 QObject *parent)
    : QObject(parent), _vehicle(vehicle), _reader(reader) {}

Vehicle *StreamerHandler::vehicle() const { return _vehicle; }

StreamerReader *StreamerHandler::reader() const { return _reader; }

SIMRACE_CORE_NAMEPACE_END
