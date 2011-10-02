#include "WindowActivationListener.h"


namespace protolayer
{

namespace carbon
{


pascal OSStatus windowActivationHandler(EventHandlerCallRef callRef,
                                        EventRef event,
                                        void* userData)
{
  WindowActivationListener* listener =
    reinterpret_cast <WindowActivationListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowActivated) {
    return listener->windowActivated(callRef, event);
  } else if (whatHappened == kEventWindowDeactivated) {
    return listener->windowDeactivated(callRef, event);
  } else if (whatHappened == kEventWindowGetClickActivation) {
    return listener->windowGetClickActivation(callRef, event);
  }

  return eventNotHandledErr;
}


const EventTypeSpec windowActivationListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowActivated },
  { kEventClassWindow, kEventWindowDeactivated },
  { kEventClassWindow, kEventWindowGetClickActivation }
};


const EventHandlerUPP windowActivationListenerEventHandler =
  NewEventHandlerUPP(windowActivationHandler);


int WindowActivationListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowActivationListenerEventTypes);
}


const EventTypeSpec* WindowActivationListener::getEventTypes()
{
  return windowActivationListenerEventTypes;
}


EventHandlerUPP WindowActivationListener::getEventHandlerUPP()
{
  return windowActivationListenerEventHandler;
}


OSStatus
WindowActivationListener::windowActivated(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowActivationListener::windowDeactivated(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowActivationListener::windowGetClickActivation(EventHandlerCallRef callRef,
                                                   EventRef event)
{
  return eventNotHandledErr;
}


}


}
