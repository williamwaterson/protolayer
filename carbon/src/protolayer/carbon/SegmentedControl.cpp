#include "SegmentedControl.h"


namespace protolayer
{

namespace carbon
{

SegmentedControl::SegmentedControl(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


SegmentedControl::SegmentedControl(const char* label,
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


SegmentedControl::~SegmentedControl()
{
}


OSStatus SegmentedControl::create(WindowRef windowRef)
{
  OSStatus result = CreatePushButtonControl(windowRef,
                                            getBounds(),
                                            _label,
                                            &getControlRef());
  initialise();
  return result;
}


void SegmentedControl::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
