#ifndef PROTOLAYER_CARBON_COMPONENT_H
#define PROTOLAYER_CARBON_COMPONENT_H

#include <map>

#include "forward.h"
#include "MouseListener.h"
#include "KeyboardListener.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class Component
{
  /** TODO: Documentation */
  typedef ::std::map <Listener*, EventHandlerRef> ListenerMapType;

  /** TODO: Documentation */
  typedef ListenerMapType::iterator ListenerIteratorType;

  /** TODO: Documentation */
  Rect* _bounds;

  /** TODO: Documentation */
  ListenerMapType _listenerMap;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Component();

  /**
   * TODO: Documentation
   * <p>
   */
  Component(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Component() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual bool isWithin(short x, short y);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void show() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void hide() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void activate() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual bool isActive() const = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual short getPositionLeft() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual short getPositionRight() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual short getPositionTop() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual short getPositionBottom() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setSize(short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  void setPosition(short x, short y);

  /**
   * TODO: Documentation
   * <p>
   */
  void addKeyboardListener(KeyboardListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeKeyboardListener(KeyboardListener& listener);

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  Rect* getBounds();

  /**
   * TODO: Documentation
   * <p>
   */
  void addListener(Listener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeListener(Listener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void initialise();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual EventTargetRef& getEventTargetRef() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  void cleanup();
};

}

}

#endif // PROTOLAYER_CARBON_COMPONENT_H
