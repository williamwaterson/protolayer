#include "Slider.h"


namespace protolayer
{

namespace carbon
{


Slider::Slider(short x,
                           short y,
                           short width,
                           short height) :
  NonEmbeddingControl(x, y, width, height)
{
}


Slider::~Slider()
{
}


OSStatus Slider::create(WindowRef windowRef)
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


void Slider::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
