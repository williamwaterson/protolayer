#ifndef PROTOLAYER_PERSISTENCE_DOMAINMANAGER_H
#define PROTOLAYER_PERSISTENCE_DOMAINMANAGER_H

#include <string>
#include <protolayer/protolayer-database.h>
#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-ontologydto.h>
#include "Exception.h"

#include "Manager.h"
#include "TypeManager.h"
#include "EndManager.h"
#include "AssociationManager.h"
#include "GeneralisationManager.h"


namespace protolayer
{

namespace persistence
{

/**
 *
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
template <> class Manager <ontologydto::DomainDTO>
{
 public:
  /**
   * TODO: Documentation
   *
   */
  static void setup()
  {
    try {
      database::Connection connection;
      connection.query("USE Protolayer;");
      connection.query("CREATE TABLE Domains(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), title VARCHAR(255), description VARCHAR(100000), creator INT UNSIGNED)");
    } catch (database::Exception& ex) {
      throw ex;
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static void drop()
  {
  }

  /**
   * TODO: Documentation
   *
   */
  static void propagateDomainIds(ontologydto::DomainDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    for (std::set < ontologydto::TypeDTO*>::iterator iter = dto.getTypes().begin(); iter != dto.getTypes().end(); iter++) {
      (*iter)->getDomainId() = dto.getId();
    }

    for (std::set < ontologydto::AssociationDTO*>::iterator iter = dto.getAssociations().begin(); iter != dto.getAssociations().end(); iter++) {
      ontologydto::EndDTO& fromEnd = (*iter)->getFromEnd();
      if (0 == fromEnd.getDomainId()) {
	fromEnd.getDomainId() = dto.getId();
      }

      ontologydto::EndDTO& toEnd = (*iter)->getToEnd();
      if (0 == toEnd.getDomainId()) {
	toEnd.getDomainId() = dto.getId();
      }
    }

    for (std::set < ontologydto::GeneralisationDTO*>::iterator iter = dto.getGeneralisations().begin(); iter != dto.getGeneralisations().end(); iter++) {
      if (0 == (*iter)->getSuperTypeDomainId()) {
	(*iter)->getSuperTypeDomainId() = dto.getId();
      }

      if (0 == (*iter)->getSubTypeDomainId()) {
	(*iter)->getSubTypeDomainId() = dto.getId();
      }
    }
  }


  static void trim(ontologydto::GeneralisationDTO& dto) {
    dto._superTypeName = util::trim(dto._superTypeName);
    dto._subTypeName = util::trim(dto._subTypeName);
  }


  static void trimGeneralisations(ontologydto::DomainDTO& domain) {
    typedef std::set <ontologydto::GeneralisationDTO*>::iterator IterType;  
    for (IterType iter = domain._generalisations.begin(); iter != domain._generalisations.end(); iter++) {
      trim(**iter);
    }
  }


  static void trim(ontologydto::AssociationDTO& association) {
    association._name = util::trim(association._name);

    association._fromEnd->_typeName = util::trim(association._fromEnd->_typeName);
    association._toEnd->_typeName = util::trim(association._toEnd->_typeName);

    association._fromEnd->_multiplicity = util::trim(association._fromEnd->_multiplicity);
    association._toEnd->_multiplicity = util::trim(association._toEnd->_multiplicity);
  }
  

  static void trimAssociations(ontologydto::DomainDTO& domain) {
    typedef std::set <ontologydto::AssociationDTO*>::iterator IterType;  
    for (IterType iter = domain._associations.begin(); iter != domain._associations.end(); iter++) {
      trim(**iter);
    }
  }


  static void trimTypes(ontologydto::DomainDTO& domain) {
    typedef std::set <ontologydto::TypeDTO*>::iterator IterType;  
    for (IterType iter = domain._types.begin(); iter != domain._types.end(); iter++) {
      ontologydto::TypeDTO* dto = *iter;
      (*iter)->_name = util::trim((*iter)->_name);
    }
  }


  static void trimAll(ontologydto::DomainDTO& domain) {
    trimTypes(domain);
    trimAssociations(domain);
    trimGeneralisations(domain);
  }


  // Need to also add trim checks on strings to ensure correct matching of types to typenames
  static void propagateTypeIds(ontologydto::DomainDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    getLogger().debug("Database", "Creating id-to-type dictionary");
    std::map <std::string, int> typeDictionary;

    int domainId = dto.getId();
    getLogger().debug("Database", "Looping through type names");

    for (std::set < ontologydto::TypeDTO*>::iterator iter = dto.getTypes().begin(); iter != dto.getTypes().end(); iter++) {
      getLogger().debug("Database", "Creating scoped name for " + (*iter)->getName());
      std::string typeName = (*iter)->getName();

      if (naming::isScoped(typeName)) {
	typeDictionary[typeName] = (*iter)->getId();

      } else {
	std::string scopedName = naming::constructScopedName(domainId, typeName);

	getLogger().debug("Persistence", "Scoped name is " + scopedName);
	typeDictionary[scopedName] = (*iter)->getId();
      }
    }
    getLogger().debug("Database", "Id-to-type dictionary created");

    getLogger().debug("Database", "Obtain dependencies and related concept IDs");
    std::map <std::string, ontologydto::AssociationDTO*> associationDictionary;
    for (std::set < ontologydto::AssociationDTO*>::iterator iter = dto._associations.begin(); iter != dto._associations.end(); iter++) {
      getLogger().debug("Database", "Within dependency loop");
      std::string typeName = (*iter)->getFromEnd().getTypeName();
      int domainId = (*iter)->getFromEnd().getDomainId();
      getLogger().debug("Database", "Within dependency loop again");
      if (domainId != 0) {
      getLogger().debug("Database", "retrieveTypeId");
	int id = TypeManager::retrieveTypeId(domainId, typeName);
      getLogger().debug("Database", "costructScopedName");
	std::string scopedName = naming::constructScopedName(domainId, typeName);

	getLogger().debug("Database", "Scoped name is " + scopedName + " for id: " + util::itoa(id));
	typeDictionary[scopedName] = id;
      }
      getLogger().debug("Database", "Within dependency loop again again");
      typeName = (*iter)->getToEnd().getTypeName();
      domainId = (*iter)->getToEnd().getDomainId();
      if (domainId != 0) {
	int id = TypeManager::retrieveTypeId(domainId, typeName);
	std::string scopedName = naming::constructScopedName(domainId, typeName);
	getLogger().debug("Database", "Scoped name is " + scopedName + " for id: " + util::itoa(id));
	typeDictionary[scopedName] = id;
      }
      getLogger().debug("Database", "Within dependency loop again again again");
    }
    getLogger().debug("Database", "Obtain dependencies");

    getLogger().debug("Database", "Setting association end typeIDs using id-to-type dictionary lookup");
    for (std::set < ontologydto::AssociationDTO*>::iterator iter = dto.getAssociations().begin(); iter != dto._associations.end(); iter++) {
      ontologydto::EndDTO& fromEnd = (*iter)->getFromEnd();
      if (0 == fromEnd.getConceptId()) {
	std::string scopedName = naming::constructScopedName(fromEnd.getDomainId(), fromEnd.getTypeName());
	if (typeDictionary.count(scopedName) == 0) {
	  getLogger().debug("Database", "Nonexistent type name: " + scopedName);
	  throw "Nonexistent type name";
	} else {
	  fromEnd.getConceptId() = typeDictionary[scopedName];
	}
      }

      ontologydto::EndDTO& toEnd = (*iter)->getToEnd();
      if (0 == toEnd.getConceptId()) {
	std::string scopedName = naming::constructScopedName(toEnd.getDomainId(), toEnd.getTypeName());
	if (typeDictionary.count(scopedName) == 0) {
	  getLogger().debug("Database", "Nonexistent type name: " + scopedName);
	  throw "Nonexistent type name";
	} else {
	  toEnd.getConceptId() = typeDictionary[scopedName];
	}
      }
    }
    getLogger().debug("Database", "Association end typeIDs set");

    getLogger().debug("Database", "Setting generalisation typeIDs using id-to-type dictionary lookup");
    for (std::set < ontologydto::GeneralisationDTO*>::iterator iter = dto._generalisations.begin(); iter != dto._generalisations.end(); iter++) {
      if (0 == (*iter)->getSuperTypeId()) {
	std::string scopedName = naming::constructScopedName(domainId, (*iter)->getSuperTypeName());
	getLogger().debug("Database", "Generalisation supertype scoped name is: " + scopedName);
	if (typeDictionary.count(scopedName) == 0) {
	  getLogger().debug("Database", "Nonexistent type name: " + scopedName);
	  throw "Nonexistent type name";
	} else {
	  getLogger().debug("Database", "Generalisation supertype ID is: " + typeDictionary[scopedName]);
	  (*iter)->getSuperTypeId() = typeDictionary[scopedName];
	}
      }

      if (0 == (*iter)->getSubTypeId()) {
	std::string scopedName = naming::constructScopedName(domainId, (*iter)->getSubTypeName());
	getLogger().debug("Database", "Generalisation subtype scoped name is: " + scopedName);
	if (typeDictionary.count(scopedName) == 0) {
	  getLogger().debug("Database", "Nonexistent type name: " + scopedName);
	  throw "Nonexistent type name";
	} else {
	  getLogger().debug("Database", "Generalisation subtype ID is: " + typeDictionary[scopedName]);
	  (*iter)->getSubTypeId() = typeDictionary[scopedName];
	}
      }
    }
    getLogger().debug("Database", "Generalisation end typeIDs set");
  }


  static int persist(database::Connection& connection,
		     ontologydto::DomainDTO& domain)
    throw (database::Exception, persistence::Exception)
  {
    std::string query;
    query += "INSERT INTO Domains VALUES(NULL,'" + domain.getTitle() + "','" + domain.getDescription() + "',NULL);";

    connection.query(query);
    domain._id = connection.getInsertId();

    getLogger().debug("Persistence", "Propagating Domain IDs");
    propagateDomainIds(domain);
    getLogger().debug("Persistence", "Propagating Domain IDs");

    TypeManager::persist(connection, domain.getTypes());

    getLogger().debug("Persistence", "Propagating Type IDs");
    propagateTypeIds(domain);
    getLogger().debug("Persistence", "Type IDs propagated");

    getLogger().debug("Persistence", "Creating Associations in database");
    AssociationManager::persist(connection, domain.getAssociations());
    getLogger().debug("Persistence", "Associations created");

    getLogger().debug("Persistence", "Creating Generalisations in database");
    GeneralisationManager::persist(connection, domain.getGeneralisations());
    getLogger().debug("Persistence", "Generalisations created");

    return domain.getId();
  }


  static int persist(ontologydto::DomainDTO& domain)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    return persist(connection, domain);
  }


  static void normaliseFromEnd(ontologydto::AssociationDTO& assoc, bool isNewDomain)
  {
    ontologydto::EndDTO& end = assoc.getFromEnd();

    int domainId = end.getDomainId();
    std::string typeName = end.getTypeName();

    if (!naming::isValidName(typeName)) {
      throw "Invalid association end";
    }

    // Cannot have the scope specified for from-domains when creating a domain from scratch
    if (isNewDomain) {
      if (domainId != 0 || naming::isScoped(typeName)) {
	throw "Invalid association end";
      }
    }
  }


  static void normaliseToEnd(ontologydto::AssociationDTO& assoc)
  {
    ontologydto::EndDTO& end = assoc.getToEnd();

    int domainId = end.getDomainId();
    std::string typeName = end.getTypeName();

    getLogger().debug("Database ", "toEnd " + end.getTypeName());

    if (!naming::isValidName(typeName)) {
      getLogger().debug("Database", "Invalid type name");
      throw "Invalid association end";
    }

    getLogger().debug("Database", "Valid type name");
    if (naming::isScoped(typeName)) {

      int scopeId = naming::getScopeId(typeName);
      std::string scope = naming::getScope(typeName);
      getLogger().debug("Database", "Scoped typename with scope of: " + scope);

      // If domain Id specified differs to scope then fail
      if (domainId != 0 && scopeId != domainId) {
	getLogger().error("Database", "Nonzero domain ID differs from scoped typename scope");
	throw "Invalid association end";
      }

      // If domain Id not specified then set to scope
      if (domainId == 0) {
	getLogger().debug("Database", "Setting zero domain ID to scoped typename scope");
	end.getDomainId() = scopeId;
      }

      // Revert any scoped type name to unscoped type name for to-end
      end._typeName = naming::getUnscopedName(typeName);
      getLogger().debug("Database ", "New unscoped toEnd typename is " + end._typeName);
    }
  }


  static void normaliseTypes(ontologydto::DomainDTO& domain)
  {
  }


  static void normaliseGeneralisations(ontologydto::DomainDTO& domain)
  {
  }


  static void normaliseAssociations(ontologydto::DomainDTO& domain)
  {
    typedef std::set <ontologydto::AssociationDTO*>::iterator IterType;  
    for (IterType iter = domain._associations.begin(); iter != domain._associations.end(); iter++) {
      normaliseFromEnd(**iter, true);
      normaliseToEnd(**iter);
    }
  }


  static void normalise(ontologydto::DomainDTO& domain) throw (persistence::Exception)
  {
    trimAll(domain);

    normaliseTypes(domain);
    normaliseAssociations(domain);
    normaliseGeneralisations(domain);
  }


  static void prepare(ontologydto::DomainDTO& domain) throw (persistence::Exception)
  {

  }


  static void check(ontologydto::DomainDTO& domain) throw (persistence::Exception)
  {
    // Obtain the domain IDs that this domain is dependent upon


    // Obtain those domains from the backend


    // Attempt to construct the inmemory model to detect inconsistencies

    
  }


  /**
   * TODO: Documentation
   *
   */
  static int create(ontologydto::DomainDTO& domain)
    throw (database::Exception, persistence::Exception)
  {
    normalise(domain);
    check(domain);

    return persist(domain);
  }


  /**
   * TODO: Documentation
   *
   */
  static bool find(int id)
  {
    database::Connection connection;

    std::string query = "SELECT * FROM Domains WHERE id = " + util::itoa(id);
    connection.query(query);

    database::Results result(connection);
    return result.getNumberRows() == 1;
  }

  static void retrieve(database::Connection& connection,
		       int& domainId,
		       ontologydto::DomainDTO& domain)
    throw (database::Exception, persistence::Exception)
  {
    std::string query = "SELECT * FROM Domains WHERE id = " + util::itoa(domainId);
    connection.query(query);

    database::Results results(connection);

    if (results.getNumberRows() == 1) {
      results.next();

      domain.getId() = atoi(results.getElement(0));
      domain.getTitle() = results.getElement(1);
      domain.getDescription() = results.getElement(2);

      TypeManager::retrieve(domainId, domain.getTypes());
      AssociationManager::retrieveAssociationsFromDomain(domainId, domain.getAssociations());
      GeneralisationManager::retrieveFromDomain(domainId, domain.getGeneralisations());
    }
  }

  static void retrieve(int id, ontologydto::DomainDTO& object)
    throw (database::Exception, persistence::Exception)
  {
    object.clear();

    database::Connection connection;
    connection.query("USE Protolayer;");
    retrieve(connection, id, object);
  }

  /**
   * TODO: Documentation
   *
   */
  static void remove(int domainId)
    throw (database::Exception, persistence::Exception)
  {
    // Retrieve the domain
    ontologydto::DomainDTO domain;
    retrieve(domainId, domain);

    // Check for dependencies upon the domain requested for removal
    std::set <ontologydto::AssociationDTO*> dependees;
    AssociationManager::retrieveAssociationsToDomain(domainId, dependees);
    if (dependees.size() > 0) {
      getLogger().debug("Persistence", "Dependencies upon requested domain " + util::itoa(domainId) + " prevent removal.");
      throw persistence::Exception("Dependencies upon requested domain " + util::itoa(domainId) + " prevent removal.");
    }

    // Remove associations and generalisations and types in that order
    AssociationManager::remove(domain.getAssociations());
    GeneralisationManager::remove(domain.getGeneralisations());
    TypeManager::remove(domain.getTypes());

    // Remove the actual domain
    database::Connection connection;
    connection.query("USE Protolayer;");
    std::string query = "DELETE FROM Domains WHERE id = " + util::itoa(domainId);
    connection.query(query);
  }

};



typedef Manager <ontologydto::DomainDTO> DomainManager;


}


}


#endif // PROTOLAYER_PERSISTENCE_DOMAINMANAGER_H
