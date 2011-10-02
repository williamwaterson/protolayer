#include "DataBrowser.h"


namespace protolayer
{

namespace carbon
{


DataBrowser::DataBrowser(short x, short y, short w, short h, Style style) :
  EmbeddingControl(x, y, w, h)
{
  _style = style;
}


DataBrowser::~DataBrowser()
{
}


OSStatus DataBrowser::create(WindowRef windowRef)
{
  setWindowRef(windowRef);
  OSStatus result = CreateDataBrowserControl(windowRef,
                                             getBounds(),
                                             _style,
                                             &getControlRef());

  initialise();
  activate();
  show();
  createEmbeddedControls();
  activate();
  show();
  return result;
}


void DataBrowser::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


}


}
