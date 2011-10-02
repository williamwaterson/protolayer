#include "ProgressBar.h"


namespace protolayer
{

namespace carbon
{

ProgressBar::ProgressBar(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


ProgressBar::ProgressBar(const char* label,
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


ProgressBar::~ProgressBar()
{
}


OSStatus ProgressBar::create(WindowRef windowRef)
{
  OSStatus result = CreatePushButtonControl(windowRef,
                                            getBounds(),
                                            _label,
                                            &getControlRef());
  initialise();
  return result;
}


void ProgressBar::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
