#ifndef PROTOLAYER_GENERALISATIONDTO_H
#define PROTOLAYER_GENERALISATIONDTO_H

#include <string>

#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-pooling.h"
#include "protolayer/protolayer-xml.h"

#include "Exception.h"


namespace protolayer
{

namespace ontologydto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class GeneralisationDTO
{
public:
  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  int _superTypeId;

  /** TODO: Documentation */
  int _superTypeDomainId;

  /** TODO: Documentation */
  std::string _superTypeName;

  /** TODO: Documentation */
  int _subTypeId;

  /** TODO: Documentation */
  int _subTypeDomainId;

  /** TODO: Documentation */
  std::string _subTypeName;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  GeneralisationDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  GeneralisationDTO(const std::string& superTypeName,
		    const std::string& subTypeName);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit GeneralisationDTO(xercesc::DOMElement& element);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit GeneralisationDTO(iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GeneralisationDTO();

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
  int& getSuperTypeId();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getSubTypeId();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getSuperTypeDomainId();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getSubTypeDomainId();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getSubTypeName();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getSuperTypeName();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GeneralisationDTO(const GeneralisationDTO& generalisationDTO);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GeneralisationDTO& operator=(const GeneralisationDTO& generalisationDTO);

};


}


}


#endif // PROTOLAYER_GENERALISATIONDTO_H
