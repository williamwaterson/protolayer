#include <unistd.h>


#include "protolayer/protolayer-server.h"
#include "protolayer/protolayer-relayservice.h"

//#include "protolayer/protolayer-nameservice.h"
//#include "protolayer/protolayer-ontoservice.h"
//#include "protolayer/protolayer-matchingservice.h"

int main()
{
  std::string fileName("etc/router-config.xml");

  try {
    xercesc::XMLPlatformUtils::Initialize();
  } catch (const xercesc::XMLException& toCatch) {
    throw;
  }

  XMLCh* str = xercesc::XMLString::transcode("Range");
  xercesc::DOMImplementation* impl =
    xercesc::DOMImplementationRegistry::getDOMImplementation(str);

  xercesc::DOMBuilder* parser = impl->
    createDOMBuilder(xercesc::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
  xercesc::DOMDocument* document = parser->parseURI(fileName.c_str());

  protolayer::server::Server* adminServer = 0;
  try {
    const XMLCh* elementName = xercesc::XMLString::transcode("server");
    xercesc::DOMNodeList* elements = document->getElementsByTagName(elementName);
    xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (elements->item(0));

    adminServer = new protolayer::server::Server(*element);

  } catch (...) {
    xercesc::XMLPlatformUtils::Terminate();
    exit(0);

  }

  protolayer::relayservice::Service* relayService = 0;
  try {
    relayService = new protolayer::relayservice::Service(80005);

  } catch (...) {
    xercesc::XMLPlatformUtils::Terminate();
    exit(0);
  }

  adminServer->add(*relayService);
  adminServer->run();

  return 0;
}
