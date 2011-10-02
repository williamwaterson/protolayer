#include "Timeline.h"


namespace protolayer
{ 

namespace workflow
{

Timeline::Timeline()
{
  _undoDepth = 20;
}


Timeline::~Timeline()
{
}


void Timeline::displaySearchPerspective()
{
}


void Timeline::displayInstancePerspective()
{
}


void Timeline::displayConceptPerspective()
{
}


void Timeline::displaySpatialPerspective()
{
}


void Timeline::setToSelectState()
{
}


void Timeline::setToCreateInstanceState()
{
}


void Timeline::setToCreateReferenceState()
{
}


void Timeline::setToPanCameraState()
{
}
  

void Timeline::setToMoveCameraState()
{
}


void Timeline::setToTargetCameraState()
{
}


void Timeline::upLayer()
{
}


void Timeline::downLayer()
{
}


void Timeline::zoomIn()
{

}


void Timeline::zoomOut()
{

}


bool Timeline::canRedo()
{
  return _currentTask != _taskQueue.begin();
}


bool Timeline::canUndo()
{
  return _currentTask != _taskQueue.end();
}


void Timeline::clearStaleHistory()
{
  if (canRedo()) {
    _currentTask = _taskQueue.erase(_taskQueue.begin(), _currentTask - 1);
  }
}


void Timeline::append(Task& task)
{
  clearStaleHistory();
  _taskQueue.push_front(&task);
  if (_taskQueue.size() > _undoDepth) {
    _taskQueue.pop_back();
  }
  _currentTask = _taskQueue.begin();
}


void Timeline::redo()
{
  if (canRedo()) {
    (*_currentTask)->doit();
    _currentTask--;
  }
}


void Timeline::undo()
{
  if (canUndo()) {
    (*_currentTask)->undo();
    _currentTask++;
  }
}


}


}
