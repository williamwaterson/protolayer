#include "GelatinePaneModel.h"


namespace gelatine
{


const GLint GelatinePaneModel::attrib[] = {AGL_RGBA, AGL_DOUBLEBUFFER,
                                           AGL_DEPTH_SIZE, 16,
                                           AGL_SAMPLE_BUFFERS_ARB, 1,
                                           AGL_NO_RECOVERY, AGL_NONE};


GelatinePaneModel::GelatinePaneModel(Shot& shot,
                                     short left,
                                     short top,
                                     short right,
                                     short bottom)
{
  _space = new Space(shot);
  _bounds = new Rect();
  SetRect(_bounds, left, top, right, bottom);
}


void
GelatinePaneModel::setPosition(short left,
                               short top)
{
  SetRect(_bounds,
          left,
          top,
          _bounds->right,
          _bounds->bottom);
}


//void
//GelatinePaneModel::setMousePosition(Point position)
//{
//  Rect portRect;
//  GetWindowBounds(_windowRef, kWindowContentRgn, &portRect);
//  getSpace().getModel().getMouse()._x = position.h - _window.getContentBounds().left;
//  getSpace().getModel().getMouse()._y = _window.getContentBounds().bottom - position.v;

  //  printf("window: l=%d b=%d \n", window.getContentBounds().left, getContentBounds().bottom);
  //  printf("mouse: x=%d y=%d \n", position.h, position.v);
  //  printf("opengl: x=%d y=%d \n\n", getSpace().getModel().getMouse()._x,
//getSpace().getModel().getMouse()._y);

  //  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(Point), NULL, &_mousePosition);
  //  _mousePosition.h -= portRect.left;
  //  _mousePosition.v -= portRect.top;

//  if (_pane.isWithin(_mousePosition.h, _mousePosition.v)) {
    //    ExitToShell();
//  }  
//}


void
GelatinePaneModel::setSize(short width,
                           short height)
{
  SetRect(_bounds,
          _bounds->left,
          _bounds->top,
          _bounds->left + width,
          _bounds->top + height);
}


GelatinePaneModel::~GelatinePaneModel()
{
}


Space&
GelatinePaneModel::getSpace()
{
  return *_space;
}


const WindowRef&
GelatinePaneModel::getWindowRef() const
{
  return _windowRef;
}


}
