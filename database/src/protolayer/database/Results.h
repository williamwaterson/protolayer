#ifndef PROTOLAYER_DATABASE_RESULTS_H
#define PROTOLAYER_DATABASE_RESULTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
//#include <mysql/mysql.h>

#include "Connection.h"
#include "Exception.h"

#include "protolayer/protolayer-logger.h"


namespace protolayer
{

namespace database
{

class Results
{
 private:
  /** TODO: Documentation */
  int _numberRows;

  /** TODO: Documentation */
  //  MYSQL_RES* _results;

  /** TODO: Documentation */
  //  MYSQL_ROW _row;

 public:
  /**
   * TODO: Documentation
   *
   */
  Results(Connection& connection) throw (database::Exception);

  /**
   * TODO: Documentation
   *
   */
  ~Results();

  /**
   * TODO: Documentation
   *
   */
  int getNumberRows() const;

  /**
   * TODO: Documentation
   *
   */
  void next();

  /**
   * TODO: Documentation
   *
   */
  char* getElement(int index);

private:
  /**
   * TODO: Documentation
   *
   */
  void connect() throw (database::Exception);

};


}


}


#endif // PROTOLAYER_DATABASE_RESULTS_H
