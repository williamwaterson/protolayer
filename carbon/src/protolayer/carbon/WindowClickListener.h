#ifndef PROTOLAYER_CARBON_WINDOWCLICKLISTENER_H
#define PROTOLAYER_CARBON_WINDOWCLICKLISTENER_H

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
class WindowClickListener : public Listener
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
  virtual OSStatus windowClickDragRgn(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickResizeRgn(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickCollapseRgn(EventHandlerCallRef callRef,
                                          EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickCloseRgn(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickZoomRgn(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickContentRgn(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickProxyIconRgn(EventHandlerCallRef callRef,
                                           EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickToolbarButtonRgn(EventHandlerCallRef callRef,
                                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus windowClickStructureRgn(EventHandlerCallRef callRef,
                                           EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWACTIVATIONLISTENER_H
