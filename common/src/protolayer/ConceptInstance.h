#ifndef PROTOLAYER_LIGHTWEIGHTASSEMBLY_CONCEPTINSTANCE_H
#define PROTOLAYER_LIGHTWEIGHTASSEMBLY_CONCEPTINSTANCE_H

#include "Exception.h"

namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ConceptInstance
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ConceptInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ConceptInstance() = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ConceptInstance(const ConceptInstance& conceptInstance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ConceptInstance& operator=(const ConceptInstance& conceptInstance);

};


}


#endif // PROTOLAYER_LIGHTWEIGHTASSEMBLY_CONCEPTINSTANCE_H
