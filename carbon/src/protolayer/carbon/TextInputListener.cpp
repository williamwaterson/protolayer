#include "TextInputListener.h"


namespace protolayer
{

namespace carbon
{


pascal OSStatus textInputHandler(EventHandlerCallRef callRef,
                                 EventRef event,
                                 void* userData)
{
  TextInputListener* listener =
    reinterpret_cast <TextInputListener*> (userData);

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventTextInputUpdateActiveInputArea) {
    return listener->textInputUpdateActiveInputArea(callRef, event);

  } else if (whatHappened == kEventTextInputUnicodeForKeyEvent) {
    return listener->textInputUnicodeForKeyEvent(callRef, event);

  } else if (whatHappened == kEventTextInputOffsetToPos) {
    return listener->textInputOffsetToPos(callRef, event);

  } else if (whatHappened == kEventTextInputPosToOffset) {
    return listener->textInputPosToOffset(callRef, event);

  } else if (whatHappened == kEventTextInputShowHideBottomWindow) {
    return listener->textInputShowHideBottomWindow(callRef, event);

  } else if (whatHappened == kEventTextInputGetSelectedText) {
    return listener->textInputGetSelectedText(callRef, event);

  } else if (whatHappened == kEventTextInputUnicodeText) {
    return listener->textInputUnicodeText(callRef, event);

  }

  return eventNotHandledErr;
}



const EventTypeSpec textInputListenerEventTypes[] =
{
  { kEventClassTextInput, kEventTextInputUpdateActiveInputArea },
  { kEventClassTextInput, kEventTextInputUnicodeForKeyEvent },
  { kEventClassTextInput, kEventTextInputOffsetToPos },
  { kEventClassTextInput, kEventTextInputPosToOffset },
  { kEventClassTextInput, kEventTextInputShowHideBottomWindow },
  { kEventClassTextInput, kEventTextInputGetSelectedText },
  { kEventClassTextInput, kEventTextInputUnicodeText }
};


const EventHandlerUPP textInputListenerEventHandler =
  NewEventHandlerUPP(textInputHandler);


int TextInputListener::getNumberEventTypes()
{
  return GetEventTypeCount(textInputListenerEventTypes);
}


const EventTypeSpec* TextInputListener::getEventTypes()
{
  return textInputListenerEventTypes;
}


EventHandlerUPP TextInputListener::getEventHandlerUPP()
{
  return textInputListenerEventHandler;
}


OSStatus
TextInputListener::textInputUpdateActiveInputArea(EventHandlerCallRef callRef,
                                                  EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
TextInputListener::textInputUnicodeForKeyEvent(EventHandlerCallRef callRef,
                                               EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
TextInputListener::textInputOffsetToPos(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
TextInputListener::textInputPosToOffset(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
TextInputListener::textInputShowHideBottomWindow(EventHandlerCallRef callRef,
                                                 EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
TextInputListener::textInputGetSelectedText(EventHandlerCallRef callRef,
                                            EventRef event)
{
  return eventNotHandledErr;
}


OSStatus
TextInputListener::textInputUnicodeText(EventHandlerCallRef callRef,
                                        EventRef event)
{
  return eventNotHandledErr;
}


}


}
