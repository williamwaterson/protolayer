#ifndef PROTOLAYER_NAMESERVICE_INMEMORYSERVICE_H
#define PROTOLAYER_NAMESERVICE_INMEMORYSERVICE_H

#include <map>
#include <set>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-util.h>
#include <protolayer/protolayer-xml.h>

#include "TechniqueRecord.h"
#include "AddressLoop.h"


namespace protolayer
{

namespace nameservice
{

/**
 * A nameservice implemented purely with in-memory data
 * data structures i.e. not persisted in a database or
 * any filesystem.
 * <p>
 */
class InMemoryService
{
  /** TODO: Documentation */
  typedef std::set <std::string> StringSetType;

  /** TODO: Documentation */
  typedef std::map <std::string, AddressLoop*>::iterator IteratorType;

  /** TODO: Documentation */
  typedef std::map <std::string, AddressLoop*>::const_iterator ConstIteratorType;

private:
  /** Maps single keywords to sets of URNs described by those keywords */
  std::map <std::string, StringSetType*> _dictionary;

  /** TODO: Documentation */
  std::map <std::string, ontologydto::DomainDTO*> _domainDirectory;

  /** Maps single keywords to detailed records of the related techniques */
  std::map <std::string, TechniqueRecord*> _techniqueDirectory;

  /** Maps single concept URN to multiple technique URNs which implement that concept */
  std::map <std::string, StringSetType*> _implementationDirectory;

  /** Maps single URNs to sets of IP locations providing the related technique */
  std::map <std::string, AddressLoop*> _locationsDirectory;

public:
  /**
   * TODO: Documentation
   *
   */
  InMemoryService();

  /**
   * TODO: Documentation
   *
   */
  bool isValidTechniqueUrn(const std::string& urn) const;

  /**
   * TODO: Documentation
   *
   */
  bool isValidOntologyUrn(const std::string& urn) const;

  /**
   * TODO: Documentation
   *
   */
  bool isRegisteredConceptUrn(const std::string& urn) const;

  /**
   * TODO: Documentation
   *
   */
  bool isValidConceptUrn(const std::string& urn) const;

  /**
   * TODO: Documentation
   *
   */
  std::string registerDomain(ontologydto::DomainDTO& domain)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  std::string registerTechnique(TechniqueRecord& record)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void unregister(const std::string& urn)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  std::string getNames(const std::string& criteria) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  Record* getRecord(const std::string& urn) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  ontologydto::DomainDTO* getDomain(const std::string& urn) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void addLocation(const std::string& urn,
		   const std::string& location)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void removeLocation(const std::string& urn,
		      const std::string& location)
    throw (Exception);

  /*
   * TODO: Documentation
   *
   */
  void extractKeywords(const std::string& criteria,
		       std::set <std::string>& keywords);

  /**
   * TODO: Documentation
   *
   */
  void matchUrns(const std::set <std::string>& keywords,
		 std::set <std::string>& results);

  /**
   * TODO: Documentation
   *
   */
  void constructResult(const std::set <std::string>& urns,
		       std::string& result);

  /**
   * TODO: Documentation
   *
   */
  std::set <std::string>& getTechniques(const std::string& urn)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  std::string nextLocation(const std::string& urn)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  std::string extractOntologyUrn(const std::string& urn)
    throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  std::string extractConceptName(const std::string& urn)
    throw (Exception);

private:
  /**
   * TODO: Documentation
   *
   */
  InMemoryService(const InMemoryService& service);

  /**
   * TODO: Documentation
   *
   */
  InMemoryService operator=(const InMemoryService& service);

};

}

}

#endif // PROTOLAYER_NAMESERVICE_SERVICE_H
