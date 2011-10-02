#include "Service.h"


namespace protolayer
{

namespace publishingservice
{

namespace
{
  std::string PUBLISHING_SERVICE = "PublishingService";
}


Service::Service(containerservice::Service& containerService,
		 Configuration& configuration) :
  server::Service(PUBLISHING_SERVICE),
  _configuration(configuration)
{  
  _runFlag = false;

  _containerService = &containerService;
}


Service::~Service()
{
}


void Service::startup()
{
}


void Service::run()
{
  _runFlag = true;

  while(_runFlag) {
    usleep(20000000);
    getLogger().info(PUBLISHING_SERVICE, "Attempting to publish");
    _containerService->publishLocations();
  }

  getLogger().info(PUBLISHING_SERVICE, "Stopping");
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


Configuration& Service::getConfiguration()
{
  return _configuration;
}


containerservice::Service& Service::getContainerService()
{
  return *_containerService;
}


}


}
