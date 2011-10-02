#include "Service.h"

namespace protolayer
{

namespace nameservice
{

namespace
{

std::string NAME_SERVICE = "NameService";

}


Service::Service(int port) :
  server::Service(NAME_SERVICE)
{
  _port = port;
  _runFlag = false;

  _impl = new InMemoryService();
}


Service::Service(xercesc::DOMElement& element) throw (Exception) :
  server::Service(NAME_SERVICE)
{
  _port = xml::extractAttribute("edit-port", element, DEFAULT_EDIT_PORT);
  _runFlag = false;

  _impl = new InMemoryService();
}


void Service::startup()
{
}


void Service::run()
{
  _runFlag = true;

  _serviceSocket = new net::ServerSocket(_port);
  _serviceSocket->listen();

  while(_runFlag) {
    net::Socket& socket = _serviceSocket->accept();
    iostream::XdrInputStream& istream = socket.getXdrInputStream();
    iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

    int protocolType = 0;
    int protocolVersion = 0;
    istream.read(protocolType);
    istream.read(protocolVersion);

    if (protocolType == net::ProtocolHeader::NAME_SERVICE &&
	protocolVersion == net::ProtocolHeader::VERSION_1) {

      int requestType = 0;
      istream.read(requestType);

      if (requestType == net::MessageProtocol::REGISTER_ONTOLOGY) {
	registerDomain(istream, ostream);

      } else if (requestType == net::MessageProtocol::REGISTER_TECHNIQUE) {
	registerTechnique(istream, ostream);

      } else if (requestType == net::MessageProtocol::UNREGISTER) {
	unregister(istream, ostream);

      } else if (requestType == net::MessageProtocol::ADD_LOCATION) {
	addLocation(istream, ostream);

      } else if (requestType == net::MessageProtocol::REMOVE_LOCATION) {
	removeLocation(istream, ostream);

      } else if  (requestType == net::MessageProtocol::GET_NAMES) {
	getNames(istream, ostream);

      } else if  (requestType == net::MessageProtocol::GET_RECORD) {
	getRecord(istream, ostream);
      
      } else if (requestType == net::MessageProtocol::GET_ONTOLOGY) {
	getDomain(istream, ostream);

      } else if (requestType == net::MessageProtocol::NEXT_LOCATION) {
	nextLocation(istream, ostream);

      } else {
	handleError(istream, ostream, "Unknown request");

      }

    }

    socket.close();
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


void Service::registerDomain(iostream::XdrInputStream& istream,
			     iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Registering domain");

  ontologydto::DomainDTO* domain = new ontologydto::DomainDTO(istream);

  getLogger().debug(NAME_SERVICE, "Registering domain");

  _mutex.acquire();

  try {
    std::string urn = _impl->registerDomain(*domain);
    handleSuccess(istream, ostream);

    ostream.write(urn);
    ostream.flush();

  } catch (Exception ex) {
    getLogger().info(NAME_SERVICE, ex.getMessage());
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::registerTechnique(iostream::XdrInputStream& istream,
				iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Registering technique");

  TechniqueRecord* record = new TechniqueRecord(istream);
  //  istream.flush();

  _mutex.acquire();

  try {
    std::string urn = _impl->registerTechnique(*record);
    handleSuccess(istream, ostream);

    ostream.write(urn);
    ostream.flush();
 
  } catch (Exception& ex) {
    getLogger().info(NAME_SERVICE, ex.getMessage());
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();

  ostream.flush();
}


void Service::addLocation(iostream::XdrInputStream& istream,
                         iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Adding location");

  std::string urn;
  std::string location;
  istream.read(urn);
  istream.read(location);
  //  istream.flush();

  _mutex.acquire();

  try {
    _impl->addLocation(urn, location);
    handleSuccess(istream, ostream);

  } catch (Exception ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::removeLocation(iostream::XdrInputStream& istream,
			     iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Remove location called");

  std::string urn;
  std::string location;

  istream.read(urn);
  istream.read(location);
  //  istream.flush();

  _mutex.acquire();

  try {
    _impl->removeLocation(urn, location);
    handleSuccess(istream, ostream);

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::unregister(iostream::XdrInputStream& istream,
			 iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Unregistering URN");

  std::string urn;
  istream.read(urn);
  //  istream.flush();

  getLogger().debug(NAME_SERVICE, "Unregistering URN " + urn);

  _mutex.acquire();

  try {
    _impl->unregister(urn);
    handleSuccess(istream, ostream);

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::getNames(iostream::XdrInputStream& istream,
		       iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Returning names for search keywords");

  std::string criteria;
  istream.read(criteria);
  //  istream.flush();

  _mutex.acquire();

  try {
    std::string result = _impl->getNames(criteria);
    handleSuccess(istream, ostream);

    ostream.write(result);
    ostream.flush();

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::getRecord(iostream::XdrInputStream& istream,
			     iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Getting record");

  std::string urn;
  istream.read(urn);
  //  istream.flush();

  _mutex.acquire();

  try {
    Record* result = _impl->getRecord(urn);
    handleSuccess(istream, ostream);

    result->encode(ostream);
    ostream.flush();

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::getDomain(iostream::XdrInputStream& istream,
			iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Getting ontology");

  std::string urn;
  istream.read(urn);

  //  istream.flush();

  _mutex.acquire();

  try {
    ontologydto::DomainDTO* result = _impl->getDomain(urn);
    handleSuccess(istream, ostream);

    result->encode(ostream);
    ostream.flush();

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());
  }

  _mutex.release();
}


void Service::getTechniques(iostream::XdrInputStream& istream,
			    iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Getting technique URNs for specified concept URN");

  std::string conceptUrn;
  istream.read(conceptUrn);
  //  istream.flush();

  typedef std::set <std::string>::iterator IterType;

  _mutex.acquire();

  try {
    std::set <std::string>& techniqueUrns = _impl->getTechniques(conceptUrn);
    handleSuccess(istream, ostream);

    ostream.write((int) techniqueUrns.size());
    for (IterType iter = techniqueUrns.begin(); iter != techniqueUrns.end(); iter++) {
      ostream.write(*iter);
    }
    ostream.flush();

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::nextLocation(iostream::XdrInputStream& istream,
			   iostream::XdrOutputStream& ostream)
{
  getLogger().debug(NAME_SERVICE, "Getting technique location for specified technique URN");

  std::string techniqueUrn;
  istream.read(techniqueUrn);
  //  istream.flush();

  _mutex.acquire();

  try {
    std::string location = _impl->nextLocation(techniqueUrn);
    handleSuccess(istream, ostream);

    ostream.write(location);
    ostream.flush();

  } catch (Exception& ex) {
    handleError(istream, ostream, ex.getMessage());

  }

  _mutex.release();
}


void Service::handleSuccess(iostream::XdrInputStream& istream,
			    iostream::XdrOutputStream& ostream)
{
  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();
}


void Service::handleError(iostream::XdrInputStream& istream,
			  iostream::XdrOutputStream& ostream,
			  const std::string& message)
{
  ostream.write(net::MessageProtocol::ERROR);
  ostream.flush();
  ostream.write(message);
  ostream.flush();
}


}


}
