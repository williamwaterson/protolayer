#include "ControllerLayer.h"


namespace protolayer
{

namespace proto
{

namespace
{

std::map <StateLayer*, ControllerLayer*> mappings;

ControllerLayer* castToControllerLayer(void* opaque)
{
  ControllerLayer* cl = reinterpret_cast <ControllerLayer*> (opaque);
  if (cl == 0) {
    return 0;
  }
  return cl;
}

StateLayer* castToStateLayer(void* opaque)
{
  ControllerLayer* cl = castToControllerLayer(opaque);
  if (cl == 0) {
    return 0;
  }
  return &(cl->getStateLayer());
}



OSStatus conceptTreeBrowserItemDataCallback(ControlRef browser, 
					    DataBrowserItemID itemID, 
					    DataBrowserPropertyID property, 
					    DataBrowserItemDataRef itemData, 
					    Boolean changeValue) 
{
  OSStatus status = eventNotHandledErr; 

  if (property == 'ENTI') {
    util::Object* object = util::Object::getObject(itemID);
    if (object == 0) {
      return status;
    }

    ontology::Domain* domain = dynamic_cast <ontology::Domain*> (object);
    if (domain != 0) {
      const char* name = domain->getTitle().c_str();
      CFStringRef nameCFSTR = CFStringCreateWithCString(kCFAllocatorDefault, name, kCFStringEncodingMacRoman);
      status = SetDataBrowserItemDataText(itemData, nameCFSTR);
      CFRelease(nameCFSTR);
      return status;
    }

    ontology::Type* type = dynamic_cast <ontology::Type*> (object);
    if (type != 0) {
      const char* name = type->getName().c_str();
      CFStringRef nameCFSTR = CFStringCreateWithCString(kCFAllocatorDefault, name, kCFStringEncodingMacRoman);
      status = SetDataBrowserItemDataText(itemData, nameCFSTR);
      CFRelease(nameCFSTR);
      return status;
    }

    ontology::Association* assoc = dynamic_cast <ontology::Association*> (object);
    if (assoc != 0) {
      const char* name = assoc->getName().c_str();
      CFStringRef nameCFSTR = CFStringCreateWithCString(kCFAllocatorDefault, name, kCFStringEncodingMacRoman);
      status = SetDataBrowserItemDataText(itemData, nameCFSTR);
      CFRelease(nameCFSTR);
      return status;
    }

  } else if (property == kDataBrowserItemIsContainerProperty) {
    util::Object* object = util::Object::getObject(itemID);

    ontology::Domain* domain = dynamic_cast <ontology::Domain*> (object);
    if (domain != 0) {
      status  = SetDataBrowserItemDataBooleanValue(itemData, true);
    } else {
      status  = SetDataBrowserItemDataBooleanValue(itemData, false);
    }

  } else {
    status = errDataBrowserPropertyNotSupported;

  }

  return status; 
} 


OSStatus instanceTreeBrowserItemDataCallback(ControlRef browser, 
					     DataBrowserItemID itemID, 
					     DataBrowserPropertyID property, 
					     DataBrowserItemDataRef itemData, 
					     Boolean changeValue) 
{
  OSStatus err = eventNotHandledErr; 

  if (property = 'ENTI') {
    err = SetDataBrowserItemDataText(itemData, CFSTR("inst0000124i34"));
  }

  return err; 
}


OSStatus spatialTreeBrowserItemDataCallback(ControlRef browser, 
					    DataBrowserItemID itemID, 
					    DataBrowserPropertyID property, 
					    DataBrowserItemDataRef itemData, 
					    Boolean changeValue) 
{  
  OSStatus err = eventNotHandledErr; 

  if (property = 'ENTI') {
    err = SetDataBrowserItemDataText(itemData, CFSTR("domain0000124i34"));
  }

  return err; 
}


DataBrowserItemDataUPP conceptTreeItemDataUPP =
  NewDataBrowserItemDataUPP(conceptTreeBrowserItemDataCallback);


DataBrowserItemDataUPP instanceTreeItemDataUPP =
  NewDataBrowserItemDataUPP(instanceTreeBrowserItemDataCallback);


DataBrowserItemDataUPP spatialTreeItemDataUPP =
  NewDataBrowserItemDataUPP(spatialTreeBrowserItemDataCallback);



void conceptDataBrowserItemNotificationCallback(ControlRef browser, 
						DataBrowserItemID itemID, 
						DataBrowserItemNotification message)
{
  ViewLayer* window = ViewLayer::match(browser);
  StateLayer* stateLayer = StateLayer::getStateLayer(*window);

  if (window == 0) {
    return;
  }

  if (message == kDataBrowserContainerOpened) {
    util::Object* object = util::Object::getObject(itemID);

    ontology::Domain* domain = dynamic_cast <ontology::Domain*> (object);
    if (domain != 0) {
      int i = 0;

      int numberTypes = domain->getNumberTypes();
      DataBrowserItemID ids[numberTypes];

      typedef protolayer::ontology::Domain::IteratorType IterType;
      for (IterType iterator = domain->getTypes(); iterator.hasNext(); ) {
      	ontology::Type& type = iterator.next();
	std::cout << "type.getId() " << type.getId() << " " << type.getName() << std::endl;
      	ids[i] = type.getId();
	i++;
      }

      AddDataBrowserItems(browser, itemID, numberTypes, ids, 'ENTI');
    }

  } else if (message == kDataBrowserSelectionSetChanged) {

    Handle selectedItems = NewHandle(0);
    if (selectedItems == NULL) {
      return;
    }

    GetDataBrowserItems(browser,
			kDataBrowserNoItem,
			true,
			kDataBrowserItemIsSelected,
			selectedItems);

    UInt32 numItems;
    GetDataBrowserItemCount(browser,
			    kDataBrowserNoItem,
			    true,
			    kDataBrowserItemIsSelected,
			    &numItems);

    for (long i = 0; i < (long) numItems; i++) {
      UInt32* value = (UInt32*) selectedItems[0];
      unsigned long v = *value;
      util::Object* object = util::Object::getObject(v);
      if (object != 0) {
	ontology::Type* type = dynamic_cast <ontology::Type*> (object);
	if (type != 0) {
	  stateLayer->setCreationType(*type);
	}
      }
    }

    
  } else if (message == kDataBrowserItemDeselected) {
    stateLayer->clearCreationType();

  }
}


void instanceDataBrowserItemNotificationCallback(ControlRef browser, 
						 DataBrowserItemID itemID, 
						 DataBrowserItemNotification message)
{
  std::cout << "instance notification callback" << std::endl;
}


void spatialDataBrowserItemNotificationCallback(ControlRef browser, 
						DataBrowserItemID itemID, 
						DataBrowserItemNotification message)
{
  std::cout << "spatial notification callback" << std::endl;
}



DataBrowserItemNotificationUPP spatialTreeItemNotificationUPP =
  NewDataBrowserItemNotificationUPP(spatialDataBrowserItemNotificationCallback);


DataBrowserItemNotificationUPP conceptTreeItemNotificationUPP =
  NewDataBrowserItemNotificationUPP(conceptDataBrowserItemNotificationCallback);


DataBrowserItemNotificationUPP instanceTreeItemNotificationUPP =
  NewDataBrowserItemNotificationUPP(instanceDataBrowserItemNotificationCallback);




/*
theCallbacks.u.v1.itemDataCallback= NewDataBrowserItemDataUPP( DataBrowserItemData );
theCallbacks.u.v1.itemCompareCallback= NewDataBrowserItemCompareUPP( SortDataBrowser );
theCallbacks.u.v1.itemNotificationCallback= NewDataBrowserItemNotificationUPP( DataBrowserMessage );
theCallbacks.u.v1.addDragItemCallback= NewDataBrowserAddDragItemUPP( DataBrowserAddDragItem );
theCallbacks.u.v1.acceptDragCallback= NewDataBrowserAcceptDragUPP( DataBrowserAcceptDrag );
theCallbacks.u.v1.receiveDragCallback= NewDataBrowserReceiveDragUPP( DataBrowserReceiveDrag );
theCallbacks.u.v1.postProcessDragCallback= NewDataBrowserPostProcessDragUPP( DataBrowserPostProcessDrag );
SetDataBrowserCallbacks( dataBrowser, &theCallbacks );
*/



pascal OSStatus separatorHandler(EventHandlerCallRef callRef,
				 EventRef event,
				 void* userData)
{
  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventControlInitialize) {

  } else if (whatHappened == kEventMouseDragged) {
    std::cout << "mouse dragged" << std::endl;

  } else if (whatHappened == kEventControlClick) {
    std::cout << "control click" << std::endl;

  } else if (whatHappened == kEventControlHit) {
    std::cout << "control hit" << std::endl;

  } else if (whatHappened == kEventMouseDown) {
    std::cout << "mouse down" << std::endl;

  } else if (whatHappened == kEventMouseMoved) {
    std::cout << "mouse moved" << std::endl;

  } else if (whatHappened == kEventMouseWheelMoved) {
    std::cout << "mouse wheel" << std::endl;

  } else if (whatHappened == kEventMouseEntered) {
    std::cout << "mouse entered" << std::endl;

  } else if (whatHappened == kEventMouseExited) {
    std::cout << "mouse exited" << std::endl;

  }

