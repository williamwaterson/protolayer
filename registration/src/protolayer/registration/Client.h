#ifndef PROTOLAYER_REGISTRATION_CLIENT_H
#define PROTOLAYER_REGISTRATION_CLIENT_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <map>

#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-dto.h>
#include <protolayer/protolayer-net.h>

#include "Exception.h"


namespace protolayer
{

namespace registration
{

/**
 * TODO: Documentation
 * <p>
 */
class Client
{
  /** TODO: Documentation */
  int _port;

  /** TODO: Documentation */
  net::Socket* _socket;

public:
  /**
   * TODO: Documentation
   *
   */
  Client(int port);

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::ontologydto::TypeDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::ontologydto::AssociationDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::ontologydto::GeneralisationDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::dto::TechniqueDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  int add(protolayer::dto::UserDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool findType(int id);

  /**
   * TODO: Documentation
   *
   */
  bool findType(int domainId, std::string typeName);

  /**
   * TODO: Documentation
   *
   */
  int retrieveTypeId(int domainId, std::string typeName);

  /**
   * TODO: Documentation
   *
   */
  bool findAssociation(int id);

  /**
   * TODO: Documentation
   *
   */
  bool findGeneralisation(int id);

  /**
   * TODO: Documentation
   *
   */
  bool findDomain(int id);

  /**
   * TODO: Documentation
   *
   */
  bool findEnd(int id);

  /**
   * TODO: Documentation
   *
   */
  bool findTechnique(int id);

  /**
   * TODO: Documentation
   *
   */
  bool findUser(int id);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::ontologydto::TypeDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::ontologydto::EndDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::ontologydto::AssociationDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::ontologydto::GeneralisationDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::dto::TechniqueDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(int id, protolayer::dto::UserDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::ontologydto::TypeDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::ontologydto::EndDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::ontologydto::AssociationDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::ontologydto::GeneralisationDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::ontologydto::DomainDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::dto::TechniqueDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  bool retrieve(protolayer::dto::UserDTO& dto);

  /**
   * TODO: Documentation
   *
   */
  void removeType(int id);

  /**
   * TODO: Documentation
   *
   */
  void removeAssociation(int id);

  /**
   * TODO: Documentation
   *
   */
  void removeGeneralisation(int id);

  /**
   * TODO: Documentation
   *
   */
  void removeDomain(int id);

  /**
   * TODO: Documentation
   *
   */
  void removeTechnique(int id);

  /**
   * TODO: Documentation
   *
   */
  void removeUser(int id);

private:
  /**
   * TODO: Documentation
   *
   */
  void checkResponse() throw (Exception);

};

}

}

#endif // PROTOLAYER_REGISTRATION_CLIENT_H
