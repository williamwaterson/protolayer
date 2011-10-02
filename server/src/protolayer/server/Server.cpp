#include "Server.h"

namespace protolayer
{

namespace server
{

namespace {

void* concurrentRun(void* arg)
{
  Service* service = reinterpret_cast <Service*> (arg);
  service->run();
  pthread_exit(NULL);  
}


}


Server::Server(int port)
{
  pthread_mutexattr_init(&_adminMutexAttributes);
  pthread_mutex_init(&_adminMutex, &_adminMutexAttributes);

  _rootSocket = new net::ServerSocket(port);
}


Server::Server(xercesc::DOMElement& element) throw (Exception)
{
  pthread_mutexattr_init(&_adminMutexAttributes);
  pthread_mutex_init(&_adminMutex, &_adminMutexAttributes);

  int port = xml::extractAttribute("port", element, DEFAULT_PORT);
  _rootSocket = new net::ServerSocket(port);
}


void Server::add(Service& service)
{
  pthread_mutex_lock(&_adminMutex);
  _services.insert(&service);
  pthread_mutex_unlock(&_adminMutex);
}


void Server::runServices()
{
  pthread_mutex_lock(&_adminMutex);
  typedef std::set <Service*>::iterator IterType;
  for (IterType iter = _services.begin(); iter != _services.end(); iter++) {
    pthread_t thread;
    Service* service = *iter;
    service->startup();
    pthread_create(&thread, NULL, concurrentRun, reinterpret_cast <void*> (service));
    pthread_detach(thread);
    _threadServiceMap[thread] = service;
  }
  pthread_mutex_unlock(&_adminMutex);
}


void Server::suspendServices()
{
  pthread_mutex_lock(&_adminMutex);
  typedef std::set <Service*>::iterator IterType;
  for (IterType iter = _services.begin(); iter != _services.end(); iter++) {
    (*iter)->suspend();
  }
  pthread_mutex_unlock(&_adminMutex);
}


void Server::resumeServices()
{
  pthread_mutex_lock(&_adminMutex);
  typedef std::set <Service*>::iterator IterType;
  for (IterType iter = _services.begin(); iter != _services.end(); iter++) {
    (*iter)->resume();
  }
  pthread_mutex_unlock(&_adminMutex);
}


void Server::shutdownServices()
{
  pthread_mutex_lock(&_adminMutex);
  typedef std::set <Service*>::iterator IterType;
  for (IterType iter = _services.begin(); iter != _services.end(); iter++) {
    (*iter)->shutdown();
  }
  pthread_mutex_unlock(&_adminMutex);
}


void Server::run()
{
  runServices();

  _rootSocket->listen();

  std::string startTime = "0m:54s:18ms";

  std::string startInfo = "Protolayer Server [";
  startInfo += VERSION;
  startInfo += " Date:200209301503]";
  startInfo += " Started in ";
  startInfo += startTime;

  logger::Logger::getSingleton().info(startInfo);

  while(true) {
    net::Socket& socket = _rootSocket->accept();
    iostream::XdrInputStream& istream = socket.getXdrInputStream();
    iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();
    int requestType = 0;

    ostream.flush();
    ostream.write(net::MessageProtocol::REPLY);
    ostream.flush();

    istream.read(requestType);
    //    istream.flush();

    if (requestType == net::MessageProtocol::SUSPEND) {
      std::cout << "Suspend process" << std::endl;
      ostream.write(net::MessageProtocol::REPLY);
      ostream.flush();

      suspendServices();

    } else if (requestType == net::MessageProtocol::RESUME) {
      std::cout << "Resume process" << std::endl;
      ostream.write(net::MessageProtocol::REPLY);
      ostream.flush();

      resumeServices();

    } else if (requestType == net::MessageProtocol::SHUTDOWN) {
      std::cout << "Shutdown process" << std::endl;
      ostream.write(net::MessageProtocol::REPLY);
      ostream.flush();

      shutdownServices();

      exit(0);

    } else {
      handleError(istream, ostream);

    }

    socket.close();
  }
}


void Server::handleError(iostream::XdrInputStream& istream,
                         iostream::XdrOutputStream& ostream)
{
}


}


}
