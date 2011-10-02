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
  return CreateRoundButtonControl(windowRef,
                                  getBounds(),
                                  kControlRoundButtonNormalSize,
                                  NULL,
                                  &getControlRef());
}


}


}
