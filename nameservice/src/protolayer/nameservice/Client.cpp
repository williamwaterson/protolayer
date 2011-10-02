#include "Client.h"

namespace protolayer
{

namespace nameservice
{

Client::Client(int port)
{
  _port = port;
}


std::string Client::registerDomain(ontologydto::DomainDTO& domain)
    throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::REGISTER_ONTOLOGY);
  domain.encode(ostream);
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

  std::string result;
  istream.read(result);

  delete _socket;

  return result;
}


std::string Client::registerTechnique(TechniqueRecord& record)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::REGISTER_TECHNIQUE);
  record.encode(ostream);
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

  std::string result;
  istream.read(result);
  //  istream.flush();

  delete _socket;

  return result;
}


void Client::unregister(const std::string& urn)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::UNREGISTER);
  ostream.write(urn);
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

  //  istream.flush();

  delete _socket;
}


void Client::addLocation(const std::string& urn,
                         const std::string& location)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::ADD_LOCATION);
  ostream.write(urn);
  ostream.write(location);
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

  //  istream.flush();

  delete _socket;
}


void Client::removeLocation(const std::string& urn,
                            const std::string& location)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::REMOVE_LOCATION);
  ostream.write(urn);
  ostream.write(location);
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

  //  istream.flush();

  delete _socket;
}


std::string Client::getNames(const std::string& criteria)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::GET_NAMES);
  ostream.write(criteria);
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

  std::string result;
  istream.read(result);
  //  istream.flush();

  delete _socket;

  return result;
}


void Client::getRecord(const std::string& urn)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::GET_RECORD);
  ostream.write(urn);
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

  //  istream.flush();

  delete _socket;
}


void Client::getDomain(const std::string& urn)
  throw (Exception, net::Exception)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::GET_ONTOLOGY);
  ostream.write(urn);
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

  ontologydto::DomainDTO* result = new ontologydto::DomainDTO(istream);
  //  istream.flush();

  delete _socket;
}


std::string Client::nextLocation(const std::string& urn)
{
  std::string address("localhost");
  _socket = new net::Socket(address, _port);

  iostream::XdrInputStream& istream = _socket->getXdrInputStream();
  iostream::XdrOutputStream& ostream = _socket->getXdrOutputStream();

  ostream.write(net::ProtocolHeader::NAME_SERVICE);
  ostream.write(net::ProtocolHeader::VERSION_1);
  ostream.write(net::MessageProtocol::NEXT_LOCATION);
  ostream.write(urn);
  ostream.flush();

  try {
    checkResponse();

  } catch (Exception& ex) {
    std::cout << "name exception" << std::endl;
    delete _socket;
    throw ex;

  } catch (net::Exception& ex) { 
    delete _socket;
    throw ex;   

  } catch (iostream::Exception& ex) {
    delete _socket;
    std::cout << "unknown" << std::endl;
  }

  std::string result;
  istream.read(result);
  //  istream.flush();

  delete _socket;

  return result;
}


void Client::checkResponse() throw (Exception)
{
  iostream::XdrInputStream& istream = _socket->getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);

  if (responseType == net::MessageProtocol::ERROR) {
    std::string message;
    istream.read(message);
    //    istream.flush();
    throw Exception(message);

  } else if (responseType != net::MessageProtocol::REPLY) {
    throw Exception("Mismatched protocol");
  }
}


}


}
