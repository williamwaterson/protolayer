#ifndef PROTOLAYER_CONVERSIONS_H
#define PROTOLAYER_CONVERSIONS_H

#include <stdlib.h>

#include <string>

#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "XMLException.h"

namespace protolayer
{

namespace xml
{

std::string toString(const XMLCh* value);

void toString(std::string& result, const XMLCh* value);

void toString(std::string& result, const xercesc::DOMNode* node);

int toInteger(const XMLCh* value);

int toInteger(int& result, const XMLCh* value);

int toInteger(int& result, const xercesc::DOMNode* node);

bool toBool(std::string& value)
  throw (XMLException);

bool toBool(const XMLCh* value)
  throw (XMLException);

void toBool(bool& result, const XMLCh* value)
  throw (XMLException);

void toBool(bool& result, const xercesc::DOMNode* node)
  throw (XMLException);

char toChar(const XMLCh* value)
  throw (XMLException);

void toChar(bool& result, const XMLCh* value)
  throw (XMLException);

void toChar(bool& result, const xercesc::DOMNode* node)
  throw (XMLException);

}


}


#endif // PROTOLAYER_WINDOW_H
