#ifndef PROTOLAYER_PROTO_SELECTDEPENDENCY_H
#define PROTOLAYER_PROTO_SELECTDEPENDENCY_H

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
class SelectDependency : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit SelectDependency(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectDependency();

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
  SelectDependency(const SelectDependency& selectDependency);

  /**
   * TODO: Documentation
   *
   */
  SelectDependency& operator=(const SelectDependency& selectDependency);

};


}


}


#endif // PROTOLAYER_PROTO_SELECTDEPENDENCY_H
