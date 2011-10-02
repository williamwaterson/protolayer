#include "CheckBox.h"


namespace protolayer
{

namespace carbon
{


CheckBox::CheckBox(const char* label,
                   short x,
                   short y,
                   short width,
                   short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);  
}


CheckBox::~CheckBox()
{
  
}


OSStatus CheckBox::create(WindowRef windowRef)
{
  OSStatus result = CreateCheckBoxControl(windowRef,
                                          getBounds(),
                                          _label,
                                          0,
                                          true,
                                          &getControlRef());
  initialise();
  return result;
}


void CheckBox::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
