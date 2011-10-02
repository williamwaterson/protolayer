#ifndef PROTOLAYER_COMPILESERVICE_SERVICE_H
#define PROTOLAYER_COMPILESERVICE_SERVICE_H

#include <map>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>

#include <sys/stat.h>
#include <dirent.h>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/util/XMLChar.hpp>
#include <xercesc/util/XMLString.hpp>

#include <protolayer/protolayer.h>
#include <protolayer/protolayer-server.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-containerservice.h>
#include <protolayer/protolayer-util.h>

#include "Configuration.h"
#include "Project.h"


namespace protolayer
{

namespace compileservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Service : public server::Service
{
private:
  /** TODO: Documentation */
  bool _runFlag;

  /** TODO: Documentation */
  std::string _homePath;

  /** TODO: Documentation */
  std::string _sourcePath;

  /** TODO: Documentation */
  std::string _buildPath;

  /** TODO: Documentation */
  std::string _deployPath;

  /** TODO: Documentation */
  DIR* _sourceDir;

  /** TODO: Documentation */
  DIR* _buildDir;

  /** TODO: Documentation */
  DIR* _deployDir;

  /** TODO: Documentation */
  std::map <std::string, Project*> _projects;

  /** TODO: Documentation */
  std::map <std::string, Project*> _deployedProjects;

  /** TODO: Documentation */
  protolayer::containerservice::Service& _containerService;

public:
  /**
   * TODO: Documentation
   *
   */
  Service(protolayer::containerservice::Service& service,
          Configuration& configuration);

  /**
   * TODO: Documentation
   *
   */
  Service(protolayer::containerservice::Service& service,
          xercesc::DOMElement& element) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  virtual ~Service();

  /**
   * TODO: Documentation
   *
   */
  void startup();

  /**
   * TODO: Documentation
   *
   */
  void run();

  /**
   * TODO: Documentation
   *
   */
  void suspend();

  /**
   * TODO: Documentation
   *
   */
  void resume();

  /**
   * TODO: Documentation
   *
   */
  void shutdown();

private:
  /**
   * TODO: Documentation
   *
   */
  Service(const Service& service);

  /**
   * TODO: Documentation
   *
   */
  Service operator=(const Service& service);

  /**
   * TODO: Documentation
   *
   */
  void walkDirectory(const char* path);

  /**
   * TODO: Documentation
   *
   */
  bool doesDirectoryExist(const char* name);

  /**
   * TODO: Documentation
   *
   */
  bool isDirectory(char* entryName);

  /**
   * TODO: Documentation
   *
   */
  bool isFile(char* entryName);

  /**
   * TODO: Documentation
   *
   */
  void performStartupSequence();

  /**
   * TODO: Documentation
   *
   */
  void performShutdownSequence();

  /**
   * TODO: Documentation
   *
   */
  void linkDeployedTechniques();

  /**
   * TODO: Documentation
   *
   */
  void unlinkDeployedTechniques();

  /**
   * TODO: Documentation
   *
   */
  void handleRemovedTechniques();

  /**
   * TODO: Documentation
   *
   */
  void handleExistingTechniques();

  /**
   * TODO: Documentation
   *
   */
  void handleNewTechniques();

  /**
   * TODO: Documentation
   *
   */
  void conditionallyCompile(char* dirName);

  /**
   * TODO: Documentation
   *
   */
  void compile(char* dirName);

  /**
   * TODO: Documentation
   *
   */
  void openWorkingDirectories();

  /**
   * TODO: Documentation
   *
   */
  void closeWorkingDirectories();

};


}


}


#endif // PROTOLAYER_COMPILESERVICE_SERVICE_H
