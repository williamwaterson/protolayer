#ifndef PROTOLAYER_ASSEMBLY_H
#define PROTOLAYER_ASSEMBLY_H

#include <set>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "Exception.h"
#include "Domain.h"
#include "DomainDependency.h"
#include "Exception.h"
#include "Instance.h"
#include "InstanceDependency.h"
#include "Reference.h"


namespace protolayer
{

namespace assembly
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class Assembly
{
public:
  /** TODO: Documentation */
  typedef util::SetIterator <Domain> DomainIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <Layer> LayerIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <Instance> InstanceIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <Reference> ReferenceIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <DomainDependency>
    DomainDependencyIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <InstanceDependency> InstanceDependencyIteratorType;

private:
  /** TODO: Documentation */
  ontology::Ontology* _ontology;

  /** TODO: Documentation */
  std::set <Domain*> _domains;

  /** TODO: Documentation */
  std::set <Layer*> _layers;

  /** TODO: Documentation */
  std::set <Instance*> _instances;

  /** TODO: Documentation */
  std::set <Reference*> _references;

  /** TODO: Documentation */
  std::set <DomainDependency*> _domainDependencies;

  /** TODO: Documentation */
  std::set <InstanceDependency*> _instanceDependencies;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Assembly(ontology::Ontology& ontology);

  /**
   * TODO: Documentation
   * <p>
   */
  Assembly(iostream::XdrInputStream& stream,
           std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Assembly();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(xercesc::DOMDocument& document);

  /**
   * TODO: Documentation
   * <p>
   */
  ontology::Ontology& getOntology();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberDomains();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainIteratorType getDomains();

  /**
   * TODO: Documentation
   * <p>
   */
  Domain* getDomain(ontology::Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  Domain* getDomain(const std::string& domainName);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependencyIteratorType getDomainDependencies();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDependency* getDomainDependency(ontology::DomainDependency& domainDependency);

  /**
   * TODO: Documentation
   *
   */
  Layer* getLayer(Instance& instance);

  /**
   * TODO: Documentation
   *
   */
  Layer* getLayer(ontology::Type& type);

  /**
   * TODO: Documentation
   *
   */
  Layer* getLayer(ontology::TypeLayer& typeLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer* getLayer(const std::string& scopedTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer* getLayer(int domainId,
		  const std::string& unscopedTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer* getLayer(const std::string& domainIdAsString,
                  const std::string& unscopedTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberInstances();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberLayers() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberReferences();

  /**
   * TODO: Documentation
   * <p>
   */
  InstanceIteratorType getInstances();

  /**
   * TODO: Documentation
   * <p>
   */
  LayerIteratorType getLayers();

  /**
   * TODO: Documentation
   * <p>
   */
  ReferenceIteratorType getReferences();

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Instance& instance)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Reference& reference)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Instance& instance)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Reference& reference)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Reference& reference);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Layer& layer);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  //  bool isComplete(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  bool participates(Instance& instance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Assembly(const Assembly& assembly);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Assembly& operator=(const Assembly& assembly);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_H