  return eventNotHandledErr;
}

const EventTypeSpec textFieldEventTypes[] =
  {
    { kEventClassTextField, kEventTextAccepted }
  };


pascal OSStatus searchFieldHandler(EventHandlerCallRef callRef,
				   EventRef event,
				   void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ViewLayer& window = castToControllerLayer(userData)->getViewLayer();

  

  window.displaySearchMode();
  if (whatHappened == kEventTextAccepted) {
    window.displaySearchMode();

  } else if (whatHappened == kEventTextDidChange) {
    window.displaySearchMode();

  }

  return eventNotHandledErr;
}

const EventHandlerUPP searchFieldHandlerUPP =
  NewEventHandlerUPP(searchFieldHandler);


/**
 * TODO: Documentation
 * <p>
 */
const EventTypeSpec controlEventTypes[] =
  {
    { kEventClassControl, kEventControlInitialize},
    { kEventClassControl, kEventControlDispose},
    { kEventClassControl, kEventControlGetOptimalBounds},
    { kEventClassControl, kEventControlHit},
    { kEventClassControl, kEventControlSimulateHit},
    { kEventClassControl, kEventControlHitTest},
    { kEventClassControl, kEventControlDraw},
    { kEventClassControl, kEventControlApplyBackground},
    { kEventClassControl, kEventControlApplyTextColor},
    { kEventClassControl, kEventControlSetFocusPart},
    { kEventClassControl, kEventControlGetFocusPart},
    { kEventClassControl, kEventControlActivate},
    { kEventClassControl, kEventControlDeactivate},
    { kEventClassControl, kEventControlSetCursor},
    { kEventClassControl, kEventControlContextualMenuClick},
    { kEventClassControl, kEventControlClick},
    { kEventClassControl, kEventControlGetNextFocusCandidate},
    { kEventClassControl, kEventControlGetAutoToggleValue},
    { kEventClassControl, kEventControlInterceptSubviewClick},
    { kEventClassControl, kEventControlGetClickActivation},
    { kEventClassControl, kEventControlDragEnter},
    { kEventClassControl, kEventControlDragWithin},
    { kEventClassControl, kEventControlDragLeave},
    { kEventClassControl, kEventControlDragReceive},
    { kEventClassControl, kEventControlTrack},
    { kEventClassControl, kEventControlGetScrollToHereStartPoint},
    { kEventClassControl, kEventControlGetIndicatorDragConstraint},
    { kEventClassControl, kEventControlIndicatorMoved},
    { kEventClassControl, kEventControlGhostingFinished},
    { kEventClassControl, kEventControlGetActionProcPart},
    { kEventClassControl, kEventControlGetPartRegion},
    { kEventClassControl, kEventControlGetPartBounds},
    { kEventClassControl, kEventControlSetData},
    { kEventClassControl, kEventControlGetData},
    { kEventClassControl, kEventControlGetSizeConstraints},
    { kEventClassControl, kEventControlValueFieldChanged},
    { kEventClassControl, kEventControlAddedSubControl},
    { kEventClassControl, kEventControlRemovingSubControl},
    { kEventClassControl, kEventControlBoundsChanged},
    { kEventClassControl, kEventControlTitleChanged},
    { kEventClassControl, kEventControlOwningWindowChanged},
    { kEventClassControl, kEventControlHiliteChanged},
    { kEventClassControl, kEventControlEnabledStateChanged},
    { kEventClassMouse, kEventMouseDown },
    { kEventClassMouse, kEventMouseUp },
    { kEventClassMouse, kEventMouseMoved },
    { kEventClassMouse, kEventMouseDragged },
    { kEventClassMouse, kEventMouseEntered },
    { kEventClassMouse, kEventMouseExited },
    { kEventClassMouse, kEventMouseWheelMoved }
  };

const EventHandlerUPP separatorHandlerUPP =
  NewEventHandlerUPP(separatorHandler);


const EventTypeSpec buttonEventTypes[] =
  {
    { kEventClassControl, kEventControlHit},
    { kEventClassControl, kEventControlActivate},
    { kEventClassControl, kEventControlDeactivate},
    { kEventClassControl, kEventControlClick}
  };


OSStatus selectButtonHandler(EventHandlerCallRef callRef,
			     EventRef event,
			     void* userData)
{
  castToControllerLayer(userData)->setToSelectState();
  return eventNotHandledErr;
}

EventHandlerUPP selectButtonHandlerUPP =
  NewEventHandlerUPP(selectButtonHandler);


OSStatus createNodeButtonHandler(EventHandlerCallRef callRef,
				 EventRef event,
				 void* userData)
{
  std::cout << "createNodeButtonHandler" << std::endl;
  castToControllerLayer(userData)->setToCreateInstanceState();
  return eventNotHandledErr;
}

EventHandlerUPP createNodeButtonHandlerUPP =
  NewEventHandlerUPP(createNodeButtonHandler);


OSStatus createReferenceButtonHandler(EventHandlerCallRef callRef,
				      EventRef event,
				      void* userData)
{
  castToControllerLayer(userData)->setToCreateReferenceState();
  return eventNotHandledErr;
}

EventHandlerUPP createReferenceButtonHandlerUPP =
  NewEventHandlerUPP(createReferenceButtonHandler);


OSStatus moveCameraButtonHandler(EventHandlerCallRef callRef,
				 EventRef event,
				 void* userData)
{
  castToControllerLayer(userData)->setToMoveCameraState();
  return eventNotHandledErr;
}

EventHandlerUPP moveCameraButtonHandlerUPP =
  NewEventHandlerUPP(moveCameraButtonHandler);


OSStatus panCameraButtonHandler(EventHandlerCallRef callRef,
				EventRef event,
				void* userData)
{
  castToControllerLayer(userData)->setToPanCameraState();
  return eventNotHandledErr;
}

EventHandlerUPP panCameraButtonHandlerUPP =
  NewEventHandlerUPP(panCameraButtonHandler);


OSStatus targetCameraButtonHandler(EventHandlerCallRef callRef,
				   EventRef event,
				   void* userData)
{
  castToControllerLayer(userData)->setToTargetCameraState();
  return eventNotHandledErr;
}

EventHandlerUPP targetCameraButtonHandlerUPP =
  NewEventHandlerUPP(targetCameraButtonHandler);


OSStatus zoomInCameraButtonHandler(EventHandlerCallRef callRef,
				   EventRef event,
				   void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer* controllerLayer = castToControllerLayer(userData);

  if (whatHappened == kEventControlClick) {
    castToControllerLayer(userData)->getStateLayer().zoom(0.9f);
  }

  return eventNotHandledErr;
}

EventHandlerUPP zoomInCameraButtonHandlerUPP =
  NewEventHandlerUPP(zoomInCameraButtonHandler);


OSStatus zoomOutCameraButtonHandler(EventHandlerCallRef callRef,
				    EventRef event,
				    void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer* controllerLayer = castToControllerLayer(userData);

  if (whatHappened == kEventControlClick) {
    castToControllerLayer(userData)->getStateLayer().zoom(1.1f);
  }
  return eventNotHandledErr;
}

EventHandlerUPP zoomOutCameraButtonHandlerUPP =
  NewEventHandlerUPP(zoomOutCameraButtonHandler);


OSStatus upLayerButtonHandler(EventHandlerCallRef callRef,
			      EventRef event,
			      void* userData)
{
  castToControllerLayer(userData)->upLayer();
  return eventNotHandledErr;
}

EventHandlerUPP upLayerButtonHandlerUPP =
  NewEventHandlerUPP(upLayerButtonHandler);


OSStatus zoomCameraButtonHandler(EventHandlerCallRef callRef,
				    EventRef event,
				    void* userData)
{
  castToControllerLayer(userData)->setToZoomCameraState();
  return eventNotHandledErr;
}

EventHandlerUPP zoomCameraButtonHandlerUPP =
  NewEventHandlerUPP(zoomCameraButtonHandler);


OSStatus downLayerButtonHandler(EventHandlerCallRef callRef,
				EventRef event,
				void* userData)
{
  castToControllerLayer(userData)->downLayer();
  return eventNotHandledErr;
}

EventHandlerUPP downLayerButtonHandlerUPP =
  NewEventHandlerUPP(downLayerButtonHandler);


pascal OSStatus searchModeButtonHandler(EventHandlerCallRef callRef,
				    EventRef event,
				    void* userData)
{ 
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer* controllerLayer = castToControllerLayer(userData);

  if (whatHappened == kEventControlClick) {
   controllerLayer->displaySearchPerspective();
  }

  return eventNotHandledErr;
}

const EventHandlerUPP searchModeButtonHandlerUPP =
  NewEventHandlerUPP(searchModeButtonHandler);


pascal OSStatus instanceModeButtonHandler(EventHandlerCallRef callRef,
					  EventRef event,
					  void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer* controllerLayer = castToControllerLayer(userData);

  if (whatHappened == kEventControlClick) {
    controllerLayer->displayInstancePerspective();
  }

  return eventNotHandledErr;
}

const EventHandlerUPP instanceModeButtonHandlerUPP =
  NewEventHandlerUPP(instanceModeButtonHandler);


pascal OSStatus conceptModeButtonHandler(EventHandlerCallRef callRef,
					 EventRef event,
					 void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer* controllerLayer = castToControllerLayer(userData);

  if (whatHappened == kEventControlClick) {
    controllerLayer->displayConceptPerspective();
  }

  return eventNotHandledErr;
}

const EventHandlerUPP conceptModeButtonHandlerUPP =
  NewEventHandlerUPP(conceptModeButtonHandler);


pascal OSStatus spatialModeButtonHandler(EventHandlerCallRef callRef,
					 EventRef event,
					 void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer* controllerLayer = castToControllerLayer(userData);

  if (whatHappened == kEventControlClick) {
    controllerLayer->displaySpatialPerspective();
  }

  return eventNotHandledErr;
}


pascal OSStatus windowHandler(EventHandlerCallRef callRef,
			      EventRef event,
			      void* userData)
{
  ViewLayer& window = castToControllerLayer(userData)->getViewLayer();

  UInt32 whatHappened = GetEventKind(event);

  if (whatHappened == kEventWindowClickResizeRgn) {
    window.evaluateControlPositions();

  } else if (whatHappened == kEventWindowBoundsChanged) {
    window.evaluateControlPositions();

  } else if (whatHappened == kEventWindowClosed) {
    ExitToShell();

  }

  return eventNotHandledErr;
}


const EventTypeSpec windowEventTypes[] =
{
  { kEventClassWindow, kEventWindowClickDragRgn },
  { kEventClassWindow, kEventWindowClickResizeRgn },
  { kEventClassWindow, kEventWindowClickCollapseRgn },
  { kEventClassWindow, kEventWindowClickCloseRgn },
  { kEventClassWindow, kEventWindowClickZoomRgn },
  { kEventClassWindow, kEventWindowClickContentRgn },
  { kEventClassWindow, kEventWindowClickProxyIconRgn },
  { kEventClassWindow, kEventWindowUpdate },
  { kEventClassWindow, kEventWindowDrawContent },
  { kEventClassWindow, kEventWindowClickToolbarButtonRgn },
  { kEventClassWindow, kEventWindowClickStructureRgn },
  { kEventClassWindow, kEventWindowBoundsChanged},
  { kEventClassWindow, kEventWindowClosed}
};


const EventTypeSpec keyboardEventTypes[] =
{
  { kEventClassKeyboard, kEventRawKeyDown },
  { kEventClassKeyboard, kEventRawKeyRepeat },
  { kEventClassKeyboard, kEventRawKeyUp },
  { kEventClassKeyboard, kEventRawKeyModifiersChanged },
  { kEventClassKeyboard, kEventHotKeyPressed },
  { kEventClassKeyboard, kEventHotKeyReleased },
};

const EventHandlerUPP windowEventHandlerUPP =
  NewEventHandlerUPP(windowHandler);


const EventTypeSpec mouseEventTypes[] =
{
  { kEventClassMouse, kEventMouseDown },
  { kEventClassMouse, kEventMouseUp },
  { kEventClassMouse, kEventMouseMoved },
  { kEventClassMouse, kEventMouseDragged },
  { kEventClassMouse, kEventMouseEntered },
  { kEventClassMouse, kEventMouseExited },
  { kEventClassMouse, kEventMouseWheelMoved }
};


pascal OSStatus mouseHandler(EventHandlerCallRef handler,
			     EventRef event,
			     void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  ControllerLayer& controllerLayer = *(castToControllerLayer(userData));
  StateLayer& stateLayer = castToControllerLayer(userData)->getStateLayer();
  ViewLayer& window = castToControllerLayer(userData)->getViewLayer();

  Point mousePosition;
  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(Point), NULL, &mousePosition);

