#ifndef PROTOLAYER_PROTO_INSTANCECREATION_H
#define PROTOLAYER_PROTO_INSTANCECREATION_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

#include "../GraphInteraction.h"
#include "../action/CreateInstance.h"

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
class InstanceCreation : public GraphInteraction
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

  /** TODO: Documentation */
  CreateInstance* _createInstance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit InstanceCreation(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~InstanceCreation();

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
  InstanceCreation(const InstanceCreation& instanceCreation);

  /**
   * TODO: Documentation
   *
   */
  InstanceCreation& operator=(const InstanceCreation& instanceCreation);

};


}


}


}


#endif // PROTOLAYER_PROTO_INSTANCECREATION_H
