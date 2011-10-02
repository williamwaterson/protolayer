#include "GeneralisationDTO.h"


namespace protolayer
{

namespace ontologydto
{

namespace
{

pooling::Pool pool(10000);

}


void* GeneralisationDTO::operator new(size_t numberBytes)
{
  return pool.acquire(numberBytes);
}


void GeneralisationDTO::operator delete(void* object)
{
  pool.release(object);
}


GeneralisationDTO::GeneralisationDTO()
{
  _id = 0;
  _superTypeId = 0;
  _superTypeDomainId = 0;
  _subTypeId = 0;
  _subTypeDomainId = 0;
}


GeneralisationDTO::GeneralisationDTO(const std::string& superTypeName,
				  const std::string& subTypeName) :
  _superTypeName(superTypeName),
  _subTypeName(subTypeName)
{
  _id = 0;
  _superTypeId = 0;
  _superTypeDomainId = 0;
  _subTypeId = 0;
  _subTypeDomainId = 0;
}


GeneralisationDTO::GeneralisationDTO(xercesc::DOMElement& element)
{
  _id = 0;
  _superTypeId = 0;
  _superTypeDomainId = 0;
  _subTypeId = 0;
  _subTypeDomainId = 0;
  _superTypeName = xml::extractAttribute("supertype", element);
  _subTypeName = xml::extractAttribute("subtype", element);
}


GeneralisationDTO::GeneralisationDTO(iostream::XdrInputStream& stream)
{
  decode(stream);
}

GeneralisationDTO::~GeneralisationDTO()
{
}


void GeneralisationDTO::clear()
{
  _id = 0;
  _superTypeId = 0;
  _superTypeDomainId = 0;
  _subTypeId = 0;
  _subTypeDomainId = 0;
  _superTypeName.clear();
  _subTypeName.clear();
}


void GeneralisationDTO::encode(iostream::XdrOutputStream& stream)
{
  stream.write(_id);
  stream.write(_superTypeId);
  stream.write(_superTypeDomainId);
  stream.write(_subTypeId);
  stream.write(_subTypeDomainId);
  stream.write(_superTypeName);
  stream.write(_subTypeName);
}


int& GeneralisationDTO::getId()
{
  return _id;
}


void GeneralisationDTO::decode(iostream::XdrInputStream& stream)
{
  stream.read(_id);
  stream.read(_superTypeId);
  stream.read(_superTypeDomainId);
  stream.read(_subTypeId);
  stream.read(_subTypeDomainId);
  stream.read(_superTypeName);
  stream.read(_subTypeName);  
}


std::string& GeneralisationDTO::getSubTypeName()
{
  return _subTypeName;
}


std::string& GeneralisationDTO::getSuperTypeName()
{
  return _superTypeName;
}


int& GeneralisationDTO::getSuperTypeId()
{
  return _superTypeId;
}


int& GeneralisationDTO::getSubTypeId()
{
  return _subTypeId;
}


int& GeneralisationDTO::getSuperTypeDomainId()
{
  return _superTypeDomainId;
}

int& GeneralisationDTO::getSubTypeDomainId()
{
  return _subTypeDomainId;
}


}


}
