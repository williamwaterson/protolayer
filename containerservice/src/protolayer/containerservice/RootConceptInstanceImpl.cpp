#include "RootConceptInstanceImpl.h"


namespace protolayer
{

namespace containerservice
{

namespace
{

template <class Param>
inline const Param& getValue(const std::map <std::string, Param>& dictionary,
		       const std::string& name)
  throw (std::runtime_error)
{
  typename std::map <std::string, Param>::const_iterator result = dictionary.find(name);
  return (*result).second;
  
//  return result =! dictionary.end() ? (*result).second : throw std::runtime_error("Non-existent attribute");

    //  if (dictionary.count(name) == 0) {
    //    throw std::runtime_error("Non-existent attribute");
//  }

//  typedef std::map <std::string, Param> MapType;
//  return (const_cast <MapType*> (&dictionary))->operator[](name);
}


}


void RootConceptInstanceImpl::decodeInstances(iostream::XdrInputStream& istream)
{
}

 
void RootConceptInstanceImpl::decodeReferences(iostream::XdrInputStream& istream)
{
}


RootConceptInstanceImpl::RootConceptInstanceImpl(iostream::XdrInputStream& stream)
{
  // Extract all instances in tree
  //  std::map <int, void*> addressMappings;

  //  decodeInstances(stream);
  //  decodeReferences(stream);

  /*
  int id = 0;
  int numberOf = 0;

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Domain* domain = new Domain(stream, addressMappings);
    _domainDictionary[domain->getName()] = domain;    
    addressMappings[id] = reinterpret_cast <void*> (domain);
    Domain::IteratorType typeIter;
    for (typeIter = domain->getTypes(); typeIter.hasNext(); ) {
      Type& type = typeIter.next();
      _typeDictionary[type.getQualifiedName()] = &type;
    }
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Association* association = new Association(stream, addressMappings);
    _associations.insert(association);
    addressMappings[id] = reinterpret_cast <void*> (association);
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Generalisation* generalisation = new Generalisation(stream, addressMappings);
    _generalisations.insert(generalisation);
    addressMappings[id] = reinterpret_cast <void*> (generalisation);
  }
  */
}


RootConceptInstanceImpl::~RootConceptInstanceImpl()
{
}


bool RootConceptInstanceImpl::getBoolValue(const std::string& name) const
{
  return getValue(_boolTuples, name);
}


short RootConceptInstanceImpl::getShortValue(const std::string& name) const
{
  return getValue(_shortTuples, name);
}


long RootConceptInstanceImpl::getLongValue(const std::string& name) const
{
  return getValue(_longTuples, name);
}


float RootConceptInstanceImpl::getFloatValue(const std::string& name) const
{
  return getValue(_floatTuples, name);
}


double RootConceptInstanceImpl::getDoubleValue(const std::string& name) const
{
  return getValue(_doubleTuples, name);
}


const std::string& RootConceptInstanceImpl::getStringValue(const std::string& name) const
{
  return getValue(_stringTuples, name);
}


}


}
