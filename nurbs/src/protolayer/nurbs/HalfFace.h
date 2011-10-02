#ifndef PROTOLAYER_FACEUSE_H
#define PROTOLAYER_FACEUSE_H

#include <set>
#include "HalfLoop.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class HalfFace
{
  /** TODO: Documentation */
  HalfLoop& _outerHalfLoop;

  /** TODO: Documentation */
  std::set <HalfLoop*> _innerHalfLoops;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HalfFace(HalfLoop& outerHalfLoop);

  /**
   * TODO: Documentation
   * <p>
   */
  ~HalfFace();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfLoop& getOuterHalfLoop();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HalfFace(const HalfFace& faceUse);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HalfFace& operator=(const HalfFace& faceUse);

};


}


}


#endif // PROTOLAYER_FACEUSE_H
