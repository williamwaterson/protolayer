#include "Assembly.h"


namespace protolayer
{

namespace assembly
{

Assembly::Assembly(ontology::Ontology& ontology)
{
  _ontology = &ontology;

  ontology::Ontology::DomainIteratorType iter;
  for (iter = _ontology->getDomains(); iter.hasNext(); ) {
    ontology::Domain& domain = iter.next();
    Domain* inst = new Domain(ontology, domain);
    _domains.insert(inst);

    typedef Domain::LayerIteratorType LayerIterType;
    for (LayerIterType layerIter = inst->getTopDownLayers(); layerIter.hasNext(); ) {
      Layer& layer = layerIter.next();
      _layers.insert(&layer);
    }
  }

  ontology::Ontology::DomainDependencyIteratorType ddIter;
  for (ddIter = _ontology->getDomainDependencies(); ddIter.hasNext(); ) {
    ontology::DomainDependency& dep = ddIter.next();
    Domain* fromInst = getDomain(dep.getFromDomain());
    Domain* toInst = getDomain(dep.getToDomain());
    DomainDependency* inst =
      new DomainDependency(dep, *fromInst, *toInst);
    _domainDependencies.insert(inst);
  }
}


Assembly::Assembly(iostream::XdrInputStream& stream,
                   std::map <int, void*>& addressMappings)
{
  int id = 0;

  stream.read(id);
  _ontology = reinterpret_cast <ontology::Ontology*> (addressMappings[id]);

  int numberOf = 0;
  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Domain* domain =
      new Domain(stream, addressMappings);
    _domains.insert(domain);
    addressMappings[id] = reinterpret_cast <void*> (domain);

    typedef Domain::LayerIteratorType LayerIterType;
    for (LayerIterType layerIter = domain->getTopDownLayers(); layerIter.hasNext(); ) {
      Layer& layer = layerIter.next();
      _layers.insert(&layer);

      typedef Layer::IteratorType InstIteratorType;
      Instance* instance = 0;
      for (InstIteratorType iter = layer.getInstances(); iter.hasNext(); ) {
        instance = &(iter.next());
        _instances.insert(instance);
      }
    }
  }

  stream.read(numberOf);
  for (int i = 0; i < numberOf; ++i) {
    stream.read(id);
    Reference* reference = new Reference(stream, addressMappings);
    _references.insert(reference);
    addressMappings[id] = reinterpret_cast <void*> (reference);
  }
}


Assembly::~Assembly()
{
}


void Assembly::encode(iostream::XdrOutputStream& stream)
{
  stream.write((int) _ontology);

  Domain* domain = 0;
  stream.write(getNumberDomains());
  typedef DomainIteratorType DIIterType;
  for (DIIterType iter = getDomains(); iter.hasNext(); ) {
    domain = &(iter.next());
    stream.write((int) domain);
    domain->encode(stream);
  }

  Reference* reference = 0;
  stream.write(getNumberReferences());
  for (ReferenceIteratorType iter = getReferences(); iter.hasNext(); ) {
    reference = &(iter.next());
    stream.write((int) reference);
    reference->encode(stream);
  }
}


void Assembly::encode(xercesc::DOMDocument& document)
{
}


ontology::Ontology& Assembly::getOntology()
{
  return *_ontology;
}


int Assembly::getNumberDomains()
{
  return _domains.size();
}


int Assembly::getNumberLayers() const
{
  return _layers.size();
}


Assembly::LayerIteratorType Assembly::getLayers()
{
  return LayerIteratorType(_layers);
}


Assembly::DomainIteratorType Assembly::getDomains()
{
  return DomainIteratorType(_domains);
}


Domain* Assembly::getDomain(ontology::Domain& ontologyDomain)
{
  Domain* result = 0;
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& domain = iter.next();
    if (domain.instantiates(ontologyDomain)) {
      result = &domain;
    }
  }
  return result;
}


Domain* Assembly::getDomain(const std::string& domainName)
{
  Domain* result = 0;
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& domain = iter.next();
    if (domain.getDomain().getTitle() == domainName) {
      result = &domain;
    }
  }
  return result;
}


Assembly::DomainDependencyIteratorType Assembly::getDomainDependencies()
{
  return DomainDependencyIteratorType(_domainDependencies);
}


