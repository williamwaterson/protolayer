#include "KeyboardListener.h"


namespace protolayer
{

namespace carbon
{

pascal OSStatus keyboardHandler(EventHandlerCallRef callRef,
                                EventRef event,
                                void* userData)
{
  KeyboardListener* listener =
    reinterpret_cast <KeyboardListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventRawKeyDown) {
    return listener->rawKeyDown(callRef, event);

  } else if (whatHappened == kEventRawKeyRepeat) {
    return listener->rawKeyRepeat(callRef, event);

  } else if (whatHappened == kEventRawKeyUp) {
    return listener->rawKeyUp(callRef, event);

  } else if (whatHappened == kEventRawKeyModifiersChanged) {
    return listener->rawKeyModifiersChanged(callRef, event);

  } else if (whatHappened == kEventHotKeyPressed) {
    return listener->hotKeyPressed(callRef, event);

  } else if (whatHappened == kEventHotKeyReleased) {
    return listener->hotKeyReleased(callRef, event);

  }

  return eventNotHandledErr;
}


const EventTypeSpec keyboardListenerEventTypes[] =
{
  { kEventClassKeyboard, kEventRawKeyDown },
  { kEventClassKeyboard, kEventRawKeyRepeat },
  { kEventClassKeyboard, kEventRawKeyUp },
  { kEventClassKeyboard, kEventRawKeyModifiersChanged },
  { kEventClassKeyboard, kEventHotKeyPressed },
  { kEventClassKeyboard, kEventHotKeyReleased }
};


int KeyboardListener::getNumberEventTypes()
{
  return GetEventTypeCount(keyboardListenerEventTypes);
}


const EventHandlerUPP keyboardListenerEventHandler =
  NewEventHandlerUPP(keyboardHandler);


const EventTypeSpec* KeyboardListener::getEventTypes()
{
  return keyboardListenerEventTypes;
}


EventHandlerUPP KeyboardListener::getEventHandlerUPP()
{
  return keyboardListenerEventHandler;
}


OSStatus
KeyboardListener::rawKeyDown(EventHandlerCallRef callRef,
                             EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
KeyboardListener::rawKeyRepeat(EventHandlerCallRef callRef,
                               EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
KeyboardListener::rawKeyUp(EventHandlerCallRef callRef,
                           EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
KeyboardListener::rawKeyModifiersChanged(EventHandlerCallRef callRef,
                                         EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
KeyboardListener::hotKeyPressed(EventHandlerCallRef callRef,
                                EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
KeyboardListener::hotKeyReleased(EventHandlerCallRef callRef,
                                 EventRef event)
{
  return eventNotHandledErr;
}


}


}
