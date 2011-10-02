#ifndef PROTOLAYER_TYPESTRUCTURE_H
#define PROTOLAYER_TYPESTRUCTURE_H

#include <set>

#include <protolayer/protolayer-util.h>

#include "TypeStack.h"

namespace protolayer
{

namespace ontology
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class TypeStructure
{
public:
  /** TODO: Documentation */
  typedef util::SetIterator <TypeStack> IteratorType;

private:
  /** TODO: Documentation */
  std::set <TypeStack*> _stacks;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeStructure(std::set <TypeStack*>& stacks);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeStructure(iostream::XdrInputStream& stream,
                std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  ~TypeStructure();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberStacks() const;

  /**
   * TODO: Documentation
   * <p>
   */
  IteratorType getStacks();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeStructure(const TypeStructure& typeStructure);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeStructure& operator=(const TypeStructure& typeStructure);

};


}


}


#endif // PROTOLAYER_TYPESTRUCTURE_H
