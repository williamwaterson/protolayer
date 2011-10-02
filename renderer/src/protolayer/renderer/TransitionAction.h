#ifndef PROTOLAYER_RENDERER_TRANSITIONACTION_H
#define PROTOLAYER_RENDERER_TRANSITIONACTION_H

#include "Shot.h"
#include "Space.h"

namespace protolayer
{

namespace renderer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class TransitionAction : public Action
{
  /** TODO: Documentation */
  Space* _space;

  /** TODO: Documentation */
  Shot* _initialShot;

  /** TODO: Documentation */
  Shot* _finalShot;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  TransitionAction(Space& space, Shot& initialShot, Shot& finalShot);

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~TransitionAction() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setSpace(Space& space);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setInitialShot(Shot& initialShot);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setFinalShot(Shot& finalShot);

  /**
   * TODO: Documentation
   * <p>
   */
  Space& getSpace();

  /**
   * TODO: Documentation
   * <p>
   */
  Shot& getInitialShot();

  /**
   * TODO: Documentation
   * <p>
   */
  Shot& getFinalShot();

  /**
   * Performs a single increment in the transition from the initial scene
   * to the final scene according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial scene to the final
   * scene.
   * <p>
   * @param initialScene
   *
   * @param finalScene
   *
   */

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TransitionAction(const TransitionAction& transitionAction);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TransitionAction& operator=(const TransitionAction& transitionAction);

};


}


}


#endif // PROTOLAYER_RENDERER_TRANSITIONACTION_H
