#include "Service.h"


namespace protolayer
{

namespace registration
{

Service::Service(int port) :
  server::Service("OntoService")
{
  _port = port;
  _runFlag = false;
}


Service::Service(xercesc::DOMElement& element) throw (server::Exception) :
  server::Service("OntoService")
{
  _port = xml::extractAttribute("port", element, DEFAULT_PORT);
  _runFlag = false;
}


void Service::startup()
{
}


template <class Param> void add(net::Socket& socket)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  Param instance(istream);

  //  protolayer::persistence::create(instance);
  int id = protolayer::persistence::Manager <Param>::create(instance);

  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();

  ostream.write(id);
  ostream.flush();  
}


template <> void add <ontologydto::DomainDTO> (net::Socket& socket)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  ontologydto::DomainDTO instance(istream);

  //  protolayer::persistence::create(instance);
  int id = protolayer::persistence::Manager <ontologydto::DomainDTO>::create(instance);

  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();

  ostream.write(id);
  ostream.flush();  
}


template <class Param> void retrieve(net::Socket& socket)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  int id;
  istream.read(id);

  try {
    Param instance;

    protolayer::persistence::Manager <Param>::retrieve(id, instance);

    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

    instance.encode(ostream);
    ostream.flush();

  } catch (persistence::Exception ex) {
    ostream.write(net::MessageProtocol::ERROR);
    ostream.flush();

  }
}


template <class Param> void remove(net::Socket& socket)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  int id;
  istream.read(id);

  try {
    protolayer::persistence::Manager <Param>::remove(id);
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

  } catch (...) {
    ostream.write(net::MessageProtocol::ERROR);
    ostream.flush();
  }
}


template <class Param> void removef(net::Socket& socket)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  int id;
  istream.read(id);

  try {
    protolayer::persistence::Manager <Param>::remove(id);
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

  } catch (...) {
    ostream.write(net::MessageProtocol::ERROR);
    ostream.flush();
  }
}


template <class Param>
void find(net::Socket& socket)
{
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  int id;
  istream.read(id);

  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();

  bool result = protolayer::persistence::Manager <Param>::find(id);

  ostream.write(result);
  ostream.flush();  
}


void Service::run()
{
  _runFlag = true;

  _serviceSocket = new net::ServerSocket(_port);
  _serviceSocket->listen();

  while(_runFlag) {

    net::Socket& socket = _serviceSocket->accept();
    
    int requestType = 0;

    iostream::XdrInputStream& istream = socket.getXdrInputStream();
    iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

    ostream.flush();

    istream.read(requestType);

    if (requestType == net::MessageProtocol::ADD_USER) {
      add <dto::UserDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_USER) {
      find <dto::UserDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_USER) {
      retrieve <dto::UserDTO> (socket);

    } else if (requestType == net::MessageProtocol::REMOVE_USER) {
      remove <dto::UserDTO> (socket);

    } else if (requestType == net::MessageProtocol::ADD_TECHNIQUE) {
      add <dto::TechniqueDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_TECHNIQUE) {
      find <dto::TechniqueDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_TECHNIQUE) {
      retrieve <dto::TechniqueDTO> (socket);

    } else if (requestType == net::MessageProtocol::REMOVE_TECHNIQUE) {
      remove <dto::TechniqueDTO> (socket);

    } else if (requestType == net::MessageProtocol::ADD_TYPE) {
      add <ontologydto::TypeDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_TYPE) {
      find <ontologydto::TypeDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_TYPE) {
      retrieve <ontologydto::TypeDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_TYPE_BY_DOMAIN_AND_NAME) {

      int domainId;
      std::string typeName;
      istream.read(domainId);
      istream.read(typeName);

      bool result = protolayer::persistence::findType(domainId, typeName);

      ostream.write(net::MessageProtocol::REPLY);
      ostream.flush();

      ostream.write(result);
      ostream.flush();

    } else if  (requestType == net::MessageProtocol::GET_TYPE_BY_DOMAIN_AND_NAME) {

      int domainId;
      std::string typeName;
      istream.read(domainId);
      istream.read(typeName);

      int typeId = protolayer::persistence::retrieveTypeId(domainId, typeName);

      ostream.write(net::MessageProtocol::REPLY);
      ostream.flush();

      ostream.write(typeId);
      ostream.flush();

    } else if (requestType == net::MessageProtocol::REMOVE_TYPE) {
      remove <ontologydto::TypeDTO> (socket);

    } else if (requestType == net::MessageProtocol::ADD_ASSOCIATION) {
      add <ontologydto::AssociationDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_ASSOCIATION) {
      find <ontologydto::AssociationDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_ASSOCIATION) {
      retrieve <ontologydto::AssociationDTO> (socket);

    } else if (requestType == net::MessageProtocol::REMOVE_ASSOCIATION) {
      remove <ontologydto::AssociationDTO> (socket);

    } else if (requestType == net::MessageProtocol::ADD_GENERALISATION) {
      add <ontologydto::GeneralisationDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_GENERALISATION) {
      find <ontologydto::GeneralisationDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_GENERALISATION) {
      retrieve <ontologydto::GeneralisationDTO> (socket);

    } else if (requestType == net::MessageProtocol::REMOVE_GENERALISATION) {
      remove <ontologydto::GeneralisationDTO> (socket);

    } else if (requestType == net::MessageProtocol::ADD_DOMAIN) {
      add <ontologydto::DomainDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_DOMAIN) {
      find <ontologydto::DomainDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_DOMAIN) {
      retrieve <ontologydto::DomainDTO> (socket);

    } else if (requestType == net::MessageProtocol::REMOVE_DOMAIN) {
      remove <ontologydto::DomainDTO> (socket);

    } else if  (requestType == net::MessageProtocol::FIND_END) {
      find <ontologydto::EndDTO> (socket);

    } else if  (requestType == net::MessageProtocol::GET_END) {
      retrieve <ontologydto::EndDTO> (socket);

    } else {
      ostream.write(net::MessageProtocol::ERROR);
      ostream.flush();

    }

    socket.close();
    delete (&socket);
  }

  delete _serviceSocket;
}


void Service::suspend()
{
}


void Service::resume()
{
}


void Service::shutdown()
{
  _runFlag = false;
}


}


}
