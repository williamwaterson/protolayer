#ifndef PROTOLAYER_CARBON_TABCONTROLLISTENER_H
#define PROTOLAYER_CARBON_TABCONTROLLISTENER_H

#include "forward.h"
#include "Listener.h"
#include "TabEvent.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class TabControlListener : public Listener
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
  virtual OSStatus controlHit(EventHandlerCallRef callRef,
                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void tabHit(TabEvent& event);

};


}


}


#endif // PROTOLAYER_CARBON_TABCONTROLLISTENER_H
