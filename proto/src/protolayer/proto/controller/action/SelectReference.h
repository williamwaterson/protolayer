#ifndef PROTOLAYER_PROTO_SELECTREFERENCE_H
#define PROTOLAYER_PROTO_SELECTREFERENCE_H

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
class SelectReference : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit SelectReference(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectReference();

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
  SelectReference(const SelectReference& selectReference);

  /**
   * TODO: Documentation
   *
   */
  SelectReference& operator=(const SelectReference& selectReference);

};


}


}


#endif // PROTOLAYER_PROTO_SELECTREFERENCE_H
