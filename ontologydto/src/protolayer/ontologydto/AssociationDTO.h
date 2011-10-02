#ifndef PROTOLAYER_ASSOCIATIONDTO_H
#define PROTOLAYER_ASSOCIATIONDTO_H

#include <map>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-pooling.h"
#include "protolayer/protolayer-xml.h"

#include "EndDTO.h"
#include "Exception.h"


namespace protolayer
{

namespace ontologydto
{

/**
 * @persist
 * @serialise
 * @prototype
 * @manage
 */
class AssociationDTO
{
public:
  /**
   * @serialise
   * @persist
   */
  int _id;

  /**
   * @serialise
   * @persist
   */
  std::string _name;

  /**
   * @serialise
   * @persist
   */
  EndDTO* _fromEnd;

  /**
   * @serialise
   * @persist
   */
  EndDTO* _toEnd;

  //  void functt();

public:
  /**
   * TODO: Documentation
   * <p>
   */
  AssociationDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  AssociationDTO(const std::string& fromTypeName, const std::string& toTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit AssociationDTO(xercesc::DOMElement& assocElement);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit AssociationDTO(iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~AssociationDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  void* operator new(size_t numberBytes);

  //  void func()
  //    { some content; }

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
  void decode(xercesc::DOMElement& assocElement);

  /**
   * TODO: Documentation
   * <p>
   */
  void decode(const std::string& fromTypeName, const std::string& toTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  void decode(const std::string& fromTypeName, int toDomainId, const std::string& toTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  void decode(int fromDomainId, const std::string& fromTypeName, int toDomainId, const std::string& toTypeName);

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
  std::string& getName();

  /**
   * TODO: Documentation
   * <p>
   */
  EndDTO& getFromEnd();

  /**
   * TODO: Documentation
   * <p>
   */
  EndDTO& getToEnd();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  AssociationDTO(const AssociationDTO& associationDTO);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  AssociationDTO& operator=(const AssociationDTO& associationDTO);

};


//void AssociationDTO::functt()
//{
//}


}


}


#endif // PROTOLAYER_ASSOCIATIONDTO_H
