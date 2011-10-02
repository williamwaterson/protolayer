#ifndef PROTOLAYER_USERDTO_H
#define PROTOLAYER_USERDTO_H

#include <string>

#include "protolayer/protolayer-iostream.h"
#include "protolayer/protolayer-util.h"
#include "protolayer/protolayer-xml.h"


namespace protolayer
{

namespace dto
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class UserDTO
{
public:
  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  std::string _username;

  /** TODO: Documentation */
  std::string _password;

  /** TODO: Documentation */
  std::string _email;

public:
  /** TODO: Documentation */
  static const std::string& getClassName();

public:
  /**
   * TODO: Documentation
   * <p>
   */
  UserDTO();

  /**
   * TODO: Documentation
   * <p>
   */
  UserDTO(protolayer::iostream::XdrInputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */ 
  virtual ~UserDTO();

  /**
   * TODO: Documentation
   * <p>
   */ 
  void encode(protolayer::iostream::XdrOutputStream& stream);

  /**
   * TODO: Documentation
   * <p>
   */
  int& getId();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getUsername();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getUserName();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getPassword();

  /**
   * TODO: Documentation
   * <p>
   */
  std::string& getEmail();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  UserDTO(const UserDTO& userDTO);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  UserDTO& operator=(const UserDTO& userDTO);

};


}


}


#endif // PROTOLAYER_USERDTO_H
