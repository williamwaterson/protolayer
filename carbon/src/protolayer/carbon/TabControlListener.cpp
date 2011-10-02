#include "TabControlListener.h"

namespace protolayer
{

namespace carbon
{

namespace
{

pascal OSStatus controlHandler(EventHandlerCallRef callRef,
                               EventRef event,
                               void* userData)
{
  TabControlListener* listener =
    reinterpret_cast <TabControlListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventControlHit) {
    //    TabControl* controlRef = reinterpret_cast <TabControl*> (userData);
    //    TabEvent* TabEvent::getInstance();
    //    TabEvent* TabEvent::getInstance();
    return listener->controlHit(callRef, event);
  }

  return eventNotHandledErr;
}

}


/**
 * TODO: Documentation
 * <p>
 */
const EventTypeSpec tabControlListenerEventTypes[] =
  {
    { kEventClassControl, kEventControlHit}
  };


const EventHandlerUPP tabControlListenerEventHandler =
  NewEventHandlerUPP(controlHandler);


int TabControlListener::getNumberEventTypes()
{
  return GetEventTypeCount(tabControlListenerEventTypes);
}


const EventTypeSpec* TabControlListener::getEventTypes()
{
  return tabControlListenerEventTypes;
}


EventHandlerUPP TabControlListener::getEventHandlerUPP()
{
  return tabControlListenerEventHandler;
}


OSStatus
TabControlListener::controlHit(EventHandlerCallRef callRef,
			       EventRef event)
{
  return eventNotHandledErr;
}


void TabControlListener::tabHit(TabEvent& event)
{
}


}


}
