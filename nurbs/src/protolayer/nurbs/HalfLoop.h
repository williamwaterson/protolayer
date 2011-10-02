#ifndef PROTOLAYER_LOOPUSE_H
#define PROTOLAYER_LOOPUSE_H

#include <deque>
#include "HalfEdge.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class HalfLoop
{
  /** TODO: Documentation */
  std::deque <HalfEdge*> _edgeUses;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HalfLoop();

  /**
   * TODO: Documentation
   * <p>
   */
  ~HalfLoop();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HalfLoop(const HalfLoop& loopUse);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HalfLoop& operator=(const HalfLoop& loopUse);

};


}


}


#endif // PROTOLAYER_LOOPUSE_H
