#include "IDGenerator.h"


namespace protolayer
{

namespace util
{

namespace
{
  IDGenerator generatorSingleton;
}


IDGenerator& IDGenerator::getInstance()
{
  return generatorSingleton;
}


IDGenerator::IDGenerator()
{
  _nextID = 1;
}


int
IDGenerator::obtainID()
{
  _nextID++;
  return _nextID;
}


void
IDGenerator::free(int id)
{
}


}


}
