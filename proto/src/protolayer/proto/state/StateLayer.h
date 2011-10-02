#ifndef PROTOLAYER_PROTO_STATELAYER_H
#define PROTOLAYER_PROTO_STATELAYER_H

#include "../forward.h"
#include "../view/ViewLayer.h"

#include "RenderingState.h"

#include "SelectState.h"
#include "InteractionState.h"
#include "Perspective.h"

#include "Perspective.h"
#include "SearchPerspective.h"
#include "ConceptPerspective.h"
#include "InstancePerspective.h"
#include "Project.h"

#include "SelectionModel.h"


namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class StateLayer
{
public:
  static StateLayer* getStateLayer(ViewLayer& layer);

private:
  /** TODO: Documentation */
  SelectionModel* _selectionModel;

  /** TODO: Documentation */
  Project* _project;

  /** TODO: Documentation */
  ViewLayer *_view;

  /** TODO: Documentation */
  RenderingState* _renderingState;

  /** TODO: Documentation */
  InteractionState* _currentInteractionState;

  /** TODO: Documentation */
  Perspective* _currentPerspective;

  /** TODO: Documentation */
  ontology::TypeLayer* _selectedLayer;

  /** TODO: Documentation */
  ontology::Type* _creationType;

  /** TODO: Documentation */
  SelectState* defaultInteractionState;

  /** TODO: Documentation */
  SearchPerspective* _defaultPerspective;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit StateLayer(ViewLayer& view);

  /**
   * TODO: Documentation
   * <p>
   */
  ~StateLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  ViewLayer& getViewLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  SelectionModel& getSelectionModel()
  {
    return *_selectionModel;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  assembly::Assembly& getAssembly()
  {
    return _project->getAssembly();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  InteractionState& getCurrentInteractionState();

  /**
   * TODO: Documentation
   *
   */
  void setCurrentInteractionState(InteractionState& state);

  /**
   * TODO: Documentation
   *
   */
  void clearCreationType();

  /**
   * TODO: Documentation
   *
   */
  void setCreationType(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  Perspective& getCurrentPerspective();

  /**
   * TODO: Documentation
   *
   */
  void setCurrentPerspective(Perspective& perspective);

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
  void zoom(float factor);

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
  StateLayer(const StateLayer& stateLayer);

  /**
   * TODO: Documentation
   *
   */
  StateLayer& operator=(const StateLayer& stateLayer);

};


}


}


#endif // PROTOLAYER_PROTO_STATELAYER_H
