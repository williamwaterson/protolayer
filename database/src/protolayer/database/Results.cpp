#include "Results.h"


namespace protolayer
{

namespace database
{

Results::Results(Connection& connection) throw (database::Exception)
{
  /*
  logger::Logger::getSingleton().debug("Database", "Creating results");
  //  _results = ::mysql_store_result(&(connection._handle));
  logger::Logger::getSingleton().debug("Database", "Created results");
  int result = 0;
  if (_results == NULL) {
    logger::Logger::getSingleton().debug("Database", "NULL Results");
    throw Exception("NULL Results");
  } else {
    logger::Logger::getSingleton().debug("Database", "Non-NULL Results");
    //    _numberRows = ::mysql_num_rows(_results);
    logger::Logger::getSingleton().debug("Database", "rows obtained");
  }
  */
}


Results::~Results()
{
  //  ::mysql_free_result(_results);
}


int Results::getNumberRows() const
{
  return _numberRows;
}


void Results::next()
{
  //  _row = mysql_fetch_row(_results);
}


char* Results::getElement(int index)
{
  return 0;
  //  return _row[index];
}


}


}