  if (whatHappened == kEventMouseMoved) {
    controllerLayer.mouseMoved(mousePosition.h, mousePosition.v);

  } else if (whatHappened == kEventMouseDown) {
    UInt32 clickCount;
    GetEventParameter(event, kEventParamClickCount, typeUInt32, NULL, sizeof(clickCount), NULL, &clickCount);
    controllerLayer.mouseDown(mousePosition.h, mousePosition.v, clickCount);

  } else if (whatHappened == kEventMouseDragged) {
    controllerLayer.mouseDragged(mousePosition.h, mousePosition.v);

  } else if (whatHappened == kEventMouseUp) {
    controllerLayer.mouseUp(mousePosition.h, mousePosition.v);

  } else if (whatHappened == kEventMouseEntered) {

  } else if (whatHappened == kEventMouseExited) {

  } else if (whatHappened == kEventMouseWheelMoved) {

  }

  return eventNotHandledErr;
}


pascal OSStatus keyboardHandler(EventHandlerCallRef handler,
				EventRef event,
				void* userData)
{
  UInt32 whatHappened = GetEventKind(event);
  StateLayer& stateLayer = castToControllerLayer(userData)->getStateLayer();
  ViewLayer& window = castToControllerLayer(userData)->getViewLayer();

  if (whatHappened == kEventRawKeyDown) {
    stateLayer.keyDown();

  } else if (whatHappened == kEventRawKeyUp) {
    stateLayer.keyUp();

  }

  return eventNotHandledErr;
}

const EventHandlerUPP keyboardHandlerUPP =
  NewEventHandlerUPP(keyboardHandler);

EventHandlerUPP mouseHandlerUPP =
  NewEventHandlerUPP(mouseHandler);

void animationHandler(EventLoopTimerRef timerRef,
		      void* userData)
{
  castToControllerLayer(userData)->getViewLayer().swapRendererPortsAndDisplay();
}


const EventLoopTimerUPP animationHandlerUPP =
  NewEventLoopTimerUPP(animationHandler);


pascal OSStatus rendererHandler(EventHandlerCallRef handler,
				EventRef event,
				void* userData)
{
  OSStatus result = eventNotHandledErr;

  ViewLayer& window = castToControllerLayer(userData)->getViewLayer();
  UInt32 eventKind = GetEventKind(event);
  /*
  if (eventKind == kEventControlInitialize) {
    window.initRenderer();

  } else if (eventKind == kEventControlDispose) {
    window.disposeRenderer();

  } else if (eventKind == kEventControlActivate) {
    window.swapRendererPortsAndDisplay();

  } else if (eventKind == kEventControlDeactivate) {
    window.swapRendererPortsAndDisplay();

  } else if (eventKind == kEventControlDraw) {
    window.swapRendererPortsAndDisplay();

  } else if (eventKind == kEventControlBoundsChanged) {
    window.rendererBoundsChanged();

  } else if (eventKind == kEventMouseMoved) {
    window.updateRendererMouse();
    window.rendererBoundsChanged();

  } else if (eventKind == kEventMouseDragged) {
    window.updateRendererMouse();
    window.rendererBoundsChanged();

  }
  */
  return result;
}


pascal OSStatus rendererMouseHandler(EventHandlerCallRef handler,
				     EventRef event,
				     void* userData)
{
  OSStatus result = eventNotHandledErr;
  /*
  ViewLayer& window = castToControllerLayer(userData)->getViewLayer();
  Rect& renderBounds = window.getRendererBounds();

  Point mousePosition;
  GetEventParameter(event, kEventParamMouseLocation, typeQDPoint, NULL, sizeof(Point), NULL, &mousePosition);

  UInt32 eventKind = GetEventKind(event);
  */


  /*
  Pane* pane = reinterpret_cast <Pane*> (userData);
  GetEventParameter(event,
		    kEventParamMouseLocation,
		    typeQDPoint,
		    NULL,
		    sizeof(::Point),
		    NULL,
		    &(pane->_mousePosition));

  GetWindowBounds(const_cast <WindowRef&> (_windowRef),
		  kWindowContentRgn,
		  &(pane->_windowBounds));

  pane->_mousePosition.h -= pane->_windowBounds.left;
  pane->_mousePosition.v -= pane->_windowBounds.top;

  HIRect bounds;
  HIViewGetBounds(pane->getControlRef(), &bounds);
  HIPoint topLeftPoint;
  topLeftPoint.x = bounds.origin.x;
  topLeftPoint.y = bounds.origin.y;
  HIViewConvertPoint(&topLeftPoint, pane->getControlRef(), NULL);

  pane->_mousePosition.h -= topLeftPoint.x;
  pane->_mousePosition.v -= topLeftPoint.y;

  pane->_mousePosition.v = pane->getControlBounds().bottom - pane->_mousePosition.v;
  pane->getSpace().setMousePosition(pane->_mousePosition.h, pane->_mousePosition.v);
  */

  /*
  if (eventKind == kEventMouseDown) {

  } else if (eventKind == kEventMouseUp) {

  } else if (eventKind == kEventMouseMoved) {

  } else if (eventKind == kEventMouseDragged) {

  } else if (eventKind == kEventMouseEntered) {

  } else if (eventKind == kEventMouseExited) {

  } else if (eventKind == kEventMouseWheelMoved) {

  }

  window.updateRendererMouse();
  window.rendererBoundsChanged();
  */
  return result;
}

const EventTypeSpec rendererEventTypes[] =
{
  { kEventClassControl, kEventControlInitialize },
  { kEventClassControl, kEventControlDispose },
  { kEventClassControl, kEventControlActivate },
  { kEventClassControl, kEventControlDeactivate },
  { kEventClassControl, kEventControlDraw },
  { kEventClassControl, kEventControlBoundsChanged },
  { kEventClassMouse, kEventMouseMoved },
  { kEventClassMouse, kEventMouseDragged }
};


EventHandlerUPP rendererHandlerUPP =
  NewEventHandlerUPP(rendererHandler);

}


