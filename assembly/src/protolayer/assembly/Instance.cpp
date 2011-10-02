#include "Instance.h"


namespace protolayer
{

namespace assembly
{

Instance::Instance(
ontology::Type& type) throw (Exception)
{
  _type = &type;
  _techniqueUrn = "urn:protolayer:tech1";

  if (_type->isAbstract()) {
    throw Exception("Cannot construct from abstract type.");
  }
}


Instance::Instance(iostream::XdrInputStream& stream,
				 std::map <int, void*> addressMappings)
{
  stream.read(_name);

  int id = 0;
   stream.read(id);
  _type = reinterpret_cast < ontology::Type* > (addressMappings[id]);

  _techniqueUrn = "urn:protolayer:tech1";
}


Instance::~Instance()
{
}


void Instance::encode(iostream::XdrOutputStream& stream)
{
  stream.write(_name);

  stream.write((int) _type);

  /*
  typedef std::map <std::string, bool>::iterator StrBoolIterType;
  for (StrBoolIterType iter = _boolTuples.begin(); iter != _boolTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::BOOL);
    stream.write(iter->second);
  }

  typedef std::map <std::string, short>::iterator StrShortIterType;
  for (StrShortIterType iter = _shortTuples.begin(); iter != _shortTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::SHORT);
    stream.write(iter->second);
  }

  typedef std::map <std::string, int>::iterator StrIntIterType;
  for (StrIntIterType iter = _intTuples.begin(); iter != _intTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::INT);
    stream.write(iter->second);
  }

  typedef std::map <std::string, long>::iterator StrLongIterType;
  for (StrLongIterType iter = _longTuples.begin(); iter != _longTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::LONG);
    stream.write(iter->second);
  }

  typedef std::map <std::string, float>::iterator StrFloatIterType;
  for (StrFloatIterType iter = _floatTuples.begin(); iter != _floatTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::FLOAT);
    stream.write(iter->second);
  }

  typedef std::map <std::string, double>::iterator StrDoubleIterType;
  for (StrDoubleIterType iter = _doubleTuples.begin(); iter != _doubleTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::DOUBLE);
    stream.write(iter->second);
  }

  typedef std::map <std::string, std::string>::iterator StrStrIterType;
  for (StrStrIterType iter = _stringTuples.begin(); iter != _stringTuples.end(); iter++) {
    stream.write(iter->first);
    stream.write(net::DataProtocol::STRING);
    stream.write(iter->second);
  }
  */
}


void Instance::encode(xercesc::DOMElement& document)
{
}


ontology::Type& Instance::getType()
{
  return *_type;
}


void Instance::setTechniqueUrn(const std::string& techniqueUrn)
{
  _techniqueUrn = techniqueUrn;
}


const std::string& Instance::getTechniqueUrn() const
{
  return _techniqueUrn;
}


bool Instance::instantiates(ontology::Type& type)
{
  return _type == &type;
}


void Instance::setName(const std::string& name)
{
  _name = name;
}


const std::string& Instance::getName() const
{
  return _name;
}


}


}
