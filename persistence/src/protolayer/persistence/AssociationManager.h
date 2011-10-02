#ifndef PROTOLAYER_PERSISTENCE_ASSOCIATIONMANAGER_H
#define PROTOLAYER_PERSISTENCE_ASSOCIATIONMANAGER_H

#include <string>
#include <protolayer/protolayer-database.h>
#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include "Exception.h"

#include "Manager.h"
#include "EndManager.h"


namespace protolayer
{

namespace persistence
{

/**
 *
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
template <> class Manager <ontologydto::AssociationDTO>
{
 public:
  /**
   * TODO: Documentation
   *
   */
  static void setup() throw (database::Exception, persistence::Exception)
  {
    try {
      database::Connection connection;
      connection.query("USE Protolayer;");
      connection.query("CREATE TABLE Associations(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), fromEnd INT UNSIGNED NOT NULL, toEnd INT UNSIGNED NOT NULL)");
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

  static void persist(database::Connection& connection, std::set <ontologydto::AssociationDTO*>& assocs)
    throw (database::Exception, persistence::Exception)
  {
    typedef std::set <ontologydto::AssociationDTO*>::iterator IterType;
    for (IterType iter = assocs.begin(); iter != assocs.end(); iter++) {
      persist(connection, **iter);
    }
  }

  static int persist(database::Connection& connection,
		     ontologydto::AssociationDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    Manager <ontologydto::EndDTO>::persist(connection, dto.getFromEnd());
    Manager <ontologydto::EndDTO>::persist(connection, dto.getToEnd());

    std::string fromEndId = util::itoa(dto.getFromEnd().getId());
    std::string toEndId = util::itoa(dto.getToEnd().getId());

    connection.query("INSERT INTO Associations VALUES(NULL,'" + fromEndId + "','" + toEndId + "');");
  
    dto.getId() = connection.getInsertId();

    return dto.getId();
  }


  static int create(ontologydto::AssociationDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    return persist(connection, dto);
  }

  /**
   * TODO: Documentation
   *
   */
  static bool find(int id) throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Associations WHERE id = " + util::itoa(id);
    connection.query(query);

    database::Results results(connection);
    results.getNumberRows() == 1;
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(database::Connection& connection,
		       int id,
		       ontologydto::AssociationDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    std::string query = "SELECT * FROM Associations WHERE id = " + util::itoa(id);
    connection.query(query);

    database::Results result(connection);

    if (result.getNumberRows() == 1) {
      result.next();

      dto.getId() = id;
      int fromEndId = atoi(result.getElement(1));
      int toEndId = atoi(result.getElement(2));

      Manager <ontologydto::EndDTO>::retrieve(connection, fromEndId, dto.getFromEnd());
      Manager <ontologydto::EndDTO>::retrieve(connection, toEndId, dto.getToEnd());
    }
  }

  static void retrieveAssociationsFromDomain(int& domainId,
					     std::set <ontologydto::AssociationDTO*>& associations)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Concepts WHERE domain = " + util::itoa(domainId);
    connection.query(query);

    database::Results conceptResults(connection);

    std::set <int> conceptIds;
    std::set <int> endIds;
    for (int i = 0; i < conceptResults.getNumberRows(); i++) {
      conceptResults.next();
      int conceptId = atoi(conceptResults.getElement(0));
      query = "SELECT * FROM Ends WHERE concept = " + util::itoa(conceptId);
      connection.query(query);

      database::Results endResults(connection);
      for (int i = 0; i < endResults.getNumberRows(); i++) {
	endResults.next();
	int endId = atoi(endResults.getElement(0));
	endIds.insert(endId);
      }
    }

    std::set <int> assocIds;
    typedef set <int>::iterator IterType;
    for (IterType iter = endIds.begin(); iter != endIds.end(); iter++) {
      int endId = *iter;
      query = "SELECT * FROM Associations WHERE fromEnd = " + util::itoa(endId);
      connection.query(query);

      database::Results assocResults(connection);
      for (int i = 0; i < assocResults.getNumberRows(); i++) {
	assocResults.next();
	int assocId = atoi(assocResults.getElement(0));
	assocIds.insert(assocId);
      }
    }

    for (IterType iter = assocIds.begin(); iter != assocIds.end(); iter++) {
      int assocId = *iter;
      ontologydto::AssociationDTO* created = new ontologydto::AssociationDTO();
      retrieve(assocId, *created);
      associations.insert(created);
    }
  }


  static void retrieveInternalAssociationsToDomain(int& domainId,
						   std::set <ontologydto::AssociationDTO*>& associations)
    throw (database::Exception, persistence::Exception)
  {
      database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Concepts WHERE domain = " + util::itoa(domainId);
    connection.query(query);

    database::Results conceptResults(connection);

    std::set <int> conceptIds;
    std::set <int> endIds;
    for (int i = 0; i < conceptResults.getNumberRows(); i++) {
      conceptResults.next();
      int conceptId = atoi(conceptResults.getElement(0));
      query = "SELECT * FROM Ends WHERE concept = " + util::itoa(conceptId);
      connection.query(query);

      database::Results endResults(connection);
      for (int i = 0; i < endResults.getNumberRows(); i++) {
	endResults.next();
	int endId = atoi(endResults.getElement(0));
	endIds.insert(endId);
      }
    }

    typedef set <int>::iterator IterType;

    std::set <int> assocIds;
    for (IterType iter = endIds.begin(); iter != endIds.end(); iter++) {
      int endId = *iter;
      query = "SELECT * FROM Associations WHERE toEnd = " + util::itoa(endId);
      connection.query(query);

      database::Results assocResults(connection);
      for (int i = 0; i < assocResults.getNumberRows(); i++) {
	assocResults.next();
	int assocId = atoi(assocResults.getElement(0));

	// Include only associations amongst concepts internal to the domain
	ontologydto::AssociationDTO* created = new ontologydto::AssociationDTO();
	retrieve(assocId, *created);
	if (created->getFromEnd().getDomainId() == domainId &&
	    created->getToEnd().getDomainId() == domainId) {
	  associations.insert(created);
	} else {
	  delete created;
	}
      }
    }
  }

  static void retrieveAssociationsToDomain(int& domainId,
					   std::set <ontologydto::AssociationDTO*>& associations)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT id FROM Concepts WHERE domain = " + util::itoa(domainId);
    connection.query(query);

    database::Results conceptResults(connection);

    std::set <int> conceptIds;
    std::set <int> endIds;
    for (int i = 0; i < conceptResults.getNumberRows(); i++) {
      conceptResults.next();

      int conceptId = atoi(conceptResults.getElement(0));
      query = "SELECT id FROM Ends WHERE concept = " + util::itoa(conceptId);
      connection.query(query);

      database::Results endResults(connection);
      for (int i = 0; i < endResults.getNumberRows(); i++) {
	endResults.next();
	int endId = atoi(endResults.getElement(0));
	endIds.insert(endId);
      }
    }

    typedef set <int>::iterator IterType;

    std::set <int> assocIds;
    for (IterType iter = endIds.begin(); iter != endIds.end(); iter++) {
      int endId = *iter;
      query = "SELECT id, fromEnd FROM Associations WHERE toEnd = " + util::itoa(endId);
      connection.query(query);

      database::Results assocResults(connection);
      if (assocResults.getNumberRows() > 0) {
	assocResults.next();
	int assocId = atoi(assocResults.getElement(0));
	int fromEndId = atoi(assocResults.getElement(1));

	query = "SELECT concept FROM Ends WHERE id = " + util::itoa(fromEndId);
	connection.query(query);

	database::Results checkResults(connection);
	checkResults.next();
	std::string fromConceptId(checkResults.getElement(0));

	query = "SELECT domain FROM Concepts WHERE id = " + fromConceptId;
	connection.query(query);

	database::Results fromConceptResults(connection);
	fromConceptResults.next();
	int fromDomainId = atoi(fromConceptResults.getElement(0));

	if (fromDomainId != domainId) {
	  ontologydto::AssociationDTO* created = new ontologydto::AssociationDTO();
	  retrieve(assocId, *created);
	  associations.insert(created);
	}
      }
    }
  }

