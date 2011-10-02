#ifndef PROTOLAYER_PROTO_CONTROLLERLAYER_H
#define PROTOLAYER_PROTO_CONTROLLERLAYER_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

#include "../forward.h"
#include "../state/StateLayer.h"
#include "interaction/Select.h"
#include "interaction/PanCamera.h"
#include "interaction/MoveCamera.h"
#include "interaction/TargetCamera.h"
#include "interaction/ZoomCamera.h"
#include "interaction/InstanceCreation.h"
#include "interaction/ReferenceCreation.h"

namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class ControllerLayer
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  static ControllerLayer* getControllerLayer(StateLayer& layer);

  /**
   * TODO: Documentation
   * <p>
   */
  static ControllerLayer* getControllerLayer(ViewLayer& layer);

private:
  /** TODO: Documentation */
  StateLayer* _stateLayer;

  /** TODO: Documentation */
  EventLoopTimerRef _animationTimerRef;

  /** TODO: Documentation */
  Interaction* _currentInteraction;

  /** TODO: Documentation */
  workflow::Timeline _timeline;

  /** TODO: Documentation */
  interaction::Select* _select;

  /** TODO: Documentation */
  interaction::PanCamera* _panCamera;

  /** TODO: Documentation */
  interaction::MoveCamera* _moveCamera;

  /** TODO: Documentation */
  interaction::TargetCamera* _targetCamera;

  /** TODO: Documentation */
  interaction::ZoomCamera* _zoomCamera;

  /** TODO: Documentation */
  interaction::InstanceCreation* _instanceCreation;

  /** TODO: Documentation */
  interaction::ReferenceCreation* _referenceCreation;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit ControllerLayer(StateLayer& stateLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  ~ControllerLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  Interaction& getCurrentInteraction();

  /**
   * TODO: Documentation
   * <p>
   */
  StateLayer& getStateLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  ViewLayer& getViewLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySearchPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void displayInstancePerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void displayConceptPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void displaySpatialPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void setCreationType(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  void setToSelectState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setToCreateInstanceState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setToCreateReferenceState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setToPanCameraState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setToMoveCameraState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setToTargetCameraState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setToZoomCameraState();

  /**
   * TODO: Documentation
   * <p>
   */
  void upLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void downLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void zoomIn();

  /**
   * TODO: Documentation
   * <p>
   */
  void zoomOut();

  /**
   * TODO: Documentation
   * <p>
   */
  void mouseMoved(float x, float y);

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
  ControllerLayer(const ControllerLayer& controllerLayer);

  /**
   * TODO: Documentation
   *
   */
  ControllerLayer& operator=(const ControllerLayer& controllerLayer);

  /**
   * TODO: Documentation
   *
   */
  OSStatus installButtonHandler(HIViewRef view,
				EventHandlerUPP handlerUPP);

  /**
   * TODO: Documentation
   *
   */
  OSStatus installWindowHandlers();

};


}


}


#endif // PROTOLAYER_PROTO_CONTROLLERLAYER_H
