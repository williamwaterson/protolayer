#ifndef PROTOLAYER_DTO_TECHNIQUEDTO_H
#define PROTOLAYER_DTO_TECHNIQUEDTO_H

#include <map>
#include <set>
#include <string>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-xml.h"
#include "protolayer/protolayer-util.h"


namespace protolayer
{

namespace dto
{

/**
 * <p>
 * @author William Waterson
 */
class TechniqueDTO
{
public:
  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  int _conceptId;

  /** TODO: Documentation */
  std::string _title;

  /** TODO: Documentation */
  std::string _description;

public:
  /**
   * TODO: Documentation
   *
   */
  static const std::string& getClassName();

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TechniqueDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit TechniqueDTO(protolayer::iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~TechniqueDTO();

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
  std::string& getUrn();

  /**
   * TODO: Documentation
   * <p>
   */
  int& getConceptId();

  /**
   * TODO: Documentation
   * <p>
   */
  void encode(protolayer::iostream::XdrOutputStream& stream);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TechniqueDTO(const TechniqueDTO& technique);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TechniqueDTO& operator=(const TechniqueDTO& technique);

};


}


}


#endif // PROTOLAYER_TECHNIQUEDTO_H
