#ifndef PROTOLAYER_PROTO_SELECTINSTANCE_H
#define PROTOLAYER_PROTO_SELECTINSTANCE_H

#include <map>
#include <set>

#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-workflow.h>


namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class SelectInstance : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit SelectInstance(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void doit();

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
