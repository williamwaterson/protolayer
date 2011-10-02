#ifndef PROTOLAYER_INSTANCECREATION_H
#define PROTOLAYER_INSTANCECREATION_H

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>

#include "Assembly.h"
#include "ConceptInstance.h"
#include "Reference.h"

namespace protolayer
{

namespace assembly
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class InstanceCreation
{
private:
  /** TODO: Documentation */
  int _creationCounter;

  /** TODO: Documentation */
  ontology::Type& _type;

  /** TODO: Documentation */
  Assembly& _assembly;

  /** TODO: Documentation */
  ConceptInstance* _createdInstance;

  /** TODO: Documentation */
  std::set <ontology::Association*> _mandatoryAssociations;

  /** TODO: Documentation */
  std::set <ontology::Association*>::iterator _activeAssociation;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit InstanceCreation(Assembly& assembly,
                            ontology::Type& type) throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~InstanceCreation();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isComplete() const;

  /**
   * TODO: Documentation
   *
   */
  bool isIncomplete() const;

  /**
   * TODO: Documentation
   *
   */
  ontology::Type& getType();

  /**
   * TODO: Documentation
   * <p>
   */
  ConceptInstance& getCreatedInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  Assembly& getAssembly();

  /**
   * TODO: Documentation
   * <p>
   */
  ontology::Association* getActiveAssociation();

  /**
   * TODO: Documentation
   * <p>
   */
  Reference* createReference(ConceptInstance& instance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  InstanceCreation(const InstanceCreation& instance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  InstanceCreation& operator=(const InstanceCreation& instance);

};


}


}


#endif // PROTOLAYER_INSTANCE_H
