#include "UserPane.h"
#include <iostream>


namespace protolayer
{

namespace carbon
{


UserPane::UserPane(short x, short y, short w, short h) :
  EmbeddingControl(x, y, w, h)
{
}


UserPane::~UserPane()
{
}


OSStatus
UserPane::create(WindowRef windowRef)
{
  setWindowRef(windowRef);
  OSStatus result = CreateUserPaneControl(windowRef,
                                          getBounds(),
                                          kControlSupportsEmbedding,
                                          &getControlRef());
  initialise();
  activate();
  show();
  createEmbeddedControls();
  return result;
}


void
UserPane::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
