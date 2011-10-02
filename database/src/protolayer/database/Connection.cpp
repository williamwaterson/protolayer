#include "Connection.h"


namespace protolayer
{

namespace database
{

Connection::Connection() throw (database::Exception)
{
  //  if(mysql_init(&_handle)==NULL) {
  //    std::string error("Failed to initialise database handle: ");
  // error += ::mysql_error(&_handle);
  // logger::Logger::getSingleton().debug("Database", error);
  // throw Exception(error);
  //}

  //  connect();
}


Connection::~Connection()
{
  //  ::mysql_close(&_handle);
}


void Connection::connect() throw (database::Exception)
{
  //  if (!(::mysql_real_connect(&_handle, "localhost", "root", "rootpassword", NULL, 0, NULL, 0))) {
  //    std::string error("Failed to connect: ");
  //    error += ::mysql_error(&_handle);
  //    logger::Logger::getSingleton().debug("Database", error);
  //    throw Exception(error);
  //  }
}


namespace {

pooling::Pool pool(10000);

}


void* Connection::operator new(size_t numberBytes)
{
  return pool.acquire(numberBytes);
}


void Connection::operator delete(void* object)
{
  pool.release(object);
}


int Connection::getInsertId() throw (database::Exception)
{
  //  return mysql_insert_id(&_handle);  
}


void Connection::query(const std::string& query) throw (database::Exception)
{
  /*
  if (mysql_query(&_handle, query.c_str()) != 0) {    
    std::string error("Failed to execute query: " );
    error += ::mysql_error(&_handle);
    logger::Logger::getSingleton().debug("Database", error);
    throw Exception(error);      
  }
  */
}


}


}
