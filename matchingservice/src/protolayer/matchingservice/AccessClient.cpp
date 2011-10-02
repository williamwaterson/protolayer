#include "AccessClient.h"

namespace protolayer
{

namespace matchingservice
{

AccessClient::AccessClient(int port)
{
  std::string address("127.0.0.1");
  _socket = new net::Socket(address, port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  int responseType = 0;

  //  istream.flush();
  istream.read(responseType);
  //  istream.flush();

  if (responseType != net::MessageProtocol::REPLY) {
    throw Exception();
  }

}


iostream::XdrInputStream& AccessClient::getAvailableAddress(const std::string& name) throw (Exception)
{
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::MessageProtocol::GETAVAILABLEADDRESS);
  ostream.flush();

  ostream.write(name);
  ostream.flush();

  checkResponse();

  return _socket->getXdrInputStream();
}


void AccessClient::checkResponse() throw (Exception)
{
  iostream::XdrInputStream& istream = _socket->getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);
  //  istream.flush();

  if (responseType == net::MessageProtocol::ERROR) {
    throw Exception();
  } else if (responseType != net::MessageProtocol::REPLY) {
    throw Exception();
  }
}


}


}
