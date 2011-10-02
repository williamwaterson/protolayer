#include "Service.h"


namespace protolayer
{

namespace compileservice
{

namespace
{
  std::string COMPILE_SERVICE = "CompileService";
}


Service::Service(protolayer::containerservice::Service& service,
                 Configuration& configuration) :
  _containerService(service),
  server::Service("CompileService")
{
  getLogger().info(COMPILE_SERVICE, "Creating instance");

  int bufferSize = 2048;
  char cwd[bufferSize + 1];
  if (!getcwd(cwd, bufferSize + 1)) {
    std::string message("Unable to obtain current working directory");
    getLogger().error(COMPILE_SERVICE, message);
    throw;
  }

  _homePath = cwd;

  _sourcePath = _homePath;
  _sourcePath.append("/tech/");

  _buildPath = _homePath;
  _buildPath.append("/var/build/");

  _deployPath = _homePath;
  _deployPath.append("/var/deploy/");

  _runFlag = false;
}


Service::Service(protolayer::containerservice::Service& service,
                 xercesc::DOMElement& element) throw (Exception) :
  server::Service("CompileService"),
  _containerService(service)
{
  getLogger().info(COMPILE_SERVICE, "Creating instance");

  int bufferSize = 2048;
  char cwd[bufferSize + 1];
  if (!getcwd(cwd, bufferSize + 1)) {
    std::string message("Unable to obtain current working directory");
    getLogger().error(COMPILE_SERVICE, message);
    throw;
  }

  _homePath = cwd;

  _sourcePath = _homePath;
  _sourcePath.append("/tech/");

  _buildPath = _homePath;
  _buildPath.append("/var/build/");

  _deployPath = _homePath;
  _deployPath.append("/var/deploy/");

  _runFlag = false;
}


Service::~Service()
{
  getLogger().info(COMPILE_SERVICE, "Destroying instance");
}


void Service::startup()
{
  getLogger().info(COMPILE_SERVICE, "Starting instance");

  try {
    openWorkingDirectories();
  } catch (...) {
    getLogger().error(COMPILE_SERVICE, "Failed to open necessary working directories");
    throw;
  }

  try {
    linkDeployedTechniques();
  } catch (...) {
    getLogger().error(COMPILE_SERVICE, "Failed to link to existing deployed techniques");
    closeWorkingDirectories();
    throw;
  }
}


void Service::run()
{
  _runFlag = true;
  while(_runFlag) {
    usleep(2000000);
    handleNewTechniques();
    handleExistingTechniques();
    handleRemovedTechniques();
  }

  getLogger().info(COMPILE_SERVICE, "Stopping instance");
  performShutdownSequence();
}


void Service::suspend()
{
  getLogger().info(COMPILE_SERVICE, "Suspending");
}


void Service::resume()
{
  getLogger().info(COMPILE_SERVICE, "Resuming");
}


void Service::performShutdownSequence()
{
  unlinkDeployedTechniques();
  closeWorkingDirectories();
}


void Service::openWorkingDirectories()
{
  std::string message("Protolayer Home: ");
  message.append(_homePath);
  getLogger().debug(COMPILE_SERVICE, message);

  message = "Opening technique source directory: ";
  message.append(_sourcePath);
  getLogger().debug(COMPILE_SERVICE, message);

  _sourceDir = opendir(_sourcePath.c_str());
  if (_sourceDir == NULL) {
    message = "Unable to open working directory ";
    message.append(_sourcePath);
    getLogger().error(COMPILE_SERVICE, message);
    throw;
  }

  message = "Opening technique build directory: ";
  message.append(_buildPath);
  getLogger().debug(COMPILE_SERVICE, message);

  _buildDir = opendir(_buildPath.c_str());
  if (_buildDir == NULL) {
    message = "Unable to open working directory ";
    message.append(_buildPath);
    getLogger().error(COMPILE_SERVICE, message);
    throw;
  }

  message = "Opening technique deploy directory: ";
  message.append(_deployPath);
  getLogger().debug(COMPILE_SERVICE, message);

  _deployDir = opendir(_deployPath.c_str());
  if (_deployDir == NULL) {
    message = "Unable to open working directory ";
    message.append(_deployPath);
    getLogger().error(COMPILE_SERVICE, message);
    throw;
  }
}


void Service::closeWorkingDirectories()
{
  closedir(_sourceDir);
  closedir(_buildDir);
  closedir(_deployDir);
}


void Service::linkDeployedTechniques()
{
}


void Service::unlinkDeployedTechniques()
{
}


void Service::handleRemovedTechniques()
{
}


void Service::handleExistingTechniques()
{
  std::map <std::string, Project*>::iterator iter = _projects.begin();
  std::map <std::string, Project*>::iterator end = _projects.end();
  for (iter = _projects.begin(); iter != end; iter++) {
    Project* project = (*iter).second;
    if (project->walk()) {
      std::string message = "Deploying technique " + project->getName();
      getLogger().debug(COMPILE_SERVICE, message);

      try {
        project->load();

      } catch (std::exception& ex) {
        std::string message = "Unable to deploy technique " + project->getName();
        getLogger().debug(COMPILE_SERVICE, message);
      }

      _deployedProjects[project->getName()] = project;
      message = "Deployed technique " + project->getName();
      getLogger().debug(COMPILE_SERVICE, message);

      TechniqueService& technique = project->getTechniqueService();
      _containerService.deploy(technique);
    }
  }
}


void Service::handleNewTechniques()
{
  rewinddir(_sourceDir);

  struct dirent* entry;
  while ((entry = readdir(_sourceDir)) != NULL) {

    if (strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    if (strcmp(entry->d_name, ".") == 0) {
      continue;
    }

    if (strcmp(entry->d_name, "CVS") == 0) {
      continue;
    }

    std::string entryPath(_sourcePath);
    entryPath.append(entry->d_name);

    struct stat status;
    stat(entryPath.c_str(), &status);

    if (S_ISREG(status.st_mode)) {
      //      std::string message(entry->d_name);
      //      message.append(" is file");
      //      getLogger().debug(COMPILE_SERVICE, message);
      continue;

    } else if (S_ISDIR(status.st_mode)) {
      std::string message(entry->d_name);
      //message.append(" is directory");
      //getLogger().debug(COMPILE_SERVICE, message);

      std::string buildPath(_buildPath);
      buildPath.append(entry->d_name);

      if (!doesDirectoryExist(buildPath.c_str())) {
        std::string temp("Creating build directory ");
        temp.append(buildPath);
        getLogger().info(COMPILE_SERVICE, temp);

        if (mkdir(buildPath.c_str(), 0755) == -1) {
          getLogger().debug(COMPILE_SERVICE, "Unable to create build directory");
          throw;
        }

        temp.erase();
        temp = "Created build directory ";
        temp.append(buildPath);
        getLogger().info(COMPILE_SERVICE, temp);
      }

      std::string projectName(entry->d_name);
      std::map <std::string, Project*>::iterator iter = _projects.find(projectName);
      if (iter == _projects.end()) {
        try {
          Project* created = new Project(_homePath, projectName);
          _projects[projectName] = created;
        } catch (std::exception& ex) {
          getLogger().info(ex.what());
        }
      }

    }
  }

}




bool Service::doesDirectoryExist(const char* name)
{
  return ::protolayer::compileservice::isDirectory(name);
}


void Service::conditionallyCompile(char* dirName)
{
}


//bool Service::checkRemoved(char* dirName)
//{
//}


void Service::compile(char* dirName)
{
  // Create the build path to be checked for timestamps
  //  std::string techniqueDir(_buildsPath);
  //  techniqueDir.append("/");
  //  techniqueDir.append(dirName);

  //  bool firstTimeCompilation = false;

  //  DIR* buildDir = opendir(dirName);
  //  if (buildDir == NULL) {
  //    if (errno == ENOENT) {
  //      std::cout << "Directory does not exist, or name is an empty string." << std::endl;
  //    } else if (errno == EACCES) {
  //      std::cout << "Permission denied." << std::endl;
  //      throw;
  //    } else if (errno == EMFILE) {
  //      std::cout << "Too many file descriptors in use by process." << std::endl
  //      throw;;
  //    } else if (errno == ENFILE) {
  //      std::cout << "Too many files are currently open in the system." << std::endl;
  //      throw;
  //    } else if (errno == ENOMEM) {
  //      std::cout << "Insufficient memory to complete the operation." << std::endl;
  //      throw;
  //    } else if (errno == ENOTDIR) {
  //      std::cout << "Name is not a directory." << std::endl;
  //      throw;
  //    } else {
  //      std::cout << "Unknown error." << std::endl;
  //      throw;
  //    }

  //    firstTimeCompilation = true;
  //  buildDir = mkdir(dirName, 755);
    
  //  }

  //  if (firstTimeCompilation) {
  //    firstTimeCompilation();
  //  } else {
  //    subsequentCompilation();
  //  }

  // Else perform attempt at compilation
  //  if (hasValidDirectoryStructure()) {

    //    for () {
    //double sourceTimeStamp =;
    //double binaryTimeStamp =;

    //      if (sourceTimeStamp >= binaryTimeStamp) {
    //  compile(entry->d_name);
    //  compilationHasOccurred = true;
    //}
    //}

    //    if (compilationHasOccurred) {
    // link();
    //}
  //  }

}


void Service::shutdown()
{
  _runFlag = false;
}


}


}



  /*    struct dirent* entry;
    struct stat status;

    while ((entry = readdir(techDir)) != NULL) {
      stat(entry->d_name, &status);
      if ((status.st_mode & S_IFMT) == S_IFDIR &&
          strcmp(entry->d_name, "..") != 0 &&
          strcmp(entry->d_name, ".") != 0) {
        conditionallyCompile(entry->d_name);
      }
    }

    rewinddir(techDir);


  if (closedir(techDir) == -1) {
    exit(1);
  }
  */
