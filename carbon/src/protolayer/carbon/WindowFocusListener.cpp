#include "WindowFocusListener.h"


namespace protolayer
{

namespace carbon
{

pascal OSStatus windowFocusHandler(EventHandlerCallRef callRef,
                                   EventRef event,
                                   void* userData)
{
  WindowFocusListener* listener =
    reinterpret_cast <WindowFocusListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowFocusAcquired) {
    return listener->windowFocusAcquired(callRef, event);

  } else  if (whatHappened == kEventWindowFocusRelinquish) {
    listener->windowFocusRelinquish(callRef, event);

  } else  if (whatHappened == kEventWindowFocusContent) {
    listener->windowFocusContent(callRef, event);

  } else  if (whatHappened == kEventWindowFocusToolbar) {
    listener->windowFocusToolbar(callRef, event);

  }

  return eventNotHandledErr;
}


EventTypeSpec windowFocusListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowFocusAcquired },
  { kEventClassWindow, kEventWindowFocusRelinquish },
  { kEventClassWindow, kEventWindowFocusContent },
  { kEventClassWindow, kEventWindowFocusToolbar }
};


const EventHandlerUPP windowFocusListenerEventHandler =
  NewEventHandlerUPP(windowFocusHandler);


int WindowFocusListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowFocusListenerEventTypes);
}


const EventTypeSpec* WindowFocusListener::getEventTypes()
{
  return windowFocusListenerEventTypes;
}


EventHandlerUPP WindowFocusListener::getEventHandlerUPP()
{
  return windowFocusListenerEventHandler;
}


OSStatus
WindowFocusListener::windowFocusAcquired(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowFocusListener::windowFocusRelinquish(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowFocusListener::windowFocusContent(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowFocusListener::windowFocusToolbar(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}

}

}
