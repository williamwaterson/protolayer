#ifndef PROTOLAYER_PROTO_ACTION_H
#define PROTOLAYER_PROTO_ACTION_H

#include <map>
#include <set>


namespace protolayer
{

namespace proto
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
  virtual void execute() = 0;

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


#endif // PROTOLAYER_PROTO_ACTION_H
