#ifndef PROTOLAYER_CARBON_CONTROL_H
#define PROTOLAYER_CARBON_CONTROL_H

#include "forward.h"
#include "Component.h"
#include "ControlListener.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class Control : public Component
{
  /** TODO: Documentation */
  friend class Window;

  /** TODO: Documentation */
  friend class EmbeddingControl;

  /** TODO: Documentation */
  friend class RootControl;

public:
  /** TODO: Documentation */
  enum Size { NORMAL_SIZE = kControlSizeNormal,
              SMALL_SIZE = kControlSizeSmall,
              LARGE_SIZE = kControlSizeLarge,
              AUTO_SIZE = kControlSizeAuto };

private:
  /** TODO: Documentation */
  ControlRef _controlRef;

  /** TODO: Documentation */
  EventTargetRef _eventTargetRef;

  /** TODO: Documentation */
  ControlListener* _controlListener;

  /** TODO: Documentation */ 
  Control::Size _size;

  /** TODO: Documentation */
  mutable Rect _controlBounds;

  /** TODO: Documentation */
  bool _isOwned;

  /** TODO: Documentation */
  bool _isVisible;

  /** TODO: Documentation */
  bool _isActive;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Control();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Control(ControlRef ref);

  /**
   * TODO: Documentation
   * <p>
   */
  Control(Control::Size size);

  /**
   * TODO: Documentation
   * <p>
   */
  Control(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  Control(Control::Size size, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Control() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isOwned() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isWithin(short x, short y);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isCreated() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const Rect& getControlBounds() const;

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
  virtual bool isActive() const;

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
  void draw();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setSize(short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setPosition(short x, short y);

  /**
   * TODO: Documentation
   * <p>
   */
  //  void setToolTipText(const char* label);

  /**
   * TODO: Documentation
   * <p>
   */
  //  const char* getToolTipText(const char* label);

  /**
   * TODO: Documentation
   * <p>
   */
  const Control::Size& getSize() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void addControlListener(ControlListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeControlListener(ControlListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  ControlRef& getControlRef();

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  void applyActivity();

  /**
   * TODO: Documentation
   * <p>
   */
  EventTargetRef& getEventTargetRef();

  /**
   * TODO: Documentation
   * <p>
   */
  void applyVisibility();

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

private:
  /**
   * TODO: Documentation
   *
   */
  virtual OSStatus create(WindowRef windowRef) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void dispose() = 0;

};

}

}

#endif // PROTOLAYER_CARBON_CONTROL_H
