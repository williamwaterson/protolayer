#include "Component.h"


namespace protolayer
{

namespace carbon
{

bool Component::isWithin(short x, short y)
{
  return (_bounds->left <= x) && (_bounds->right > x) &&
         (_bounds->top <= y) && (_bounds->bottom > y);
}


Component::Component()
{
  _bounds = new Rect();
  SetRect(_bounds, 0, 0, 0, 0);
}


Component::Component(short left,
                     short top,
                     short right,
                     short bottom)
{
  _bounds = new Rect();
  SetRect(_bounds, left, top, right, bottom);
}


short
Component::getPositionLeft() const
{
  return _bounds->left;
}


short
Component::getPositionRight() const
{
  return _bounds->right;
}


short
Component::getPositionTop() const
{
  return _bounds->top;
}


short
Component::getPositionBottom() const
{
  return _bounds->bottom;
}


Component::~Component()
{
  delete _bounds;
}


Rect*
Component::getBounds()
{
  return _bounds;
}


void
Component::setSize(short w, short h)
{
  short x = getPositionLeft();
  short y = getPositionTop();
  SetRect(_bounds, x, y, x + w, y + h);  
}


void
Component::addKeyboardListener(KeyboardListener& listener)
{
  addListener(listener);
}


void
Component::removeKeyboardListener(KeyboardListener& listener)
{
  removeListener(listener);
}


void
Component::addListener(Listener& listener)
{
  if (_listenerMap.count(&listener) == 0) {
    _listenerMap[&listener] = NULL;
    if (getEventTargetRef() != NULL) {
      InstallEventHandler(getEventTargetRef(),
                          listener.getEventHandlerUPP(),
                          listener.getNumberEventTypes(),
                          listener.getEventTypes(),
                          reinterpret_cast <void*> (&listener),
                          &(_listenerMap[&listener]));
    }
  }
}


void
Component::removeListener(Listener& listener)
{
  if (_listenerMap.count(&listener) != 0) {
    if (getEventTargetRef() != NULL) {
      RemoveEventHandler(_listenerMap[&listener]);
    }
    _listenerMap.erase(&listener);
  }
}


void Component::initialise()
{
  ListenerIteratorType iter;
  ListenerIteratorType end = _listenerMap.end();
  for (iter = _listenerMap.begin() ; iter != end; ++iter) {
    Listener* listener = (*iter).first;
    InstallEventHandler(getEventTargetRef(),
                        listener->getEventHandlerUPP(),
                        listener->getNumberEventTypes(),
                        listener->getEventTypes(),
                        reinterpret_cast <void*> (listener),
                        &(_listenerMap[listener]));
  }
}


void Component::cleanup()
{
  ListenerIteratorType iter;
  ListenerIteratorType end = _listenerMap.end();
  for (iter = _listenerMap.begin() ; iter != end; ++iter) {
    RemoveEventHandler((*iter).second);
  }
}


}


}
