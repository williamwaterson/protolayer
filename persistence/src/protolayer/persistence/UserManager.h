#ifndef PROTOLAYER_PERSISTENCE_USERMANAGER_H
#define PROTOLAYER_PERSISTENCE_USERMANAGER_H

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
template <> class Manager <dto::UserDTO>
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
      connection.query("CREATE TABLE Users(id INT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY(id), username VARCHAR(255) NOT NULL, password VARCHAR(255) NOT NULL, email V\
ARCHAR(255))");

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
		      std::set <dto::UserDTO*>& types)
  {
    typedef std::set <dto::UserDTO*>::iterator IterType;
    for (IterType iter = types.begin(); iter != types.end(); iter++) {
      persist(connection, **iter);
    }
  }

  /**
   * TODO: Documentation
   *
   */
  static int persist(database::Connection& connection,
		     dto::UserDTO& dto) throw (database::Exception)
  {
    std::string query;
    query += "INSERT INTO Users VALUES(NULL, '" + dto.getUsername() + "','" + dto.getPassword() + "','" + dto.getEmail() + "');";

    connection.query(query);
    dto.getId() = connection.getInsertId();

    return dto.getId();
  }

  /**
   * TODO: Documentation
   *
   */
  static int create(dto::UserDTO& dto) throw (persistence::Exception, database::Exception)
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
    connection.query("SELECT * FROM Users WHERE id = " + util::itoa(id));

    database::Results results(connection);

    return results.getNumberRows() == 1;
  }

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(int id, dto::UserDTO& object) throw (persistence::Exception)
  {
    database::Connection connection;

    connection.query("USE Protolayer;");
    connection.query("SELECT * FROM Users WHERE id = " + util::itoa(id));

    database::Results results(connection);

    if (results.getNumberRows() == 1) {
      results.next();

      object.getId() = id;
      object.getUsername() = results.getElement(1);
      object.getPassword() = results.getElement(2);
      object.getEmail() = results.getElement(3);

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
    std::string query("DELETE FROM Users WHERE id = ");
    query += util::itoa(id);

    connection.query(query);
  }

};


typedef Manager <dto::UserDTO> UserManager;


}


}


#endif // PROTOLAYER_PERSISTENCE_USERMANAGER_H
