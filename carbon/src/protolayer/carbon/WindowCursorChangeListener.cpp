#include "WindowCursorChangeListener.h"


namespace protolayer
{

namespace carbon
{


pascal OSStatus windowCursorHandler(EventHandlerCallRef callRef,
                                    EventRef event,
                                    void* userData)
{
  WindowCursorChangeListener* listener =
    reinterpret_cast <WindowCursorChangeListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowCursorChange) {
    return listener->windowCursorChange(callRef, event);
  }

  return eventNotHandledErr;
}


const EventTypeSpec windowCursorChangeListenerEventTypes[] =
{
  { kEventClassWindow, kEventWindowCursorChange }
};


const EventHandlerUPP windowCursorChangeListenerEventHandler =
  NewEventHandlerUPP(windowCursorHandler);


int WindowCursorChangeListener::getNumberEventTypes()
{
  return GetEventTypeCount(windowCursorChangeListenerEventTypes);
}


const EventTypeSpec* WindowCursorChangeListener::getEventTypes()
{
  return windowCursorChangeListenerEventTypes;
}


EventHandlerUPP WindowCursorChangeListener::getEventHandlerUPP()
{
  return windowCursorChangeListenerEventHandler;
}


OSStatus
WindowCursorChangeListener::windowCursorChange(EventHandlerCallRef callRef,
                                               EventRef event)
{
}

}

}
