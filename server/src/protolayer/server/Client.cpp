#include "Client.h"

namespace protolayer
{

namespace server
{


Client::Client(int port)
{
  std::string address("127.0.0.1");
  _socket = new net::Socket(address, port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  int responseType = 0;

//  istream.flush();
  istream.read(responseType);
  //  istream.flush();

  //  checkResponse();
}


void Client::shutdown()
{
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::MessageProtocol::SHUTDOWN);
  ostream.flush();

  //  checkResponse();
}


void Client::checkResponse()
{
  iostream::XdrInputStream& istream = _socket->getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);
  //  istream.flush();

  if (responseType == net::MessageProtocol::ERROR) {
    throw;
  } else if (responseType != net::MessageProtocol::REPLY) {
    throw;
  }
}


}


}
