#include "Service.h"


namespace protolayer
{

namespace containerservice
{

namespace
{
  std::string CONTAINER_SERVICE = "ContainerService";
}


Service::Service(Configuration& configuration) :
  server::Service("TechniqueService"),
  _configuration(configuration)
  //  _graphDecoder(30000L)
{
  _runFlag = false;
}


Service::~Service()
{
}


void Service::publishLocations()
{
  typedef std::map <std::string, TechniqueService*>::iterator IterType;

  nameservice::Client*  client = 0;
  try {
    client = new nameservice::Client(80001);
  } catch (net::Exception& ex) {
    getLogger().info(CONTAINER_SERVICE, ex.getMessage());
    return;
  }

  _mutex.acquire();

  getLogger().debug(CONTAINER_SERVICE, "Looping locations");

  for (IterType iter = _deployedTechniqueServices.begin();
       iter != _deployedTechniqueServices.end();
       iter++) {

    try {
      client->addLocation(iter->first, "localhost");

    } catch (nameservice::Exception& ex) {
      getLogger().info(CONTAINER_SERVICE, ex.getMessage());
      // Don't break as other locations may be registered

    } catch (net::Exception& ex) {
      getLogger().info(CONTAINER_SERVICE, ex.getMessage());
      break;  // Must break rather than throw so deletion of client instance 

    }
  }

  getLogger().debug(CONTAINER_SERVICE, "Finished looping locations");

  _mutex.release();

  delete client;
}


void Service::startup()
{
}


void Service::run()
{
  _runFlag = true;

  _serviceSocket = new net::ServerSocket(50000);
  _serviceSocket->listen();

  while(_runFlag) {

    net::Socket& socket = _serviceSocket->accept();
    iostream::XdrInputStream& istream = socket.getXdrInputStream();
    iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

    int protocolType = 0;
    int protocolVersion = 0;
    istream.read(protocolType);
    istream.read(protocolVersion);

    if (protocolType == net::ProtocolHeader::CONTAINER_SERVICE &&
	protocolVersion == net::ProtocolHeader::VERSION_1) {

      int requestType = 0;
      istream.read(requestType);
      //    istream.flush();

      if (requestType == net::MessageProtocol::POPULATE) {
	populate(istream, ostream);

      } else if  (requestType == net::MessageProtocol::VALIDATE) {
	validate(istream, ostream);

      } else if  (requestType == net::MessageProtocol::EVALUATE) {
	evaluate(istream, ostream);

      } else {
	handleError(istream, ostream);

      }

    }

    socket.close();

    delete &socket;
  }

  delete _serviceSocket;
}


TechniqueService* Service::handleTechniqueLookup(iostream::XdrInputStream& istream,
						 iostream::XdrOutputStream& ostream)
{
  std::string urn;
  istream.read(urn);
  getLogger().info(CONTAINER_SERVICE, "Technique service " + urn + " looked up");
  //  istream.flush();

  return getTechniqueService(urn);
}


void Service::handleFailedLookup(iostream::XdrInputStream& istream,
				 iostream::XdrOutputStream& ostream)
{
  ostream.write(net::MessageProtocol::ERROR);
  ostream.flush();
}


void Service::populate(iostream::XdrInputStream& istream,
		       iostream::XdrOutputStream& ostream)
{
  getLogger().info(CONTAINER_SERVICE, "Populate called on service");

  TechniqueService* technique = handleTechniqueLookup(istream, ostream);

  if (technique == 0) {
    getLogger().info(CONTAINER_SERVICE, "Technique service lookup failed");
    handleFailedLookup(istream, ostream);

  } else {
    getLogger().info(CONTAINER_SERVICE, "Technique service lookup succeeded");
    RootConceptInstance* subgraph = extractSubgraph(istream, ostream);

    try {
      technique->populate(*subgraph);
      handleSuccess(istream, ostream);

    } catch (...) {
      handleError(istream, ostream);
    }

    releaseSubgraph(*subgraph);
  }
}



void Service::validate(iostream::XdrInputStream& istream,
		       iostream::XdrOutputStream& ostream)
{
  getLogger().info(CONTAINER_SERVICE, "Validate called on service");

  TechniqueService* technique = handleTechniqueLookup(istream, ostream);

  getLogger().info(CONTAINER_SERVICE, "Technique service " + technique->getUrn() + " looked up");

  if (technique == 0) {
    getLogger().info(CONTAINER_SERVICE, "Technique service lookup failed");
    handleFailedLookup(istream, ostream);

  } else 
    getLogger().info(CONTAINER_SERVICE, "Technique service lookup succeeded");{
    RootConceptInstance* subgraph = extractSubgraph(istream, ostream);

    try {
      technique->validate(*subgraph);
      handleSuccess(istream, ostream);

    } catch (...) {
      handleError(istream, ostream);
    }

    releaseSubgraph(*subgraph);
  }
}


void Service::evaluate(iostream::XdrInputStream& istream,
		       iostream::XdrOutputStream& ostream)
{
  getLogger().info(CONTAINER_SERVICE, "Evaluate called on service");

  TechniqueService* technique = handleTechniqueLookup(istream, ostream);

  getLogger().info(CONTAINER_SERVICE, "Technique service " + technique->getUrn() + " looked up");

  if (technique == 0) {
    getLogger().info(CONTAINER_SERVICE, "Technique service lookup failed");
    handleFailedLookup(istream, ostream);

  } else {
    getLogger().info(CONTAINER_SERVICE, "Technique service lookup succeeded");
    RootConceptInstance* subgraph = extractSubgraph(istream, ostream);

    try {
      technique->evaluate(*subgraph);
      handleSuccess(istream, ostream);

    } catch (...) {
      handleError(istream, ostream);
    }

    releaseSubgraph(*subgraph);
  }
}


void Service::handleSuccess(iostream::XdrInputStream& istream,
			    iostream::XdrOutputStream& ostream)
{
  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();
}


void Service::handleError(iostream::XdrInputStream& istream,
			  iostream::XdrOutputStream& ostream)
{
  ostream.write(net::MessageProtocol::ERROR);
  ostream.flush();
}


void Service::deploy(TechniqueService& technique)
{
  const std::string& urn = technique.getUrn();

  _mutex.acquire();

  if (_deployedTechniqueServices.find(urn) == _deployedTechniqueServices.end()) {
    _deployedTechniqueServices[urn] = &technique;

    getLogger().info(CONTAINER_SERVICE, "Technique " + urn + " deployed");

    try {
      nameservice::Client client(80001);
      client.addLocation(urn, "localhost");

      getLogger().info(CONTAINER_SERVICE, "Remote addition of technique " + urn + " successful");
      getLogger().info(CONTAINER_SERVICE, "Technique " + urn + " is externally accessible");

    } catch (nameservice::Exception& ex) {
      getLogger().info(CONTAINER_SERVICE, "Remote addition of technique " + urn + " failed");
      getLogger().info(CONTAINER_SERVICE, ex.getMessage());
      getLogger().info(CONTAINER_SERVICE, "Technique " + urn + " not accessible externally (only locally from this host)");

    } catch (net::Exception& ex) {
      getLogger().info(CONTAINER_SERVICE, "Remote addition of technique " + urn + " failed");
      getLogger().info(CONTAINER_SERVICE, ex.getMessage());
      getLogger().info(CONTAINER_SERVICE, "Technique " + urn + " not accessible externally (only locally from this host)");

    }

  }

  _mutex.release();

}


RootConceptInstance* Service::extractSubgraph(iostream::XdrInputStream& istream,
					      iostream::XdrOutputStream& ostream)
{
  RootConceptInstanceImpl* root = new RootConceptInstanceImpl(istream);
  return root;
}


void Service::releaseSubgraph(RootConceptInstance& instance)
{
  delete (&instance);
}


void Service::undeploy(TechniqueService& technique)
{
  const std::string& urn = technique.getUrn();  

  _mutex.acquire();

  _deployedTechniqueServices.erase(urn);
  getLogger().info(CONTAINER_SERVICE, "Technique " + urn + " undeployed");

  _mutex.release();
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


Configuration& Service::getConfiguration()
{
  return _configuration;
}


TechniqueService* Service::getTechniqueService(const std::string& urn)
{
  TechniqueService* result = 0;

  _mutex.acquire();

  if (_deployedTechniqueServices.find(urn) != _deployedTechniqueServices.end()) {
    result = _deployedTechniqueServices[urn];
  }

  _mutex.release();

  return result;
}


}


}
