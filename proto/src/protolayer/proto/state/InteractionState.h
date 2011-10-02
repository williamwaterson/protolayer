#ifndef MESON_INTERACTIONSTATE_H
#define MESON_INTERACTIONSTATE_H


#include "../forward.h"
#include "RenderingState.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class InteractionState
{
  /** TODO: Documentation */
  RenderingState* _renderingState;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  explicit InteractionState(RenderingState& renderingState);

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~InteractionState() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseDown(float x, float y, int clickCount);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseMoved(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseDragged(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void mouseUp(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void keyDown();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void keyUp();

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  InteractionState(const InteractionState& state);

  /**
   * TODO: Documentation
   * <p>
   */  
  InteractionState& operator=(const InteractionState& state);

};


}


}


#endif MESON_INTERACTIONSTATE_H
