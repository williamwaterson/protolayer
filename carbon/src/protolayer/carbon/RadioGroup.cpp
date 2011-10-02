#include "RadioGroup.h"


namespace protolayer
{

namespace carbon
{

RadioGroup::RadioGroup(short x,
                       short y,
                       short w,
                       short h) :
  EmbeddingControl(x, y, w, h)
{
}


RadioGroup::~RadioGroup()
{
}


OSStatus RadioGroup::create(WindowRef windowRef)
{
  setWindowRef(windowRef);
  OSStatus result = CreateRadioGroupControl(windowRef,
                                            getBounds(),
                                            &getControlRef());
  initialise();
  createEmbeddedControls();
  return result;
}


void RadioGroup::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
