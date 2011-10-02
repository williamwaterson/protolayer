#include "Separator.h"


namespace protolayer
{

namespace carbon
{


Separator::Separator(short x,
                       short y,
                       short width,
                       short height) :
  NonEmbeddingControl(x, y, width, height)
{
  _label = CFSTR("");
}


Separator::Separator(const char* label,
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


Separator::~Separator()
{
}


OSStatus Separator::create(WindowRef windowRef)
{
  OSStatus result = CreateSeparatorControl(windowRef,
                                           getBounds(),
                                           &getControlRef());
  initialise();
  return result;
}


void Separator::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
