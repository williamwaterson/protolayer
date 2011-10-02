#include "PaneView.h"
#include <stdio.h>

namespace protolayer
{

namespace osx
{

pascal OSStatus protolayerRendererEventHandler(EventHandlerCallRef handler,
                                             EventRef event,
                                             void* userData)
{
  OSStatus result = eventNotHandledErr;
  PaneView* view = reinterpret_cast <PaneView*> (userData);
  UInt32 eventKind = GetEventKind(event);

  switch (eventKind) {

  case kEventControlInitialize:
    view->init();
    break;

  case kEventControlDispose:
    view->dispose();
    break;

  case kEventControlActivate:
    view->swapPortsAndDisplay();
    break;

  case kEventControlDeactivate:
    break;

  case kEventControlDraw:
    view->swapPortsAndDisplay();
    break;

  case kEventControlBoundsChanged:
    Rect* controlRect = view->getModel()._bounds;

    Rect portRect;
    GetWindowPortBounds(view->getModel().getWindowRef(), &portRect);
    InvalWindowRect(view->getModel().getWindowRef(), &portRect);

    view->resize(controlRect->left,
                 controlRect->top,
                 controlRect->right,
                 controlRect->bottom);
    view->swapPortsAndDisplay();
    break;

  }

  return result;
}


const EventTypeSpec protolayerViewEventTypes[] =
{
  { kEventClassControl, kEventControlInitialize },
  { kEventClassControl, kEventControlDispose },
  { kEventClassControl, kEventControlActivate },
  { kEventClassControl, kEventControlDeactivate },
  { kEventClassControl, kEventControlDraw },
  { kEventClassControl, kEventControlBoundsChanged }
};


EventHandlerUPP protolayerViewEventHandler =
  NewEventHandlerUPP(protolayerRendererEventHandler);


int PaneView::getNumberEventTypes()
{
  return GetEventTypeCount(protolayerViewEventTypes);
}


const EventTypeSpec* PaneView::getEventTypes()
{
  return protolayerViewEventTypes;
}


EventHandlerUPP PaneView::getEventHandlerUPP()
{
  return protolayerViewEventHandler;
}


PaneView::PaneView(PaneModel& model) :
  _model(model)
{
}


PaneView::~PaneView()
{
}


PaneModel&
PaneView::getModel()
{
  return _model;
}


void
PaneView::init()
{
}


void
PaneView::display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _model.getSpace().display();

  glFlush();
  aglSwapBuffers(_model._aglContext);
}


void
PaneView::resize(short left, short top, short right, short bottom)
{
  aglSetCurrentContext(_model._aglContext);
  aglUpdateContext(_model._aglContext);

  short width = right - left;
  short height = bottom - top;
  float aspectRatio =  (float) width / (float) height;
  //  float fieldOfViewY = 45.0f * _model.getSpace().getCurrentShot().getCamera().getZoom();
  float fieldOfViewY = 45.0f * _model.getSpace().getShots().next().getCamera().getZoom();

  Rect portRect;
  GetWindowPortBounds(_model._windowRef, &portRect);
  short portHeight = portRect.bottom - portRect.top;

  GLint bufferRect[4];
  bufferRect[0] = _model._bounds->left; // x
  bufferRect[1] = portHeight - _model._bounds->bottom; // y
  bufferRect[2] = _model._bounds->right - _model._bounds->left; // width
  bufferRect[3] = _model._bounds->bottom - _model._bounds->top; // height

  aglSetInteger(_model._aglContext, AGL_BUFFER_RECT, bufferRect);
  aglEnable(_model._aglContext, AGL_BUFFER_RECT);

  //  aglSetInteger(inData->mContext, AGL_CLIP_REGION, (const GLint*)rgn);
  //  aglEnable(inData->mContext, AGL_CLIP_REGION);

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fieldOfViewY, aspectRatio, 1.0f, 1000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  InvalWindowRect(_model._windowRef, &portRect);
  _model.getSpace().resize(width, height);
}


void
PaneView::dispose()
{
  _model.getSpace().dispose();

  aglSetCurrentContext(NULL);
  aglSetDrawable(_model._aglContext, NULL);

  aglDestroyContext(_model._aglContext);
  aglDestroyPixelFormat(_model._aglPixelFormat);

  _model._aglContext = NULL;
  _model._aglPixelFormat = NULL;
}


void
PaneView::swapPortsAndDisplay()
{
  GrafPtr savedPort;
  GetPort(&savedPort);

  SetPort(GetWindowPort(_model._windowRef));
  aglSetDrawable(_model._aglContext, GetWindowPort(_model._windowRef));
  aglSetCurrentContext(_model._aglContext);

  display();

  Rect portRect;
  GetWindowPortBounds(getModel().getWindowRef(), &portRect);
  InvalWindowRect(getModel().getWindowRef(), &portRect);

  SetPort(savedPort);
}


}


}
