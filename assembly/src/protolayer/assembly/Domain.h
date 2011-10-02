#ifndef PROTOLAYER_ASSEMBLY_DOMAIN_H
#define PROTOLAYER_ASSEMBLY_DOMAIN_H

#include <assert.h>
#include <map>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>

#include "Exception.h"
#include "Layer.h"

namespace protolayer
{

namespace assembly
{

/** TODO: Documentatin */
class Layer;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class Domain : public util::Object
{
public:
  /** TODO: Documentation */
  typedef util::VectorIterator <Layer> LayerIteratorType;

private:
  /** TODO: Documentation */
  ontology::Domain* _domain;

  /** TODO: Documentation */
  std::vector <Layer*> _topDownLayers;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Domain(ontology::Ontology& ontology,
                 ontology::Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  Domain(xercesc::DOMElement& element,
	 ontology::Ontology& ontology);

  /**
   * TODO: Documentation
   * <p>
   */
  Domain(iostream::XdrInputStream& stream,
	 std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Domain();

  /**
   * TODO: Documentation
   *
   */
  ontology::Domain& getDomain();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   *
   */
  bool instantiates(ontology::Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberLayers() const;

  /**
   * TODO: Documentation
   * <p>
   */
  Layer& getLayer(int index);

  /**
   * TODO: Documentation
   * <p>
   */
  LayerIteratorType getTopDownLayers();

  /**
   * TODO: Documentation
   * <p>
   */
  LayerIteratorType getTopDownLayers(Layer& from);

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
  Layer* getLayer(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer* getLayer(ontology::Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer* getLayer(ontology::TypeLayer& typeLayer);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Domain(const Domain& instance);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Domain& operator=(const Domain& instance);

};


}


}


#endif // PROTOLAYER_ASSEMBLY_DOMAIN_H
