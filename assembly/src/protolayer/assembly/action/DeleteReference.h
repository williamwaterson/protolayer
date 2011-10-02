#ifndef PROTOLAYER_PROTO_DELETEREFERENCE_H
#define PROTOLAYER_PROTO_DELETEREFERENCE_H

#include <map>
#include <set>

#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-workflow.h>


namespace protolayer
{

namespace assembly
{

/**
 * TODO: Documentation
 * <p>
 */
class DeleteReference : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DeleteReference(assembly::Reference& reference);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DeleteReference();

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
  DeleteReference(const DeleteReference& deleteReference);

  /**
   * TODO: Documentation
   *
   */
  DeleteReference& operator=(const DeleteReference& deleteReference);

};


}


}


#endif // PROTOLAYER_PROTO_DELETEREFERENCE_H
