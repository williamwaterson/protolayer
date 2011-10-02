#ifndef PROTOLAYER_CONTAINERSERVICE_IMMUTABLECONCEPTINSTANCE_H
#define PROTOLAYER_CONTAINERSERVICE_IMMUTABLECONCEPTINSTANCE_H

#include <stdexcept>
#include <map>

#include "ConceptInstance.h"

#include "Exception.h"

namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ImmutableConceptInstance : public ConceptInstance
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ImmutableConceptInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ImmutableConceptInstance() = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ImmutableConceptInstance(const ImmutableConceptInstance& conceptInstance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ImmutableConceptInstance& operator=(const ImmutableConceptInstance& conceptInstance);

};


}


#endif // PROTOLAYER_CONTAINERSERVICE_IMMUTABLECONCEPTINSTANCE_H
