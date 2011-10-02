#ifndef PROTOLAYER_PROTO_ZOOMCAMERA_H
#define PROTOLAYER_PROTO_ZOOMCAMERA_H

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
class ZoomCamera : public GraphInteraction
{
private:
  /** TODO: Documentation */
  float _oldMouseY;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ZoomCamera(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~ZoomCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseDown(float x, float y, int clickCount);

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

private:
  /**
   * TODO: Documentation
   *
   */
  ZoomCamera(const ZoomCamera& zoomCamera);

  /**
   * TODO: Documentation
   *
   */
  ZoomCamera& operator=(const ZoomCamera& zoomCamera);

};


}


}


}


#endif // PROTOLAYER_PROTO_ZOOMCAMERA_H
