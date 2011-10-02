#ifndef PROTOLAYER_PROTO_SELECTDOMAIN_H
#define PROTOLAYER_PROTO_SELECTDOMAIN_H

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
class SelectDomain : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit SelectDomain(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectDomain();

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
  SelectDomain(const SelectDomain& selectDomain);

  /**
   * TODO: Documentation
   *
   */
  SelectDomain& operator=(const SelectDomain& selectDomain);

};


}


}


#endif // PROTOLAYER_PROTO_SELECTDOMAIN_H
