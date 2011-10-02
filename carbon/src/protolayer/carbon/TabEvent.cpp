#include "TabEvent.h"


namespace protolayer
{

namespace carbon
{

namespace
{

TabEvent* singleton = 0;

}


TabEvent* TabEvent::getInstance(Tab& tab)
{
  if (singleton == 0) {
    singleton = new TabEvent();
  }
  singleton->_tab = &tab;
  return singleton;
}


TabEvent::TabEvent()
{
  _tab = 0;
}


TabEvent::~TabEvent()
{
}


Tab& TabEvent::getTab()
{
  return *_tab;
}


}


}
