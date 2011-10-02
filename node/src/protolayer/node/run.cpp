#include <unistd.h>
#include "protolayer/protolayer-server.h"
#include "protolayer/protolayer-compileservice.h"
#include "protolayer/protolayer-containerservice.h"
#include "protolayer/protolayer-publishingservice.h"

int main()
{
  protolayer::logger::Logger& logger =
    protolayer::logger::Logger::getSingleton();

  logger.info("[Protolayer] Loading Server XML Configuration");
  std::string fileName("etc/node-config.xml");

  try {
    xercesc::XMLPlatformUtils::Initialize();
  } catch (const xercesc::XMLException& toCatch) {
    std::cout << "Failed initialisation" << std::endl;
  }

  XMLCh* str = xercesc::XMLString::transcode("Range");
  xercesc::DOMImplementation* impl =
    xercesc::DOMImplementationRegistry::getDOMImplementation(str);

  xercesc::DOMBuilder* parser = impl->
    createDOMBuilder(xercesc::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
  xercesc::DOMDocument* document = parser->parseURI(fileName.c_str());

  protolayer::server::Server* adminServer = 0;
  try {
    const XMLCh* elementName = xercesc::XMLString::transcode("adminservice");
    xercesc::DOMNodeList* elements = document->getElementsByTagName(elementName);
    xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (elements->item(0));

    adminServer = new protolayer::server::Server(*element);

  } catch (...) {
    xercesc::XMLPlatformUtils::Terminate();
    exit(0);

  }

  protolayer::containerservice::Configuration* techConfiguration = 0;
  protolayer::containerservice::Service* containerService = 0;
  try {
    const XMLCh* elementName = xercesc::XMLString::transcode("containerservice");
    xercesc::DOMNodeList* elements = document->getElementsByTagName(elementName);
    xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (elements->item(0));

    techConfiguration = new protolayer::containerservice::Configuration(*element);
    containerService = new protolayer::containerservice::Service(*techConfiguration);

  } catch (...) {
    xercesc::XMLPlatformUtils::Terminate();
    exit(0);
  }

  protolayer::compileservice::Service* compileService = 0;
  try {
    const XMLCh* elementName = xercesc::XMLString::transcode("compileservice");
    xercesc::DOMNodeList* elements = document->getElementsByTagName(elementName);
    xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (elements->item(0));

    compileService = new protolayer::compileservice::Service(*containerService, *element);

  } catch (...) {
    xercesc::XMLPlatformUtils::Terminate();
    exit(0);
  }

  protolayer::publishingservice::Configuration* publishingConfiguration = 0;
  protolayer::publishingservice::Service* publishingService = 0;
  try {
    const XMLCh* elementName = xercesc::XMLString::transcode("namingservice");
    xercesc::DOMNodeList* elements = document->getElementsByTagName(elementName);
    xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (elements->item(0));

    publishingConfiguration = new protolayer::publishingservice::Configuration(*element);
    publishingService = new protolayer::publishingservice::Service(*containerService, *publishingConfiguration);

  } catch (...) {
    xercesc::XMLPlatformUtils::Terminate();
    exit(0);
  }

  adminServer->add(*containerService);
  adminServer->add(*compileService);
  adminServer->add(*publishingService);

  adminServer->run();

  return 0;
}