ControllerLayer* ControllerLayer::getControllerLayer(StateLayer& layer)
{
  if (mappings.count(&layer) != 0) {
    return mappings[&layer];
  }
  return 0;
}


ControllerLayer* ControllerLayer::getControllerLayer(ViewLayer& layer)
{
  StateLayer* stateLayer = StateLayer::getStateLayer(layer);
  if (stateLayer != 0) {
    return getControllerLayer(*stateLayer);
  }
  return 0;
}


OSStatus ControllerLayer::installWindowHandlers()
{
  OSStatus err;

  ViewLayer& viewLayer = _stateLayer->getViewLayer();
  WindowRef window = viewLayer.getWindow();

  err = InstallEventHandler(GetWindowEventTarget(window),
			    windowEventHandlerUPP,
			    GetEventTypeCount(windowEventTypes),
			    windowEventTypes,
			    reinterpret_cast <void*> (this),
			    NULL);

  err = InstallEventHandler(GetWindowEventTarget(window),
			    mouseHandlerUPP,
			    GetEventTypeCount(mouseEventTypes),
			    mouseEventTypes,
			    reinterpret_cast <void*> (this),
			    NULL);

  err = InstallEventHandler(GetWindowEventTarget(window),
			    keyboardHandlerUPP,
			    GetEventTypeCount(keyboardEventTypes),
			    keyboardEventTypes,
			    reinterpret_cast <void*> (this),
			    NULL);

  return err;
}


