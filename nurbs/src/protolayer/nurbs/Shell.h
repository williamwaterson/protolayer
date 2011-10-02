#ifndef PROTOLAYER_SHELL_H
#define PROTOLAYER_SHELL_H

#include <set>

#include "HalfEdge.h"
#include "HalfFace.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Shell
{
  /** TODO: Documentation */
  std::set <HalfFace*> _faceUses;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Shell();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Shell();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shell(const Shell& shell);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shell& operator=(const Shell& shell);

};


}


}


#endif // PROTOLAYER_SHELL_H