  static void retrieveAssociationsFromConcept(int& conceptId,
					      std::set <ontologydto::AssociationDTO*>& associations)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Ends WHERE concept = " + util::itoa(conceptId);
    connection.query(query);

    std::set <int> assocIds;
    database::Results endResults(connection);
    for (int i = 0; i < endResults.getNumberRows(); i++) {
      endResults.next();
      int endId = atoi(endResults.getElement(0));
      query = "SELECT * FROM Associations WHERE fromEnd = " + util::itoa(endId);
      connection.query(query);

      database::Results assocResults(connection);
      for (int i = 0; i < assocResults.getNumberRows(); i++) {
	assocResults.next();
	int assocId = atoi(assocResults.getElement(0));
	assocIds.insert(assocId);
      }
    }

    typedef std::set <int>::iterator IterType;
    for (IterType iter = assocIds.begin(); iter != assocIds.end(); iter++) {
      int assocId = *iter;
      ontologydto::AssociationDTO* created = new ontologydto::AssociationDTO();
      retrieve(assocId, *created);
      associations.insert(created);
    }
  }

  static void retrieveAssociationsToConcept(int& conceptId,
					    std::set <ontologydto::AssociationDTO*>& associations)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Ends WHERE concept = " + util::itoa(conceptId);
    connection.query(query);

