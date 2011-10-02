#ifndef TEMP
#define TEMP

#include <protolayer/protolayer-iostream.h>
#include "TypeService.h"

namespace protolayer
{

namespace registration
{

namespace 
{

}


void encode(iostream::XdrOutputStream& stream, TypeService& instance)
{
  stream.write(instance._name);
  stream.write(instance._flag);
}


void decode(iostream::XdrInputStream& stream, TypeService& instance)
{
  stream.read(instance._name);
  stream.read(instance._flag);
}


void encode(iostream::XdrOutputStream& stream, TypeService* instance)
{
  stream.write(instance->_name);
  stream.write(instance->_flag);
}


void decode(iostream::XdrInputStream& stream, TypeService* instance)
{
  stream.read(instance->_name);
  stream.read(instance->_flag);
}


void decode(iostream::XdrInputStream& stream, std::set <TypeService*>& collection) {
  int numberOf = 0;
  for (int i = 0; i < numberOf; ++i) {
    TypeService* instance = new TypeService();
    decode(stream, instance);
    collection.insert(instance);
  }
}


void encode(iostream::XdrOutputStream& stream, std::set <TypeService*>& collection) {
  stream.write((int) collection.size());
  for (std::set <TypeService*>::iterator iter = collection.begin(); iter != collection.end(); iter++) {
    encode(stream, *iter);
  }
}


}


}


#endif

