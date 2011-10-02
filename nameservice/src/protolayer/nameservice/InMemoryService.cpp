#include "InMemoryService.h"


namespace protolayer
{

namespace nameservice
{

namespace
{

char SEPARATOR = ':';

std::string NAME_SERVICE = "NameService";

std::string ONTOLOGY_URN_PREFIX = "urn:protolayer:onto";

std::string TECHNIQUE_URN_PREFIX = "urn:protolayer:tech";


/*
 * TODO: Better handling of released. Read write locking.
 *
 */
class UrnGenerator
{
private:
  /** TODO: Documentation */
  int _id;

  /** TODO: Documentation */
  std::string _prefix;

  /** TODO: Documentation */
  pthread_mutex_t _mutex;

  /** TODO: Documentation */
  pthread_mutexattr_t _mutexAttributes;  

public:
  /**
   * TODO: Documentation
   *
   */
  explicit UrnGenerator(const std::string& prefix)
  {
    _id = 1;
    _prefix = prefix;

    pthread_mutexattr_init(&_mutexAttributes);
    pthread_mutex_init(&_mutex, &_mutexAttributes);
  }

  /**
   * TODO: Documentation
   *
   */
  ~UrnGenerator()
  {
    pthread_mutex_lock(&_mutex);
    pthread_mutex_destroy(&_mutex);
    pthread_mutexattr_destroy(&_mutexAttributes);
  }

  /**
   * TODO: Documentation
   *
   */
  int obtainId()
  {
    return _id++;
  }

