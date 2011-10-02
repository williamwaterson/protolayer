#include "RelevanceBar.h"


namespace protolayer
{

namespace carbon
{


RelevanceBar::RelevanceBar(short x,
                           short y,
                           short width,
                           short height)
{
}


RelevanceBar::~RelevanceBar()
{
}


OSStatus RelevanceBar::create(WindowRef windowRef)
{
  OSStatus result = CreateRelevanceBarControl(windowRef,
                                              getBounds(),
                                              0,
                                              1,
                                              1,
                                              &getControlRef());
  initialise();
  return result;
}


void RelevanceBar::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
