#ifndef PROTOLAYER_CARBON_WINDOWCURSORCHANGELISTENER_H
#define PROTOLAYER_CARBON_WINDOWCURSORCHANGELISTENER_H

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
class WindowCursorChangeListener : public Listener
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
  virtual OSStatus windowCursorChange(EventHandlerCallRef callRef,
                                      EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWCURSORCHANGELISTENER_H
