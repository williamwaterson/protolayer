#ifndef PROTOLAYER_FACE_H
#define PROTOLAYER_FACE_H

#include <set>

#include "HalfFace.h"
#include "Loop.h"
#include "Surface.h"

namespace protolayer
{

namespace nurbs
{

// Forward declarations
class Shell;


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Face
{
  /** TODO: Documentation */
  friend class Shell;

  /** TODO: Documentation */
  Surface& _surface;

  /** TODO: Documentation */
  Loop& _outerLoop;

  /** TODO: Documentation */
  ::std::set <Loop*> _innerLoops;

  /** TODO: Documentation */
  HalfFace _firstHalfFace;

  /** TODO: Documentation */
  HalfFace _secondHalfFace;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Face(Surface& surface, Loop& outerLoop);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Face();

  /**
   * TODO: Documentation
   * <p>
   */
  Surface& getSurface();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfFace& getFirstHalfFace();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfFace& getSecondHalfFace();

  /**
   * TODO: Documentation
   * <p>
   */
  Loop& getOuterLoop();

  /**
   * TODO: Documentation
   * <p>
   */
  void addLoop(Loop& loop);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeLoop(Loop& loop);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Face(const Face& face);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Face& operator=(const Face& face);

};


}


}


#endif // PROTOLAYER_FACE_H
