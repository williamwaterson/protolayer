#include "MenuListener.h"

namespace protolayer
{

namespace carbon
{

static pascal OSStatus menuHandler(EventHandlerCallRef callRef,
                                   EventRef event,
                                   void* userData)
{

  MenuListener* listener =
    reinterpret_cast <MenuListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventMenuBeginTracking) {
    return listener->menuBeginTracking(callRef, event);

  } else if (whatHappened == kEventMenuEndTracking) {
    return listener->menuEndTracking(callRef, event);

  } else if (whatHappened == kEventMenuChangeTrackingMode) {
    return listener->menuChangeTrackingMode(callRef, event);

  } else if (whatHappened == kEventMenuOpening) {
    return listener->menuOpening(callRef, event);

  } else if (whatHappened == kEventMenuClosed) {
    return listener->menuClosed(callRef, event);

  } else if (whatHappened == kEventMenuTargetItem) {
    return listener->menuTargetItem(callRef, event);

  } else if (whatHappened == kEventMenuMatchKey) {
    return listener->menuMatchKey(callRef, event);

  } else if (whatHappened == kEventMenuEnableItems) {
    return listener->menuEnableItems(callRef, event);

  } else if (whatHappened == kEventMenuPopulate) {
    return listener->menuPopulate(callRef, event);

  } else if (whatHappened == kEventMenuMeasureItemWidth) {
    return listener->menuMeasureItemWidth(callRef, event);

  } else if (whatHappened == kEventMenuMeasureItemHeight) {
    return listener->menuMeasureItemHeight(callRef, event);

  } else if (whatHappened == kEventMenuDrawItem) {
    return listener->menuDrawItem(callRef, event);

  } else if (whatHappened == kEventMenuDrawItemContent) {
    return listener->menuDrawItemContent(callRef, event);

  } else if (whatHappened == kEventMenuDispose) {
    return listener->menuDispose(callRef, event);

  }

  return eventNotHandledErr;
}


const EventTypeSpec menuListenerEventTypes[] =
{
  { kEventClassMenu, kEventMenuBeginTracking },
  { kEventClassMenu, kEventMenuEndTracking },
  { kEventClassMenu, kEventMenuChangeTrackingMode },
  { kEventClassMenu, kEventMenuOpening },
  { kEventClassMenu, kEventMenuClosed },
  { kEventClassMenu, kEventMenuTargetItem },
  { kEventClassMenu, kEventMenuMatchKey },
  { kEventClassMenu, kEventMenuEnableItems },
  { kEventClassMenu, kEventMenuPopulate },
  { kEventClassMenu, kEventMenuMeasureItemWidth },
  { kEventClassMenu, kEventMenuMeasureItemHeight },
  { kEventClassMenu, kEventMenuDrawItem },
  { kEventClassMenu, kEventMenuDrawItemContent },
  { kEventClassMenu, kEventMenuDispose }
};


const EventHandlerUPP menuListenerEventHandler =
  NewEventHandlerUPP(menuHandler);


int MenuListener::getNumberEventTypes()
{
  return GetEventTypeCount(menuListenerEventTypes);
}


const EventTypeSpec* MenuListener::getEventTypes()
{
  return menuListenerEventTypes;
}


EventHandlerUPP MenuListener::getEventHandlerUPP()
{
  return menuListenerEventHandler;
}


OSStatus
MenuListener::menuBeginTracking(EventHandlerCallRef callRef,
                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuEndTracking(EventHandlerCallRef callRef,
                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuChangeTrackingMode(EventHandlerCallRef callRef,
                                     EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuOpening(EventHandlerCallRef callRef,
                          EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuClosed(EventHandlerCallRef callRef,
                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuTargetItem(EventHandlerCallRef callRef,
                             EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuMatchKey(EventHandlerCallRef callRef,
                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuEnableItems(EventHandlerCallRef callRef,
                              EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuPopulate(EventHandlerCallRef callRef,
                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuMeasureItemWidth(EventHandlerCallRef callRef,
                                   EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuMeasureItemHeight(EventHandlerCallRef callRef,
                                    EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuDrawItem(EventHandlerCallRef callRef,
                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuDrawItemContent(EventHandlerCallRef callRef,
                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
MenuListener::menuDispose(EventHandlerCallRef callRef,
                          EventRef event)
{
  return eventNotHandledErr;
}


}


}
