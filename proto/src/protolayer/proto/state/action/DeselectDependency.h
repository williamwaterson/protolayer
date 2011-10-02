#ifndef PROTOLAYER_PROTO_DESELECTDEPENDENCY_H
#define PROTOLAYER_PROTO_DESELECTDEPENDENCY_H

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
class DeselectDependency : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DeselectDependency(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DeselectDependency();

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
  DeselectDependency(const DeselectDependency& deselectDependency);

  /**
   * TODO: Documentation
   *
   */
  DeselectDependency& operator=(const DeselectDependency& deselectDependency);

};


}


}


#endif // PROTOLAYER_PROTO_DESELECTDEPENDENCY_H
