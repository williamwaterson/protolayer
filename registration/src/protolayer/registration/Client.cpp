#include "Client.h"

namespace protolayer
{

namespace registration
{

Client::Client(int port)
{
  _port = port;
}


void Client::checkResponse() throw (Exception)
{
  iostream::XdrInputStream& istream = _socket->getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);

  if (responseType == net::MessageProtocol::ERROR) {
    throw Exception();
  } else if (responseType != net::MessageProtocol::REPLY) {
    throw Exception();
  }
}


void checkResponse(net::Socket& socket) throw (Exception)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();

  int responseType = 0;
  istream.read(responseType);

  if (responseType == net::MessageProtocol::ERROR) {
    throw Exception();
  } else if (responseType != net::MessageProtocol::REPLY) {
    throw Exception();
  }
}

template <class Param> int add(Param& instance, net::MessageProtocol::Type messageType, int& port)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, port);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(messageType);
  ostream.flush();

  instance.encode(ostream);
  ostream.flush();

  checkResponse(socket);

  int resultId = 0;
  socket.getXdrInputStream().read(resultId);

  return resultId;
}

template <class Param>
bool retrieve(Param& instance, int& id, net::MessageProtocol::Type type, int& port)
{
  instance.clear();

  std::string address("127.0.0.1");
  net::Socket socket(address, port);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(type);
  ostream.flush();

  ostream.write(id);
  ostream.flush();

  checkResponse(socket);

  instance.clear();
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  instance.decode(istream);

  // TODO: Change this
  return true;
}


int Client::add(protolayer::ontologydto::TypeDTO& dto)
{
  return ::protolayer::registration::add(dto, net::MessageProtocol::ADD_TYPE, _port);
}


int Client::add(protolayer::ontologydto::AssociationDTO& dto)
{
  return ::protolayer::registration::add(dto, net::MessageProtocol::ADD_ASSOCIATION, _port);
}


int Client::add(protolayer::ontologydto::GeneralisationDTO& dto)
{
  return ::protolayer::registration::add(dto, net::MessageProtocol::ADD_GENERALISATION, _port);
}


int Client::add(protolayer::ontologydto::DomainDTO& dto)
{
  return ::protolayer::registration::add(dto, net::MessageProtocol::ADD_DOMAIN, _port);
}


int Client::add(protolayer::dto::TechniqueDTO& dto)
{
  return ::protolayer::registration::add(dto, net::MessageProtocol::ADD_TECHNIQUE, _port);
}


int Client::add(protolayer::dto::UserDTO& dto)
{
  return ::protolayer::registration::add(dto, net::MessageProtocol::ADD_USER, _port);
}


bool Client::retrieve(int id, protolayer::ontologydto::TypeDTO& dto)
{
  return ::protolayer::registration::retrieve(dto, id, net::MessageProtocol::GET_TYPE, _port);
}


bool Client::retrieve(int id, protolayer::ontologydto::EndDTO& dto)
{
  return protolayer::registration::retrieve(dto, id, net::MessageProtocol::GET_END, _port);
}


bool Client::retrieve(int id, protolayer::ontologydto::AssociationDTO& dto)
{
  return protolayer::registration::retrieve(dto, id, net::MessageProtocol::GET_ASSOCIATION, _port);
}


bool Client::retrieve(int id, protolayer::ontologydto::GeneralisationDTO& dto)
{
  return protolayer::registration::retrieve(dto, id, net::MessageProtocol::GET_GENERALISATION, _port);
}


bool Client::retrieve(int id, protolayer::ontologydto::DomainDTO& dto)
{
  return protolayer::registration::retrieve(dto, id, net::MessageProtocol::GET_DOMAIN, _port);
}


bool Client::retrieve(protolayer::ontologydto::TypeDTO& dto)
{
  return retrieve(dto.getId(), dto);
}


bool Client::retrieve(protolayer::ontologydto::EndDTO& dto)
{
  return retrieve(dto.getId(), dto);
}


bool Client::retrieve(protolayer::ontologydto::AssociationDTO& dto)
{
  return retrieve(dto.getId(), dto);
}


bool Client::retrieve(protolayer::ontologydto::GeneralisationDTO& dto)
{
  return retrieve(dto.getId(), dto);
}


bool Client::retrieve(protolayer::ontologydto::DomainDTO& dto)
{
  return retrieve(dto.getId(), dto);
}


bool remove(net::MessageProtocol::Type messageType, int& id, int& port)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, port);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(messageType);
  ostream.flush();

  ostream.write(id);
  ostream.flush();

  checkResponse(socket);

  // TODO: Implement better
  return true;
}


void Client::removeUser(int id)
{
  protolayer::registration::remove(net::MessageProtocol::REMOVE_USER, id, _port);
}


void Client::removeTechnique(int id)
{
  protolayer::registration::remove(net::MessageProtocol::REMOVE_TECHNIQUE, id, _port);
}


void Client::removeType(int id)
{
  protolayer::registration::remove(net::MessageProtocol::REMOVE_TYPE, id, _port);
}


void Client::removeAssociation(int id)
{
  protolayer::registration::remove(net::MessageProtocol::REMOVE_ASSOCIATION, id, _port);
}


void Client::removeGeneralisation(int id)
{
  protolayer::registration::remove(net::MessageProtocol::REMOVE_GENERALISATION, id, _port);
}


void Client::removeDomain(int id)
{
  protolayer::registration::remove(net::MessageProtocol::REMOVE_DOMAIN, id, _port);
}


bool find(net::MessageProtocol::Type messageType, int& id, int& port)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, port);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(messageType);
  ostream.flush();

  ostream.write(id);
  ostream.flush();

  registration::checkResponse(socket);

  iostream::XdrInputStream& istream = socket.getXdrInputStream();

  bool result = false;
  istream.read(result);

  return result;
}


bool Client::findTechnique(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_TECHNIQUE, id, _port);
}


bool Client::findUser(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_USER, id, _port);
}


bool Client::findType(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_TYPE, id, _port);
}


bool Client::findType(int domainId, std::string typeName)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, _port);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(net::MessageProtocol::FIND_TYPE_BY_DOMAIN_AND_NAME);
  ostream.flush();

  ostream.write(domainId);
  ostream.write(typeName);
  ostream.flush();

  registration::checkResponse(socket);

  iostream::XdrInputStream& istream = socket.getXdrInputStream();

  bool result = false;
  istream.read(result);

  return result;
}


int Client::retrieveTypeId(int domainId, std::string typeName)
{
  std::string address("127.0.0.1");
  net::Socket socket(address, _port);

  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ostream.write(net::MessageProtocol::GET_TYPE_BY_DOMAIN_AND_NAME);
  ostream.flush();

  ostream.write(domainId);
  ostream.write(typeName);
  ostream.flush();

  iostream::XdrInputStream& istream = socket.getXdrInputStream();

  registration::checkResponse(socket);

  int result = 0;
  istream.read(result);

  return result;
}


bool Client::findAssociation(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_ASSOCIATION, id, _port);
}


bool Client::findGeneralisation(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_GENERALISATION, id, _port);  
}


bool Client::findDomain(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_DOMAIN, id, _port);  
}


bool Client::findEnd(int id)
{
  return protolayer::registration::find(net::MessageProtocol::FIND_END, id, _port);  
}


}


}
