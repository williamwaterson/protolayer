#include "LayerPrism.h"


namespace protolayer
{

namespace proto
{

LayerPrism::LayerPrism(LayerHexMesh& layerHexMesh) :
  geometry::RectangularPrism(LENGTH, HEIGHT, LENGTH,
                             *(new style::Appearance()),
                             *(new style::Appearance())),
  _layerHexMesh(layerHexMesh)
{
}


LayerHexMesh& LayerPrism::getLayerHexMesh()
{
  return _layerHexMesh;
}


//    try {
//      xercesc::XMLPlatformUtils::Initialize();
//    } catch (const xercesc::XMLException& toCatch) {
//      throw; // XMLTestException("Failed initialisation");
//    }

//    XMLCh* str = xercesc::XMLString::transcode("Range");
//    xercesc::DOMImplementation* implementation =
//      xercesc::DOMImplementationRegistry::getDOMImplementation(str);

//    xercesc::DOMBuilder* parser = implementation->
//      createDOMBuilder(xercesc::DOMImplementationLS::MODE_SYNCHRONOUS, 0);
//    xercesc::DOMDocument* document = parser->parseURI(fileName.c_str());

//    try {
//      const XMLCh* dialog = xercesc::XMLString::transcode("dialog");
//      xercesc::DOMNodeList* elements = document->getElementsByTagName(dialog);
//      std::cout << elements->getLength() << std::endl;
//      for (int i = 0; i < elements->getLength(); ++i) {
//      xercesc::DOMNode* node = elements->item(i);
//      xercesc::DOMElement* element = dynamic_cast <xercesc::DOMElement*> (node);
//      Dialog* dialog = new Dialog(*element);
//      if (dialog != 0) {
//        std::cout << "here" << std::endl;
//        _dialogs.insert(dialog);
//      }
//     }

//    } catch (XULException ex) {
//    xercesc::XMLPlatformUtils::Terminate();
//    throw ex;
//  }

//  parser->release();
//  xercesc::XMLPlatformUtils::Terminate();


}


}
