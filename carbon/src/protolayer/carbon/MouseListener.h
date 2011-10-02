#ifndef PROTOLAYER_CARBON_MOUSELISTENER_H
#define PROTOLAYER_CARBON_MOUSELISTENER_H

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
class MouseListener : public Listener
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
  virtual const EventTypeSpec* getEventTypes();

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual EventHandlerUPP getEventHandlerUPP();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseDown(EventHandlerCallRef callRef,
                             EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseUp(EventHandlerCallRef callRef,
                           EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseMoved(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseDragged(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseEntered(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseExited(EventHandlerCallRef callRef,
                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus mouseWheelMoved(EventHandlerCallRef callRef,
                                   EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_MOUSELISTENER_H
