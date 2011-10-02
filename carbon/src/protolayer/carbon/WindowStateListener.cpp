#include "WindowStateListener.h"


namespace protolayer
{

namespace carbon
{

pascal OSStatus windowStateHandler(EventHandlerCallRef callRef,
                                   EventRef event,
                                   void* userData)
{
  WindowStateListener* listener =
    reinterpret_cast <WindowStateListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowShowing) {
    return listener->windowShowing(callRef, event);

  } else if (whatHappened == kEventWindowHiding) {
    return listener->windowHiding(callRef, event);

  } else if (whatHappened == kEventWindowShown) {
    ExitToShell();
    return listener->windowShown(callRef, event);

  } else if (whatHappened == kEventWindowHidden) {
    return listener->windowHidden(callRef, event);

  } else if (whatHappened == kEventWindowCollapsing) {
    return listener->windowCollapsing(callRef, event);

  } else if (whatHappened == kEventWindowCollapsed) {
    return listener->windowCollapsed(callRef, event);

  } else if (whatHappened == kEventWindowExpanding) {
    return listener->windowExpanding(callRef, event);

  } else if (whatHappened == kEventWindowExpanded) {
    return listener->windowExpanded(callRef, event);

  } else if (whatHappened == kEventWindowZoomed) {
    return listener->windowZoomed(callRef, event);

  } else if (whatHappened == kEventWindowBoundsChanging) {
    return listener->windowBoundsChanging(callRef, event);

  } else if (whatHappened == kEventWindowBoundsChanged) {
    return listener->windowBoundsChanged(callRef, event);

  } else if (whatHappened == kEventWindowResizeStarted) {
    return listener->windowResizeStarted(callRef, event);

  } else if (whatHappened == kEventWindowResizeCompleted) {
    return listener->windowResizeCompleted(callRef, event);

  } else if (whatHappened == kEventWindowDragStarted) {
    return listener->windowDragStarted(callRef, event);

  } else if (whatHappened == kEventWindowDragCompleted) {
    return listener->windowDragCompleted(callRef, event);

  } else if (whatHappened == kEventWindowClosed) {
    return listener->windowClosed(callRef, event);

  }

  return eventNotHandledErr;
}


const EventTypeSpec windowStateListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowShowing },
  { kEventClassWindow, kEventWindowHiding },
  { kEventClassWindow, kEventWindowShown },
  { kEventClassWindow, kEventWindowHidden },
  { kEventClassWindow, kEventWindowCollapsing },
  { kEventClassWindow, kEventWindowCollapsed },
  { kEventClassWindow, kEventWindowExpanding },
  { kEventClassWindow, kEventWindowExpanded },
  { kEventClassWindow, kEventWindowZoomed },
  { kEventClassWindow, kEventWindowBoundsChanging },
  { kEventClassWindow, kEventWindowBoundsChanged },
  { kEventClassWindow, kEventWindowResizeStarted },
  { kEventClassWindow, kEventWindowResizeCompleted },
  { kEventClassWindow, kEventWindowDragStarted },
  { kEventClassWindow, kEventWindowDragCompleted },
  { kEventClassWindow, kEventWindowClosed }
};


const EventHandlerUPP windowStateListenerEventHandler =
  NewEventHandlerUPP(windowStateHandler);


int WindowStateListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowStateListenerEventTypes);
}


const EventTypeSpec* WindowStateListener::getEventTypes()
{
  return windowStateListenerEventTypes;
}


EventHandlerUPP WindowStateListener::getEventHandlerUPP()
{
  return windowStateListenerEventHandler;
}


OSStatus
WindowStateListener::windowShowing(EventHandlerCallRef callRef,
                                   EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowHiding(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowShown(EventHandlerCallRef callRef,
                                 EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowHidden(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowCollapsing(EventHandlerCallRef callRef,
                                      EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowCollapsed(EventHandlerCallRef callRef,
                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowExpanding(EventHandlerCallRef callRef,
                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowExpanded(EventHandlerCallRef callRef,
                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowZoomed(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowBoundsChanging(EventHandlerCallRef callRef,
                                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowBoundsChanged(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowResizeStarted(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowResizeCompleted(EventHandlerCallRef callRef,
                                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowDragStarted(EventHandlerCallRef callRef,
                                       EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowDragCompleted(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
WindowStateListener::windowClosed(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


}


}
