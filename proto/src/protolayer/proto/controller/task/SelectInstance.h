#ifndef PROTOLAYER_PROTO_ACTION_H
#define PROTOLAYER_PROTO_ACTION_H

#include <map>
#include <set>

#include <protolayer/protolayer-workflow.h>

namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class SelectInstance : public workflow::Task
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  SelectInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectInstance() = 0;

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
  SelectInstance(const SelectInstance& selectInstance);

  /**
   * TODO: Documentation
   *
   */
  SelectInstance& operator=(const SelectInstance& selectInstance);

};


}


}


#endif // PROTOLAYER_PROTO_SELECTINSTANCE_H
