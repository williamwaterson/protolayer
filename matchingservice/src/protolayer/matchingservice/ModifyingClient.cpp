#include "ModifyingClient.h"

namespace protolayer
{

namespace matchingservice
{

ModifyingClient::ModifyingClient(int port)
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


void ModifyingClient::addAddress(const std::string& name,
                                 const std::string& address) throw (Exception)
{
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::MessageProtocol::ADDADDRESS);
  ostream.flush();

  ostream.write(name);
  ostream.flush();

  ostream.write(address);
  ostream.flush();

  checkResponse();
}


void ModifyingClient::removeAddress(const std::string& name,
                                    const std::string& address) throw (Exception)
{
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::MessageProtocol::REMOVEADDRESS);
  ostream.flush();

  ostream.write(name);
  ostream.flush();

  ostream.write(address);
  ostream.flush();

  checkResponse();
}


iostream::XdrInputStream& ModifyingClient::getAvailableAddress(const std::string& name) throw (Exception)
{
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::MessageProtocol::GETAVAILABLEADDRESS);
  ostream.flush();

  ostream.write(name);
  ostream.flush();

  checkResponse();

  return _socket->getXdrInputStream();
}


void ModifyingClient::checkResponse() throw (Exception)
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
