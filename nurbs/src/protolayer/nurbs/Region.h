#ifndef PROTOLAYER_REGION_H
#define PROTOLAYER_REGION_H

#include <set>

#include "Shell.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Region
{
  /** TODO: Documentation */
  std::set <Shell*> _shells;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Region();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Region();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Region(const Region& region);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Region& operator=(const Region& region);

};


}


}


#endif // PROTOLAYER_REGION_H
