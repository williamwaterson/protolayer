#include "Control.h"

namespace protolayer
{

namespace carbon
{

Control::Control()
{
  _size = AUTO_SIZE;
  _controlRef = NULL;
  _eventTargetRef = NULL;
  _isOwned = false;
  _isVisible = true;
  _isActive = true;
}


Control::Control(ControlRef ref)
{
  _size = AUTO_SIZE;
  _controlRef = ref;
  _eventTargetRef = NULL;
  _isOwned = false;
  _isVisible = true;
  _isActive = true;
}


Control::Control(Control::Size size)
{
  _size = size;
  _controlRef = NULL;
  _eventTargetRef = NULL;
  _isOwned = false;
  _isVisible = true;
  _isActive = true;
}


Control::Control(short x, short y, short w, short h) :
  Component(x, y, w, h)  
{
  _size = AUTO_SIZE;
  _controlRef = NULL;
  _eventTargetRef = NULL;
  _isOwned = false;
  _isVisible = true;
  _isActive = true;
}


Control::Control(Control::Size size, short x, short y, short w, short h) :
  Component(x, y, w, h)  
{
  _size = size;
  _controlRef = NULL;
  _eventTargetRef = NULL;
  _isOwned = false;
  _isVisible = true;
  _isActive = true;
}


Control::~Control()
{
}


bool Control::isOwned() const
{
  return _isOwned;
}


const Control::Size& Control::getSize() const
{
  return _size;
}


const Rect&
Control::getControlBounds() const
{
  if (_controlRef != NULL) {
    GetControlBounds(_controlRef, &_controlBounds);
  }
  return _controlBounds;
}


/**
 * TODO: Documentation
 * <p>
 */
EventTargetRef& Control::getEventTargetRef()
{
  return _eventTargetRef;
}


void
Control::setSize(short width, short height)
{
  Component::setSize(width, height);
  if (_controlRef != NULL) {
    //    HIViewSetFrame(_controlRef, width, height);
    SizeControl(_controlRef, width, height);
  }
}


void
Control::setPosition(short x, short y)
{
  if (_controlRef != NULL) {
    //    HIViewSetFrame(_controlRef, width, height);
    MoveControl(_controlRef, x, y);
  }
}


void Control::show()
{
  _isVisible = true;
  applyVisibility();
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::hide()
{
  _isVisible = false;
  applyVisibility();
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::activate()
{
  _isActive = true;
  applyActivity();
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::deactivate()
{
  _isActive = false;
  applyActivity();
}


ControlRef& Control::getControlRef()
{
  return _controlRef;
}


bool Control::isCreated() const
{
  return _controlRef != NULL;
}


bool Control::isWithin(short x, short y)
{
  GetControlBounds(_controlRef, getBounds());
  return (x >= getBounds()->left) && (x < getBounds()->right) &&
         (y >= getBounds()->top ) && (y < getBounds()->bottom);
}


void Control::draw()
{
  Draw1Control(_controlRef);
}


void Control::applyVisibility()
{
  //  if (_isVisible) {
  //    ShowControl(_controlRef);
  //  } else {
  //    HideControl(_controlRef);
  //  }
  if (_controlRef != NULL) {
    HIViewSetVisible(_controlRef, _isVisible);
  }
}


void Control::applyActivity()
{
  if (_controlRef != NULL) {
    if (_isActive) {
      ActivateControl(_controlRef);
    } else {
      DeactivateControl(_controlRef);
    }
  }
}


bool Control::isActive() const
{
  return _isActive;
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::addControlListener(ControlListener& listener)
{
  addListener(listener);
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::removeControlListener(ControlListener& listener)
{
  removeListener(listener);
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::initialise()
{
  _eventTargetRef = GetControlEventTarget(_controlRef);
  Component::initialise();
}


/**
 * TODO: Documentation
 * <p>
 */
void Control::cleanup()
{
  Component::cleanup();
  _eventTargetRef = NULL;
}


}


}
