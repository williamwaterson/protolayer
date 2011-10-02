#ifndef PROTOLAYER_NAMESERVICE_CLIENT_H
#define PROTOLAYER_NAMESERVICE_CLIENT_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>

#include <set>

#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-ontology.h>

#include "TechniqueRecord.h"
#include "Exception.h"


namespace protolayer
{

namespace nameservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Client
{
  /** TODO: Documentation */
  typedef std::set <std::string> StringSetType;

private:
  /** TODO: Documentation */
  net::Socket* _socket;

  /** TODO: Documentation */
  int _port;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Client(int port);

  /**
   * TODO: Documentation
   *
   */
  std::string registerDomain(ontologydto::DomainDTO& domain)
    throw (Exception, net::Exception);

  /**
   * Adds the specified resource according to URN, record,
   * for a technique. The URN must be compliant with the
   * technique URN specification.
   *
   * @param urn
   *   a valid technique universal resource name
   *
   * @param record
   *   the record of the new technique being added
   *
   * @throws Exception
   *   upon failure of this operation
   */
  std::string registerTechnique(TechniqueRecord& record)
    throw (Exception, net::Exception);

  /**
   * Appends a subsequent location for an existing technique URN.
   * Method intended for remote invocation.
   */
  void addLocation(const std::string& urn,
                   const std::string& location)
    throw (Exception, net::Exception);

  /**
   * Removes an existing urn from the service.
   * A dependency check is made preventing removal
   * if other resources currently depend upon this
   * resource.
   */
  void unregister(const std::string& urn)
    throw (Exception, net::Exception);

  /**
   * Removes an existing location for the specified
   * technique URN. If this is the last location then
   * the method behaves like <code>removeName</code>
   * for the specified URN.
   */
  void removeLocation(const std::string& urn,
                      const std::string& location)
    throw (Exception, net::Exception);

  /**
   * Returns a serialised set of URNs matching the keyword search criteria.
   */
  std::string getNames(const std::string& criteria)
    throw (Exception, net::Exception);

  /**
   * Returns a serialised Record instance for the specified URN.
   */
  void getRecord(const std::string& urn)
    throw (Exception, net::Exception);

  /**
   * Returns a serialised Ontology for the specified URN.
   * The URN must be valid with respect to that expected for ontology
   * resources i.e.
   */
  void getDomain(const std::string& urn)
    throw (Exception, net::Exception);

  /**
   * Returns the next load-balanced URL that matches the location
   * for the technique URN specified. The URN implicitly must be compliant
   * with the technique URN specification.
   */
  std::string nextLocation(const std::string& urn);

private:
  /**
   * TODO: Documentation
   *
   */
  void checkResponse() throw (Exception);

};

}

}

#endif // PROTOLAYER_NAMESERVICE_CLIENT_H
