#ifndef PROTOLAYER_PROTO_CREATEREFERENCE_H
#define PROTOLAYER_PROTO_CREATEREFERENCE_H

#include <map>
#include <set>

#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-workflow.h>

#include "../../state/StateLayer.h"

namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class CreateReference : public workflow::Action
{
private:
  /** TODO: Documentation */
  StateLayer* _stateLayer;

  /** TODO: Documentation */
  ontology::Association* _association;

  /** TODO: Documentation */
  assembly::Instance* _fromInstance;

  /** TODO: Documentation */
  assembly::Instance* _toInstance;

  /** TODO: Documentation */
  assembly::Reference* _reference;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit CreateReference(StateLayer& stateLayer,
			   ontology::Association& assocation,
			   assembly::Instance& fromInstance,
			   assembly::Instance& toInstance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~CreateReference();

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
  CreateReference(const CreateReference& createReference);

  /**
   * TODO: Documentation
   *
   */
  CreateReference& operator=(const CreateReference& createReference);

};


}


}


#endif // PROTOLAYER_PROTO_CREATEREFERENCE_H
