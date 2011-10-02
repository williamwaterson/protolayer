#ifndef PROTOLAYER_CARBON_TEXTINPUTLISTENER_H
#define PROTOLAYER_CARBON_TEXTINPUTLISTENER_H

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
class TextInputListener : public Listener
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
  virtual OSStatus textInputUpdateActiveInputArea(EventHandlerCallRef callRef,
                                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus textInputUnicodeForKeyEvent(EventHandlerCallRef callRef,
                                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus textInputOffsetToPos(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus textInputPosToOffset(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus textInputShowHideBottomWindow(EventHandlerCallRef callRef,
                                                 EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus textInputGetSelectedText(EventHandlerCallRef callRef,
                                            EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus textInputUnicodeText(EventHandlerCallRef callRef,
                                        EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_TEXTINPUTLISTENER_H
