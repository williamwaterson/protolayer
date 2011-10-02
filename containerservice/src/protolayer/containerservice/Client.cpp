#include "Client.h"

namespace protolayer
{

namespace containerservice
{

Client::Client(int port)
{
  _port = port;
}


void Client::validate(const std::string& address,
		      assembly::Instance& instance)
  throw (Exception, net::Exception)
{
  //  std::string address("localhost");
  _socket = new net::Socket(address, _port);
  std::cout << "socket created" << std::endl;

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();
  std::cout << "streams obtained" << std::endl;

  ostream.write(net::ProtocolHeader::CONTAINER_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::VALIDATE);
  std::cout << "Write method called via validate" << std::endl;

  ostream.write(instance.getTechniqueUrn());
  std::cout << "Write to call technique urn" << std::endl;

  ostream.flush();
  std::cout << "Flush called " << std::endl;

  try {
    checkResponse();

  } catch (Exception& ex) {
    std::cout << "Ex caught " << std::endl;
    delete _socket;
    throw ex;

  } catch (net::Exception& ex) {
    std::cout << "net::Ex caught " << std::endl;
    delete _socket;
    throw ex;
  }

  delete _socket;
}


void Client::populate(const std::string& address,
		      assembly::Instance& instance)
  throw (Exception, net::Exception)
{
  //  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::CONTAINER_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::POPULATE);
  ostream.write(instance.getTechniqueUrn());
  ostream.flush();

  try {
    checkResponse();

  } catch (Exception& ex) {
    std::cout << "caught ex" << std::endl;
    delete _socket;
    std::cout << "socket deleted" << std::endl;
    throw ex;

  } catch (net::Exception& ex) {
    delete _socket;
    throw ex;

  }

  delete _socket;
}


void Client::evaluate(const std::string& address,
		      assembly::Instance& instance)
  throw (Exception, net::Exception)
{
  //  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::CONTAINER_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::EVALUATE);
  ostream.write(instance.getTechniqueUrn());
  ostream.flush();

  try {
    checkResponse();
  } catch (Exception& ex) {
    delete _socket;
    throw ex;
  } catch (net::Exception& ex) {
    delete _socket;
    throw ex;
  }

  delete _socket;
}


void Client::checkResponse() throw (Exception)
{
  iostream::XdrInputStream& istream = _socket->getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);
  //  istream.flush();

  if (responseType == net::MessageProtocol::ERROR) {
    std::string message;
    istream.read(message);
    //    istream.flush();
    throw Exception(message);

  } else if (responseType != net::MessageProtocol::REPLY) {
    throw Exception("Protocol mismatch");

  }
}



}


}
