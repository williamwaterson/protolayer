#include "ImmutableConceptInstanceImpl.h"


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


ImmutableConceptInstanceImpl::ImmutableConceptInstanceImpl()
{
}


ImmutableConceptInstanceImpl::~ImmutableConceptInstanceImpl()
{
}


bool ImmutableConceptInstanceImpl::getBoolValue(const std::string& name) const
{
  return getValue(_boolTuples, name);
}


short ImmutableConceptInstanceImpl::getShortValue(const std::string& name) const
{
  return getValue(_shortTuples, name);
}


long ImmutableConceptInstanceImpl::getLongValue(const std::string& name) const
{
  return getValue(_longTuples, name);
}


float ImmutableConceptInstanceImpl::getFloatValue(const std::string& name) const
{
  return getValue(_floatTuples, name);
}


double ImmutableConceptInstanceImpl::getDoubleValue(const std::string& name) const
{
  return getValue(_doubleTuples, name);
}


const std::string& ImmutableConceptInstanceImpl::getStringValue(const std::string& name) const
{
  return getValue(_stringTuples, name);
}


}


}
