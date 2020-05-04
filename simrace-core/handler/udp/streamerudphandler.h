#ifndef STREAMERUDPHANDLER_H
#define STREAMERUDPHANDLER_H

#include <QUdpSocket>

#include <simrace-core/handler/streamerhandler.h>

SIMRACE_CORE_NAMEPACE_BEGIN

class StreamerUDPHandler : public StreamerHandler {
public:
  StreamerUDPHandler(Vehicle *vehicle, StreamerReader *reader, const int port,
                     QObject *parent = nullptr);

  void start() override;
  void stop() override;

private:
  int _port = 0;
  QUdpSocket _socket;

private slots:
  void onReadyRead();
};

SIMRACE_CORE_NAMEPACE_END

#endif // STREAMERUDPHANDLER_H
