#include "StaticText.h"


namespace protolayer
{

namespace carbon
{


StaticText::StaticText(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


StaticText::StaticText(const char* label,
                       short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFStringCreateWithCString(NULL, label, kCFStringEncodingMacRoman);
}


StaticText::~StaticText()
{
}


void
StaticText::setText(const char* text)
{
  SetControlData(getControlRef(), 0, kControlStaticTextTextTag, strlen(text), text);
}


OSStatus StaticText::create(WindowRef windowRef)
{
  OSStatus result = CreateStaticTextControl(windowRef,
                                            getBounds(),
                                            _label,
                                            NULL,
                                            &getControlRef());
  initialise();
  applyActivity();
  applyVisibility();
  return result;
}


void StaticText::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
