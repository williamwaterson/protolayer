#include "EndDTO.h"


namespace protolayer
{

namespace ontologydto
{

namespace
{

pooling::Pool pool(10000);

}


EndDTO::EndDTO()
{
  _id = 0;
  _conceptId = 0;
  _domainId = 0;
}


EndDTO::EndDTO(xercesc::DOMElement& element)
{
  decode(element);
}


EndDTO::EndDTO(iostream::XdrInputStream& stream)
{
  decode(stream);
}


EndDTO::~EndDTO()
{
}


void* EndDTO::operator new(size_t numberBytes)
{
  return pool.acquire(numberBytes);
}


void EndDTO::operator delete(void* object)
{
  pool.release(object);
}


void EndDTO::encode(iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_conceptId);
  stream.write(_domainId);
  stream.write(_label);
  stream.write(_typeName);
  stream.write(_multiplicity);
}


void EndDTO::decode(iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_conceptId);
  stream.read(_domainId);
  stream.read(_label);
  stream.read(_typeName);
  stream.read(_multiplicity);  
}


void EndDTO::decode(xercesc::DOMElement& element)
{
  _id = 0;
  _conceptId = xml::extractAttribute("typeId", element, 0);

  std::cout << "_conceptId set to " << _conceptId << std::endl;

  _domainId = 0;
  _typeName = xml::extractAttribute("type", element);
  _multiplicity = xml::extractAttribute("multiplicity", element, "1");
}


EndDTO::EndDTO(const std::string& typeName)
{
  _id = 0;
  _conceptId = 0;
  _domainId = 0;

  _typeName = typeName;
}


EndDTO::EndDTO(int domainId, const std::string& typeName)
{
  _id = 0;
  _conceptId = 0;

  _domainId = domainId;
  _typeName = typeName;
}


void EndDTO::decode(const std::string& typeName)
{
  clear();
  _typeName = typeName;
}


void EndDTO::decode(int domainId, const std::string& typeName)
{
  clear();

  _domainId = domainId;
  _typeName = typeName;
}


void EndDTO::clear()
{
  _id = 0;
  _conceptId = 0;
  _domainId = 0;
  _label.clear();
  _typeName.clear();
  _multiplicity.clear();
}


int& EndDTO::getId()
{
  return _id;
}


int& EndDTO::getConceptId()
{
  return _conceptId;
}


int& EndDTO::getDomainId()
{
  return _domainId;
}


std::string& EndDTO::getLabel()
{
  return _label;
}


std::string& EndDTO::getTypeName()
{
  return _typeName;
}


std::string& EndDTO::getMultiplicity()
{
  return _multiplicity;
}


}


}
