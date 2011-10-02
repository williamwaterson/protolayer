#ifndef PROTOLAYER_LAYER_H
#define PROTOLAYER_LAYER_H

#include <algorithm>
#include <set>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-ontology.h>

#include "Exception.h"
#include "Instance.h"

namespace protolayer
{

namespace assembly
{

/** TODO: Documentation */
class Instance;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class Layer : public util::Object
{
public:
  /** TODO: Documentation */
  typedef util::SetIterator <Instance> IteratorType;

private:
  /** TODO: Documentation */
  ontology::TypeLayer* _typeLayer;

  /** TODO: Documentation */
  std::set <Instance*> _instances;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Layer(ontology::TypeLayer& typeLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer(iostream::XdrInputStream& stream,
        std::map <int, void*> addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  Layer(xercesc::DOMElement& element,
        ontology::Ontology& ontology);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Layer();

  /**
   * TODO: Documentation
   * <p>
   */
  ontology::TypeLayer& getTypeLayer();

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
   * <p>
   */
  bool instantiates(ontology::TypeLayer& typeLayer);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberInstances() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Instance& instance);

  /**
   * TODO: Documentation
   * <p>
   */
  IteratorType getInstances();

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
  void remove(Instance& instance)
    throw (Exception);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Layer(const Layer& layer);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Layer& operator=(const Layer& layer);

};


}


}


#endif // PROTOLAYER_LAYER_H