DomainDependency* Assembly::getDomainDependency(ontology::DomainDependency& ontologyDomainDependency)
{
  DomainDependency* result = 0;
  DomainDependencyIteratorType iter;
  for (iter = getDomainDependencies(); iter.hasNext(); ) {
    DomainDependency& domainDependency = iter.next();
    if (domainDependency.instantiates(ontologyDomainDependency)) {
      result = &domainDependency;
    }
  }
  return result;
}


int Assembly::getNumberInstances()
{
  return _instances.size();
}


Assembly::InstanceIteratorType Assembly::getInstances()
{
  return InstanceIteratorType(_instances);
}


bool Assembly::contains(Layer& layer)
{
  bool result = false;
  DomainIteratorType diIter;
  for (diIter = getDomains(); diIter.hasNext(); ) {
    Domain& di = diIter.next();
    if (di.contains(layer)) {
      result = true;
    }
  }
  return result;
}


bool Assembly::contains(Domain& domain)
{
  return _domains.find(&domain) != _domains.end();
}


bool Assembly::contains(Reference& reference)
{
  return _references.find(&reference) != _references.end();
}


bool Assembly::contains(Instance& instance)
{
  return _instances.find(&instance) != _instances.end();
}


void Assembly::add(Instance& instance)
  throw (Exception)
{
  Layer* layer = getLayer(instance.getType());
  if (layer == 0) {
    throw Exception("Specifed type is not Assembly member.");
  }

  layer->add(instance);
  _instances.insert(&instance);
}


void Assembly::add(Reference& reference)
  throw (Exception)
{
  _references.insert(&reference);
}


void Assembly::remove(Instance& instance)
  throw (Exception)
{
  if (!contains(instance)) {
    throw Exception("Instance cannot be removed: Not part of Assembly.");
  }

  if (participates(instance)) {
    throw Exception("Instance cannot be removed: Currently participating in Reference(s).");
  }

  _instances.erase(&instance);
  Layer& layer = *(getLayer(instance));  // Already checked non-null layer pointer above
  layer.remove(instance);
}


bool Assembly::participates(Instance& instance)
{
  bool result = false;
  ReferenceIteratorType iter;
  for (iter = getReferences(); iter.hasNext(); ) {
    Reference& reference = iter.next();
    if (reference.involves(instance)) {
      result = true;
      break;
    }
  }
  return result;
}


void Assembly::remove(Reference& reference)
  throw (Exception)
{
  if (!contains(reference)) {
    throw Exception("Reference cannot be removed: Not part of this assembly.");
  }
  _references.erase(&reference);
}


Layer* Assembly::getLayer(Instance& instance)
{
  Layer* result = 0;
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& di = iter.next();
    Layer* check = di.getLayer(instance);
    if (check != 0) {
      result = check;
    }
  }
  return result;
}


Layer* Assembly::getLayer(ontology::Type& type)
{
  Layer* result = 0;
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& di = iter.next();
    Layer* check = di.getLayer(type);
    if (check != 0) {
      result = check;
    }
  }
  return result;  
}


Layer* Assembly::getLayer(ontology::TypeLayer& typeLayer)
{
  Layer* result = 0;
  DomainIteratorType iter;
  for (iter = getDomains(); iter.hasNext(); ) {
    Domain& di = iter.next();
    Layer* check = di.getLayer(typeLayer);
    if (check != 0) {
      result = check;
    }
  }
  return result;  
}


Layer* Assembly::getLayer(const std::string& scopedTypeName)
{
  Layer* result = 0;
  ontology::Type* type = getOntology().getTypeByScopedName(scopedTypeName);
  if (type != 0) {
    result = getLayer(*type);
  }
  return result;
}


Layer* Assembly::getLayer(int domainId,
                          const std::string& unscopedTypeName)
{
  Layer* result = 0;
  ontology::Domain* domain = getOntology().getDomainById(domainId);
  if (domain != 0) {
    ontology::Type* type = domain->getTypeByUnscopedName(unscopedTypeName);
    if (type != 0) {
      result = getLayer(*type);
    }
  }
  return result;
}


Layer* Assembly::getLayer(const std::string& domainIdAsString,
                          const std::string& unscopedTypeName)
{
  Layer* result = 0;
  ontology::Domain* domain = getOntology().getDomainById(domainIdAsString);
  if (domain != 0) {
    ontology::Type* type = domain->getTypeByUnscopedName(unscopedTypeName);
    if (type != 0) {
      result = getLayer(*type);
    }
  }
  return result;
}


int Assembly::getNumberReferences()
{
  return _references.size();
}


Assembly::ReferenceIteratorType Assembly::getReferences()
{
  return ReferenceIteratorType(_references);
}


}


}

