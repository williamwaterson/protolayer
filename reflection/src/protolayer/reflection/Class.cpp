#include "TypeDTO.h"


namespace protolayer
{

namespace ontologydto
{

TypeDTO::TypeDTO() :
  _isLeaf(false),
  _isAbstract(false),
  _isSingleton(false),
  _id(0),
  _domainId(0)
{
}


TypeDTO::TypeDTO(xercesc::DOMElement& element) :
  _name(xml::extractAttribute("name", element)),
  _isLeaf(xml::extractAttribute("isLeaf", element, false)),
  _isAbstract(xml::extractAttribute("isAbstract", element, false)),
  _isSingleton(xml::extractAttribute("isSingleton", element, false))
{
  _domainId = 0;
  _id = 0;
}


TypeDTO::TypeDTO(iostream::XdrInputStream& stream)
{
  decode(stream);
}


void TypeDTO::encode(iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_domainId);
  stream.write(_isLeaf);
  stream.write(_isAbstract);
  stream.write(_isSingleton);
  stream.write(_name);
}


void TypeDTO::decode(iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_domainId);
  stream.read(_isLeaf);
  stream.read(_isAbstract);
  stream.read(_isSingleton);
  stream.read(_name);  
}


TypeDTO::~TypeDTO()
{
}


int& TypeDTO::getId()
{
  return _id;
}


int& TypeDTO::getDomainId()
{
  return _domainId;
}


std::string& TypeDTO::getName()
{
  return _name;
}


bool& TypeDTO::isLeaf()
{
  return _isLeaf;
}


bool& TypeDTO::isAbstract()
{
  return _isAbstract;
}


bool& TypeDTO::isSingleton()
{
  return _isSingleton;
}


}


}
