#ifndef PROTOLAYER_PROTO_DESELECTDOMAIN_H
#define PROTOLAYER_PROTO_DESELECTDOMAIN_H

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
class DeselectDomain : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DeselectDomain(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DeselectDomain();

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
  DeselectDomain(const DeselectDomain& deselectDomain);

  /**
   * TODO: Documentation
   *
   */
  DeselectDomain& operator=(const DeselectDomain& deselectDomain);

};


}


}


#endif // PROTOLAYER_PROTO_DESELECTDOMAIN_H
