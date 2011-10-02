#ifndef PROTOLAYER_TYPEDTO_H
#define PROTOLAYER_TYPEDTO_H

#include <map>
#include <set>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-pooling.h"
#include "protolayer/protolayer-util.h"
#include "protolayer/protolayer-xml.h"

namespace protolayer
{

namespace ontologydto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class TypeDTO
{
public:
  /** TODO: Documentation */
  bool _isLeaf;

  /** TODO: Documentation */
  bool _isAbstract;

  /** TODO: Documentation */
  bool _isSingleton;

  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  int _domainId;

  /** TODO: Documentation */
  std::string _name;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TypeDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeDTO(const std::string& name);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeDTO(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit TypeDTO(iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~TypeDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  void* operator new(size_t numberBytes);

  /**
   * TODO: Documentation
   * <p>
   */
  void operator delete(void* object);

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  void decode(iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  void clear();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getId();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getDomainId();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getName();

  /**
   * Todo: Documentation
   * <p>
   */
  bool& isLeaf();

  /**
   * TODO: Documentation
   * <p>
   */
  bool& isAbstract();

  /**
   * TODO: Documentation
   * <p>
   */
  bool& isSingleton();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeDTO(const TypeDTO& typeDTO);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TypeDTO& operator=(const TypeDTO& typeDTO);

};


}


}


#endif // PROTOLAYER_TYPEDTO_H
