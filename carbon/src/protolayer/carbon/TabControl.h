
#ifndef PROTOLAYER_CARBON_TABCONTROL_H
#define PROTOLAYER_CARBON_TABCONTROL_H

#include <vector>

#include "forward.h"
#include "EmbeddingControl.h"
#include "TabControlListener.h"
#include "Tab.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class TabControl : public EmbeddingControl
{
private:
  /** TODO: Documentation */
  int _numberTabs;

  /** TODO: Documentation */
  ControlTabEntry* _tabArray;

  /** TODO: Documentation */
  std::vector <TabControlListener*> _listeners;

  /** TODO: Documentation */
  std::vector <Tab*> _tabs;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TabControl(short x,
	     short y,
	     short w,
	     short h); // , int numberTabs, ControlTabEntry* tabArray);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~TabControl();

  /**
   * TODO: Documentation
   * <p>
   */
  void addTabControlListener(TabControlListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberTabListeners() const;

  /**
   * TODO: Documentation
   * <p>
   */
  TabControlListener& getTabControlListener(int index);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberTabs() const;

  /**
   * TODO: Documentation
   * <p>
   */
  Tab& getTab(int index);  

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Tab& tab);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Tab& tab);

  /**
   * TODO: Documentation
   * <p>
   */
  void clear();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus create(WindowRef windowRef);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void dispose();

};

}

}

#endif // PROTOLAYER_CARBON_TABCONTROL_H
