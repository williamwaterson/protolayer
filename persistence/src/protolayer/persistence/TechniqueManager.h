#ifndef PROTOLAYER_PERSISTENCE_TECHNIQUEMANAGER_H
#define PROTOLAYER_PERSISTENCE_TECHNIQUEMANAGER_H

#include <string>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-dto.h>
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
template <> class Manager <dto::TechniqueDTO>
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
      connection.query("CREATE TABLE Techniques(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), title VARCHAR(255), description VARCHAR(100000), concept INT UNSIGNED NOT NULL)");

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
		      std::set <dto::TechniqueDTO*>& types)
  {
    typedef std::set <dto::TechniqueDTO*>::iterator IterType;
    for (IterType iter = types.begin(); iter != types.end(); iter++) {
      persist(connection, **iter);
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static int persist(database::Connection& connection,
		     dto::TechniqueDTO& dto) throw (database::Exception)
  {
    std::string title = dto.getTitle();
    std::string conceptId = util::itoa(dto.getConceptId());

    std::string query("INSERT INTO Techniques VALUES(NULL,'" + title + "', NULL, '" + conceptId + "');");

    connection.query(query);
    dto.getId() = connection.getInsertId();

    return dto.getId();
  }

  /**
   * TODO: Documentation
   *
   */
  static int create(dto::TechniqueDTO& dto) throw (persistence::Exception, database::Exception)
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
  static bool find(int id)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT * FROM Techniques WHERE id = " + util::itoa(id));

    database::Results results(connection);

    return results.getNumberRows() == 1;
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(int id, dto::TechniqueDTO& object) throw (persistence::Exception)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT * FROM Techniques WHERE id = " + util::itoa(id));

    database::Results results(connection);

    if (results.getNumberRows() == 1) {
      results.next();

      object.getId() = id;
      object.getTitle() = results.getElement(1);
      object.getDescription() = results.getElement(2);
      object.getConceptId() = atoi(results.getElement(3));

    } else {
      throw persistence::Exception("No database entry for that record ID");
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static void remove(int id) throw (persistence::Exception)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    std::string query("DELETE FROM Techniques WHERE id = ");
    query += util::itoa(id);

    connection.query(query);
  }

};


typedef Manager <dto::TechniqueDTO> TechniqueManager;


}


}


#endif // PROTOLAYER_PERSISTENCE_MANAGER_H
