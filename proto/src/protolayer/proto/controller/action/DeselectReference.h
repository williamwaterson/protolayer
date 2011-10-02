#ifndef PROTOLAYER_PROTO_DESELECTREFERENCE_H
#define PROTOLAYER_PROTO_DESELECTREFERENCE_H

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
class DeselectReference : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DeselectReference(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DeselectReference();

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
  DeselectReference(const DeselectReference& deselectReference);

  /**
   * TODO: Documentation
   *
   */
  DeselectReference& operator=(const DeselectReference& deselectReference);

};


}


}


#endif // PROTOLAYER_PROTO_DESELECTREFERENCE_H
