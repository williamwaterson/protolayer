#ifndef PROTOLAYER_PROTO_SELECT_H
#define PROTOLAYER_PROTO_SELECT_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

#include "../../state/StateLayer.h"
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
class Select : public GraphInteraction
{
private:
  /** TODO: Documentation */
  StateLayer* _stateLayer;

  /** TODO: Documentation */
  style::Appearance* _domainAppearance;

  /** TODO: Documentation */
  style::Appearance* _selectedDomainAppearance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Select(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Select();

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
  Select(const Select& select);

  /**
   * TODO: Documentation
   *
   */
  Select& operator=(const Select& select);

};


}


}


}


#endif // PROTOLAYER_PROTO_SELECT_H
