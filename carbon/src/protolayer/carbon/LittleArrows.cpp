#include "LittleArrows.h"


namespace protolayer
{

namespace carbon
{


LittleArrows::LittleArrows(short x,
                           short y,
                           short width,
                           short height) :
  NonEmbeddingControl(x, y, width, height)
{
}


LittleArrows::~LittleArrows()
{
}


OSStatus LittleArrows::create(WindowRef windowRef)
{
  OSStatus result = CreateLittleArrowsControl(windowRef,
                                              getBounds(),
                                              0,
                                              0,
                                              0,
                                              0,
                                              &getControlRef());
  initialise();
  return result;
}


void LittleArrows::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
