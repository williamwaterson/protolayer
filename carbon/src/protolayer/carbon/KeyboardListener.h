#ifndef PROTOLAYER_CARBON_KEYBOARDLISTENER_H
#define PROTOLAYER_CARBON_KEYBOARDLISTENER_H

#include "forward.h"
#include "Listener.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
void installListener(KeyboardListener& listener,
                     EventTargetRef target);


/**
 * TODO: Documentation
 * <p>
 */
class KeyboardListener : public Listener
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  int getNumberEventTypes();

  /**
   * TODO: Documentation
   * <p>
   */  
  const EventTypeSpec* getEventTypes();

  /**
   * TODO: Documentation
   * <p>
   */  
  EventHandlerUPP getEventHandlerUPP();

public:
  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus rawKeyDown(EventHandlerCallRef callRef,
                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus rawKeyRepeat(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus rawKeyUp(EventHandlerCallRef callRef,
                            EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus rawKeyModifiersChanged(EventHandlerCallRef callRef,
                                          EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus hotKeyPressed(EventHandlerCallRef callRef,
                                 EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus hotKeyReleased(EventHandlerCallRef callRef,
                                  EventRef event);

};


}


}


#endif // PROTOLAYER_CARBON_KEYBOARDLISTENER_H
