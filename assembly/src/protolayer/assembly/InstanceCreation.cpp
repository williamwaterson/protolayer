#include "InstanceCreation.h"


namespace protolayer
{

namespace assembly
{

ontology::Association* InstanceCreation::getActiveAssociation()
{
  ontology::Association* result = 0;
  if (isIncomplete()) {
    result = *_activeAssociation;
  }
  return result;
}


bool InstanceCreation::isComplete() const
{
  return _activeAssociation == _mandatoryAssociations.end();
}


bool InstanceCreation::isIncomplete() const
{
  return !isComplete();
}


ConceptInstance& InstanceCreation::getCreatedInstance()
{
  return *_createdInstance;
}


InstanceCreation::InstanceCreation(Assembly& assembly,
                                   ontology::Type& type) throw (Exception) :
  _assembly(assembly),
  _type(type),
  _creationCounter(0)
{
  _createdInstance = assembly.createConceptInstance(type);
  
  ontology::Ontology& ontology = assembly.getOntology();
  std::set <ontology::Association*> associations =
    ontology.getAssociationsFrom(type);

  typedef std::set <ontology::Association*>::iterator IterType;
  for (IterType iter = associations.begin(); iter != associations.end(); iter++) {
    ontology::Association& association = **iter;    
    if (association.getToEnd().getMultiplicity().getLowerBound() > 0) {
      _mandatoryAssociations.insert(&association);
    }
  }

  if (_mandatoryAssociations.size() > 0) {
    _activeAssociation = _mandatoryAssociations.begin();
  } else {
    _activeAssociation = _mandatoryAssociations.end();    
  }
}


InstanceCreation::~InstanceCreation()
{
}


ontology::Type& InstanceCreation::getType()
{
  return _type;
}


Assembly& InstanceCreation::getAssembly()
{
  return _assembly;
}


Reference* InstanceCreation::createReference(ConceptInstance& toInstance)
{
  Reference* result = 0;
  if (isIncomplete()) {
    ontology::Association& association = **_activeAssociation;
    result = _assembly.createReference(association, *_createdInstance,
                                       toInstance);
    if (result != 0) {
      ontology::Multiplicity& multiplicity =
        association.getToEnd().getMultiplicity();

      _creationCounter++;
      if (_creationCounter == multiplicity.getLowerBound()) {
        _activeAssociation++;
        _creationCounter = 0;
      }
    }    
  }
  return result;
}


}


}
