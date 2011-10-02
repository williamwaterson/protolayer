#include "RootControl.h"
#include <typeinfo>
#include <iostream>

namespace protolayer
{

namespace carbon
{

RootControl::RootControl(WindowRef windowRef) :
  EmbeddingControl(windowRef)
{
  //  CreateRootControl(windowRef, &getControlRef());
  //  GetRootControl(windowRef, &getControlRef());
  OSStatus err = HIViewFindByID(HIViewGetRoot(windowRef), kHIViewWindowContentID, &getControlRef());
  //  getControlRef() = HIViewGetRoot(windowRef);
  _isOwned = true;
  activate();
  show();
}


RootControl::~RootControl()
{
}


OSStatus RootControl::create(WindowRef windowRef)
{
  setWindowRef(windowRef);
  initialise();
  activate();
  show();
  createEmbeddedControls();
  return noErr;
}


void RootControl::dispose()
{
}


}


}
