#ifndef PROTOLAYER_CONTAINERSERVICE_ROOTCONCEPTINSTANCE_H
#define PROTOLAYER_CONTAINERSERVICE_ROOTCONCEPTINSTANCE_H

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
class RootConceptInstance : public ConceptInstance
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  RootConceptInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RootConceptInstance() = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RootConceptInstance(const RootConceptInstance& conceptInstance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RootConceptInstance& operator=(const RootConceptInstance& conceptInstance);

};


}


#endif // PROTOLAYER_CONTAINERSERVICE_ROOTCONCEPTINSTANCE_H
