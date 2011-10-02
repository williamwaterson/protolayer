#include "RadioButton.h"


namespace protolayer
{

namespace carbon
{


RadioButton::RadioButton(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


RadioButton::RadioButton(const char* label,
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


RadioButton::~RadioButton()
{
}


OSStatus RadioButton::create(WindowRef windowRef)
{
  OSStatus result = CreateRadioButtonControl(windowRef,
                                             getBounds(),
                                             _label,
                                             0,
                                             true,
                                             &getControlRef());
  initialise();
  return result;
}


void RadioButton::dispose()
{  
  cleanup();
  DisposeControl(getControlRef());
}


}


}
