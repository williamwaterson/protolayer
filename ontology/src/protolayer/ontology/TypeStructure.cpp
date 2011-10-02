#include "TypeStructure.h"


namespace protolayer
{

namespace ontology
{

TypeStructure::TypeStructure(::std::set <TypeStack*>& stacks) :
  _stacks(stacks)
{  
}


TypeStructure::~TypeStructure()
{
}


int TypeStructure::getNumberStacks() const
{
  return _stacks.size();
}


TypeStructure::IteratorType TypeStructure::getStacks()
{
  return IteratorType(_stacks);
}


}


}
