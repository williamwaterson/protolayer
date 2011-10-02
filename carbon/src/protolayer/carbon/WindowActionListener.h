#ifndef PROTOLAYER_CARBON_WINDOWACTIONLISTENER_H
#define PROTOLAYER_CARBON_WINDOWACTIONLISTENER_H

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
class WindowActionListener : public Listener
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
  virtual OSStatus windowCollapse(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowExpand(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClose(EventHandlerCallRef callRef,
                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowZoom(EventHandlerCallRef callRef,
                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowContextualMenuSelect(EventHandlerCallRef callRef,
                                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowPathSelect(EventHandlerCallRef callRef,
                                    EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowGetIdealSize(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowGetMinimumSize(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowGetMaximumSize(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowConstrain(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowHandleContentClick(EventHandlerCallRef callRef,
                                            EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowGetDockTileMenu(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowProxyBeginDrag(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowProxyEndDrag(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowToolbarSwitchMode(EventHandlerCallRef callRef,
                                           EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWACTIONLISTENER_H
