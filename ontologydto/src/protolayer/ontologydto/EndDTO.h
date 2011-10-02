#ifndef PROTOLAYER_ONTOLOGYDTO_ENDDTO_H
#define PROTOLAYER_ONTOLOGYDTO_ENDDTO_H

#include <string>

#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-pooling.h"
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
class EndDTO
{
public:
  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  int _conceptId;

  /** TODO: Documentation */
  int _domainId;

  /** TODO: Documentation */
  std::string _label;

  /** TODO: Documentation */
  std::string _typeName;

  /** TODO: Documentation */
  std::string _multiplicity;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  EndDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit EndDTO(const std::string& typeName);

  /**
   * TODO: Documentation
   * <p>
   */
  EndDTO(int domainId, const std::string& typeName);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit EndDTO(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit EndDTO(iostream::XdrInputStream& stream);

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
  void decode(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  void decode(const std::string& typeName);

  /**
   * TODO: Documentation
   * <p>
   */
  void decode(int domainId, const std::string& typeName);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~EndDTO();

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
  int& getConceptId();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getDomainId();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getLabel();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getTypeName();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getMultiplicity();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  EndDTO(const EndDTO& endDTO);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  EndDTO& operator=(const EndDTO& endDTO);

};


}


}


#endif // PROTOLAYER_END_H
