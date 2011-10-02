#ifndef PROTOLAYER_REGISTRATION_USERSERVICE_H
#define PROTOLAYER_REGISTRATION_USERSERVICE_H

#include <map>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-persistence.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-xml.h>

#include <protolayer/protolayer-database.h>


namespace protolayer
{

namespace registration
{

/**
 * TODO: Documentation
 * <p>
 */
class UserService
{
public:
  /**
   * TODO: Documentation
   *
   */
  UserService();

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::dto::UserDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool findUser(int id);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::dto::UserDTO& user);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::dto::UserDTO& user);

  /**
   * TODO: Documentation
   *
   */
  void remove(int userId);

private:
  /**
   * TODO: Documentation
   *
   */
  UserService(const UserService& userService);

  /**
   * TODO: Documentation
   *
   */
  UserService operator=(const UserService& userService);

};


}


}


#endif // PROTOLAYER_REGISTRATION_USERSERVICE_H
