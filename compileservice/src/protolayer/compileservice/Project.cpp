#include "Project.h"


namespace protolayer
{

namespace compileservice
{

namespace
{
  std::string COMPILE_SERVICE("CompileService");
}


bool isRegularFile(const std::string& path)
{
  struct stat status;
  stat(path.c_str(), &status);
  return S_ISREG(status.st_mode);
}


bool isDirectory(const std::string& path)
{
  struct stat status;
  stat(path.c_str(), &status);
  return S_ISDIR(status.st_mode);
}


bool Project::isLoaded() const
{
  return _loaded;
}


Project::Project(const std::string& homePath,
                 const std::string& relativePath) throw (std::exception&) :
  _loaded(false),
  _libPath(homePath),
  _sourcePath(homePath),
  _buildPath(homePath),
  _stagingPath(homePath),
  _deployPath(homePath),
  _techniqueService(0)
{
  _name = relativePath;
  _libraryName = "lib_" + relativePath + ".la";

  _sourcePath += "/tech/" + relativePath;
  openSourceDirectory();

  _buildPath += "/var/build/" + relativePath;
  openBuildDirectory();

  _stagingPath += "/var/staging/";
  openStagingDirectory();

  _deployPath += "/var/deploy/";
  openDeployDirectory();

  _libPath += "/lib/";
}


Project::~Project()
{
  delete _buildDir;
  delete _sourceDir;
  delete _stagingDir;
  delete _deployDir;
}


const std::string& Project::getName() const
{
  return _name;
}


const std::string& Project::getLibraryName() const
{
  return _libraryName;
}


const std::string& Project::getSourcePath() const
{
  return _sourcePath;
}


const std::string& Project::getBuildPath() const
{
  return _buildPath;
}


const std::string& Project::getStagingPath() const
{
  return _stagingPath;
}


const std::string& Project::getDeployPath() const
{
  return _deployPath;
}


bool Project::doesDirectoryExist(const char* name)
{
  bool result = false;
  DIR* dir = opendir(name);
  if (dir != NULL) {
    closedir(dir);
    result = true;
  }
  return result;
}


bool isSpecialExclusionEntry(const char* value)
{
  return strcmp(value, "CVS") == 0;
}


bool isCurrentDirectoryEntry(const char* value)
{
  return strcmp(value, ".") == 0;
}


bool isParentDirectoryEntry(const char* value)
{
  return strcmp(value, "..") == 0;
}


bool isStandardExclusionEntry(const char* value)
{
  return isCurrentDirectoryEntry(value) || isParentDirectoryEntry(value);
}


bool compileCpp(const std::string& sourcePath, const std::string& buildPath)
{
  bool compilationFlag = false;

  std::string command("/bin/sh ../libtool --mode=compile g++ -g -O2 -c ");
  command += sourcePath + " -o " + buildPath;

  logger::Logger::getSingleton().info(command);
  if (system(command.c_str()) == 0) {
    compilationFlag = true;
  }

  return compilationFlag;
}


void compileJava(const std::string& sourcePath, const std::string& buildPath)
{
  std::string command("gcj -lgcj ");
  command += sourcePath + " -o " + buildPath;

  logger::Logger::getSingleton().info(command);
  system(command.c_str());
}


bool hasSourceChanged(std::string& sourcePath,
                      std::string& buildPath)
{
  struct stat sourceStatus;
  stat(sourcePath.c_str(), &sourceStatus);

  struct stat buildStatus;
  stat(buildPath.c_str(), &buildStatus);

  //  double diffSeconds = difftime(sourceStatus.st_mtimespec.tv_sec,
  //                                buildStatus.st_mtimespec.tv_sec);
  //  double diffNanoseconds = sourceStatus.st_mtimespec.tv_nsec -
  //    buildStatus.st_mtimespec.tv_nsec;
  //  bool result = (diffSeconds > 0) || (diffSeconds == 0 && diffNanoseconds > 0);

  double diffSeconds = difftime(sourceStatus.st_mtime,
                                buildStatus.st_mtime);

  bool result = diffSeconds > 0;

  return result;
}


bool endsWith(const std::string& text, const std::string& suffix)
{
  bool result = true;

  int textLength = text.length();
  int suffixLength = suffix.length();
  int startIndex = textLength - suffixLength;

  if (suffixLength > textLength) {
    result = false;
  } else {
    int j = 0;
    for (int i = startIndex; i < textLength; i++) {
      if (text[i] != suffix[j]) {
        result = false;
      }
      j++;
    }
  }

  return result;
}


bool beginsWith(const std::string& text, const std::string& prefix)
{
  bool result = true;

  int textLength = text.length();
  int prefixLength = prefix.length();

  if (prefixLength > textLength) {
    result = false;

  } else {
    for (int i = 0; i < prefixLength; i++) {
      if (text[i] != prefix[i]) {
        result = false;
      }
    }
  }

  return result;
}


bool isDescriptorFile(const std::string& path)
{
  return endsWith(path, "technique.xml");
}


bool isCppSourceFile(const std::string& path)
{
  return endsWith(path, ".cpp") ||
         endsWith(path, ".hpp") ||
         endsWith(path, ".cc");
}


bool isJavaSourceFile(const std::string& path)
{
  return endsWith(path, ".java");
}


TechniqueService& Project::getTechniqueService() throw (std::exception&)
{
  if (_techniqueService == 0) {
    throw std::runtime_error("Technique not loaded");
  }

  return *_techniqueService;
}


bool Project::walkAndLink()
{
  bool linked = false;

  std::string temp;
  struct dirent* entry;

  rewinddir(_buildDir->getRawDir());

  while ((entry = readdir(_buildDir->getRawDir())) != NULL) {

    if (isStandardExclusionEntry(entry->d_name) ||
        isSpecialExclusionEntry(entry->d_name)) {
      continue;
    }

    std::string entryPath(_buildPath);
    entryPath += "/";
    entryPath += entry->d_name;

    if (isRegularFile(entryPath) && endsWith(entryPath, ".lo")) {

      _linkingList.insert(entryPath);

    } else if (isDirectory(entryPath)) {

      try {
        walkAndLink(entry->d_name);
      } catch (...) {
        throw std::runtime_error("Unable to walk directory tree");        
      }

    }

  }

  std::string libPath = _stagingPath + "/" + _libraryName;

  std::string command = "/bin/sh ../libtool --mode=link g++ -g -O2 -module -rpath /usr/local/lib -o ";
  command += libPath;
  command += " ";

  std::set <std::string>::iterator iter = _linkingList.begin();
  for (iter = _linkingList.begin(); iter != _linkingList.end(); iter++) {
    command += *iter + " ";
  }

  logger::Logger::getSingleton().info(command);
  if (system(command.c_str()) == 0) {
    linked = true;
  }

  //  std::string installPath = _stagingPath + _libraryName;

  //  command = "/bin/sh ../libtool --mode=install /usr/bin/install -c ";
  //  command += libPath + " ";
  //  command += " ";
  //  command += installPath;

  //  logger::Logger::getSingleton().info(command);
  //  if (system(command.c_str()) == 0) {
  //    linked = true;
  //  }

  _linkingList.clear();

  return linked;
}


void Project::walkAndLink(const char* path)
{
  std::string buildPath(_buildPath);
  buildPath += "/";
  buildPath += path;

  std::string message = "Opening build directory: ";
  message += buildPath;
  logger::Logger::getSingleton().debug(COMPILE_SERVICE, message);

  Directory* buildDir = 0;
  try {
    buildDir = new Directory(buildPath.c_str());
  } catch (std::exception& ex) {
    if (strcmp(ex.what(), "Directory does not exist, or name is an empty string.") != 0) {
      throw std::runtime_error("Unable to open portion of working directory");
    }
  }

  struct dirent* entry;

  while ((entry = readdir(buildDir->getRawDir())) != NULL) {

    if (isStandardExclusionEntry(entry->d_name) ||
        isSpecialExclusionEntry(entry->d_name)) {
      continue;
    }

    std::string entryPath(buildPath);
    entryPath += "/";
    entryPath += entry->d_name;

    if (isRegularFile(entryPath) && endsWith(entryPath, ".lo")) {

      _linkingList.insert(entryPath);

    } else if (isDirectory(entryPath)) {

      std::string relativePath = path;
      relativePath += "/";
      relativePath += entry->d_name;

      try {
        walkAndLink(relativePath.c_str());
      } catch (...) {
        throw std::runtime_error("Unable to walk directory tree");        
      }

    }
  }

  logger::Logger::getSingleton().debug("[CompileService] Close build directory");
  delete buildDir;
}


bool Project::handleCppFiles(std::string entryPath,
                             const char* entry)
{
  bool compilationFlag = false;

  if (isCppSourceFile(entryPath)) {

    std::string outputEntry(entry);
    int length = outputEntry.length() - 1;
    outputEntry.erase(length - 3);
    outputEntry += ".lo";

    std::string buildPath(_buildPath);
    buildPath += "/";
    buildPath += outputEntry;

    if (hasSourceChanged(entryPath, buildPath)) {
      if (compileCpp(entryPath, buildPath)) {
        compilationFlag = true;
      }
    }
  }

  return compilationFlag;
}


void Project::handleJavaFiles(std::string entryPath,
                              const char* entry)
{
  if (isJavaSourceFile(entryPath)) {

    std::string outputEntry(entry);
    int length = outputEntry.length() - 1;
    outputEntry.erase(length - 4);
    outputEntry += ".lo";

    std::string buildPath = _buildPath + "/" + outputEntry;

    if (hasSourceChanged(entryPath, buildPath)) {
      compileJava(entryPath, buildPath);
    }

  }
}


bool Project::walk()
{
  bool deployFlag = false;
  bool compilationFlag = false;

  std::string temp;
  struct dirent* entry;

  rewinddir(_sourceDir->getRawDir());

  while ((entry = readdir(_sourceDir->getRawDir())) != NULL) {

    if (isStandardExclusionEntry(entry->d_name) ||
        isSpecialExclusionEntry(entry->d_name)) {
      continue;
    }

    std::string entryPath(_sourcePath);
    entryPath += "/";
    entryPath += entry->d_name;

    if (isDescriptorFile(entryPath)) {
      logger::Logger::getSingleton().info("technique.xml found");

    } else if (isRegularFile(entryPath)) {

      if (handleCppFiles(entryPath, entry->d_name)) {
        compilationFlag = true;
      }

    } else if (isDirectory(entryPath)) {

      std::string buildPath(_buildPath);
      buildPath += "/";
      buildPath += entry->d_name;

      if (!doesDirectoryExist(buildPath.c_str())) {

        std::string temp("[CompileService] Creating build directory ");
        temp += buildPath;
        logger::Logger::getSingleton().info(temp);

        if (mkdir(buildPath.c_str(), 0755) == -1) {
          throw std::runtime_error("Unable to create build directory");
        }

        temp = "[CompileService] Created build directory ";
        temp += buildPath;
        logger::Logger::getSingleton().info(temp);
      }

      try {
        if (walkDirectories(entry->d_name)) {
          compilationFlag = true;
        }
      } catch (...) {
        throw std::runtime_error("Unable to walk directory tree");        
      }

    }
  }

  if (compilationFlag) {
    if (walkAndLink()) {
      deployFlag = true;
    }
  }

  return deployFlag;
}


void Project::load() throw (std::exception&)
{
  if (isLoaded()) {
    throw std::runtime_error("Already loaded.");
  }

  std::string libPath = _stagingPath + _libraryName;

  bool createdImage = false;

  if (lt_dlinit() != 0) {
    logger::Logger::getSingleton().info("Unable to init libltdl");
    throw std::runtime_error("Unable to init libltdl");
  }

  lt_dlhandle handle = lt_dlopen(libPath.c_str());
  if (handle == NULL) {
    logger::Logger::getSingleton().info(libPath.c_str());
    logger::Logger::getSingleton().info(lt_dlerror());
    logger::Logger::getSingleton().info("Unable to load the library");
    throw std::runtime_error("Unable to load the library");
  }
    
  // load the symbol
  TechniqueService* (*constructTechniqueService) (void);
  constructTechniqueService = (TechniqueService* (*)(void)) lt_dlsym(handle, "constructTechniqueService");
  if (!constructTechniqueService) {
    lt_dlclose(handle);
    logger::Logger::getSingleton().info("Could not find symbol: \"constructTechniqueService\".");
    throw std::runtime_error("Could not find symbol: \"constructTechniqueService\".");
  }

  try {
    _techniqueService = constructTechniqueService();
  } catch (std::exception& ex) {
    lt_dlclose(handle);
    throw std::runtime_error("Unable to construct the techniqueService instance");
  }

  _loaded = true;
}


void Project::unload()
{
  if (_loaded) {
    lt_dlclose(handle);
    _loaded = false;
  }
}


bool Project::walkDirectories(const char* path)
{
  bool compilationFlag = false;

  std::string sourcePath(_sourcePath);
  sourcePath += "/";
  sourcePath += path;

  std::string message("Opening source directory: ");
  message += sourcePath;
  logger::Logger::getSingleton().debug(COMPILE_SERVICE, message);

  Directory* sourceDir = new Directory(sourcePath.c_str());
  try {
    sourceDir = new Directory(sourcePath.c_str());
  } catch (std::exception& ex) {
    if (strcmp(ex.what(), "Directory does not exist, or name is an empty string.") != 0) {
      throw ex;
    }
  }

  std::string buildPath(_buildPath);
  buildPath += "/";
  buildPath += path;

  message = "Opening build directory: ";
  message += buildPath;
  logger::Logger::getSingleton().debug(COMPILE_SERVICE, message);

  Directory* buildDir = 0;
  try {
    buildDir = new Directory(buildPath.c_str());
  } catch (std::exception& ex) {
    if (strcmp(ex.what(), "Directory does not exist, or name is an empty string.") != 0) {
      throw std::runtime_error("Unable to open portion of working directory");
    }
  }

  struct dirent* entry;

  while ((entry = readdir(sourceDir->getRawDir())) != NULL) {

    if (isStandardExclusionEntry(entry->d_name) ||
        isSpecialExclusionEntry(entry->d_name)) {
      continue;
    }

    std::string entryPath(_sourcePath);
    entryPath += "/";
    entryPath += entry->d_name;

    std::string extendedPath(buildPath);
    extendedPath += "/";
    extendedPath += entry->d_name;

    if (isRegularFile(entryPath)) {

      if (handleCppFiles(entryPath, extendedPath.c_str())) {
        compilationFlag = true;
      }

    } else if (isDirectory(entryPath)) {

      if (!doesDirectoryExist(extendedPath.c_str())) {
        if (mkdir(extendedPath.c_str(), 0755) == -1) {
          throw std::runtime_error("Unable to create build directory");
        }
      }

      std::string relativePath(path);
      relativePath += "/";
      relativePath += entry->d_name;

      try {
        if (walkDirectories(relativePath.c_str())) {
          compilationFlag = true;
        }
      } catch (...) {
        throw std::runtime_error("Unable to walk directory tree");        
      }
    }
  }

  logger::Logger::getSingleton().debug("[CompileService] Close build directory");
  delete buildDir;

  logger::Logger::getSingleton().debug("[CompileService] Close source directory");
  delete sourceDir;

  return compilationFlag;
}


DIR* Project::getSourceDirectory()
{
  return _sourceDir->getRawDir();
}


DIR* Project::getBuildDirectory()
{
  return _buildDir->getRawDir();
}


void Project::openDeployDirectory() throw (std::exception&)
{
  _deployDir = 0;
  try {
    _deployDir = new Directory(_deployPath.c_str());
  } catch (std::exception& ex) {
    logger::Logger::getSingleton().error(ex.what());
    throw ex;
  }
}


void Project::openStagingDirectory() throw (std::exception&)
{
  _stagingDir = 0;
  try {
    _stagingDir = new Directory(_stagingPath.c_str());
  } catch (std::exception& ex) {
    logger::Logger::getSingleton().error(ex.what());
    throw ex;
  }
}


void Project::openSourceDirectory() throw (std::exception&)
{
  _sourceDir = 0;
  try {
    _sourceDir = new Directory(_sourcePath.c_str());
  } catch (std::exception& ex) {
    logger::Logger::getSingleton().error(ex.what());
    throw ex;
  }
}


void Project::openBuildDirectory() throw (std::exception&)
{
  _buildDir = 0;
  try {
    _buildDir = new Directory(_buildPath.c_str());
  } catch (std::exception& ex) {
    logger::Logger::getSingleton().error(ex.what());    
    throw ex;
  }
}


}


}
