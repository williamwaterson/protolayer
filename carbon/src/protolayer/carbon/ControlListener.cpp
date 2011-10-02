#include "ControlListener.h"

namespace protolayer
{

namespace carbon
{

pascal OSStatus controlHandler(EventHandlerCallRef callRef,
                               EventRef event,
                               void* userData)
{
  ControlListener* listener =
    reinterpret_cast <ControlListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventControlInitialize) {
    return listener->controlInitialize(callRef, event);

  } else if (whatHappened == kEventControlDispose) {
    return listener->controlDispose(callRef, event);

  } else if (whatHappened == kEventControlGetOptimalBounds) {
    return listener->controlGetOptimalBounds(callRef, event);

  } else if (whatHappened == kEventControlInitialize) {
    return listener->controlInitialize(callRef, event);

  } else if (whatHappened == kEventControlHit) {
    return listener->controlHit(callRef, event);

  } else if (whatHappened == kEventControlSimulateHit) {
    return listener->controlSimulateHit(callRef, event);

  } else if (whatHappened == kEventControlHitTest) {
    return listener->controlHitTest(callRef, event);

  } else if (whatHappened == kEventControlDraw) {
    return listener->controlDraw(callRef, event);

  } else if (whatHappened == kEventControlApplyBackground) {
    return listener->controlApplyBackground(callRef, event);

  } else if (whatHappened == kEventControlApplyTextColor) {
    return listener->controlApplyTextColor(callRef, event);

  } else if (whatHappened == kEventControlSetFocusPart) {
    return listener->controlSetFocusPart(callRef, event);

  } else if (whatHappened == kEventControlGetFocusPart) {
    return listener->controlGetFocusPart(callRef, event);

  } else if (whatHappened == kEventControlActivate) {
    return listener->controlActivate(callRef, event);

  } else if (whatHappened == kEventControlDeactivate) {
    return listener->controlDeactivate(callRef, event);

  } else if (whatHappened == kEventControlSetCursor) {
    return listener->controlSetCursor(callRef, event);

  } else if (whatHappened == kEventControlContextualMenuClick) {
    return listener->controlContextualMenuClick(callRef, event);

  } else if (whatHappened == kEventControlClick) {
    return listener->controlClick(callRef, event);

  } else if (whatHappened == kEventControlGetNextFocusCandidate) {
    return listener->controlGetNextFocusCandidate(callRef, event);

  } else if (whatHappened == kEventControlGetAutoToggleValue) {
    return listener->controlGetAutoToggleValue(callRef, event);

  } else if (whatHappened == kEventControlInterceptSubviewClick) {
    return listener->controlInterceptSubviewClick(callRef, event);

  } else if (whatHappened == kEventControlGetClickActivation) {
    return listener->controlGetClickActivation(callRef, event);

  } else if (whatHappened == kEventControlDragEnter) {
    return listener->controlDragEnter(callRef, event);

  } else if (whatHappened == kEventControlDragWithin) {
    return listener->controlDragWithin(callRef, event);

  } else if (whatHappened == kEventControlDragLeave) {
    return listener->controlDragLeave(callRef, event);

  } else if (whatHappened == kEventControlDragReceive) {
    return listener->controlDragReceive(callRef, event);

  } else if (whatHappened == kEventControlTrack) {
    return listener->controlTrack(callRef, event);

  } else if (whatHappened == kEventControlGetScrollToHereStartPoint) {
    return listener->controlGetScrollToHereStartPoint(callRef, event);

  } else if (whatHappened == kEventControlGetIndicatorDragConstraint) {
    return listener->controlGetIndicatorDragConstraint(callRef, event);

  } else if (whatHappened == kEventControlIndicatorMoved) {
    return listener->controlIndicatorMoved(callRef, event);

  } else if (whatHappened == kEventControlGhostingFinished) {
    return listener->controlGhostingFinished(callRef, event);

  } else if (whatHappened == kEventControlGetActionProcPart) {
    return listener->controlGetActionProcPart(callRef, event);

  } else if (whatHappened == kEventControlGetPartRegion) {
    return listener->controlGetPartRegion(callRef, event);

  } else if (whatHappened == kEventControlGetPartBounds) {
    return listener->controlGetPartBounds(callRef, event);

  } else if (whatHappened == kEventControlSetData) {
    return listener->controlSetData(callRef, event);

  } else if (whatHappened == kEventControlGetData) {
    return listener->controlGetData(callRef, event);

  } else if (whatHappened == kEventControlGetSizeConstraints) {
    return listener->controlGetSizeConstraints(callRef, event);

  } else if (whatHappened == kEventControlValueFieldChanged) {
    return listener->controlValueFieldChanged(callRef, event);

  } else if (whatHappened == kEventControlAddedSubControl) {
    return listener->controlAddedSubControl(callRef, event);

  } else if (whatHappened == kEventControlRemovingSubControl) {
    return listener->controlRemovingSubControl(callRef, event);

  } else if (whatHappened == kEventControlBoundsChanged) {
    return listener->controlBoundsChanged(callRef, event);

  } else if (whatHappened == kEventControlTitleChanged) {
    return listener->controlTitleChanged(callRef, event);

  } else if (whatHappened == kEventControlOwningWindowChanged) {
    return listener->controlOwningWindowChanged(callRef, event);

  } else if (whatHappened == kEventControlHiliteChanged) {
    return listener->controlHiliteChanged(callRef, event);

  } else if (whatHappened == kEventControlEnabledStateChanged) {
    return listener->controlEnabledStateChanged(callRef, event);

  }

