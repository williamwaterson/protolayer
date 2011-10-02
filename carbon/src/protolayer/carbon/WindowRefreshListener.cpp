#include "WindowRefreshListener.h"


namespace protolayer
{

namespace carbon
{

pascal OSStatus windowRefreshHandler(EventHandlerCallRef callRef,
                                     EventRef event,
                                     void* userData)
{
  WindowRefreshListener* listener =
    reinterpret_cast <WindowRefreshListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowUpdate) {
    return listener->windowUpdate(callRef, event);
  } else if (whatHappened == kEventWindowDrawContent) {
    return listener->windowDrawContent(callRef, event);
  }

  return eventNotHandledErr;
}



const EventTypeSpec windowRefreshListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowUpdate },
  { kEventClassWindow, kEventWindowDrawContent }
};


const EventHandlerUPP windowRefreshListenerEventHandler =
  NewEventHandlerUPP(windowRefreshHandler);


int WindowRefreshListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowRefreshListenerEventTypes);
}


const EventTypeSpec* WindowRefreshListener::getEventTypes()
{
  return windowRefreshListenerEventTypes;
}


EventHandlerUPP WindowRefreshListener::getEventHandlerUPP()
{
  return windowRefreshListenerEventHandler;
}


OSStatus
WindowRefreshListener::windowUpdate(EventHandlerCallRef callRef,
                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowRefreshListener::windowDrawContent(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


}


}
