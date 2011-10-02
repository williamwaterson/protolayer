#include "StateLayer.h"


namespace protolayer
{ 

namespace proto
{

namespace 
{

std::map <ViewLayer*, StateLayer*> mappings;

}


StateLayer* StateLayer::getStateLayer(ViewLayer& layer)
{
  if (mappings.count(&layer) != 0) {
    return mappings[&layer];
  }
  return 0;
}


StateLayer::StateLayer(ViewLayer& view)
{
  mappings[&view] = this;
  _view = &view;
  _project = new Project();
  assembly::Assembly& assembly = _project->getAssembly();

  _selectionModel = new SelectionModel();

  _view->constructShots(assembly);
  _view->populateConceptSelectCombo(assembly.getOntology());
  _view->rendererBoundsChanged();

  scenegraph::Shot& shot = view.getRootShot();

  _renderingState = new RenderingState(shot);
  _defaultPerspective = new SearchPerspective();

  _currentPerspective = _defaultPerspective;
  _currentInteractionState = new SelectState(*_renderingState);

  _currentPerspective->activate(*_view);

  WindowRef window = _view->getWindow();
  ActivateWindow(window, true);
  SetPortWindowPort(window);
  ShowWindow(window);
  SelectWindow(window);
  ActivateWindow(window, true);

  _selectedLayer = 0;
  _creationType = 0;
}


StateLayer::~StateLayer()
{
  mappings.erase(_view);
}


void
StateLayer::setCreationType(ontology::Type& type)
{
  _creationType = &type;
}


void
StateLayer::clearCreationType()
{
  _creationType = 0;
}


void StateLayer::upLayer()
{
}


void StateLayer::downLayer()
{
}


void StateLayer::zoom(float factor)
{
  float value = getViewLayer().getCurrentShot().getCamera().getZoom();
  value *= factor;
  getViewLayer().getCurrentShot().getCamera().setZoom(value);
  getViewLayer().swapRendererPortsAndDisplay();
}


void StateLayer::mouseMoved(float x, float y)
{
  getCurrentInteractionState().mouseMoved(x, y);
}


void StateLayer::mouseDown(float x, float y, int clickCount)
{
  getCurrentInteractionState().mouseDown(x, y, clickCount);
}


void StateLayer::mouseDragged(float x, float y)
{
  getCurrentInteractionState().mouseDragged(x, y);
}


void StateLayer::mouseUp(float x, float y)
{
  getCurrentInteractionState().mouseUp(x, y);
}


void StateLayer::keyDown()
{
  getCurrentInteractionState().keyDown();
}


void StateLayer::keyUp()
{
  getCurrentInteractionState().keyUp();
}


//void StateLayer::setToSelectState()
//{
//  std::cout << "setToSelectState" << std::endl;
  //  _currentInteractionState = &_selectState;
//}


//void StateLayer::setToPanCameraState()
//{
  //  _panCameraState.setShot(*_currentShot);
  //_currentInteractionState = &_panCameraState;  
//}


//void StateLayer::setToMoveCameraState()
//{
  //  _moveCameraState.setShot(*_currentShot);
  //  _currentInteractionState = &_moveCameraState;  
//}


//void StateLayer::setToTargetCameraState()
//{
  //  _targetCameraState.setShot(*_currentShot);
  //_currentInteractionState = &_targetCameraState;  
//}


ViewLayer& StateLayer::getViewLayer()
{
  return *_view;
}


InteractionState& StateLayer::getCurrentInteractionState()
{
  return *_currentInteractionState;
}


void StateLayer::setCurrentInteractionState(InteractionState& state)
{
  _currentInteractionState = &state;
}


Perspective& StateLayer::getCurrentPerspective()
{
  return *_currentPerspective;
}


void StateLayer::setCurrentPerspective(Perspective& perspective)
{
  _currentPerspective = &perspective;
}



}


}
