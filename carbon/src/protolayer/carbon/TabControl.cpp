#include "TabControl.h"
#include <iostream>


namespace protolayer
{

namespace carbon
{

namespace
{

pascal OSStatus eventHandler(EventHandlerCallRef handler,
			     EventRef event,
			     void* userData)
{
  TabControl* tabControl = reinterpret_cast <TabControl*> (userData);
  *tabControl;

  UInt32 whatHappened = GetEventKind(event);
  if (whatHappened == kEventControlHit) {
    short tabIndex = GetControlValue(tabControl->getControlRef());
    Tab& tab = tabControl->getTab(tabIndex - 1);
    TabEvent* event = TabEvent::getInstance(tab);
    for (int i = 0; i < tabControl->getNumberTabListeners(); i++) {
      tabControl->getTabControlListener(i).tabHit(*event);
    }
  }

  return eventNotHandledErr;
}

const EventTypeSpec eventTypes[] =
{
  { kEventClassControl, kEventControlHit}
};


EventHandlerUPP handler =
  NewEventHandlerUPP(eventHandler);


int getNumberEventTypes()
{
  return GetEventTypeCount(eventTypes);
}


const EventTypeSpec* getEventTypes()
{
  return eventTypes;
}


EventHandlerUPP getEventHandlerUPP()
{
  return handler;
}


}

int TabControl::getNumberTabListeners() const
{
  return _listeners.size();
}




TabControlListener& TabControl::getTabControlListener(int index)
{
  return *(_listeners[index]);
}



TabControl::TabControl(short x,
		       short y,
		       short w,
		       short h) :
  //                       int numberTabs, ControlTabEntry* tabArray) :
  EmbeddingControl(x, y, w, h)
{
  //  _numberTabs = numberTabs;
  //  _tabArray = tabArray;
}


TabControl::~TabControl()
{
}


void TabControl::addTabControlListener(TabControlListener& listener)
{
  _listeners.push_back(&listener);
  //  addListener(listener);
}

OSStatus TabControl::create(WindowRef windowRef)
{
  setWindowRef(windowRef);

  _tabArray = new ControlTabEntry[getNumberTabs()];
  for (int i = 0; i < getNumberTabs(); i++) {
    Tab& tab = getTab(i);
    _tabArray[i].icon = NULL;
    _tabArray[i].name = CFStringCreateWithCString(NULL, tab.getName().c_str(), kCFStringEncodingMacRoman);
    _tabArray[i].enabled = (int) tab.isEnabled();
  }

  OSStatus result = CreateTabsControl(windowRef,
                                      getBounds(),
                                      kControlSizeSmall,
                                      kControlTabDirectionNorth,
                                      getNumberTabs(),
                                      _tabArray,
                                      &getControlRef());

  initialise();
  activate();
  show();
  createEmbeddedControls();
  activate();
  show();

  InstallEventHandler(GetWindowEventTarget(windowRef),
		      getEventHandlerUPP(),
		      getNumberEventTypes(),
		      getEventTypes(),
		      reinterpret_cast <void*> (this),
		      NULL);

  return result;
}


void TabControl::dispose()
{
  cleanup();
  DisposeControl(getControlRef());
}


int TabControl::getNumberTabs() const
{
  return _tabs.size();
}


Tab& TabControl::getTab(int index)
{
  return *(_tabs[index]);
}


void TabControl::add(Tab& tab)
{
  _tabs.push_back(&tab);
}


void TabControl::remove(Tab& tab)
{
  //  _tabs.push_back(&tab);
}


void TabControl::clear()
{
  _tabs.clear();
}


}


}
