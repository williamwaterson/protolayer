#ifndef PROTOLAYER_COMPILESERVICE_PROJECT_H
#define PROTOLAYER_COMPILESERVICE_PROJECT_H

#include <arpa/inet.h>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <set>
#include <sys/stat.h>
#include <dirent.h>

#if HAVE_CONFIG_H
#  include <config.h>
#endif

#include "ltdl.h"

#include <protolayer/protolayer.h>
#include <protolayer/protolayer-net.h>
#include <protolayer/protolayer-server.h>

#include "Directory.h"

namespace protolayer
{

namespace compileservice
{

/**
 * TODO: Documentation
 * <p>
 */
class Project
{
private:
  /** TODO: Documentation */
  bool _loaded;

  /** TODO: Documentation */
  lt_dlhandle handle;

  /** TODO: Documentation */
  std::string _name;

  /** TODO: Documentation */
  std::string _libraryName;

  /** TODO: Documentation */
  std::string _libPath;

  /** TODO: Documentation */
  std::string _sourcePath;

  /** TODO: Documentation */
  std::string _buildPath;

  /** TODO: Documentation */
  std::string _stagingPath;

  /** TODO: Documentation */
  std::string _deployPath;

  /** TODO: Documentation */
  Directory* _sourceDir;

  /** TODO: Documentation */
  Directory* _buildDir;

  /** TODO: Documentation */
  Directory* _stagingDir;

  /** TODO: Documentation */
  Directory* _deployDir;

  /** TODO: Documentation */
  std::set <std::string> _linkingList;

  /** TODO: Documentation */
  TechniqueService* _techniqueService;

public:
  /**
   * TODO: Documentation
   *
   */
  Project(const std::string& homePath,
          const std::string& relativePath) throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  ~Project();

  /**
   * TODO: Documentation
   *
   */
  DIR* getSourceDirectory();

  /**
   * TODO: Documentation
   *
   */
  DIR* getBuildDirectory();

  /**
   * TODO: Documentation
   *
   */
  bool walk();

  /**
   * TODO: Documentation
   *
   */
  bool isLoaded() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getLibraryName() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getSourcePath() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getBuildPath() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getStagingPath() const;

  /**
   * TODO: Documentation
   *
   */
  const std::string& getDeployPath() const;

  /**
   * TODO: Documentation
   *
   */
  void load() throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  void unload();

  /**
   * TODO: Documentation
   *
   */
  TechniqueService& getTechniqueService() throw (std::exception&);

private:
  /**
   * TODO: Documentation
   *
   */
  void openSourceDirectory() throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  void openBuildDirectory() throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  void openDeployDirectory() throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  void openStagingDirectory() throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  bool walkDirectories(const char* path);

  /**
   * TODO: Documentation
   *
   */
  bool doesDirectoryExist(const char* name);

  /**
   * TODO: Documentation
   *
   */
  bool handleCppFiles(std::string entryPath,
                      const char* entry);

  /**
   * TODO: Documentation
   *
   */
  bool loadModule();

  /**
   * TODO: Documentation
   *
   */
  void handleJavaFiles(std::string entryPath,
                       const char* entry);

  /**
   * TODO: Documentation
   *
   */
  bool walkAndLink();

  /**
   * TODO: Documentation
   *
   */
  void walkAndLink(const char* path);

};

}


}


#endif // PROTOLAYER_COMPILESERVICE_PROJECT_H
