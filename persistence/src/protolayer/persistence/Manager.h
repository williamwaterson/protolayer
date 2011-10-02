#ifndef PROTOLAYER_PERSISTENCE_MANAGER_H
#define PROTOLAYER_PERSISTENCE_MANAGER_H

#include <string>
#include <set>

#include <protolayer/protolayer-iostream.h>
#include <protolayer/protolayer-database.h>
#include "Exception.h"


namespace protolayer
{

namespace persistence
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
template <class T> class Manager
{
 public:
  /**
   * TODO: Documentation
   *
   */
  static void setup() throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static int create(T& object) throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static int persist(database::Connection& connection, T& dto) throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static void persist(database::Connection& connection, std::set <T*>& collection) throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static bool find(int id) throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static void retrieve(int id, T& object) throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static void remove(int id) throw (database::Exception, persistence::Exception);

  /**
   * TODO: Documentation
   *
   */
  static void remove(std::set <T*>& collection) throw (database::Exception, persistence::Exception);

};


}


}


#endif // PROTOLAYER_PERSISTENCE_MANAGER_H
