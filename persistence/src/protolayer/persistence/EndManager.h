#ifndef PROTOLAYER_PERSISTENCE_ENDMANAGER_H
#define PROTOLAYER_PERSISTENCE_ENDMANAGER_H

#include <string>
#include <protolayer/protolayer-database.h>
#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-ontology.h>
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
template <> class Manager <ontologydto::EndDTO>
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
      connection.query("CREATE TABLE Ends(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), label VARCHAR(255), concept INT UNSIGNED, multiplicity VARCHAR(255))");
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
  static int persist(database::Connection& connection,
		     ontologydto::EndDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    std::string conceptId = util::itoa(dto.getConceptId());

    std::string query("INSERT INTO Ends VALUES(NULL,'" + dto.getLabel() + "','" + conceptId + "','" + dto.getMultiplicity() + "');");
    connection.query(query);
 
    dto.getId() = connection.getInsertId();

    return dto.getId();
  }

  /**
   * TODO: Documentation
   *
   */
  static int create(ontologydto::EndDTO& object)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    return persist(connection, object);
  }

  /**
   * TODO: Documentation
   *
   */
  static bool find(int id) throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT * FROM Ends WHERE id = " + util::itoa(id));

    database::Results results(connection);

    return results.getNumberRows() == 1;
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(database::Connection& connection, int id, ontologydto::EndDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    connection.query("SELECT * FROM Ends WHERE id = " + util::itoa(id));
    
    database::Results results(connection);

    if (results.getNumberRows() == 1) {
      results.next();
      dto.getId() = id;
      dto.getLabel() = results.getElement(1);
      dto.getConceptId() = atoi(results.getElement(2));
      dto.getMultiplicity() = results.getElement(3);
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(int id, ontologydto::EndDTO& dto)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    connection.query("USE Protolayer;");
    retrieve(connection, id, dto);
  }

  /**
   * TODO: Documentation
   *
   */
  static void remove(int id)
    throw (database::Exception, persistence::Exception)
  {
    database::Connection connection;
    std::string query = "DELETE FROM Ends WHERE id = " + util::itoa(id);
    connection.query(query);
  }

};


typedef Manager <ontologydto::EndDTO> EndManager;


}


}


#endif // PROTOLAYER_PERSISTENCE_ENDMANAGER_H