  /**
   * TODO: Documentation
   *
   */
  std::string obtainUrn()
  {
    char buffer[33];

    pthread_mutex_lock(&_mutex);
    sprintf(buffer, "%d", obtainId());
    pthread_mutex_unlock(&_mutex);

    return _prefix + buffer;
  }

};


UrnGenerator ontologyUrnGenerator(ONTOLOGY_URN_PREFIX);
UrnGenerator techniqueUrnGenerator(TECHNIQUE_URN_PREFIX);


}


InMemoryService::InMemoryService()
{
}


std::string ltrim(const std::string &str, const std::string &whitespace = "\t ")
{
  int idx = str.find_first_not_of(whitespace);
  if(idx != std::string::npos) {
    return str.substr(idx);
  }
  return "";
}


std::string rtrim( const std::string& str, const std::string& whitespace = "\t\n\r ")
{
  int idx = str.find_last_not_of(whitespace);
  if(idx != std::string::npos) {
    return str.substr(0,idx+1);
  }
  return str;
}


std::string trim( const std::string &str, const std::string &whitespace = "\t\n\r ")
{
  return rtrim(ltrim(str));
}


bool containsSpaces(const std::string& str)
{
  return false;
}


std::string InMemoryService::registerDomain(ontologydto::DomainDTO& domain)
  throw (Exception)
{
  if (domain.getTypes().size() == 0) {
    throw Exception("Submitted domain ontology must consist of at least one type for registration");
  }

  std::string urn = ontologyUrnGenerator.obtainUrn();

  if (_domainDirectory.count(urn) == 0) {
    _domainDirectory[urn] = &domain;
  } else {
    throw Exception("URN address space exhausted for domain ontologies");
  }

  typedef std::set <ontologydto::TypeDTO*>::iterator IterType;
  for (IterType iter = domain.getTypes().begin(); iter != domain.getTypes().end(); iter++) {
    std::string name = trim((*iter)->getName());
    std::string conceptUrn = urn + SEPARATOR + name;
    _implementationDirectory[conceptUrn] = new std::set <std::string> ();
    logger::Logger::getSingleton().debug("NameService", "Registered concept URN " + conceptUrn);
  }

  return urn;
}


bool InMemoryService::isValidTechniqueUrn(const std::string& urn) const
{
  return 0 == urn.find(TECHNIQUE_URN_PREFIX, 0);
}


bool InMemoryService::isValidOntologyUrn(const std::string& urn) const
{
  return 0 == urn.find(ONTOLOGY_URN_PREFIX, 0);
}


std::string InMemoryService::extractOntologyUrn(const std::string& urn)
  throw (Exception)
{
  if (!isValidOntologyUrn(urn)) {
    throw Exception("Supplied URN is invalid format for an ontology");
  }

  // Need better checks to prevent "::::" and similar invalid urns

  int urnEnd = urn.find(SEPARATOR, 0);
  int domainEnd = urn.find(SEPARATOR, urnEnd + 1);
  int resourceEnd = urn.find(SEPARATOR, domainEnd + 1);
  int finalEnd = urn.find(SEPARATOR, resourceEnd + 1);

  std::string result;

  if (urnEnd == std::string::npos) {
    throw Exception("Supplied URN is malformed");

  } else if (domainEnd == std::string::npos) {
    throw Exception("Supplied URN is malformed");

  } else if (resourceEnd == std::string::npos) {
    result = urn;

  } else {
    result = urn.substr(0, resourceEnd);

  }

  return result;
}


std::string InMemoryService::extractConceptName(const std::string& urn)
  throw (Exception)
{
  if (!isValidOntologyUrn(urn)) {
    throw Exception("Supplied URN is invalid format for an ontology");
  }

  // Need better checks to prevent "::::" and similar invalid urns

  int urnEnd = urn.find(SEPARATOR, 0);
  int domainEnd = urn.find(SEPARATOR, urnEnd + 1);
  int resourceEnd = urn.find(SEPARATOR, domainEnd + 1);
  int finalEnd = urn.find(SEPARATOR, resourceEnd + 1);

  std::string result;

  if (urnEnd == std::string::npos) {
    throw Exception("Supplied URN is malformed");

  } else if (domainEnd == std::string::npos) {
    throw Exception("Supplied URN is malformed");

  } else if (resourceEnd == std::string::npos) {
    throw Exception("Supplied URN " + urn + " contains no concept URN extension");

  } else if (resourceEnd + 1 == std::string::npos) {
    throw Exception("Supplied URN " + urn + " contains no concept URN extension");

  } else {
    result = urn.substr(resourceEnd + 1, finalEnd);

  }

  return result;
}


std::string InMemoryService::registerTechnique(TechniqueRecord& record)
  throw (Exception)
{
  std::string conceptUrn = record.getImplementedConceptUrn();
  conceptUrn = trim(conceptUrn);

  // Need better check for no internal white space
  //  if (containsWhitespace(conceptUrn)) {
  //    throw Exception("Concept URN for submitted technique URN must contain no internal spaces");
  //  }

  if (conceptUrn.size() == 0 ||
      conceptUrn.find_first_not_of("\t\n\r") == std::string::npos) {
    throw Exception("Submitted technique record lacks specified concept URN");
  }

  logger::Logger::getSingleton().debug("NameService", "Concept URN is " + conceptUrn);

  std::string domainUrn = extractOntologyUrn(conceptUrn);
  logger::Logger::getSingleton().debug("NameService", "Ontology URN is " + domainUrn);

  if (_domainDirectory.count(domainUrn) != 1) {
    throw Exception("Encompassing ontology " + domainUrn + " for specified concept is not registered");
  }

  ontologydto::DomainDTO* domain = _domainDirectory[domainUrn];
  std::string conceptName = extractConceptName(conceptUrn);
  if (conceptName.size() == 0 ||
      conceptUrn.find_first_not_of("\t\n\r") == std::string::npos) {
    throw Exception("Submitted concept URN lacks concept name extension");
  }

  logger::Logger::getSingleton().debug("NameService", "Concept name is " + conceptName);

  /*
  if (domain.getType(conceptName) == 0) {
    throw Exception("Specified concept name " + conceptName + " does not exist in ontology " + domainUrn);
  } else {
    logger::Logger::getSingleton().debug("NameService", "Concept name " + conceptName + " does exist in ontology " + ontologyUrn);
  }
  */

  if (_implementationDirectory.count(conceptUrn) == 0) {
    throw Exception("Invalid service state for concept-to-technique mapping");
  }

  std::string urn = techniqueUrnGenerator.obtainUrn();

  if (_techniqueDirectory.count(urn) == 0 &&
      _locationsDirectory.count(urn) == 0 &&
      _implementationDirectory.count(conceptUrn) != 0) {

      _techniqueDirectory[urn] = &record;
      _implementationDirectory[conceptUrn]->insert(urn);
      _locationsDirectory[urn] = new AddressLoop();

  } else {
    throw Exception("URN address space exhausted for techniques");

  }

  return urn;
}


void InMemoryService::addLocation(const std::string& urn,
				  const std::string& location)
  throw (Exception)
{
  if (!isValidTechniqueUrn(urn)) {
    throw Exception("Invalid techique URN " + urn);
  }

  if (_locationsDirectory.count(urn) == 0) {
    throw Exception("Unable to add location as technique URN " + urn + " is not registered");
  } else {
    _locationsDirectory[urn]->addAddress(location);
  }
}


void InMemoryService::removeLocation(const std::string& urn,
				     const std::string& location)
  throw (Exception)
{
  if (!isValidTechniqueUrn(urn)) {
    throw Exception("Invalid techique URN " + urn);
  }

  if (_locationsDirectory.count(urn) == 0) {
    throw Exception("Technique URN " + urn + " is not registered");

  } else {
    _locationsDirectory[urn]->removeAddress(location);
  }
}


void InMemoryService::unregister(const std::string& urn)
  throw (Exception)
{
  try {
    if (isValidOntologyUrn(urn)) {
    
      if (_domainDirectory.count(urn) == 0) {
	throw Exception("Unable to unregister nonexistent ontology URN " + urn);
      }

      ontologydto::DomainDTO* ontology = _domainDirectory[urn];
      _domainDirectory.erase(urn);
      if (ontology != 0) {
	delete ontology;
      }

    } else if (isValidTechniqueUrn(urn)) {

      if (_locationsDirectory.count(urn) == 0 ||
	  _techniqueDirectory.count(urn) == 0) {
	throw Exception("Unable to unregister nonexistent technique URN " + urn);
      }

      AddressLoop* locations = _locationsDirectory[urn];
      _locationsDirectory.erase(urn);
      if (locations != 0) {
	delete locations;
      }

      Record* record = _techniqueDirectory[urn];
      _techniqueDirectory.erase(urn);
      if (record != 0) {
	delete record;
      }

    } else {
      throw Exception("Invalid URN " + urn + " (neither ontology or technique");

    }

  } catch (std::exception& ex) {
    throw Exception(ex.what());

  }

}


void InMemoryService::extractKeywords(const std::string& criteria,
				      std::set <std::string>& keywords)
{
  std::string result;

  size_t begin = criteria.find_first_not_of(' ');
  size_t end = criteria.find(' ', begin);

  while (begin != std::string::npos) {
    std::string keyword = criteria.substr(begin, end - begin);
    keywords.insert(keyword);

    begin = criteria.find_first_not_of(' ', end);
    end = criteria.find(' ', begin);
  }
}


void InMemoryService::matchUrns(const std::set <std::string>& keywords,
				std::set <std::string>& results)
{
  typedef StringSetType::const_iterator IterType;

  for (IterType iter = keywords.begin(); iter != keywords.end(); iter++) {
    std::string keyword = *iter;
    if (0 != _dictionary.count(keyword)) {
      StringSetType* urns = _dictionary[keyword];
      for (IterType urnIter = urns->begin(); urnIter != urns->end(); urnIter++) {
	std::string result = *urnIter;
	results.insert(result);
      }
    }
  }
}


void InMemoryService::constructResult(const std::set <std::string>& urns,
				      std::string& result)
{
  typedef StringSetType::const_iterator IterType;

  for (IterType iter = urns.begin(); iter != urns.end(); iter++) {
    result += *iter;
    result += ' ';
  }
}


std::string InMemoryService::getNames(const std::string& criteria)
  throw (Exception)
{
  std::set <std::string> keywords;
  extractKeywords(criteria, keywords);

  //  std::set <std::string> urns;
  //  matchUrns(keywords, urns);

  std::string result;
  //  constructResult(urns, result);
  constructResult(keywords, result);

  return result;
}


std::set <std::string>& InMemoryService::getTechniques(const std::string& conceptUrn)
  throw (Exception)
{
  std::set <std::string>* techniqueUrns;

  if (_implementationDirectory.count(conceptUrn) == 0) {
    throw Exception("Concept URN nonexistent");
  } else {
    techniqueUrns = _implementationDirectory[conceptUrn];
  }

  return *techniqueUrns;
}


ontologydto::DomainDTO* InMemoryService::getDomain(const std::string& urn)
  throw (Exception)
{
  ontologydto::DomainDTO* result = 0;

  try {
    if (isValidOntologyUrn(urn)) {

      if (_domainDirectory.count(urn) == 0) {
	throw Exception("Ontology URN " + urn + " not registered");
      }

      result = _domainDirectory[urn];

    } else {
      throw Exception("Invalid Ontology URN " + urn);

    }

  } catch (std::exception& ex) {
    throw Exception(ex.what());

  }

  if (result == 0) {
    throw Exception("Null ontology pointer for URN " + urn);
  }

  return result;
}


Record* InMemoryService::getRecord(const std::string& urn)
  throw (Exception)
{
  Record* result = 0;

  if (isValidOntologyUrn(urn)) {
    
    if (_domainDirectory.count(urn) == 0) {
      throw Exception("Ontology URN " + urn + " not registered");
    }

    //    result = _ontologyRecords[urn];
    
  } else if (isValidTechniqueUrn(urn)) {

    if (_locationsDirectory.count(urn) == 0 ||
  	_techniqueDirectory.count(urn) == 0) {
      throw Exception("Technique URN " + urn + " not registered");
    }

    result = _techniqueDirectory[urn];

  } else {
    throw Exception("Invalid URN " + urn + " (neither ontology or technique");

  }

  return result;
}


std::string InMemoryService::nextLocation(const std::string& urn)
  throw (Exception)
{
  if (_locationsDirectory.count(urn) == 0) {
    throw Exception("Technique URN nonexistent: " + urn);
  }
   
  return _locationsDirectory[urn]->next();
}


}


}
