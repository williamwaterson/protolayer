#include "Conversions.h"


namespace protolayer
{

namespace xml
{

std::string toString(const XMLCh* value)
{
  return xercesc::XMLString::transcode(value);
}


void toString(std::string& result, const XMLCh* value)
{
  result = xercesc::XMLString::transcode(value);
}


void toString(std::string& result, const xercesc::DOMNode* node)
{
  toString(result, node->getNodeValue());
}


int toInteger(const XMLCh* value)
{
  return atoi(toString(value).c_str());
}


int toInteger(int& result, const XMLCh* value)
{
  result = atoi(toString(value).c_str());
}


int toInteger(int& result, const xercesc::DOMNode* node)
{
  toInteger(result, node->getNodeValue());
}


bool toBool(std::string& value)
  throw (XMLException)
{
  bool result;
  if (value == "true") {
    result = true;
  } else if (value == "false") {
    result = false;
  } else {
    throw XMLException("Non-boolean value provided to a boolean attribute.");
  }

  return result;
}


bool toBool(const XMLCh* value)
  throw (XMLException)
{
  std::string stringValue = toString(value);
  return toBool(stringValue);
}


void toBool(bool& result, const XMLCh* value)
  throw (XMLException)
{
  result = toBool(value);
}


void toBool(bool& result, const xercesc::DOMNode* node)
  throw (XMLException)
{
  toBool(result, node->getNodeValue());
}


char toChar(const XMLCh* value)
  throw (XMLException)
{
  char result;
  std::string stringValue = toString(value);
  if (stringValue.size() != 1) {
    throw XMLException("Zero length or multi-character passed for character attribute");
  } else {
    result = stringValue.c_str()[0];
  }
  return result;
}


void toChar(char& result, const XMLCh* value)
  throw (XMLException)
{
  result = toChar(value);
}


void toChar(char& result, const xercesc::DOMNode* node)
  throw (XMLException)
{
  toChar(result, node->getNodeValue());
}


}


}
