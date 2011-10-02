#ifndef PROTOLAYER_ANIMATION_TRANSITIONACTION_H
#define PROTOLAYER_ANIMATION_TRANSITIONACTION_H

#include "protolayer/protolayer-scenegraph.h"
#include "Action.h"


namespace protolayer
{

namespace animation
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class TransitionAction : public Action
{
  /** TODO: Documentation */
  scenegraph::Shot* _initialShot;

  /** TODO: Documentation */
  scenegraph::Shot* _finalShot;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  TransitionAction(scenegraph::Shot& initialShot, scenegraph::Shot& finalShot);

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~TransitionAction() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setInitialShot(scenegraph::Shot& initialShot);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setFinalShot(scenegraph::Shot& finalShot);

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Shot& getInitialShot();

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Shot& getFinalShot();

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


#endif // PROTOLAYER_ANIMATION_TRANSITIONACTION_H