    database::Results endResults(connection);

    std::set <int> assocIds;
    for (int i = 0; i < endResults.getNumberRows(); i++) {
      endResults.next();
      int endId = atoi(endResults.getElement(0));
      query = "SELECT * FROM Associations WHERE toEnd = " + util::itoa(endId);
      connection.query(query);

      database::Results assocResults(connection);
      for (int i = 0; i < assocResults.getNumberRows(); i++) {
	assocResults.next();
	int assocId = atoi(assocResults.getElement(0));
	assocIds.insert(assocId);
      }
    }

    typedef std::set <int>::iterator IterType;
    for (IterType iter = assocIds.begin(); iter != assocIds.end(); iter++) {
      int assocId = *iter;
      ontologydto::AssociationDTO* created = new ontologydto::AssociationDTO();
      retrieve(assocId, *created);
      associations.insert(created);
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(int id, ontologydto::AssociationDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    return retrieve(connection, id, dto);
  }

  /**
   * TODO: Documentation
   *
   */
  static void remove(int id) 
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    ontologydto::AssociationDTO association;
    retrieve(id, association);

    int fromEndId = association.getFromEnd().getId();
    int toEndId = association.getToEnd().getId();

    std::string query = "DELETE FROM Associations WHERE id = " + util::itoa(id);
    connection.query(query);

    query = "DELETE FROM Ends WHERE id = " + util::itoa(fromEndId);
    connection.query(query);

    query = "DELETE FROM Ends WHERE id = " + util::itoa(toEndId);
    connection.query(query);
  }

  static void remove(std::set <ontologydto::AssociationDTO*>& assocs)
    throw (database::Exception, persistence::Exception)
  {
    typedef std::set <ontologydto::AssociationDTO*>::iterator IterType;
    for (IterType iter = assocs.begin(); iter != assocs.end(); iter++) {
      remove((*iter)->getId());
    }
  }

};


typedef Manager <ontologydto::AssociationDTO> AssociationManager;

}


}


#endif // PROTOLAYER_PERSISTENCE_ASSOCIATIONMANAGER_H
