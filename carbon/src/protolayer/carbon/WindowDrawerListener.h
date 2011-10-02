#ifndef PROTOLAYER_CARBON_WINDOWDRAWERLISTENER_H
#define PROTOLAYER_CARBON_WINDOWDRAWERLISTENER_H

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
class WindowDrawerListener : public Listener
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
  virtual OSStatus windowDrawerOpening(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDrawerOpened(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDrawerClosing(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDrawerClosed(EventHandlerCallRef callRef,
                                      EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWDRAWERLISTENER_H
