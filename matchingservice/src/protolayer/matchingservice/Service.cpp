#include "Service.h"

namespace protolayer
{

namespace matchingservice
{

Service::Service(int port) :
  server::Service("MatchingService")
{
  pthread_mutexattr_init(&_mutexattr);
  pthread_mutex_init(&_mutex, &_mutexattr);

  _port = port;
  _runFlag = false;
}


Service::Service(xercesc::DOMElement& element) throw (Exception) :
  server::Service("MatchingService")
{
  pthread_mutexattr_init(&_mutexattr);
  pthread_mutex_init(&_mutex, &_mutexattr);

  _port = xml::extractAttribute("port", element, DEFAULT_EDIT_PORT);
  _runFlag = false;
}


void Service::startup()
{
}


void Service::run()
{
  _runFlag = true;

  _serviceSocket = new net::ServerSocket(_port);
  _serviceSocket->listen();

  while(_runFlag) {

    net::Socket& socket = _serviceSocket->accept();
    iostream::XdrInputStream& istream = socket.getXdrInputStream();
    iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();
    int requestType = 0;

    ostream.flush();
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

    istream.read(requestType);
    //    istream.flush();

    if  (requestType == net::MessageProtocol::ADDADDRESS) {
      addAddress(istream, ostream);

    } else if  (requestType == net::MessageProtocol::REMOVEADDRESS) {
      removeAddress(istream, ostream);

    } else if  (requestType == net::MessageProtocol::GETAVAILABLEADDRESS) {
      getNextAddress(istream, ostream);

    } else {
      handleError(istream, ostream);

    }

    socket.close();
  }

  delete _serviceSocket;

}


void Service::suspend()
{
}


void Service::resume()
{
}


void Service::shutdown()
{
  _runFlag = false;
}


void Service::addAddress(iostream::XdrInputStream& istream,
                         iostream::XdrOutputStream& ostream)
{
  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();

  // Extract the name and address
  std::string name;
  istream.read(name);
  //  istream.flush();

  std::string address;
  istream.read(address);
  //  istream.flush();

  addAddress(name, address);
}


void Service::addAddress(const std::string& name,
                         const std::string& address)
{
  pthread_mutex_lock(&_mutex);

  // Insert the address for the name, creating a new AddressLoop if required
  IteratorType iter = _directory.find(name);
  if (iter == _directory.end()) {
    typedef std::map <std::string, AddressLoop*>::value_type PairType;
    AddressLoop* loop = new AddressLoop(address);
    _directory.insert(PairType(name, loop));

  } else {
    (_directory[name])->addAddress(address);

  }

  pthread_mutex_unlock(&_mutex);
}


Service::~Service()
{
  pthread_mutex_lock(&_mutex);  
  pthread_mutex_destroy(&_mutex);
  pthread_mutexattr_destroy(&_mutexattr);
}


void Service::removeAddress(iostream::XdrInputStream& istream,
                            iostream::XdrOutputStream& ostream)
{
  ostream.write(net::MessageProtocol::REPLY);
  ostream.flush();

  std::string name;
  istream.read(name);
  //  istream.flush();

  std::string address;
  istream.read(address);
  //  istream.flush();

  removeAddress(name, address);
}


void Service::removeAddress(const std::string& name,
                            const std::string& address)
{
  pthread_mutex_lock(&_mutex);

  IteratorType iter = _directory.find(name);
  if (iter != _directory.end()) {
    AddressLoop* loop = _directory[name];
    loop->removeAddress(address);
    if (loop->isEmpty()){
      _directory.erase(name);
      delete loop;
    }
  }

  pthread_mutex_unlock(&_mutex);
}


bool Service::getNextAddress(const std::string& name,
                             std::string& result) const
{
  pthread_mutex_lock(&_mutex);

  bool flag = false;
  ConstIteratorType iter = _directory.find(name);
  if (iter != _directory.end()) {
    iter->second->next(result);
    flag = true;
  }

  pthread_mutex_unlock(&_mutex);

  return flag;
}


void Service::getNextAddress(iostream::XdrInputStream& istream,
                             iostream::XdrOutputStream& ostream) const
{
  // Extract the name and address
  std::string name;
  istream.read(name);
  //  istream.flush();

  pthread_mutex_lock(&_mutex);

  // Obtain the next available end point if possible
  ConstIteratorType iter = _directory.find(name);
  if (iter != _directory.end()) {
    std::string address;
    iter->second->next(address);

    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

    ostream.write(address);
    ostream.flush();

  } else {
    pthread_mutex_unlock(&_mutex);

    handleError(istream, ostream);

  }

  pthread_mutex_unlock(&_mutex);
}


void Service::handleError(iostream::XdrInputStream& istream,
                          iostream::XdrOutputStream& ostream) const
{
  ostream.write(net::MessageProtocol::ERROR);
  ostream.flush();
}


}


}
