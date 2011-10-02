#ifndef PROTOLAYER_CARBON_WINDOWACTIVATIONLISTENER_H
#define PROTOLAYER_CARBON_WINDOWACTIVATIONLISTENER_H

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
class WindowActivationListener : public Listener
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
  virtual OSStatus windowActivated(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDeactivated(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowGetClickActivation(EventHandlerCallRef callRef,
                                            EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWACTIVATIONLISTENER_H
