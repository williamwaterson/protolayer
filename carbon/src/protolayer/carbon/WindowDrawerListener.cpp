#include "WindowDrawerListener.h"


namespace protolayer
{

namespace carbon
{

pascal OSStatus windowDrawerHandler(EventHandlerCallRef callRef,
                                    EventRef event,
                                    void* userData)
{
  WindowDrawerListener* listener =
    reinterpret_cast <WindowDrawerListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowDrawerOpening) {
    return listener->windowDrawerOpening(callRef, event);

  } else if (whatHappened == kEventWindowDrawerOpened) {
    return listener->windowDrawerOpened(callRef, event);

  } else if (whatHappened == kEventWindowDrawerClosing) {
    return listener->windowDrawerClosing(callRef, event);

  } else if (whatHappened == kEventWindowDrawerClosed) {
    return listener->windowDrawerClosed(callRef, event);

  }

  return eventNotHandledErr;
}


const EventTypeSpec windowDrawerListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowDrawerOpening },
  { kEventClassWindow, kEventWindowDrawerOpened },
  { kEventClassWindow, kEventWindowDrawerClosing },
  { kEventClassWindow, kEventWindowDrawerClosed }
};


const EventHandlerUPP windowDrawerListenerEventHandler =
  NewEventHandlerUPP(windowDrawerHandler);


int WindowDrawerListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowDrawerListenerEventTypes);
}


const EventTypeSpec* WindowDrawerListener::getEventTypes()
{
  return windowDrawerListenerEventTypes;
}


EventHandlerUPP WindowDrawerListener::getEventHandlerUPP()
{
  return windowDrawerListenerEventHandler;
}


OSStatus
WindowDrawerListener::windowDrawerOpening(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowDrawerListener::windowDrawerOpened(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowDrawerListener::windowDrawerClosing(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowDrawerListener::windowDrawerClosed(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}

}

}
