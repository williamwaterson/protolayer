#ifndef PROTOLAYER_PROTO_REFERENCECREATION_H
#define PROTOLAYER_PROTO_REFERENCECREATION_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

#include "../GraphInteraction.h"

namespace protolayer
{

namespace proto
{

namespace interaction
{

/**
 * TODO: Documentation
 * <p>
 */
class ReferenceCreation : public GraphInteraction
{
private:
  /** TODO: Documentation */
  float _oldMouseX;

  /** TODO: Documentation */
  float _oldMouseY;

  /** TODO: Documentation */
  float _mouseX;

  /** TODO: Documentation */
  float _mouseY;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit ReferenceCreation(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~ReferenceCreation();

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseDown(float x, float y, int clickCount);

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseMoved(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseDragged(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseUp(float x, float y);

  /**
   * TODO: Documentation
   * <p>
   */
  void keyDown();

  /**
   * TODO: Documentation
   * <p>
   */
  void keyUp();

private:
  /**
   * TODO: Documentation
   *
   */
  ReferenceCreation(const ReferenceCreation& referenceCreation);

  /**
   * TODO: Documentation
   *
   */
  ReferenceCreation& operator=(const ReferenceCreation& referenceCreation);

};


}


}


}


#endif // PROTOLAYER_PROTO_REFERENCECREATION_H
