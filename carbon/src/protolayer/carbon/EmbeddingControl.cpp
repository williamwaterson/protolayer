#include "EmbeddingControl.h"
#include <typeinfo>
#include <iostream>


namespace protolayer
{

namespace carbon
{


EmbeddingControl::EmbeddingControl()
{
  _ownerWindowRef = NULL;
}


EmbeddingControl::EmbeddingControl(WindowRef windowRef)
{
  _ownerWindowRef = windowRef;
}


EmbeddingControl::EmbeddingControl(short x,
                                   short y,
                                   short w,
                                   short h) :
  Control(x, y, w, h)
{
  _ownerWindowRef = NULL;
}


EmbeddingControl::~EmbeddingControl()
{
}


void EmbeddingControl::setWindowRef(WindowRef windowRef)
{
  _ownerWindowRef = windowRef;
}


void EmbeddingControl::add(NonEmbeddingControl& control)
{
  if (control.isOwned()) {
    return;
  } else {
    _controls.insert(&control);
    control._isOwned = true;
    if (_ownerWindowRef != NULL) {
      Control* pc = &control;
      control.create(_ownerWindowRef);
      OSStatus err = HIViewAddSubview(getControlRef(), control.getControlRef());
      if (err != noErr) {
        exit(1);
      }
      control.applyVisibility();
      control.applyActivity();
    }
  }
}


void EmbeddingControl::add(EmbeddingControl& control)
{
  if (control.isOwned()) {
    return;
  } else {
    _controls.insert(&control);
    control._isOwned = true;
    if (_ownerWindowRef != NULL) {
      Control* pc = &control;
      control.create(_ownerWindowRef);
      OSStatus err = HIViewAddSubview(getControlRef(), control.getControlRef());
      if (err != noErr) {
        exit(1);
      }
      control.applyVisibility();
      control.applyActivity();
    }
  }
}


Iterator <Control>
EmbeddingControl::getEmbeddedControls()
{
  return Iterator <Control> (_controls);
}


void
EmbeddingControl::setPort()
{
  SetPort(GetWindowPort (_ownerWindowRef));
}


void EmbeddingControl::remove(NonEmbeddingControl& control)
{
  _controls.erase(&control);
  if (_ownerWindowRef != NULL) {
    control.dispose();
  }
}


void EmbeddingControl::remove(EmbeddingControl& control)
{
  _controls.erase(&control);
  if (_ownerWindowRef != NULL) {
    control.dispose();
  }
}


bool EmbeddingControl::contains(Control& control) const
{
  return _controls.find(&control) != _controls.end();
}


void EmbeddingControl::createEmbeddedControls()
{
  Control* control = 0;
  std::set <Control*>::iterator iter = _controls.begin();
  std::set <Control*>::iterator end = _controls.end();  
  for (iter = _controls.begin(); iter != _controls.end(); iter++) {
    control = *iter; // iterator.next();
    if (control->isCreated()) {
    } else {
      OSStatus err = control->create(_ownerWindowRef);
      err = HIViewAddSubview(getControlRef(), control->getControlRef());
      control->applyVisibility();
      control->applyActivity();
    }
  }
}


void EmbeddingControl::disposeEmbeddedControls()
{
  for (IteratorType iterator(_controls); iterator.hasNext(); ) {
    iterator.next()->dispose();
  }
}

}

}
