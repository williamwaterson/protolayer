#ifndef PROTOLAYER_PROTO_DELETEINSTANCE_H
#define PROTOLAYER_PROTO_DELETEINSTANCE_H

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
class DeleteInstance : public workflow::Action
{
  /** TODO: Documentation */
  Assembly* _assembly;

  /** TODO: Documentation */
  assembly::Instance* _instance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DeleteInstance(Assembly& assembly,
			  assembly::Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DeleteInstance();

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
  DeleteInstance(const DeleteInstance& deleteInstance);

  /**
   * TODO: Documentation
   *
   */
  DeleteInstance& operator=(const DeleteInstance& deleteInstance);

};


}


}


#endif // PROTOLAYER_PROTO_DELETEINSTANCE_H
