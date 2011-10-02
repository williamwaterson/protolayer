#include "PaneModel.h"


namespace protolayer
{

namespace osx
{

  const GLint PaneModel::attrib[] = {AGL_RGBA, AGL_DOUBLEBUFFER,
                                     AGL_DEPTH_SIZE, 20,
                                     AGL_SAMPLE_BUFFERS_ARB, 1,
                                     AGL_NO_RECOVERY, AGL_NONE};

  //const GLint PaneModel::attrib[] = {AGL_RGBA, AGL_DOUBLEBUFFER,
  //                                           AGL_SAMPLE_BUFFERS_ARB, 1,
  //                                           AGL_NO_RECOVERY, AGL_NONE};


PaneModel::PaneModel(renderer::Space& space,
                     short left,
                     short top,
                     short right,
                     short bottom)
{
  _space = &space;
  _bounds = new Rect();
  SetRect(_bounds, left, top, right, bottom);
}


void
PaneModel::setPosition(short left,
                       short top)
{
  SetRect(_bounds,
          left,
          top,
          _bounds->right,
          _bounds->bottom);
}


//void
//PaneModel::setMousePosition(Point position)
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
PaneModel::setSize(short width,
                           short height)
{
  SetRect(_bounds,
          _bounds->left,
          _bounds->top,
          _bounds->left + width,
          _bounds->top + height);
}


PaneModel::~PaneModel()
{
}


renderer::Space&
PaneModel::getSpace()
{
  return *_space;
}


const WindowRef&
PaneModel::getWindowRef() const
{
  return _windowRef;
}


}


}
