#ifndef PROTOLAYER_PERSISTENCE_GENERALISATIONMANAGER_H
#define PROTOLAYER_PERSISTENCE_GENERALISATIONMANAGER_H

#include <string>
#include <protolayer/protolayer-database.h>
#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
#include "Exception.h"

#include "Manager.h"
#include "TypeManager.h"


namespace protolayer
{

namespace persistence
{

/**
 *
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
template <> class Manager <ontologydto::GeneralisationDTO>
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
      connection.query("CREATE TABLE Generalisations(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), superType INT UNSIGNED NOT NULL, subType INT UNSIGNED NOT NULL)");
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

  static void persist(database::Connection& connection,
		      std::set <ontologydto::GeneralisationDTO*>& generalisations)
    throw (database::Exception, persistence::Exception)
  {
    typedef std::set <ontologydto::GeneralisationDTO*>::iterator IterType;
    for (IterType iter = generalisations.begin(); iter != generalisations.end(); iter++) {
      persist(connection, **iter);
    }
  }

  static int persist(database::Connection& connection,
		     ontologydto::GeneralisationDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    std::string superTypeId = util::itoa(dto.getSuperTypeId());
    std::string subTypeId = util::itoa(dto.getSubTypeId());

    std::string query("INSERT INTO Generalisations VALUES(NULL,'" + superTypeId + "','" + subTypeId + "');");
    connection.query(query);

    dto.getId() = connection.getInsertId();

    return dto.getId();
  }

  /**
   * TODO: Documentation
   *
   */
  static int create(ontologydto::GeneralisationDTO& object)
    throw (persistence::Exception, database::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    return persist(connection, object);
  }

  /**
   * TODO: Documentation
   *
   */
  static bool find(int id)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;

    std::string query = "SELECT * FROM Generalisations WHERE id = " + util::itoa(id);
    connection.query(query);

    database::Results results(connection);
    return results.getNumberRows() == 1;
  }

  static void retrieve(database::Connection& connection, int id, ontologydto::GeneralisationDTO& object)
    throw (database::Exception, persistence::Exception)
  {
    std::string query = "SELECT * FROM Generalisations WHERE id = " + util::itoa(id);
    connection.query(query);

    database::Results results(connection);    
    if (results.getNumberRows() != 1) {
      throw persistence::Exception("No results matching requested generalisation ID");

    } else {
      results.next();

      object.getId() = atoi(results.getElement(0));
      object.getSuperTypeId() = atoi(results.getElement(1));
      object.getSubTypeId() = atoi(results.getElement(2));

      std::string superTypeQuery = "SELECT * FROM Concepts WHERE id = " + util::itoa(object.getSuperTypeId());
      connection.query(superTypeQuery);

      database::Results superResults(connection);
      superResults.next();
      object._superTypeName = superResults.getElement(1);
      object._superTypeDomainId = atoi(superResults.getElement(2));

      std::string subTypeQuery = "SELECT * FROM Concepts WHERE id = " + util::itoa(object.getSubTypeId());
      connection.query(subTypeQuery);

      database::Results subResults(connection);
      subResults.next();
      object._subTypeName = subResults.getElement(1);
      object._subTypeDomainId = atoi(subResults.getElement(2));
    }
  }

  static void retrieveFromDomain(int& domainId,
				 std::set <ontologydto::GeneralisationDTO*>& generalisations)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Concepts WHERE domain = " + util::itoa(domainId);
    connection.query(query);

    database::Results conceptResults(connection);

    std::set <int> genIds;
    for (int i = 0; i < conceptResults.getNumberRows(); i++) {
      conceptResults.next();
      int conceptId = atoi(conceptResults.getElement(0));

      query = "SELECT * FROM Generalisations WHERE superType = " + util::itoa(conceptId);      
      connection.query(query);

      database::Results firstGenResults(connection);
      for (int i = 0; i < firstGenResults.getNumberRows(); i++) {
	firstGenResults.next();
	int genId = atoi(firstGenResults.getElement(0));
	genIds.insert(genId);
      }

      query = "SELECT * FROM Generalisations WHERE subType = " + util::itoa(conceptId);      
      connection.query(query);

      database::Results secondGenResults(connection);
      for (int i = 0; i < secondGenResults.getNumberRows(); i++) {
	secondGenResults.next();
	int genId = atoi(secondGenResults.getElement(0));
	genIds.insert(genId);
      }
    }

    typedef set <int>::iterator IterType;
    for (IterType iter = genIds.begin(); iter != genIds.end(); iter++) {
      int genId = *iter;
      ontologydto::GeneralisationDTO* created = new ontologydto::GeneralisationDTO();
      retrieve(genId, *created);
      generalisations.insert(created);
    }
  }

  static void retrieve(int id, ontologydto::GeneralisationDTO& object)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    retrieve(connection, id, object);
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

    std::string query = "DELETE FROM Generalisations WHERE id = " + util::itoa(id);
    connection.query(query);
  }

  /**
   * TODO: Documentation
   *
   */
  static void remove(std::set <ontologydto::GeneralisationDTO*>& generalisations)
    throw (database::Exception, persistence::Exception)
  {
    typedef std::set <ontologydto::GeneralisationDTO*>::iterator IterType;
    for (IterType iter = generalisations.begin(); iter != generalisations.end(); iter++) {
      remove((*iter)->getId());
    }
  }

};



typedef Manager <ontologydto::GeneralisationDTO> GeneralisationManager;


}


}


#endif // PROTOLAYER_PERSISTENCE_GENERALISATIONMANAGER_H
