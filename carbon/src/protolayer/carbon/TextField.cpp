#include "TextField.h"


namespace protolayer
{

namespace carbon
{

TextField::TextField(short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


TextField::TextField(const char* label,
                         short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);
}


TextField::~TextField()
{
}


OSStatus TextField::create(WindowRef windowRef)
{
  OSStatus result = CreateEditTextControl(windowRef,
                                          getBounds(),
                                          _label,
                                          false,
                                          false,
                                          NULL,
                                          &getControlRef());

  SetControlData(getControlRef(), kControlNoPart, kControlEditTextSingleLineTag, 0, 0);
  initialise();
  applyActivity();
  applyVisibility();
  return result;
}


void TextField::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
