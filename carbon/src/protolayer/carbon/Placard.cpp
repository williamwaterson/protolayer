#include "Placard.h"

namespace protolayer
{


namespace carbon
{


Placard::Placard(short x,
                 short y,
                 short w,
                 short h) :
  EmbeddingControl(x, y, w, h)
{
}


Placard::~Placard()
{
}


OSStatus Placard::create(WindowRef windowRef)
{
  setWindowRef(windowRef);
  OSStatus result = CreatePlacardControl(windowRef,
                                         getBounds(),
                                         &getControlRef());
  initialise();
  createEmbeddedControls();
  return result;
}


void Placard::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
