#include "PushButton.h"


namespace protolayer
{

namespace carbon
{

PushButton::PushButton(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


PushButton::PushButton(const char* label,
                       short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFStringCreateWithCString(NULL,
                                     label,
                                     kCFStringEncodingMacRoman);
}


PushButton::~PushButton()
{
}


OSStatus PushButton::create(WindowRef windowRef)
{
  OSStatus result = CreatePushButtonControl(windowRef,
                                            getBounds(),
                                            _label,
                                            &getControlRef());
  initialise();
  return result;
}


void PushButton::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
