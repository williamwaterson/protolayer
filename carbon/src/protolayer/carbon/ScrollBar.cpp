#include "ScrollBar.h"


namespace protolayer
{

namespace carbon
{


ScrollBar::ScrollBar(short x,
                     short y,
                     short width,
                     short height) :
  NonEmbeddingControl(x, y, width, height)
{
}


ScrollBar::~ScrollBar()
{
}


OSStatus ScrollBar::create(WindowRef windowRef)
{
  OSStatus result = CreateScrollBarControl(windowRef,
                                           getBounds(),
                                           0,
                                           0,
                                           0,
                                           0,
                                           true,
                                           NULL,
                                           &getControlRef());
  initialise();
  return result;
}


void ScrollBar::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
