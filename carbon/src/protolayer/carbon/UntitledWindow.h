#ifndef PROTOLAYER_CARBON_UNTITLEDWINDOW_H
#define PROTOLAYER_CARBON_UNTITLEDWINDOW_H

#include <map>

#include "forward.h"
#include "Window.h"
#include "WindowTraits.h"

namespace protolayer
{

namespace carbon
{

template <int WindowClassParam>
class UntitledWindow : public Window
{
 private:
  /** TODO: Documentation */
  typedef WindowTraits <WindowClassParam>
    WindowTraitsType;

  /** TODO: Documentation */
  enum { DefaultWindowAttributes = WindowTraitsType::DefaultWindowAttributes };

  /** TODO: Documentation */
  static const int WINDOW_CLASS = WindowClassParam;

 public:
  /**
   * TODO: Documentation
   * <p>
   */
  UntitledWindow(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  UntitledWindow(WindowAttributes attributes,
                 short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  ~UntitledWindow();

};


template <int WindowClassParam>
UntitledWindow <WindowClassParam>::
UntitledWindow(short x, short y,
               short w, short h) :
  Window(WindowClassParam, DefaultWindowAttributes, x, y, w, h)
{
}


template <int WindowClassParam>
UntitledWindow <WindowClassParam>::
UntitledWindow(WindowAttributes attributes,
               short x, short y,
               short w, short h) :
  Window(WINDOW_CLASS, attributes, x, y, w, h)
{
}


template <int WindowClassParam>
UntitledWindow <WindowClassParam>::
~UntitledWindow()
{
}



// Template typedefs
typedef UntitledWindow <kHelpWindowClass> HelpWindow;
typedef UntitledWindow <kHelpWindowClass> HelpTag;
typedef UntitledWindow <kOverlayWindowClass> OverlayWindow;

}

}

#endif // PROTOLAYER_CARBON_UNTITLEDWINDOW_H
