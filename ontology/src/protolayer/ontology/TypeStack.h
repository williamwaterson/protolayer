#ifndef PROTOLAYER_TYPESTACK_H
#define PROTOLAYER_TYPESTACK_H

#include <map>
#include <vector>

#include <protolayer/protolayer-util.h>

#include "Type.h"
#include "TypeLayer.h"

namespace protolayer
{

namespace ontology
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class TypeStack
{
public:
  /** TODO: Documentation */
  typedef util::VectorIterator <TypeLayer> IteratorType;

private:
  /** TODO: Documentation */
  std::vector <TypeLayer*> _topDownLayers;

  /** TODO: Documentation */
  std::map <Type*, TypeLayer*> _typeLayerMap;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeStack(std::vector <TypeLayer*>& topDownLayers);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeStack(iostream::XdrInputStream& stream,
            std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  ~TypeStack();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberLayers() const;

  /**
   * TODO: Documentation
   * <p>
   */
  TypeLayer& getLayer(int index);

  /**
   * TODO: Documentation
   * <p>
   */
  IteratorType getTopDownLayers();

  /**
   * TODO: Documentation
   * <p>
   */
  IteratorType getTopDownLayers(TypeLayer& from);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeStack(const TypeStack& typeStack);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeStack& operator=(const TypeStack& typeStack);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  void extractTypeLayerMap();

};


}


}


#endif // PROTOLAYER_TYPESTACK_H
