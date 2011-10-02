#include "ChasingArrows.h"


namespace protolayer
{

namespace carbon
{


ChasingArrows::ChasingArrows(short x,
                             short y,
                             short width,
                             short height) :
  NonEmbeddingControl(x, y, width, height)
{
}


ChasingArrows::ChasingArrows(Control::Size size,
                             short x,
                             short y,
                             short width,
                             short height) :
  NonEmbeddingControl(size, x, y, width, height)
{
}


ChasingArrows::~ChasingArrows()
{
}


OSStatus ChasingArrows::create(WindowRef windowRef)
{
  OSStatus result = CreateChasingArrowsControl(windowRef,
                                               getBounds(),
                                               &getControlRef());
  initialise();
  SetControlData(getControlRef(), kControlNoPart, kControlSizeTag,
                 sizeof(kControlSizeLarge), (void *) (kControlSizeLarge));
  return result;
}


void ChasingArrows::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