OSStatus ControllerLayer::installButtonHandler(HIViewRef view,
					       EventHandlerUPP handlerUPP)
{
  return InstallEventHandler(GetControlEventTarget(view),
			     handlerUPP,
			     GetEventTypeCount(buttonEventTypes),
			     buttonEventTypes,
			     reinterpret_cast <void*> (this),
			     NULL);  
}


ControllerLayer::ControllerLayer(StateLayer& stateLayer)
{
  OSStatus err;

  mappings[&stateLayer] = this;
  _stateLayer = &stateLayer;

  _select = new interaction::Select(stateLayer);
  _targetCamera = new interaction::TargetCamera(stateLayer);
  _moveCamera = new interaction::MoveCamera(stateLayer);
  _panCamera = new interaction::PanCamera(stateLayer);
  _zoomCamera = new interaction::ZoomCamera(stateLayer);
  _instanceCreation = new interaction::InstanceCreation(stateLayer);
  _referenceCreation = new interaction::ReferenceCreation(stateLayer);

  _currentInteraction = _select;

  ViewLayer& viewLayer = stateLayer.getViewLayer();
  WindowRef window = viewLayer.getWindow();

  installWindowHandlers();

  installButtonHandler(viewLayer.getSelectButton(), selectButtonHandlerUPP);
  installButtonHandler(viewLayer.getCreateNodeButton(), createNodeButtonHandlerUPP);
  installButtonHandler(viewLayer.getCreateReferenceButtonRef(), createReferenceButtonHandlerUPP);

  installButtonHandler(viewLayer.getInstanceModeButtonRef(), instanceModeButtonHandlerUPP);
  installButtonHandler(viewLayer.getConceptModeButtonRef(), conceptModeButtonHandlerUPP);
  installButtonHandler(viewLayer.getSearchModeButtonRef(), searchModeButtonHandlerUPP);

  installButtonHandler(viewLayer.getMoveCameraButtonRef(), moveCameraButtonHandlerUPP);
  installButtonHandler(viewLayer.getPanCameraButtonRef(), panCameraButtonHandlerUPP);
  installButtonHandler(viewLayer.getTargetCameraButtonRef(), targetCameraButtonHandlerUPP);

  installButtonHandler(viewLayer.getZoomInCameraButtonRef(), zoomInCameraButtonHandlerUPP);
  installButtonHandler(viewLayer.getZoomOutCameraButtonRef(), zoomOutCameraButtonHandlerUPP);
  installButtonHandler(viewLayer.getZoomCameraButton(), zoomCameraButtonHandlerUPP);

  installButtonHandler(viewLayer.getUpLayerButtonRef(), upLayerButtonHandlerUPP);
  installButtonHandler(viewLayer.getDownLayerButtonRef(), downLayerButtonHandlerUPP);

  InstallStandardEventHandler(GetControlEventTarget(viewLayer.getContentView()));

  //  err = InstallEventHandler(GetControlEventTarget(window->getSeparator()),
  //		    separatorHandlerUPP,
  //		    GetEventTypeCount(controlEventTypes),
  //		    controlEventTypes,
  //		    reinterpret_cast <void*> (this),
  //		    NULL);

  //  err = InstallEventHandler(GetControlEventTarget(window->getSearchField()),
  //		    searchFieldHandlerUPP,
  //		    GetEventTypeCount(textFieldEventTypes),
  //		    textFieldEventTypes,
  //		    reinterpret_cast <void*> (this),
  //		    NULL);

  /*
  InstallEventHandler(GetWindowEventTarget(window),
		      rendererHandlerUPP,
		      GetEventTypeCount(rendererEventTypes),
                      rendererEventTypes,
                      reinterpret_cast <void*> (this),
                      NULL);

  InstallEventLoopTimer(GetMainEventLoop(),
                        0,
			kEventDurationMillisecond * 14,
                        animationHandlerUPP,
                        reinterpret_cast <void*> (this),
                        &_animationTimerRef);
  */

  {
  DataBrowserCallbacks  dbCallbacks; 

  dbCallbacks.version = kDataBrowserLatestCallbacks; 
  err = InitDataBrowserCallbacks(&dbCallbacks); 
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;


  dbCallbacks.u.v1.itemDataCallback = spatialTreeItemDataUPP;
  dbCallbacks.u.v1.itemNotificationCallback = spatialTreeItemNotificationUPP;

  err = SetDataBrowserCallbacks(viewLayer.getSpatialTree(), &dbCallbacks); 
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;
  SetAutomaticControlDragTrackingEnabledForWindow(window, true); 

  short numRows = 1;
  err = AddDataBrowserItems(viewLayer.getSpatialTree(), kDataBrowserNoItem, numRows, NULL, kDataBrowserItemNoProperty);
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;
  }

  {
  DataBrowserCallbacks  dbCallbacks; 

  dbCallbacks.version = kDataBrowserLatestCallbacks; 
  err = InitDataBrowserCallbacks(&dbCallbacks); 
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;

  dbCallbacks.u.v1.itemDataCallback = conceptTreeItemDataUPP;
  dbCallbacks.u.v1.itemNotificationCallback = conceptTreeItemNotificationUPP;

  err = SetDataBrowserCallbacks(viewLayer.getConceptTree(), &dbCallbacks); 
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;
  SetAutomaticControlDragTrackingEnabledForWindow(window, true);

  int numberDomains = stateLayer.getAssembly().getOntology().getNumberDomains();
  DataBrowserItemID ids[numberDomains];

  std::cout << "numberDomains " << numberDomains << std::endl;

  int i = 0;
  typedef ontology::Ontology::Ontology::DomainIteratorType IterType;
  for (IterType iterator = stateLayer.getAssembly().getOntology().getDomains(); iterator.hasNext(); ) {
    ontology::Domain& domain = iterator.next();
    std::cout << domain.getTitle() << " " << domain.getId() << std::endl;
    ids[i] = domain.getId();
    std::cout << ids[i] << std::endl;
    i++;
  }

  err = AddDataBrowserItems(viewLayer.getConceptTree(), kDataBrowserNoItem, numberDomains, ids, kDataBrowserItemNoProperty);
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;
  }

  {
  DataBrowserCallbacks  dbCallbacks; 

  dbCallbacks.version = kDataBrowserLatestCallbacks; 
  err = InitDataBrowserCallbacks(&dbCallbacks); 
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;


  dbCallbacks.u.v1.itemDataCallback = instanceTreeItemDataUPP;
  dbCallbacks.u.v1.itemNotificationCallback = instanceTreeItemNotificationUPP;


  err = SetDataBrowserCallbacks(viewLayer.getInstanceTree(), &dbCallbacks); 
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;
  SetAutomaticControlDragTrackingEnabledForWindow(window, true); 

  short numRows = 1;
  err = AddDataBrowserItems(viewLayer.getInstanceTree(), kDataBrowserNoItem, numRows, NULL, kDataBrowserItemNoProperty);
  if(err) std::cout << "Error occured adding resource to data browser." << std::endl;

  }

}


