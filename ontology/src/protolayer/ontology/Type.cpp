#include "Type.h"


namespace protolayer
{

namespace ontology
{

Type::Type(ontologydto::TypeDTO& typeDTO)
{
  _id = typeDTO.getId();
  _domainId = typeDTO.getDomainId();
  _isLeaf = typeDTO.isLeaf();
  _isAbstract = typeDTO.isAbstract();
  _isSingleton = typeDTO.isSingleton();
  _name = typeDTO.getName();

  std::cout << "id " << _id << std::endl;
}


Type::~Type()
{
}


int Type::getId() const
{
  return _id;
}


int Type::getDomainId() const
{
  return _domainId;
}


const std::string& Type::getName() const
{
  return _name;
}


bool Type::isLeaf() const
{
  return _isLeaf;
}


bool Type::isAbstract() const
{
  return _isAbstract;
}


bool Type::isSingleton() const
{
  return _isSingleton;
}


}


}
