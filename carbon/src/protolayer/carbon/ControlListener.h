#ifndef PROTOLAYER_CARBON_CONTROLLISTENER_H
#define PROTOLAYER_CARBON_CONTROLLISTENER_H

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
class ControlListener : public Listener
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
  virtual OSStatus controlInitialize(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDispose(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetOptimalBounds(EventHandlerCallRef callRef,
                                           EventRef event);

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
  virtual OSStatus controlSimulateHit(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlHitTest(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDraw(EventHandlerCallRef callRef,
                               EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlApplyBackground(EventHandlerCallRef callRef,
                                          EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlApplyTextColor(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlSetFocusPart(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetFocusPart(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlActivate(EventHandlerCallRef callRef,
                                   EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDeactivate(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlSetCursor(EventHandlerCallRef callRef,
                                    EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlContextualMenuClick(EventHandlerCallRef callRef,
                                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlClick(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetNextFocusCandidate(EventHandlerCallRef callRef,
                                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetAutoToggleValue(EventHandlerCallRef callRef,
                                             EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlInterceptSubviewClick(EventHandlerCallRef callRef,
                                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetClickActivation(EventHandlerCallRef callRef,
                                             EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDragEnter(EventHandlerCallRef callRef,
                                    EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDragWithin(EventHandlerCallRef callRef,
                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDragLeave(EventHandlerCallRef callRef,
                                    EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlDragReceive(EventHandlerCallRef callRef,
                                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlTrack(EventHandlerCallRef callRef,
                                EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetScrollToHereStartPoint(EventHandlerCallRef callRef,
                                                    EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetIndicatorDragConstraint(EventHandlerCallRef callRef,
                                                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlIndicatorMoved(EventHandlerCallRef callRef,
                                         EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGhostingFinished(EventHandlerCallRef callRef,
                                           EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetActionProcPart(EventHandlerCallRef callRef,
                                            EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetPartRegion(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetPartBounds(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlSetData(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetData(EventHandlerCallRef callRef,
                                  EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlGetSizeConstraints(EventHandlerCallRef callRef,
                                             EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlValueFieldChanged(EventHandlerCallRef callRef,
                                            EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlAddedSubControl(EventHandlerCallRef callRef,
                                          EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlRemovingSubControl(EventHandlerCallRef callRef,
                                             EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlBoundsChanged(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlTitleChanged(EventHandlerCallRef callRef,
                                       EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlOwningWindowChanged(EventHandlerCallRef callRef,
                                              EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlHiliteChanged(EventHandlerCallRef callRef,
                                        EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus controlEnabledStateChanged(EventHandlerCallRef callRef,
                                              EventRef event);

};

}

}

#endif // PROTOLAYER_CARBON_CONTROLLISTENER_H
