#include "PopUpButton.h"


namespace protolayer
{

namespace carbon
{

PopUpButton::PopUpButton(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


PopUpButton::PopUpButton(const char* label,
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


PopUpButton::~PopUpButton()
{
}


OSStatus PopUpButton::create(WindowRef windowRef)
{
  OSStatus result = CreatePushButtonControl(windowRef,
                                            getBounds(),
                                            _label,
                                            &getControlRef());
  initialise();
  return result;
}


void PopUpButton::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
