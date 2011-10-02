#ifndef PROTOLAYER_PROTO_PANCAMERA_H
#define PROTOLAYER_PROTO_PANCAMERA_H

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
class PanCamera : public GraphInteraction
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
  PanCamera(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~PanCamera();

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
  PanCamera(const PanCamera& panCamera);

  /**
   * TODO: Documentation
   *
   */
  PanCamera& operator=(const PanCamera& panCamera);

};


}


}


}


#endif // PROTOLAYER_PROTO_PANCAMERA_H
