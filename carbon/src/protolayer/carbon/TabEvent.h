#ifndef PROTOLAYER_CARBON_TABEVENT_H
#define PROTOLAYER_CARBON_TABEVENT_H

#include <vector>

#include "forward.h"
#include "Tab.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class TabEvent
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  static TabEvent* getInstance(Tab& tab);

private:
  /** TODO: Documentation */
  Tab* _tab;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Tab& getTab();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  TabEvent();

  /**
   * TODO: Documentation
   * <p>
   */
  ~TabEvent();

};


}


}


#endif // PROTOLAYER_CARBON_TABEVENT_H
