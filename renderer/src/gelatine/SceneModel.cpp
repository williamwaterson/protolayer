#include "SceneModel.h"


namespace gelatine
{


SceneModel::SceneModel()
{
  _alpha = 1.0f;
  _backgroundColor[0] = 0.5f;
  _backgroundColor[1] = 0.5f;
  _backgroundColor[2] = 0.5f;
  _backgroundColor[3] = 0.5f;
}


float
SceneModel::getAlpha() const
{
  return _alpha;
}


SceneModel::ShapeIteratorType
SceneModel::getShapes()
{
  return _shapes.begin();
}


SceneModel::ShapeIteratorType
SceneModel::getLastShape()
{
  return _shapes.end();
}


/*
void
SceneModel::add(Shape& shape)
{
  int id = _idGenerator.obtainID();
  shape.getModel().setID(id);
  _shapeNameMap.insert(std::map <int, Shape*>::value_type(id, &shape));
  _shapes.insert(&shape);
}


void
SceneModel::remove(Shape& shape)
{
  _shapeNameMap.erase(shape.getModel().getID());
  _shapes.erase(&shape);
}
*/

void
SceneModel::trigger(Action& action)
{
  if (!action.inProgress()) {
    _actionsForTriggering.insert(&action);
  }
}


SceneModel::ActionIteratorType
SceneModel::getActionsForTriggering()
{
  return _actionsForTriggering.begin();
}


SceneModel::ActionIteratorType
SceneModel::getActionsInProgress()
{
  return _actionsInProgress.begin();
}


void
SceneModel::incrementActions()
{
  Action* action;
  ActionIteratorType iter;
  ActionIteratorType end = _actionsInProgress.end();
  for (iter = _actionsInProgress.begin(); iter != end; ++iter) {
    action = *iter;
    Microseconds(&_tick);
    _time = (float) UnsignedWideToUInt64(_tick);
    action->increment(_time);
  }
}


void
SceneModel::commenceTriggeredActions()
{
  Action* action;
  ActionIteratorType iter;
  ActionIteratorType end = _actionsForTriggering.end();    
  for (iter = getActionsForTriggering(); iter != end; ++iter) {
    action = *iter;
    Microseconds(&_tick);
    _time = (float) UnsignedWideToUInt64(_tick);
    action->commence(_time);
    _actionsInProgress.insert(action);
  }

  _actionsForTriggering.clear();
}


void
SceneModel::releaseCompletedActions()
{
  Action* action;
  ActionIteratorType iter;
  ActionIteratorType end = _actionsInProgress.end();
  for (iter = _actionsInProgress.begin(); iter != end; ++iter) {
    action = *iter;
    if (!action->inProgress()) {
      _actionsInProgress.erase(action);
    }
  }
}


float*
SceneModel::getBackgroundColor()
{
  return _backgroundColor;
}


ProjectedMouse&
SceneModel::getProjectedMouse()
{
  return _projectedMouse;
}


SelectionPlane&
SceneModel::getSelectionPlane()
{
  return _selectionPlane;
}


protolayer::IDGenerator&
SceneModel::getIDGenerator()
{
  return _idGenerator;
}


//Shape*
//SceneModel::getShapeForName(int name)
//{
//  if (_shapeNameMap.count(name) != 0) {
//    return _shapeNameMap[name]; 
//  }
//  return 0;
//}


void
SceneModel::setAlpha(float alpha)
{
  _alpha = alpha;
}


void
SceneModel::setBackgroundColor(float red,
                               float blue,
                               float green,
                               float alpha)
{
  _backgroundColor[0] = red;
  _backgroundColor[1] = blue;
  _backgroundColor[2] = green;
  _backgroundColor[3] = alpha;
}


}
