#ifndef PROTOLAYER_CARBON_MENULISTENER_H
#define PROTOLAYER_CARBON_MENULISTENER_H

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
void installListener(MenuListener& listener,
                     EventTargetRef target);


/**
 * TODO: Documentation
 * <p>
 */
class MenuListener : public Listener
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

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuBeginTracking(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuEndTracking(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuChangeTrackingMode(EventHandlerCallRef callRef,
                                          EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuOpening(EventHandlerCallRef callRef,
                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuClosed(EventHandlerCallRef callRef,
                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuTargetItem(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuMatchKey(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuEnableItems(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuPopulate(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuMeasureItemWidth(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuMeasureItemHeight(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuDrawItem(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuDrawItemContent(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus menuDispose(EventHandlerCallRef callRef,
                               EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_MENULISTENER_H
