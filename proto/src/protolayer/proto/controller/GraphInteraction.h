#ifndef PROTOLAYER_PROTO_GRAPHINTERACTION_H
#define PROTOLAYER_PROTO_GRAPHINTERACTION_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

#include "Interaction.h"
#include "../state/StateLayer.h"

namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class GraphInteraction : public Interaction
{
private:
  /** TODO: Documentation */
  StateLayer* _stateLayer;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  GraphInteraction(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GraphInteraction() = 0;

  /**
   * TODO: Documentation
   *
   */
  StateLayer& getStateLayer();

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
   *
   */
  GraphInteraction(const GraphInteraction& graphInteraction);

  /**
   * TODO: Documentation
   *
   */ 
  GraphInteraction& operator=(const GraphInteraction& graphInteraction);

  /**
   * TODO: Documentation
   *
   */
  void updateProjectedMouse(float x, float y);

};


}


}


#endif // PROTOLAYER_PROTO_GRAPHINTERACTION_H
