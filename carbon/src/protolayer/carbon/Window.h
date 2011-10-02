#ifndef PROTOLAYER_CARBON_WINDOW_H
#define PROTOLAYER_CARBON_WINDOW_H

#include "forward.h"
#include "Component.h"
#include "EmbeddingControl.h"
#include "Listener.h"
#include "NonEmbeddingControl.h"
#include "RootControl.h"
#include "WindowActionListener.h"
#include "WindowActivationListener.h"
#include "WindowClickListener.h"
#include "WindowCursorChangeListener.h"
#include "WindowDrawerListener.h"
#include "WindowFocusListener.h"
#include "WindowRefreshListener.h"
#include "WindowStateListener.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class Window : public Component
{
private:
  /** TODO: Documentation */
  WindowRef _windowRef;

  /** TODO: Documentation */
  mutable Rect _structureBounds;

  /** TODO: Documentation */
  mutable Rect _contentBounds;
  /** TODO: Documentation */
  EventTargetRef _eventTargetRef;

  /** TODO: Documentation */
  RootControl* _rootControl;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Window(WindowClass windowClass,
         WindowAttributes windowAttributes,
         short x,
         short y,
         short w,
         short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Window() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  EventTargetRef& getEventTargetRef();

  /**
   * TODO: Documentation
   * <p>
   */
  OSStatus setContentColor(RGBColor& color);

  /**
   * TODO: Documentation
   * <p>
   */
  const Rect& getStructureBounds() const;

  /**
   * TODO: Documentation
   * <p>
   */
  RootControl& getRootControl();

  /**
   * TODO: Documentation
   * <p>
   */
  const Rect& getContentBounds() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setWindowAttributes(WindowAttributes attributes);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearWindowAttributes(WindowAttributes attributes);

  /**
   * TODO: Documentation
   * <p>
   */
  WindowAttributes getWindowAttributes() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(NonEmbeddingControl& control);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(EmbeddingControl& control);

  /**
   * TODO: Documentation
   * <p>
   */
  //  void removeAll();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void show();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void hide();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void activate();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void deactivate();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void invalidatePort();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual bool isActive() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void addMouseListener(MouseListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowActionListener(WindowActionListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowActivationListener(WindowActivationListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowClickListener(WindowClickListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowCursorChangeListener(WindowCursorChangeListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowFocusListener(WindowFocusListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowRefreshListener(WindowRefreshListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowDrawerListener(WindowDrawerListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void addWindowStateListener(WindowStateListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeMouseListener(MouseListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowActionListener(WindowActionListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowActivationListener(WindowActivationListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowClickListener(WindowClickListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowCursorChangeListener(WindowCursorChangeListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowFocusListener(WindowFocusListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowRefreshListener(WindowRefreshListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowDrawerListener(WindowDrawerListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeWindowStateListener(WindowStateListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  WindowRef& getWindowRef();

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  void initialise();

  /**
   * TODO: Documentation
   * <p>
   */
  void cleanup();

};

}

}

#endif // PROTOLAYER_CARBON_WINDOW_H
