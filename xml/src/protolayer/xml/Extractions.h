#ifndef PROTOLAYER_XML_EXTRACTIONS_H
#define PROTOLAYER_XML_EXTRACTIONS_H

#include <string>

#include "XMLException.h"

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "Conversions.h"

namespace protolayer
{

namespace xml
{

std::string extractAttribute(char* name,
                             xercesc::DOMElement& element,
                             char* defaultValue);

std::string extractAttribute(char* name,
                             xercesc::DOMElement& element);

bool extractAttribute(char* name,
                      xercesc::DOMElement& element,
                      bool defaultValue);

int extractAttribute(char* name,
                     xercesc::DOMElement& element,
                     int defaultValue);

char extractAttribute(char* name,
                      xercesc::DOMElement& element,
                      char defaultValue);

}


}


#endif // PROTOLAYER_XML_EXTRACTIONS_H
