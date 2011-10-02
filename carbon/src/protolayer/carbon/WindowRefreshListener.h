#ifndef PROTOLAYER_CARBON_WINDOWREFRESHLISTENER_H
#define PROTOLAYER_CARBON_WINDOWREFRESHLISTENER_H

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
class WindowRefreshListener : public Listener
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

public:
  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowUpdate(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDrawContent(EventHandlerCallRef callRef,
                                     EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWREFRESHLISTENER_H
