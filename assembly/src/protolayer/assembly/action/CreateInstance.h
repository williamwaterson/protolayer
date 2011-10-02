#ifndef PROTOLAYER_PROTO_CREATEINSTANCE_H
#define PROTOLAYER_PROTO_CREATEINSTANCE_H

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
class CreateInstance : public workflow::Action
{
private:
  /** TODO: Documentation */
  Assembly* _assembly;

  /** TODO: Documentation */
  ontology::Type* _type;

  /** TODO: Documentation */
  assembly::Instance* _instance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit CreateInstance(Assembly& assembly,
			  ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~CreateInstance();

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
  CreateInstance(const CreateInstance& createInstance);

  /**
   * TODO: Documentation
   *
   */
  CreateInstance& operator=(const CreateInstance& createInstance);

};


}


}


#endif // PROTOLAYER_PROTO_CREATEINSTANCE_H
