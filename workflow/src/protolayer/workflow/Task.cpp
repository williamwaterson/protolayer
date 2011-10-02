#include "Task.h"


namespace protolayer
{ 

namespace workflow
{

Task::Task()
{
  _undoDepth = 20;
}


Task::~Task()
{
}


bool Task::canRedo()
{
  return _currentStep != _stepQueue.begin();
}


bool Task::canUndo()
{
  return _currentStep != _stepQueue.end();
}


void Task::clearStaleHistory()
{
  if (canRedo()) {
    _currentStep = _stepQueue.erase(_stepQueue.begin(), _currentStep - 1);
  }
}


void Task::append(Step& step)
{
  clearStaleHistory();
  _stepQueue.push_front(&step);
  if (_stepQueue.size() > _undoDepth) {
    _stepQueue.pop_back();
  }
  _currentStep = _stepQueue.begin();
}


void Task::doit()
{
  if (canRedo()) {
    (*_currentStep)->doit();
    _currentStep--;
  }
}


void Task::undo()
{
  if (canUndo()) {
    (*_currentStep)->undo();
    _currentStep++;
  }
}


}


}
