#ifndef PROTOLAYER_PROTO_MOVECAMERA_H
#define PROTOLAYER_PROTO_MOVECAMERA_H

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
class MoveCamera : public GraphInteraction
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
  explicit MoveCamera(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~MoveCamera();

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
  MoveCamera(const MoveCamera& moveCamera);

  /**
   * TODO: Documentation
   *
   */
  MoveCamera& operator=(const MoveCamera& moveCamera);

};


}


}


}


#endif // PROTOLAYER_PROTO_MOVECAMERA_H
