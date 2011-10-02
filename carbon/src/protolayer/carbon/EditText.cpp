#include "EditText.h"

namespace protolayer
{

namespace carbon
{

EditText::EditText(short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


EditText::EditText(const char* label,
                         short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);
}


EditText::~EditText()
{
}


OSStatus EditText::create(WindowRef windowRef)
{
  OSStatus result = CreateEditTextControl(windowRef,
                                          getBounds(),
                                          _label,
                                          false,
                                          false,
                                          NULL,
                                          &getControlRef());
  initialise();
  applyActivity();
  applyVisibility();
  return result;
}


void EditText::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
