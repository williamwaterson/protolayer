#include "GelatinePane.h"


namespace gelatine
{


pascal OSStatus gelatinePaneEventHandler(EventHandlerCallRef handler,
                                         EventRef event,
                                         void* userData)
{
  GelatinePane* pane = reinterpret_cast <GelatinePane*> (userData);
  GetEventParameter(event,
                    kEventParamMouseLocation,
                    typeQDPoint,
                    NULL,
                    sizeof(::Point),
                    NULL,
                    &(pane->_mousePosition));

  GetWindowBounds(const_cast <WindowRef&> (pane->getModel().getWindowRef()),
                  kWindowContentRgn,
                  &(pane->_windowBounds));

  pane->_mousePosition.h -= pane->_windowBounds.left;
  pane->_mousePosition.v -= pane->_windowBounds.top;

  HIRect bounds;
  HIViewGetBounds(pane->getControlRef(), &bounds);
  HIPoint topLeftPoint;
  topLeftPoint.x = bounds.origin.x;
  topLeftPoint.y = bounds.origin.y;
  HIViewConvertPoint(&topLeftPoint, pane->getControlRef(), NULL);

  pane->_mousePosition.h -= topLeftPoint.x;
  pane->_mousePosition.v -= topLeftPoint.y;

  pane->_mousePosition.v = pane->getControlBounds().bottom - pane->_mousePosition.v;
  pane->getSpace().updateMouse(pane->_mousePosition.h, pane->_mousePosition.v);

  return eventNotHandledErr;
}


namespace
{


const EventTypeSpec gelatinePaneEventTypes[] =
{
  { kEventClassMouse, kEventMouseMoved },
  { kEventClassMouse, kEventMouseDragged }
};


EventHandlerUPP gelatinePaneMouseHandler =
  NewEventHandlerUPP(gelatinePaneEventHandler);


int getNumberGelatinePaneEventTypes()
{
  return GetEventTypeCount(gelatinePaneEventTypes);
}


const EventTypeSpec* getGelatinePaneEventTypes()
{
  return gelatinePaneEventTypes;
}


EventHandlerUPP getGelatinePaneEventHandlerUPP()
{
  return gelatinePaneMouseHandler;
}


} // unnamed namespace


GelatinePane::GelatinePane(Shot& shot,
                           short left,
                           short top,
                           short right,
                           short bottom) :
  protolayer::carbon::NonEmbeddingControl::NonEmbeddingControl(left, top, right, bottom)
{
  GelatinePaneModel* model = new GelatinePaneModel(shot, left, top, right, bottom);
  _view = new GelatinePaneView(*model);
}


GelatinePane::~GelatinePane()
{
  delete _view;
}


GelatinePaneView&
GelatinePane::getView()
{
  return *_view;
}


GelatinePaneModel&
GelatinePane::getModel()
{
  return _view->getModel();
}


OSStatus
GelatinePane::create(WindowRef windowRef)
{
  OSStatus result = CreateUserPaneControl(windowRef,
                                          getBounds(),
                                          kControlSupportsFocus,
                                          &(getControlRef()));

  getModel()._windowRef = windowRef;

  getModel()._aglPixelFormat = aglChoosePixelFormat(NULL, 0, GelatinePaneModel::attrib);
  getModel()._aglContext = aglCreateContext(getModel()._aglPixelFormat, NULL);

  Rect portRect;
  GetWindowPortBounds(windowRef, &portRect);

  //  Rect windowRect;  
  //GetWindowBounds(windowRef, kWindowStructureRgn, &windowRect);



  short portHeight = portRect.bottom - portRect.top;
  short portWidth = portRect.right - portRect.left;

  //  HIPoint topLeftPoint;
  //  topLeftPoint.x = getModel()._bounds->left;
  //  topLeftPoint.y = getModel()._bounds->top;
  //  HIViewRef view = this->getControlRef();
  //  HIViewConvertPoint(&topLeftPoint, view, NULL );
  //  printf("left old, top old: %d, %d", getModel()._bounds->left, getModel()._bounds->top);
  //  printf("left, top: %10.5f, %10.5f", topLeftPoint.x, topLeftPoint.y);

  //  HIPoint bottomRightPoint;
  //  bottomRightPoint.x = getModel()._bounds->right;
  //  bottomRightPoint.y = getModel()._bounds->bottom;
  //  printf("right old, bottom old: %d, %d", getModel()._bounds->right, getModel()._bounds->bottom);
  //  HIViewConvertPoint(&bottomRightPoint, view, NULL );
  //  printf("right, bottom: %10.5f, %10.5f", bottomRightPoint.x, bottomRightPoint.y);

  GLint bufferRect[4];
  //  bufferRect[0] = (short) topLeftPoint.x; // x
  //  bufferRect[1] = portHeight - (short) bottomRightPoint.y; // y
  //  bufferRect[2] = getModel()._bounds->right - getModel()._bounds->left; // width
  //  bufferRect[3] = getModel()._bounds->bottom - getModel()._bounds->top; // height

  bufferRect[0] = getModel()._bounds->left; // x
  bufferRect[1] = portHeight - getModel()._bounds->bottom; // y
  bufferRect[2] = getModel()._bounds->right - getModel()._bounds->left; // width
  bufferRect[3] = getModel()._bounds->bottom - getModel()._bounds->top; // height

  aglSetInteger(getModel()._aglContext, AGL_BUFFER_RECT, bufferRect);
  aglEnable(getModel()._aglContext, AGL_BUFFER_RECT);

  aglSetDrawable(getModel()._aglContext, GetWindowPort(windowRef));
  aglSetCurrentContext(getModel()._aglContext);

  _view->init();
  initialise();
  activate();
  show();
  InstallEventHandler(GetWindowEventTarget(getModel().getWindowRef()),
                      getGelatinePaneEventHandlerUPP(),
                      getNumberGelatinePaneEventTypes(),
                      getGelatinePaneEventTypes(),
                      reinterpret_cast <void*> (this),
                      NULL);
  InstallStandardEventHandler(getEventTargetRef());
  addListener(*_view);
  return result;
}


void
GelatinePane::dispose()
{
  cleanup();
}


Space&
GelatinePane::getSpace()
{
  return getModel().getSpace();;
}


void
GelatinePane::updateBounds()
{
  Rect portRect;
  GetWindowPortBounds(getModel()._windowRef, &portRect);

  HIViewRef rootView = HIViewGetRoot(getModel()._windowRef);

  HIRect contentBounds;
  HIViewRef contentView;
  GetRootControl(getModel()._windowRef, &contentView);
  HIViewGetBounds(contentView, &contentBounds);

  HIViewFindByID(HIViewGetRoot(getModel()._windowRef), kHIViewWindowContentID, &contentView);
  HIViewGetBounds(contentView, &contentBounds);

  short portHeight = portRect.bottom - portRect.top;
  short portWidth = portRect.right - portRect.left;

  HIPoint topLeftPoint;
  topLeftPoint.x = getModel()._bounds->left;
  topLeftPoint.y = getModel()._bounds->top;
  HIViewRef view = this->getControlRef();
  HIViewConvertPoint(&topLeftPoint, view, NULL);

  HIPoint bottomRightPoint;
  bottomRightPoint.x = getModel()._bounds->right;
  bottomRightPoint.y = getModel()._bounds->bottom;
  HIViewConvertPoint(&bottomRightPoint, view, NULL);

  GLint bufferRect[4];
  //  bufferRect[0] = (short) topLeftPoint.x; // x
  //  bufferRect[1] = portHeight - (short) bottomRightPoint.y; // y
  //  bufferRect[2] = getModel()._bounds->right - getModel()._bounds->left; // width
  //  bufferRect[3] = getModel()._bounds->bottom - getModel()._bounds->top; // height

  bufferRect[0] = (short) topLeftPoint.x; // x
  bufferRect[1] = portHeight - (short) bottomRightPoint.y; // y
  bufferRect[2] = getModel()._bounds->right - getModel()._bounds->left; // width
  bufferRect[3] = getModel()._bounds->bottom - getModel()._bounds->top; // height

  aglSetInteger(getModel()._aglContext, AGL_BUFFER_RECT, bufferRect);


  HIRect ctrlBounds, winBounds;
  HIViewGetBounds(getControlRef(), &ctrlBounds);
  WindowRef window = GetControlOwner(getControlRef());
  ControlRef root = NULL;
  GetRootControl(window, &root);
  HIViewFindByID(HIViewGetRoot(getModel()._windowRef), kHIViewWindowContentID, &root);
  HIViewGetBounds(root, &winBounds);

  HIViewConvertRect(&ctrlBounds, getControlRef(), NULL); //root);
  bufferRect[0] = ctrlBounds.origin.x;
  bufferRect[1] = (winBounds.size.height) - (ctrlBounds.origin.y + ctrlBounds.size.height);
  bufferRect[2] = ctrlBounds.size.width;
  bufferRect[3] = ctrlBounds.size.height;
  //  aglSetInteger(getModel()._aglContext, AGL_BUFFER_RECT, bufferRect);
}


void
GelatinePane::setPosition(short x, short y)
{
  NonEmbeddingControl::setPosition(x, y);
  getModel().setPosition(x, y);
}


void
GelatinePane::setSize(short width, short height)
{
  getModel().setSize(width, height);
  NonEmbeddingControl::setSize(width, height);
}


}
