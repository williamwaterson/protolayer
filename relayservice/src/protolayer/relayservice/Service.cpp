#include "Service.h"


namespace protolayer
{

namespace relayservice
{


  //void Service::exiterr(MYSQL& handle, int exitcode)
  //{
  //  fprintf(stderr, "%s\n", ::mysql_error(&handle));
  //  exit(exitcode);
  //}


  //void Service::executeConnect(MYSQL& handle)
  //{
  //  if(mysql_init(&handle) == NULL) {
  //    exiterr(handle, 1);
  //  }
  /*
  if (!(::mysql_real_connect(&handle, "localhost", "root", "rootpassword", NULL, 0, NULL, 0))) {
    std::cout << "Failed to connect" << std::endl;
    fprintf(stderr, "%s\n", ::mysql_error(&handle));
    exit(1);
  }

  if (mysql_query(&handle, "USE Protolayer;") != 0) {
    std::cout << "Failed to select Protolayer database" << std::endl;
    exiterr(handle, 1);
  }
  */
  //}


  //void Service::executeQuery(MYSQL& handle, std::string& query)
  //{
  /*
  if (mysql_query(&handle, query.c_str()) != 0) {
    std::cout << "INFO: Failed to apply query" << std::endl;
    fprintf(stderr, "%s\n", ::mysql_error(&handle));
  }
  */
  //}


Service::Service(int port) : server::Service("Relayservice")
{
  /*
  _port = port;
  _runFlag = false;

  pthread_mutexattr_init(&_mutexAttributes);
  pthread_mutex_init(&_mutex, &_mutexAttributes);
  */
}


Service::Service(xercesc::DOMElement& element) throw (server::Exception) :
  server::Service("Relayservice")
{
  /*
  _port = xml::extractAttribute("edit-port", element, DEFAULT_EDIT_PORT);
  _runFlag = false;

  pthread_mutexattr_init(&_mutexAttributes);
  pthread_mutex_init(&_mutex, &_mutexAttributes);
  */
}


Service::~Service()
{
  // Still need to delete all existing addressloops in the mutex lock below

  //  pthread_mutex_lock(&_mutex);
  //  pthread_mutex_destroy(&_mutex);
  //pthread_mutexattr_destroy(&_mutexAttributes);
}


void Service::startup()
{
}


void Service::run()
{
  /*
  _runFlag = true;

  _serviceSocket = new net::ServerSocket(_port);
  _serviceSocket->listen();

  while(_runFlag) {

    net::Socket& socket = _serviceSocket->accept();
    
    int requestType = 0;

    iostream::XdrInputStream& istream = socket.getXdrInputStream();
    iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

    ostream.flush();
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

    istream.read(requestType);

    if (requestType == net::MessageProtocol::ADD_LOCATION) {
      addLocation(socket);

    } else if  (requestType == net::MessageProtocol::NEXT_LOCATION) {
      nextLocation(socket);

    } else {
      ostream.write(net::MessageProtocol::ERROR);
      ostream.flush();

    }

    socket.close();
    delete (&socket);
  }

  delete _serviceSocket;
  */
}


bool Service::isValidTechniqueId(int id)
{
  /*  MYSQL handle;
  MYSQL_RES* results;
  int numberRows;

  executeConnect(handle);

  std::string query = "SELECT * FROM Techniques WHERE id = " + util::itoa(id, 10);
  executeQuery(handle, query);

  results = mysql_store_result(&handle);

  if (results != NULL) {
    numberRows = mysql_num_rows(results);
  } else {
    mysql_free_result(results);
    mysql_close(&handle);
    throw Exception("Null pointer returned on database result set");
  }

  mysql_free_result(results);
  mysql_close(&handle);

  return numberRows == 1;
  */
  return true;
}


void Service::addLocation(net::Socket& socket)
{
  //  getLogger().debug(NAME_SERVICE, "Adding location");
  /*
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  int id;
  std::string location;

  istream.read(id);
  istream.read(location);

  util::trim(location);

  bool result = true;

  if (!isValidTechniqueId(id)) {
    result = false;

  } else {
    pthread_mutex_lock(&_mutex);
    if (_locationsDirectory.count(id) == 0) {
      _locationsDirectory[id] = new AddressLoop();
    }
    _locationsDirectory[id]->addAddress(location);
    pthread_mutex_unlock(&_mutex);
  }

  if (result) {
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

  } else {
    ostream.write(net::MessageProtocol::ERROR);
    ostream.flush();

  }
  */
  // add error handling here message send
}


void Service::nextLocation(net::Socket& socket)
{
  //  getLogger().debug(NAME_SERVICE, "Getting technique location for specified technique URN");
  /*
  iostream::XdrInputStream& istream = socket.getXdrInputStream();
  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();

  int id;
  istream.read(id);

  bool result = true;
  std::string location;
  pthread_mutex_lock(&_mutex);
  {
    if (_locationsDirectory.count(id) == 0) {
      result = false;
    }

    location = _locationsDirectory[id]->next();
  }
  pthread_mutex_unlock(&_mutex);

  if (result) {
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

    ostream.write(location);
    ostream.flush();

  } else {
    ostream.write(net::MessageProtocol::ERROR);
    ostream.flush();    

  }
  */
}


void Service::suspend()
{
}


void Service::resume()
{
}


void Service::shutdown()
{
  //  _runFlag = false;
}


}


}
