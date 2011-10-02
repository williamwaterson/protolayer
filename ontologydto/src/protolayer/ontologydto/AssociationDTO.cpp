#include "AssociationDTO.h"


namespace protolayer
{

namespace ontologydto
{

namespace
{

xercesc::DOMElement* extractElement(xercesc::DOMElement& assocElement,
                                    const XMLCh* name)
{
  xercesc::DOMNodeList* subElements = assocElement.getElementsByTagName(name);
  if (subElements->getLength() != 1) {
    throw Exception("Association element breaks cardinality for ends.");
  }

  xercesc::DOMNode* node = subElements->item(0);
  return dynamic_cast <xercesc::DOMElement*> (node);
}


pooling::Pool associationPool(10000);


}


void* AssociationDTO::operator new(size_t numberBytes)
{
  return associationPool.acquire(numberBytes);
}


void AssociationDTO::operator delete(void* object)
{
  associationPool.release(object);
}


AssociationDTO::AssociationDTO()
{
  _id = 0;

  _fromEnd = new EndDTO();
  _toEnd = new EndDTO();
}


AssociationDTO::AssociationDTO(const std::string& fromTypeName, const std::string& toTypeName)
{
  _id = 0;

  _fromEnd = new EndDTO(fromTypeName);
  _toEnd = new EndDTO(toTypeName);
}


void AssociationDTO::decode(const std::string& fromTypeName, int toDomainId, const std::string& toTypeName)
{
  _id = 0;

  _fromEnd->decode(fromTypeName);
  _toEnd->decode(toDomainId, toTypeName);
}


void AssociationDTO::decode(int fromDomainId, const std::string& fromTypeName, int toDomainId, const std::string& toTypeName)
{
  _id = 0;

  _fromEnd->decode(fromDomainId, fromTypeName);
  _toEnd->decode(toDomainId, toTypeName);
}


void AssociationDTO::decode(const std::string& fromTypeName, const std::string& toTypeName)
{
  _id = 0;

  _fromEnd->decode(fromTypeName);
  _toEnd->decode(toTypeName);
}


AssociationDTO::AssociationDTO(xercesc::DOMElement& assocElement)
{
  _id = 0;

  _name = xml::extractAttribute("name", assocElement);

  const XMLCh* fromCh = xercesc::XMLString::transcode("from");
  const XMLCh* toCh = xercesc::XMLString::transcode("to");

  xercesc::DOMElement* fromElement = extractElement(assocElement, fromCh);
  xercesc::DOMElement* toElement = extractElement(assocElement, toCh);

  _fromEnd = new EndDTO(*fromElement);
  _toEnd = new EndDTO(*toElement);
}


AssociationDTO::AssociationDTO(iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_name);
  _fromEnd = new EndDTO(stream);
  _toEnd = new EndDTO(stream);
}


AssociationDTO::~AssociationDTO()
{
  delete _fromEnd;
  delete _toEnd;
}


void AssociationDTO::encode(iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_name);
  _fromEnd->encode(stream);
  _toEnd->encode(stream);
}


void AssociationDTO::clear()
{
  _id = 0;
  _name.clear();
  _fromEnd->clear();
  _toEnd->clear();
}


void AssociationDTO::decode(iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_name);
  _fromEnd->decode(stream);
  _toEnd->decode(stream);
}


void AssociationDTO::decode(xercesc::DOMElement& assocElement)
{
  _id = 0;

  _name = xml::extractAttribute("name", assocElement);

  const XMLCh* fromCh = xercesc::XMLString::transcode("from");
  const XMLCh* toCh = xercesc::XMLString::transcode("to");

  xercesc::DOMElement* fromElement = extractElement(assocElement, fromCh);
  xercesc::DOMElement* toElement = extractElement(assocElement, toCh);

  _fromEnd->decode(*fromElement);
  _toEnd->decode(*toElement);
}


int& AssociationDTO::getId()
{
  return _id;
}


std::string& AssociationDTO::getName()
{
  return _name;
}


EndDTO& AssociationDTO::getFromEnd()
{
  return *_fromEnd;
}


EndDTO& AssociationDTO::getToEnd()
{
  return *_toEnd;
}


}


}
