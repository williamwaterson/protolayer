#ifndef PROTOLAYER_CARBON_WINDOWFOCUSLISTENER_H
#define PROTOLAYER_CARBON_WINDOWFOCUSLISTENER_H

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
class WindowFocusListener : public Listener
{
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

public:
  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowFocusAcquired(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowFocusRelinquish(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowFocusContent(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowFocusToolbar(EventHandlerCallRef callRef,
                                      EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWFOCUSLISTENER_H
