#include "GelatinePaneView.h"
#include <stdio.h>

namespace gelatine
{

pascal OSStatus gelatineRendererEventHandler(EventHandlerCallRef handler,
                                             EventRef event,
                                             void* userData)
{
  OSStatus result = eventNotHandledErr;
  GelatinePaneView* view = reinterpret_cast <GelatinePaneView*> (userData);
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


const EventTypeSpec gelatineViewEventTypes[] =
{
  { kEventClassControl, kEventControlInitialize },
  { kEventClassControl, kEventControlDispose },
  { kEventClassControl, kEventControlActivate },
  { kEventClassControl, kEventControlDeactivate },
  { kEventClassControl, kEventControlDraw },
  { kEventClassControl, kEventControlBoundsChanged }
};


EventHandlerUPP gelatineViewEventHandler =
  NewEventHandlerUPP(gelatineRendererEventHandler);


int GelatinePaneView::getNumberEventTypes()
{
  return GetEventTypeCount(gelatineViewEventTypes);
}


const EventTypeSpec* GelatinePaneView::getEventTypes()
{
  return gelatineViewEventTypes;
}


EventHandlerUPP GelatinePaneView::getEventHandlerUPP()
{
  return gelatineViewEventHandler;
}


GelatinePaneView::GelatinePaneView(GelatinePaneModel& model) :
  _model(model)
{
}


GelatinePaneView::~GelatinePaneView()
{
}


GelatinePaneModel&
GelatinePaneView::getModel()
{
  return _model;
}


void
GelatinePaneView::init()
{
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA); //remavable

  glEnable(GL_BLEND);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_LINE_SMOOTH);
  glDisable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  _model.getSpace().getView().init();

  short width = getModel()._bounds->right - getModel()._bounds->left;
  short height = getModel()._bounds->bottom - getModel()._bounds->top;
  float aspectRatio =  (float) width / (float) height;

  float fieldOfViewY = 45.0f * _model.getSpace().getCurrentShot().getCamera().getZoom();
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fieldOfViewY, aspectRatio, 1.0f, 1000.0f);
  _model.getSpace().getModel().getDimensions().setDimensions(width, height);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}


void
GelatinePaneView::display()
{
  //  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA);

  //  glEnable(GL_BLEND);
  //  glEnable(GL_POINT_SMOOTH);
  //glEnable(GL_LINE_SMOOTH);
  //glDisable(GL_DEPTH_TEST);
  //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//  short width = getModel()._bounds->right - getModel()._bounds->left;
//  short height = getModel()._bounds->bottom - getModel()._bounds->top;
//  float aspectRatio =  (float) width / (float) height;

//  float fieldOfViewY = 45.0f * _model.getSpace().getCurrentShot().getCamera().getZoom();
//  glViewport(0, 0, width, height);
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//  gluPerspective(fieldOfViewY, aspectRatio, 1.0f, 1000.0f);

//  glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _model.getSpace().getView().display();
  glFlush();
  aglSwapBuffers(_model._aglContext);
}


void
GelatinePaneView::resize(short left, short top, short right, short bottom)
{
  aglSetCurrentContext(_model._aglContext);
  aglUpdateContext(_model._aglContext);

  short width = right - left;
  short height = bottom - top;
  float aspectRatio =  (float) width / (float) height;
  float fieldOfViewY = 45.0f * _model.getSpace().getCurrentShot().getCamera().getZoom();

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
  _model.getSpace().getView().resize(width, height);
}


void
GelatinePaneView::dispose()
{
  _model.getSpace().getView().dispose();

  aglSetCurrentContext(NULL);
  aglSetDrawable(_model._aglContext, NULL);

  aglDestroyContext(_model._aglContext);
  aglDestroyPixelFormat(_model._aglPixelFormat);

  _model._aglContext = NULL;
  _model._aglPixelFormat = NULL;
}


void
GelatinePaneView::swapPortsAndDisplay()
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
