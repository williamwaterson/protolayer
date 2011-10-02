#ifndef PROTOLAYER_DOMAINDTO_H
#define PROTOLAYER_DOMAINDTO_H

#include <map>
#include <set>
#include <string>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-pooling.h"
#include "protolayer/protolayer-xml.h"

#include "Exception.h"
#include "TypeDTO.h"
#include "AssociationDTO.h"
#include "GeneralisationDTO.h"


namespace protolayer
{

namespace ontologydto
{

/**
 * @prototype
 * <p>
 * @author William Waterson
 */
class DomainDTO
{
public:
  /** @prototype */
  int _id;

  /** TODO: Documentation */
  std::string _title;

  /** TODO: Documentation */
  std::string _description;

  /** TODO: Documentation */
  std::set <TypeDTO*> _types;

  /** TODO: Documentation */
  std::set <AssociationDTO*> _associations;

  /** TODO: Documentation */
  std::set <GeneralisationDTO*> _generalisations;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  DomainDTO() throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit DomainDTO(const std::string& title);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit DomainDTO(xercesc::DOMDocument& document)
    throw (Exception);

  /**
   * TODO: Documentation
   * <p>
   */
  DomainDTO(iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DomainDTO();

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
  std::string& getTitle();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getDescription();

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <TypeDTO*>& getTypes();

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <AssociationDTO*>& getAssociations();

  /**
   * TODO: Documentation
   * <p>
   */
  std::set <GeneralisationDTO*>& getGeneralisations();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DomainDTO(const DomainDTO& domain);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DomainDTO& operator=(const DomainDTO& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  void initialise(xercesc::DOMElement& element)
    throw (Exception);

};


}


}


#endif // PROTOLAYER_DOMAINDTO_H
