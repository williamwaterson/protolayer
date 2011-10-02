#ifndef PROTOLAYER_LOADER_H
#define PROTOLAYER_LOADER_H

#include <stdlib.h>

#include <string>
#include <iostream.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "XMLException.h"

namespace protolayer
{

namespace xml
{

xercesc::DOMDocument* createDocument();

void writeToFile(std::string& fileName, xercesc::DOMDocument* document);

xercesc::DOMDocument* readFromFile(std::string& fileName);

void release(xercesc::DOMDocument& document);

}


}


#endif // PROTOLAYER_LOADER_H
