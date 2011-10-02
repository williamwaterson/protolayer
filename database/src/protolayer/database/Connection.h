#ifndef PROTOLAYER_DATABASE_CONNECTION_H
#define PROTOLAYER_DATABASE_CONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
//#include <mysql/mysql.h>

#include "protolayer/protolayer-logger.h"
#include "protolayer/protolayer-pooling.h"
#include "Exception.h"


namespace protolayer
{

namespace database
{

// Forward declarations
class Results;


class Connection
{
  /** Friends */
  friend class Results;

 private:
  /** TODO: Documentation */
  //  MYSQL _handle;

 public:
  /**
   * TODO: Documentation
   *
   */
  Connection() throw (database::Exception);

  /**
   * TODO: Documentation
   *
   */
  ~Connection();

  /**
   * TODO: Documentation
   * <p>
   */
  void* operator new(size_t numberBytes);

  /**
   * TODO: Documentation
   * <p>
   */
  void operator delete(void* object);

  /**
   * TODO: Documentation
   *
   */
  void query(const std::string& query) throw (database::Exception);

  /**
   * TODO: Documentation
   *
   */
  int getInsertId() throw (database::Exception);

private:
  /**
   * TODO: Documentation
   *
   */
  void connect() throw (database::Exception);

};


}


}


#endif // PROTOLAYER_DATABASE_CONNECTION_H
