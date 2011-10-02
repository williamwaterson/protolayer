#ifndef PROTOLAYER_PROTO_TARGETCAMERA_H
#define PROTOLAYER_PROTO_TARGETCAMERA_H

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
class TargetCamera : public GraphInteraction
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit TargetCamera(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~TargetCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseDown(float x, float y, int clickCount);

private:
  /**
   * TODO: Documentation
   *
   */
  TargetCamera(const TargetCamera& targetCamera);

  /**
   * TODO: Documentation
   *
   */
  TargetCamera& operator=(const TargetCamera& targetCamera);

};


}


}


}


#endif // PROTOLAYER_PROTO_TARGETCAMERA_H
