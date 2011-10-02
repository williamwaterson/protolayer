#ifndef PROTOLAYER_PERSISTENCE_TYPEMANAGER_H
#define PROTOLAYER_PERSISTENCE_TYPEMANAGER_H

#include <string>
//#include <mysql/mysql.h>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontologydto.h>
#include <protolayer/protolayer-logger.h>
#include <protolayer/protolayer-database.h>
#include "Exception.h"

#include "Manager.h"


namespace protolayer
{

namespace persistence
{

/**
 *
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
template <> class Manager <ontologydto::TypeDTO>
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
      connection.query("CREATE TABLE Concepts(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), name VARCHAR(255), domain INT UNSIGNED, isLeaf BOOL, isAbstract BOOL, isSingleton BOOL)");
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
  static void persist(database::Connection& connection,
		      std::set <ontologydto::TypeDTO*>& types)
  {
    typedef std::set <ontologydto::TypeDTO*>::iterator IterType;
    for (IterType iter = types.begin(); iter != types.end(); iter++) {
      persist(connection, **iter);
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static int persist(database::Connection& connection,
		     ontologydto::TypeDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    std::string domainId = util::itoa(dto.getDomainId());

    std::string isAbstract("0");
    if (dto.isAbstract()) {
      isAbstract = "1";
    }

    std::string isLeaf("0");
    if (dto.isLeaf()) {
      isLeaf = "1";
    }

    std::string isSingleton("0");
    if (dto.isSingleton()) {
      isSingleton = "1";
    }

    std::string query("INSERT INTO Concepts VALUES(NULL,'" + dto.getName() + "','" + domainId + "','" + isLeaf + "','" + isAbstract + "','" + isSingleton + "');");
    connection.query(query);
    dto.getId() = connection.getInsertId();

    return dto.getId();
  }

  /**
   * TODO: Documentation
   *
   */
  static int create(ontologydto::TypeDTO& dto)
    throw (persistence::Exception, database::Exception)
  {
    int result = 0;

    database::Connection connection;
    connection.query("USE Protolayer;");
    result = persist(connection, dto);

    return result;
  }

  /**
   * TODO: Documentation
   *
   */
  static bool find(int domainId, std::string name)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT id FROM Concepts WHERE domain = " + util::itoa(domainId) + " AND name = '" + name + "'");

    database::Results results(connection);

    return results.getNumberRows() == 1;
  }

  static bool find(int id)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT * FROM Concepts WHERE id = " + util::itoa(id));

    database::Results results(connection);

    return results.getNumberRows() == 1;
  }

  static int retrieveTypeId(int domainId, std::string typeName)
    throw (database::Exception, persistence::Exception)
  {
    getLogger().debug("Persistence", "connect");
    database::Connection connection;
    getLogger().debug("Persistence", "construct query");

    connection.query("USE Protolayer;");
    std::string query = "SELECT id FROM Concepts WHERE domain = " + util::itoa(domainId) + " AND name = '" + typeName + "'";
    getLogger().debug("Persistence", "query");
    try {
      connection.query(query);
    } catch (database::Exception& ex) {
      getLogger().debug("Persistence", ex.getMessage());      
      exit(1);
    }
    getLogger().debug("Persistence", "after query");

    int result = 0;
    getLogger().debug("Persistence", "construct results");
    database::Results results(connection);
    getLogger().debug("Persistence", "constructed results");
    if (results.getNumberRows() == 1) {
      getLogger().debug("Persistence", "results.next() to be called");
      results.next();
      getLogger().debug("Persistence", "results.next() called");
      result = atoi(results.getElement(0));
      getLogger().debug("Persistence", "results.getElements(0) called");
    }

    return result;
  }

  static void retrieve(int& domainId,
		       std::set <ontologydto::TypeDTO*>& types) throw (database::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");

    std::string query = "SELECT * FROM Concepts WHERE domain = " + util::itoa(domainId);
    connection.query(query);

    database::Results results(connection);

    for (int i = 0; i < results.getNumberRows(); i++) {
      results.next();

      ontologydto::TypeDTO* type = new ontologydto::TypeDTO();

      type->getId() = atoi(results.getElement(0));
      type->getName() = results.getElement(1);
      type->getDomainId() = atoi(results.getElement(2));
      type->isLeaf() = atoi(results.getElement(3));
      type->isAbstract() = atoi(results.getElement(4));
      type->isSingleton() = atoi(results.getElement(5));

      types.insert(type);
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(int id, ontologydto::TypeDTO& object)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT * FROM Concepts WHERE id = " + util::itoa(id));

    database::Results results(connection);

    if (results.getNumberRows() == 1) {
      results.next();

      object.getId() = id;
      object.getName() = results.getElement(1);
      object.getDomainId() = atoi(results.getElement(2));
      object.isLeaf() = atoi(results.getElement(3));
      object.isAbstract() = atoi(results.getElement(4));
      object.isSingleton() = atoi(results.getElement(5));

    } else {
      throw persistence::Exception("No database entry for that record ID");
    }
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

    std::string query("DELETE FROM Concepts WHERE id = ");
    query += util::itoa(id);

    connection.query(query);
  }

  static void remove(std::set <ontologydto::TypeDTO*>& types)
    throw (database::Exception, persistence::Exception)
  {
    typedef std::set <ontologydto::TypeDTO*>::iterator IterType;
    for (IterType iter = types.begin(); iter != types.end(); iter++) {
      remove((*iter)->getId());
    }
  }

};


typedef Manager <ontologydto::TypeDTO> TypeManager;


}


}


#endif // PROTOLAYER_PERSISTENCE_MANAGER_H
