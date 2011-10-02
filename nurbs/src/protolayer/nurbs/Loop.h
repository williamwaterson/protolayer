#ifndef PROTOLAYER_LOOP_H
#define PROTOLAYER_LOOP_H

#include <set>

#include "Edge.h"
#include "HalfLoop.h"

namespace protolayer
{

namespace nurbs
{

// Forward declarations
class Face;


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Loop
{
  /** TODO: Documentation */
  friend class Face;

  /** TODO: Documentation */
  ::std::set <Edge*> _edges;

  /** TODO: Documentation */
  HalfLoop _firstHalfLoop;

  /** TODO: Documentation */
  HalfLoop _secondHalfLoop;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Loop();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Loop();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfLoop& getFirstHalfLoop();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfLoop& getSecondHalfLoop();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Loop(const Loop& loop);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Loop& operator=(const Loop& loop);

};


}


}


#endif // PROTOLAYER_LOOP_H
