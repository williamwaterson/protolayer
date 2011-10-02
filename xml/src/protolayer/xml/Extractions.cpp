#include "Extractions.h"


namespace protolayer
{

namespace xml
{

std::string extractAttribute(char* name,
                             xercesc::DOMElement& element,
                             char* defaultValue)
{
  std::string result;
  xercesc::DOMNamedNodeMap* attributes = element.getAttributes();
  if (attributes == NULL) {
    result = defaultValue;
  } else {
    const XMLCh* nameXMLCh = xercesc::XMLString::transcode(name);
    xercesc::DOMNode* node = attributes->getNamedItem(nameXMLCh);
    if (node == NULL) {
      result = defaultValue;
    } else {
      result = xml::toString(node->getNodeValue());
    }
  }
  return result;
}

std::string extractAttribute(char* name,
                             xercesc::DOMElement& element)
{
  std::string result;
  std::string defaultValue = "";

  xercesc::DOMNamedNodeMap* attributes = element.getAttributes();
  if (attributes == NULL) {
    result = defaultValue;
  } else {
    const XMLCh* nameXMLCh = xercesc::XMLString::transcode(name);
    xercesc::DOMNode* node = attributes->getNamedItem(nameXMLCh);
    if (node == NULL) {
      result = defaultValue;
    } else {
      result = xml::toString(node->getNodeValue());
    }
  }
  return result;
}


bool extractAttribute(char* name,
                      xercesc::DOMElement& element,
                      bool defaultValue)
{
  const XMLCh* nameCh = xercesc::XMLString::transcode(name);
  const XMLCh* valueCh = element.getAttribute(nameCh);
  std::string value =  xercesc::XMLString::transcode(valueCh);

  bool result = defaultValue;
  if (value != "") {
    result = xml::toBool(valueCh);
  }
  return result;
}


int extractAttribute(char* name,
                     xercesc::DOMElement& element,
                     int defaultValue)
{
  int result = defaultValue;
  xercesc::DOMNamedNodeMap* attributes = element.getAttributes();
  if (attributes != NULL) {
    const XMLCh* nameXMLCh = xercesc::XMLString::transcode(name);
    xercesc::DOMNode* node = attributes->getNamedItem(nameXMLCh);
    if (node != NULL) {
      result = xml::toInteger(node->getNodeValue());
    }
  }
  return result;
}


char extractAttribute(char* name,
                      xercesc::DOMElement& element,
                      char defaultValue)
{
  char result = defaultValue;
  xercesc::DOMNamedNodeMap* attributes = element.getAttributes();
  if (attributes != NULL) {
    const XMLCh* nameXMLCh = xercesc::XMLString::transcode(name);
    xercesc::DOMNode* node = attributes->getNamedItem(nameXMLCh);
    if (node != NULL) {
      result = xml::toChar(node->getNodeValue());
    }
  }
  return result;
}


}


}
