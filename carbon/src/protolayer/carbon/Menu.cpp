#include "RoundButton.h"


namespace protolayer
{

namespace carbon
{


RoundButton::RoundButton(short x,
                         short y,
                         short width,
                         short height) :
  NonEmbeddingControl(x, y, width, height)
{
}


RoundButton::~RoundButton()
{
}


OSStatus RoundButton::create(WindowRef windowRef)
{
  OSStatus result = CreateRoundButtonControl(windowRef,
                                             getBounds(),
                                             kControlRoundButtonNormalSize,
                                             NULL,
                                             &getControlRef());
  initialise();
  return result;
}


}


}
