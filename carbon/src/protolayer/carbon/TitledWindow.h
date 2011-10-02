#ifndef PROTOLAYER_CARBON_TITLEDWINDOW_H
#define PROTOLAYER_CARBON_TITLEDWINDOW_H

#include <map>

#include "forward.h"
#include "Window.h"
#include "WindowTraits.h"

namespace protolayer
{

namespace carbon
{

template <int WindowClassParam>
class TitledWindow : public Window
{
private:
  /** TODO: Documentation */
  typedef WindowTraits <WindowClassParam>
    WindowTraitsType;

  /** TODO: Documentation */
  enum { DefaultWindowAttributes =
         WindowTraitsType::DefaultWindowAttributes };

  /** TODO: Documentation */
  static const int WINDOW_CLASS = WindowClassParam;

  /** TODO: Documentation */
  CFStringRef _title;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TitledWindow(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  TitledWindow(const char* title, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  TitledWindow(WindowAttributes windowAttributes,
               short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  TitledWindow(WindowAttributes windowAttributes,
               const char* title,
               short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  ~TitledWindow();

  /**
   * TODO: Documentation
   * <p>
   */
  void setTitle(const char* title);

};


template <int WindowClassParam>
TitledWindow <WindowClassParam>::
TitledWindow(short x, short y, short w, short h) :
  Window(WINDOW_CLASS, DefaultWindowAttributes, x, y, w, h)
{
}


template <int WindowClassParam>
TitledWindow <WindowClassParam>::
TitledWindow(const char* title,
             short x, short y,
             short w, short h) :
  Window(WINDOW_CLASS, DefaultWindowAttributes, x, y, w, h)
{
  _title = CFStringCreateWithCString(NULL,
                                     title,
                                     kCFStringEncodingMacRoman);
  SetWindowTitleWithCFString(getWindowRef(), _title);
}


template <int WindowClassParam>
TitledWindow <WindowClassParam>::
TitledWindow(WindowAttributes attributes,
             short x, short y, short w, short h) :
  Window(WINDOW_CLASS, attributes, x, y, w, h)
{
}


template <int WindowClassParam>
TitledWindow <WindowClassParam>::
TitledWindow(WindowAttributes attributes,
             const char* title,
             short x, short y,
             short w, short h) :
  Window(WINDOW_CLASS, attributes, x, y, w, h)
{
  _title = CFStringCreateWithCString(NULL,
                                     title,
                                     kCFStringEncodingMacRoman);
  SetWindowTitleWithCFString(getWindowRef(), _title);
}


template <int WindowClassParam>
TitledWindow <WindowClassParam>::
~TitledWindow()
{
  CFRelease(_title);
}


template <int WindowClassParam>
void
TitledWindow <WindowClassParam>::
setTitle(const char* title)
{
  _title = CFStringCreateWithCString(NULL,
                                     title,
                                     kCFStringEncodingMacRoman);
  SetWindowTitleWithCFString(getWindowRef(), _title); 
}

// Typedefed template instantiations
typedef TitledWindow <kDocumentWindowClass> DocumentWindow;
typedef TitledWindow <kMovableAlertWindowClass> AlertWindow;
typedef TitledWindow <kMovableModalWindowClass> ModalWindow;
typedef TitledWindow <kFloatingWindowClass> FloatingWindows;
typedef TitledWindow <kUtilityWindowClass> UtilityWindow;
typedef TitledWindow <kSheetWindowClass> SheetWindow;
typedef TitledWindow <kToolbarWindowClass> ToolbarWindow;
typedef TitledWindow <kSheetAlertWindowClass> ShertAlertWindow;


// Further re-typedefs
typedef ModalWindow ModalDialog;

}

}

#endif // PROTOLAYER_CARBON_TITLEDWINDOW_H
