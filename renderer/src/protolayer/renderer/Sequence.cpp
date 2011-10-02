#include "Sequence.h"


namespace protolayer
{

namespace renderer
{

Sequence::Sequence()
{
  _inProgress = false;

  _timeElapsed = ZERO;
  _timeStarted = ZERO;
  _timeCurrent = ZERO;
}


Sequence::~Sequence()
{
}


void Sequence::commence(float timeStarted)
{
  _timeStarted = timeStarted;
  _inProgress = true;
}


bool Sequence::inProgress()
{
  return _inProgress;
}


void Sequence::increment(float timeCurrent)
{
  _timeCurrent = timeCurrent;
  _timeElapsed = _timeCurrent - _timeStarted;

  while (_queue.empty() == false && _queue.top()->_time < _timeElapsed) {
    Event* event = _queue.top();
    event->_action->commence(_timeElapsed);
    _activeEvents.insert(event);
    _queue.pop();
  }

  typedef std::set <Event*>::iterator IterType;

  std::set <Event*> forRemoval;
  for (IterType iter = _activeEvents.begin(); iter != _activeEvents.end(); iter++) {
    Event* event = *iter;
    event->_action->increment(_timeElapsed);
    if (event->_action->inProgress() == false) {
      forRemoval.insert(event);
    }
  }

  for (IterType iter = forRemoval.begin(); iter != forRemoval.end(); iter++) {
    Event* event = *iter;
    event->_action->postComplete();
    _activeEvents.erase(event);
  }

  if (_activeEvents.empty() && _queue.empty()) {
    _inProgress = false;
  }
}


void Sequence::postComplete()
{
  _timeElapsed = ZERO;
  _timeStarted = ZERO;
  _timeCurrent = ZERO;

  typedef std::set <Event*>::iterator IterType;

  _queue = EventQueueType();
  for (IterType iter = _events.begin(); iter != _events.end(); iter++) {
    Event* event = *iter;
    _queue.push(event);
  }
}


Event* Sequence::createEvent(float time, Action& action)
{
  Event* result = 0;
  if (_actions.find(&action) == _actions.end()) {
    result = new Event(time, action);
    _actions.insert(&action);
    _events.insert(result);
    _queue.push(result);
  }
  return result;
}


void Sequence::clearEvents()
{
  _actions.clear();
  _events.clear();
  while (_queue.empty() == false && _queue.top()->_time < _timeElapsed) {
    Event* event = _queue.top();
    _queue.pop();
    _activeEvents.erase(event);
    delete event;
  }
}


}


}

