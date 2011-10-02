#include "BevelButton.h"
#include <iostream>

namespace protolayer
{

namespace carbon
{

BevelButton::BevelButton(short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _isRounded = false;
  _behaviour = PUSH_BUTTON;
  _thickness = MEDIUM_THICKNESS;
  _label = CFSTR("");
}


BevelButton::BevelButton(const char* label,
                         short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _isRounded = false;
  _behaviour = PUSH_BUTTON;
  _thickness = MEDIUM_THICKNESS;
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);
}


BevelButton::BevelButton(bool isRounded,
                         short x,
                         short y,
                         short width,
                         short height)
{
  _isRounded = isRounded;
  _behaviour = PUSH_BUTTON;
  _thickness = MEDIUM_THICKNESS;
  _label = CFSTR("");
}


BevelButton::BevelButton(const char* label,
                         bool isRounded,
                         short x,
                         short y,
                         short w,
                         short h)
{
  _isRounded = isRounded;
  _behaviour = PUSH_BUTTON;
  _thickness = MEDIUM_THICKNESS;
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);
}


BevelButton::~BevelButton()
{
}


OSStatus BevelButton::create(WindowRef windowRef)
{
  OSStatus result = CreateBevelButtonControl(windowRef,
                                             getBounds(),
                                             _label,
                                             _thickness,
                                             SINGLE_VALUE, //_behaviour,
                                             NULL, 0, 0, 0,
                                             &getControlRef());
  if (_isRounded) {
    _kind = kThemeRoundButton;
    SetControlData (getControlRef(),
                    0,
                    kControlBevelButtonKindTag,
                    sizeof(_kind),
                    (void*) &_kind);
  }

  initialise();
  applyActivity();
  applyVisibility();
  return result;
}


void BevelButton::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
