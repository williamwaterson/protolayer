#include "Client.h"

namespace protolayer
{

namespace relayservice
{

Client::Client(int port)
{
  _port = port;
}


void checkResponse(net::Socket& socket) throw (Exception)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);

  if (responseType == net::MessageProtocol::ERROR) {
    throw Exception("Exception has occurred");
  } else if (responseType != net::MessageProtocol::REPLY) {
    throw Exception("Internal implementation error");
  }
}


void Client::addLocation(int techniqueId, const std::string& location)
  throw (Exception, net::Exception)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, _port);

  checkResponse(socket);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(net::MessageProtocol::ADD_LOCATION);
  ostream.flush();

  ostream.write(techniqueId);
  ostream.write(location);
  ostream.flush();

  checkResponse(socket);
}


std::string Client::nextLocation(int techniqueId)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, _port);

  checkResponse(socket);

  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(net::MessageProtocol::NEXT_LOCATION);
  ostream.flush();

  ostream.write(techniqueId);
  ostream.flush();

  checkResponse(socket);

  std::string result;
  istream.read(result);

  return result;
}


}


}
