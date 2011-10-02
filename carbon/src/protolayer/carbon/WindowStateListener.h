#ifndef PROTOLAYER_CARBON_WINDOWSTATELISTENER_H
#define PROTOLAYER_CARBON_WINDOWSTATELISTENER_H

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
class WindowStateListener : public Listener
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
  virtual OSStatus windowShowing(EventHandlerCallRef callRef,
                                 EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowHiding(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowShown(EventHandlerCallRef callRef,
                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowHidden(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowCollapsing(EventHandlerCallRef callRef,
                                    EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowCollapsed(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowExpanding(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowExpanded(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowZoomed(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowBoundsChanging(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowBoundsChanged(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowResizeStarted(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowResizeCompleted(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDragStarted(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowDragCompleted(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClosed(EventHandlerCallRef callRef,
                                EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWSTATELISTENER_H
