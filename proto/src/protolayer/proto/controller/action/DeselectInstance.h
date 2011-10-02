#ifndef PROTOLAYER_PROTO_DESELECTINSTANCE_H
#define PROTOLAYER_PROTO_DESELECTINSTANCE_H

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
class DeselectInstance : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DeselectInstance(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DeselectInstance();

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
  DeselectInstance(const DeselectInstance& deselectInstance);

  /**
   * TODO: Documentation
   *
   */
  DeselectInstance& operator=(const DeselectInstance& deselectInstance);

};


}


}


#endif // PROTOLAYER_PROTO_DESELECTINSTANCE_H
