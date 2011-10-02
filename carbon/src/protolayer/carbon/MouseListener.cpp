#include "MouseListener.h"


namespace protolayer
{

namespace carbon
{

static pascal OSStatus mouseHandler(EventHandlerCallRef callRef,
                                    EventRef event,
                                    void* userData)
{
  OSStatus result = eventNotHandledErr;
  MouseListener* target = reinterpret_cast <MouseListener*> (userData);
  UInt32 eventKind = GetEventKind(event);
  switch (eventKind) {

  case kEventMouseDown:
    target->mouseDown(callRef, event);
    break;

  case kEventMouseUp:
    target->mouseUp(callRef, event);
    break;

  case kEventMouseEntered:
    target->mouseEntered(callRef, event);
    break;

  case kEventMouseExited:
    target->mouseExited(callRef, event);
    break;

  case kEventMouseDragged:
    target->mouseDragged(callRef, event);
    break;

  case kEventMouseMoved:
    target->mouseMoved(callRef, event);
    break;

  case kEventMouseWheelMoved:
    target->mouseWheelMoved(callRef, event);
    break;

  }

  return eventNotHandledErr;
}


const EventTypeSpec mouseListenerEventTypes[] =
{
  { kEventClassMouse, kEventMouseDown },
  { kEventClassMouse, kEventMouseUp },
  { kEventClassMouse, kEventMouseMoved },
  { kEventClassMouse, kEventMouseDragged },
  { kEventClassMouse, kEventMouseEntered },
  { kEventClassMouse, kEventMouseExited },
  { kEventClassMouse, kEventMouseWheelMoved }
};


const EventHandlerUPP mouseListenerEventHandler =
  NewEventHandlerUPP(mouseHandler);


int MouseListener::getNumberEventTypes()
{
  return GetEventTypeCount(mouseListenerEventTypes);
}


const EventTypeSpec* MouseListener::getEventTypes()
{
  return mouseListenerEventTypes;
}


EventHandlerUPP MouseListener::getEventHandlerUPP()
{
  return mouseListenerEventHandler;
}


OSStatus
MouseListener::mouseDown(EventHandlerCallRef callRef,
                         EventRef event)
{
}


OSStatus
MouseListener::mouseUp(EventHandlerCallRef callRef,
                       EventRef event)
{
}


OSStatus
MouseListener::mouseMoved(EventHandlerCallRef callRef,
                          EventRef event)
{
}


OSStatus
MouseListener::mouseDragged(EventHandlerCallRef callRef,
                            EventRef event)
{
}


OSStatus
MouseListener::mouseEntered(EventHandlerCallRef callRef,
                            EventRef event)
{
}


OSStatus
MouseListener::mouseExited(EventHandlerCallRef callRef,
                           EventRef event)
{
}


OSStatus
MouseListener::mouseWheelMoved(EventHandlerCallRef callRef,
                               EventRef event)
{
}


}


}
