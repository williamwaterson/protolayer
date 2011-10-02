#include "GroupBox.h"

namespace protolayer
{

namespace carbon
{

GroupBox::GroupBox(short x,
                   short y,
                   short w,
                   short h) :
  EmbeddingControl(x, y, w, h)
{
  _title = CFSTR("");
}


GroupBox::GroupBox(const char* title,
                   short x,
                   short y,
                   short w,
                   short h) :
  EmbeddingControl(x, y, w, h)
{
  _title = CFStringCreateWithCString(NULL,
                                     title,
                                     kCFStringEncodingMacRoman);
}


GroupBox::~GroupBox()
{
}


OSStatus GroupBox::create(WindowRef windowRef)
{
  setWindowRef(windowRef);
  OSStatus result = CreateGroupBoxControl(windowRef,
                                          getBounds(),
                                          _title,
                                          true,
                                          &getControlRef());
  initialise();
  createEmbeddedControls();
  return result;
}


void GroupBox::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