  return eventNotHandledErr;
}


/**
 * TODO: Documentation
 * <p>
 */
const EventTypeSpec controlListenerEventTypes[] =
  {
    { kEventClassControl, kEventControlInitialize},
    { kEventClassControl, kEventControlDispose},
    { kEventClassControl, kEventControlGetOptimalBounds},
    { kEventClassControl, kEventControlHit},
    { kEventClassControl, kEventControlSimulateHit},
    { kEventClassControl, kEventControlHitTest},
    { kEventClassControl, kEventControlDraw},
    { kEventClassControl, kEventControlApplyBackground},
    { kEventClassControl, kEventControlApplyTextColor},
    { kEventClassControl, kEventControlSetFocusPart},
    { kEventClassControl, kEventControlGetFocusPart},
    { kEventClassControl, kEventControlActivate},
    { kEventClassControl, kEventControlDeactivate},
    { kEventClassControl, kEventControlSetCursor},
    { kEventClassControl, kEventControlContextualMenuClick},
    { kEventClassControl, kEventControlClick},
    { kEventClassControl, kEventControlGetNextFocusCandidate},
    { kEventClassControl, kEventControlGetAutoToggleValue},
    { kEventClassControl, kEventControlInterceptSubviewClick},
    { kEventClassControl, kEventControlGetClickActivation},
    { kEventClassControl, kEventControlDragEnter},
    { kEventClassControl, kEventControlDragWithin},
    { kEventClassControl, kEventControlDragLeave},
    { kEventClassControl, kEventControlDragReceive},
    { kEventClassControl, kEventControlTrack},
    { kEventClassControl, kEventControlGetScrollToHereStartPoint},
    { kEventClassControl, kEventControlGetIndicatorDragConstraint},
    { kEventClassControl, kEventControlIndicatorMoved},
    { kEventClassControl, kEventControlGhostingFinished},
    { kEventClassControl, kEventControlGetActionProcPart},
    { kEventClassControl, kEventControlGetPartRegion},
    { kEventClassControl, kEventControlGetPartBounds},
    { kEventClassControl, kEventControlSetData},
    { kEventClassControl, kEventControlGetData},
    { kEventClassControl, kEventControlGetSizeConstraints},
    { kEventClassControl, kEventControlValueFieldChanged},
    { kEventClassControl, kEventControlAddedSubControl},
    { kEventClassControl, kEventControlRemovingSubControl},
    { kEventClassControl, kEventControlBoundsChanged},
    { kEventClassControl, kEventControlTitleChanged},
    { kEventClassControl, kEventControlOwningWindowChanged},
    { kEventClassControl, kEventControlHiliteChanged},
    { kEventClassControl, kEventControlEnabledStateChanged}
  };


const EventHandlerUPP controlListenerEventHandler =
  NewEventHandlerUPP(controlHandler);


int ControlListener::getNumberEventTypes()
{
  return GetEventTypeCount(controlListenerEventTypes);
}


const EventTypeSpec* ControlListener::getEventTypes()
{
  return controlListenerEventTypes;
}


EventHandlerUPP ControlListener::getEventHandlerUPP()
{
  return controlListenerEventHandler;
}


OSStatus
ControlListener::controlInitialize(EventHandlerCallRef callRef,
                                   EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDispose(EventHandlerCallRef callRef,
                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetOptimalBounds(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlHit(EventHandlerCallRef callRef,
                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlSimulateHit(EventHandlerCallRef callRef,
                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlHitTest(EventHandlerCallRef callRef,
                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDraw(EventHandlerCallRef callRef,
                             EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlApplyBackground(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlApplyTextColor(EventHandlerCallRef callRef,
                                       EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlSetFocusPart(EventHandlerCallRef callRef,
                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetFocusPart(EventHandlerCallRef callRef,
                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlActivate(EventHandlerCallRef callRef,
                                 EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDeactivate(EventHandlerCallRef callRef,
                                   EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlSetCursor(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlContextualMenuClick(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlClick(EventHandlerCallRef callRef,
                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetNextFocusCandidate(EventHandlerCallRef callRef,
                                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetAutoToggleValue(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlInterceptSubviewClick(EventHandlerCallRef callRef,
                                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetClickActivation(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDragEnter(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDragWithin(EventHandlerCallRef callRef,
                                   EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDragLeave(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlDragReceive(EventHandlerCallRef callRef,
                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlTrack(EventHandlerCallRef callRef,
                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetScrollToHereStartPoint(EventHandlerCallRef callRef,
                                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetIndicatorDragConstraint(EventHandlerCallRef callRef,
                                                   EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlIndicatorMoved(EventHandlerCallRef callRef,
                                       EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGhostingFinished(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetActionProcPart(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetPartRegion(EventHandlerCallRef callRef,
                                      EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetPartBounds(EventHandlerCallRef callRef,
                                      EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlSetData(EventHandlerCallRef callRef,
                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetData(EventHandlerCallRef callRef,
                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlGetSizeConstraints(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlValueFieldChanged(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlAddedSubControl(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlRemovingSubControl(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlBoundsChanged(EventHandlerCallRef callRef,
                                      EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlTitleChanged(EventHandlerCallRef callRef,
                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlOwningWindowChanged(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlHiliteChanged(EventHandlerCallRef callRef,
                                      EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
ControlListener::controlEnabledStateChanged(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


}


}
