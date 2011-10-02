#ifndef PROTOLAYER_COMPILESERVICE_FILE_H
#define PROTOLAYER_COMPILESERVICE_FILE_H

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <map>

#include <protolayer/protolayer-net.h>

namespace protolayer
{

namespace compileservice
{

/**
 * TODO: Documentation
 * <p>
 */
class File
{
private:
  /** TODO: Documentation */
  std::string _name;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit File(const char* name);

  /**
   * TODO: Documentation
   *
   */
  explicit File(const std::string& name);

};

}

}

#endif // PROTOLAYER_COMPILESERVICE_FILE_H
