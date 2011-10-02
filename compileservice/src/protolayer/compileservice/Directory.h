#ifndef PROTOLAYER_COMPILESERVICE_DIRECTORY_H
#define PROTOLAYER_COMPILESERVICE_DIRECTORY_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <set>
#include <exception>
#include <stdexcept>

#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>

#include "File.h"

#include <protolayer/protolayer-net.h>

namespace protolayer
{

namespace compileservice
{

bool isRegularFile(const char* path);

bool isDirectory(const char* path);

/**
 * TODO: Documentation
 * <p>
 */
class Directory
{
private:
  /** TODO: Documentation */
  std::string _path;

  /** TODO: Documentation */
  DIR* _dir;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Directory(const char* path) throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  explicit Directory(const std::string& path) throw (std::exception&);

  /**
   * TODO: Documentation
   *
   */
  ~Directory();

  /**
   * TODO: Documentation
   *
   */
  void open() throw (std::exception);

  /**
   * TODO: Documentation
   *
   */
  void close() throw (std::exception);

  /**
   * TODO: Documentation
   *
   */
  DIR* getRawDir();

};


}


}


#endif // PROTOLAYER_COMPILESERVICE_DIRECTORY_H
