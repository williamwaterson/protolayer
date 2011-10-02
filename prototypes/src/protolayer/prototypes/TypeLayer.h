#ifndef PROTOLAYER_TYPELAYER_H
#define PROTOLAYER_TYPELAYER_H

#include <algorithm>
#include <set>

#include <protolayer/protolayer-util.h>

#include "Type.h"

namespace protolayer
{

namespace ontology
{

/** TODO: Documentation */
class Instance;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class TypeLayer : public util::Object
{
public:
  /** TODO: Documentation */
  typedef util::SetIterator <Type> IteratorType;

private:
  /** TODO: Documentation */
  std::set <Type*> _types;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeLayer(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeLayer(std::set <Type*>& types);

  /**
   * TODO: Documentation
   * <p>
   */
  TypeLayer(iostream::XdrInputStream& stream,
            std::map <int, void*>& addressMappings);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~TypeLayer();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  IteratorType getTypes();

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(Type& type);

  /**
   * TODO: Documentation
   * <p>
   */
  bool involves(const std::string& conceptTypeUrn);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeLayer(const TypeLayer& typeLayer);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeLayer& operator=(const TypeLayer& typeLayer);

};


}


}


#endif // PROTOLAYER_TYPELAYER_H