ControllerLayer::~ControllerLayer()
{
  mappings.erase(_stateLayer);
}


void ControllerLayer::mouseMoved(float x, float y)
{
  getCurrentInteraction().mouseMoved(x, y);
}


void ControllerLayer::mouseDown(float x, float y, int clickCount)
{
  getCurrentInteraction().mouseDown(x, y, clickCount);
}


void ControllerLayer::mouseDragged(float x, float y)
{
  getCurrentInteraction().mouseDragged(x, y);
}


void ControllerLayer::mouseUp(float x, float y)
{
  getCurrentInteraction().mouseUp(x, y);
}


void ControllerLayer::keyDown()
{
  getCurrentInteraction().keyDown();
}


void ControllerLayer::keyUp()
{
  getCurrentInteraction().keyUp();
}


Interaction& ControllerLayer::getCurrentInteraction()
{
  return *_currentInteraction;
}


StateLayer& ControllerLayer::getStateLayer()
{
  return *_stateLayer;
}


ViewLayer& ControllerLayer::getViewLayer()
{
  return _stateLayer->getViewLayer();
}


void ControllerLayer::displaySearchPerspective()
{
  getViewLayer().displaySearchMode();
}


void ControllerLayer::displayInstancePerspective()
{
  getViewLayer().displayInstanceAssemblyMode();
}


void ControllerLayer::displayConceptPerspective()
{
  getViewLayer().displayConceptAssemblyMode();
}


void ControllerLayer::displaySpatialPerspective()
{
  getViewLayer().displaySpatialMode();
}


void ControllerLayer::setCreationType(ontology::Type& type)
{
  getStateLayer().setCreationType(type);
}


void ControllerLayer::setToSelectState()
{
  _currentInteraction = _select;
}


void ControllerLayer::setToCreateInstanceState()
{
  _currentInteraction = _instanceCreation;
}


void ControllerLayer::setToCreateReferenceState()
{
  _currentInteraction = _referenceCreation;
}


void ControllerLayer::setToPanCameraState()
{
  _currentInteraction = _panCamera;
}
  

void ControllerLayer::setToMoveCameraState()
{
  _currentInteraction = _moveCamera;
}


void ControllerLayer::setToTargetCameraState()
{
  _currentInteraction = _targetCamera;
}


void ControllerLayer::setToZoomCameraState()
{
  _currentInteraction = _zoomCamera;
}


void ControllerLayer::upLayer()
{
}


void ControllerLayer::downLayer()
{
}


void ControllerLayer::zoomIn()
{

}


void ControllerLayer::zoomOut()
{

}


}


}
