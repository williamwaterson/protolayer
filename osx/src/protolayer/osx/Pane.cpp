#include "Pane.h"


namespace protolayer
{

namespace osx
{

pascal OSStatus protolayerPaneEventHandler(EventHandlerCallRef handler,
                                         EventRef event,
                                         void* userData)
{
  Pane* pane = reinterpret_cast <Pane*> (userData);
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
  pane->getSpace().setMousePosition(pane->_mousePosition.h, pane->_mousePosition.v);

  return eventNotHandledErr;
}


namespace
{


const EventTypeSpec protolayerPaneEventTypes[] =
{
  { kEventClassMouse, kEventMouseMoved },
  { kEventClassMouse, kEventMouseDragged }
};


EventHandlerUPP protolayerPaneMouseHandler =
  NewEventHandlerUPP(protolayerPaneEventHandler);


int getNumberPaneEventTypes()
{
  return GetEventTypeCount(protolayerPaneEventTypes);
}


const EventTypeSpec* getPaneEventTypes()
{
  return protolayerPaneEventTypes;
}


EventHandlerUPP getPaneEventHandlerUPP()
{
  return protolayerPaneMouseHandler;
}


}


Pane::Pane(renderer::Space& space, short left, short top,
           short right, short bottom) :
  protolayer::carbon::NonEmbeddingControl::NonEmbeddingControl(left, top, right, bottom)
{
  PaneModel* model = new PaneModel(space, left, top, right, bottom);
  _view = new PaneView(*model);
}


Pane::~Pane()
{
  delete _view;
}


PaneView& Pane::getView()
{
  return *_view;
}


PaneModel& Pane::getModel()
{
  return _view->getModel();
}


OSStatus Pane::create(WindowRef windowRef)
{
  OSStatus result = CreateUserPaneControl(windowRef,
                                          getBounds(),
                                          kControlSupportsFocus,
                                          &(getControlRef()));

  getModel()._windowRef = windowRef;

  getModel()._aglPixelFormat = aglChoosePixelFormat(NULL, 0, PaneModel::attrib);
  getModel()._aglContext = aglCreateContext(getModel()._aglPixelFormat, NULL);
  aglSetCurrentContext(getModel()._aglContext);

  Rect portRect;
  GetWindowPortBounds(windowRef, &portRect);

  short portHeight = portRect.bottom - portRect.top;
  short portWidth = portRect.right - portRect.left;

  GLint bufferRect[4];

  bufferRect[0] = getModel()._bounds->left; // x
  bufferRect[1] = portHeight - getModel()._bounds->bottom; // y
  bufferRect[2] = getModel()._bounds->right - getModel()._bounds->left; // width
  bufferRect[3] = getModel()._bounds->bottom - getModel()._bounds->top; // height

  aglSetInteger(getModel()._aglContext, AGL_BUFFER_RECT, bufferRect);
  aglEnable(getModel()._aglContext, AGL_BUFFER_RECT);

  aglSetDrawable(getModel()._aglContext, GetWindowPort(windowRef));
  gluNewNurbsRenderer();

  getModel().getSpace().init();

  short width = getModel()._bounds->right - getModel()._bounds->left;
  short height = getModel()._bounds->bottom - getModel()._bounds->top;
  float aspectRatio =  (float) width / (float) height;

  getModel().getSpace().setDimensions(width, height);

  initialise();
  activate();
  show();

  InstallEventHandler(GetWindowEventTarget(getModel().getWindowRef()),
                      getPaneEventHandlerUPP(),
                      getNumberPaneEventTypes(),
                      getPaneEventTypes(),
                      reinterpret_cast <void*> (this),
                      NULL);
  InstallStandardEventHandler(getEventTargetRef());
  addListener(*_view);
  return result;
}


void Pane::dispose()
{
  cleanup();
}


renderer::Space& Pane::getSpace()
{
  return getModel().getSpace();;
}


void Pane::updateBounds()
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


void Pane::setPosition(short x, short y)
{
  NonEmbeddingControl::setPosition(x, y);
  getModel().setPosition(x, y);
}


void Pane::setSize(short width, short height)
{
  getModel().setSize(width, height);
  NonEmbeddingControl::setSize(width, height);
}


}


}
