#include "streamerudphandler.h"

SIMRACE_CORE_NAMEPACE_BEGIN

StreamerUDPHandler::StreamerUDPHandler(Vehicle *vehicle, StreamerReader *reader,
                                       const int port, QObject *parent)
    : StreamerHandler(vehicle, reader, parent), _port(port) {
  return;
}

void StreamerUDPHandler::start() {
  _socket.bind(_port, QUdpSocket::ShareAddress);
  connect(&_socket, &QIODevice::readyRead, this,
          &StreamerUDPHandler::onReadyRead);
}

void StreamerUDPHandler::stop() {
  disconnect(&_socket, &QIODevice::readyRead, nullptr, nullptr);
  _socket.close();
}

void StreamerUDPHandler::onReadyRead() {
  QByteArray datagram;
  while (_socket.hasPendingDatagrams()) {
    datagram.resize(_socket.pendingDatagramSize());
    _socket.readDatagram(datagram.data(), _socket.pendingDatagramSize());
  }
  read(datagram);
}

SIMRACE_CORE_NAMEPACE_END
