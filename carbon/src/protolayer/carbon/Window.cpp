#include "Window.h"

namespace protolayer
{

namespace carbon
{

Window::Window(WindowClass windowClass,
               WindowAttributes windowAttributes,
               short x,
               short y,
               short w,
               short h) :
  Component(x, y, w, h)
{
  // Screen out attributes that don't work
  windowAttributes &=
    GetAvailableWindowAttributes(windowClass);

  CreateNewWindow(windowClass,
                  windowAttributes,
                  getBounds(),
                  &_windowRef);
  SetWindowBounds (_windowRef,
                   kWindowStructureRgn,
                   getBounds());

  Rect bounds;
  bounds.left = getBounds()->left;
  bounds.right = getBounds()->right;
  bounds.top = getBounds()->top;
  bounds.bottom = bounds.top + 4;
  
  _eventTargetRef = GetWindowEventTarget(_windowRef);
  Component::initialise();

  SetWindowBounds (_windowRef,
                   kWindowTitleBarRgn,
                   &bounds);

  bounds.left = getBounds()->left;
  bounds.right = getBounds()->left + 4;
  bounds.top = getBounds()->top;
  bounds.bottom = bounds.top + 4;
  SetWindowBounds (_windowRef,
                   kWindowCloseBoxRgn,
                   &bounds);

  SetPortWindowPort(_windowRef);
  ShowWindow(_windowRef);
  SelectWindow(_windowRef);

  SetPortWindowPort(_windowRef);
  //  InstallStandardEventHandler(_eventTargetRef);

  SelectWindow(_windowRef);
  ActivateWindow(_windowRef, true);

  DrawControls(_windowRef);
  _rootControl = new RootControl(_windowRef);
}


void
Window::invalidatePort()
{
  Rect portRect;
  GetWindowPortBounds(_windowRef, &portRect);
  InvalWindowRect(_windowRef, &portRect);
}


Window::~Window()
{
  Component::cleanup();

  //  delete _rootControl;
  //DisposeWindow(_windowRef);
}


OSStatus
Window::setContentColor(RGBColor& color)
{
  SetWindowContentColor(_windowRef, &color);
}


const Rect&
Window::getStructureBounds() const
{
  GetWindowBounds(_windowRef, kWindowStructureRgn, &_structureBounds);
  return _structureBounds;
}


const Rect&
Window::getContentBounds() const
{
  GetWindowBounds(_windowRef, kWindowContentRgn, &_contentBounds);
  return _contentBounds;
}


void
Window::addMouseListener(MouseListener& listener)
{
  addListener(listener);
}


void
Window::removeMouseListener(MouseListener& listener)
{
  removeListener(listener);
}


/**
 * TODO: Documentation
 * <p>
 */
EventTargetRef& Window::getEventTargetRef()
{
  return _eventTargetRef;
}


void
Window::setWindowAttributes(WindowAttributes attributes)
{
  ChangeWindowAttributes(_windowRef, attributes, kWindowNoAttributes);
}


void
Window::clearWindowAttributes(WindowAttributes attributes)
{
  ChangeWindowAttributes(_windowRef, kWindowNoAttributes, attributes);
}


WindowAttributes
Window::getWindowAttributes() const
{
  WindowAttributes attributes;
  GetWindowAttributes(_windowRef, &attributes);
  return attributes;
}


void
Window::show()
{
  ShowWindow(_windowRef);
  _rootControl->show();
}


void Window::hide()
{
  HideWindow(_windowRef);
  _rootControl->hide();
}


void Window::activate()
{
  ActivateWindow(_windowRef, true);
  _rootControl->activate();
}


void Window::deactivate()
{
  ActivateWindow(_windowRef, false);
  _rootControl->deactivate();
}


bool
Window::isActive() const
{
  IsWindowActive(_windowRef);
}


RootControl& Window::getRootControl()
{
  return *_rootControl;
}


WindowRef&
Window::getWindowRef()
{
  return _windowRef;
}


void
Window::addWindowActionListener(WindowActionListener& listener)
{
  addListener(listener);
}


void
Window::addWindowActivationListener(WindowActivationListener& listener)
{
  addListener(listener);
}


void
Window::addWindowClickListener(WindowClickListener& listener)
{
  addListener(listener);
}


void
Window::addWindowCursorChangeListener(WindowCursorChangeListener& listener)
{
  addListener(listener);
}


void
Window::addWindowFocusListener(WindowFocusListener& listener)
{
  addListener(listener);
}


void
Window::addWindowRefreshListener(WindowRefreshListener& listener)
{
  addListener(listener);
}


void
Window::addWindowDrawerListener(WindowDrawerListener& listener)
{
  addListener(listener);
}


void
Window::addWindowStateListener(WindowStateListener& listener)
{
  addListener(listener);
}


void
Window::removeWindowActionListener(WindowActionListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowActivationListener(WindowActivationListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowClickListener(WindowClickListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowCursorChangeListener(WindowCursorChangeListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowFocusListener(WindowFocusListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowRefreshListener(WindowRefreshListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowDrawerListener(WindowDrawerListener& listener)
{
  removeListener(listener);
}


void
Window::removeWindowStateListener(WindowStateListener& listener)
{
  removeListener(listener);
}

}

}
