#ifndef PROTOLAYER_WORKFLOW_ACTION_H
#define PROTOLAYER_WORKFLOW_ACTION_H

#include <map>
#include <set>

//#include "Action.h"


namespace protolayer
{

namespace workflow
{

/**
 * TODO: Documentation
 * <p>
 */
class Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Action();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Action() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void doit() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void undo();

private:
  /**
   * TODO: Documentation
   *
   */
  Action(const Action& action);

  /**
   * TODO: Documentation
   *
   */
  Action& operator=(const Action& action);

};


}


}


#endif // PROTOLAYER_WORKFLOW_ACTION_H
