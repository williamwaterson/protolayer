#include "Directory.h"


namespace protolayer
{

namespace compileservice
{

bool isRegularFile(const char* path)
{
  struct stat entryStats;
  stat(path, &entryStats);
  return (entryStats.st_mode & S_IFMT) == S_IFREG;
}


bool isDirectory(const char* path)
{
  struct stat entryStats;
  stat(path, &entryStats);
  return (entryStats.st_mode & S_IFMT) == S_IFDIR;
}


Directory::Directory(const char* path) throw (std::exception&) :
  _path(path)
{
  open();
}


Directory::Directory(const std::string& path) throw (std::exception&) :
  _path(path)
{
  open();
}


Directory::~Directory()
{
  try {
    close();
  } catch (std::exception e) {
    // avoid throwing exception on destruction
  }
}


void Directory::open() throw (std::exception)
{
  _dir = opendir(_path.c_str());
  if (_dir == NULL) {
    if (errno == ENOENT) {
      throw std::runtime_error("Directory does not exist, or name is an empty string.");
    } else if (errno == EACCES) {
      throw std::runtime_error("Permission denied.");
    } else if (errno == EMFILE) {
      throw std::runtime_error("Too many file descriptors in use by process.");
    } else if (errno == ENFILE) {
      throw std::runtime_error("Too many files are currently open in the system.");
    } else if (errno == ENOMEM) {
      throw std::runtime_error("Insufficient memory to complete the operation.");
    } else if (errno == ENOTDIR) {
      throw std::runtime_error("Name is not a directory.");
    } else {
      throw std::runtime_error("Unknown error.");
    }
  }
}

void Directory::close() throw (std::exception)
{
  closedir(_dir);
}


DIR* Directory::getRawDir()
{
  return _dir;
}


}


}
