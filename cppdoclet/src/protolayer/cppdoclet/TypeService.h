#ifndef PROTOLAYER_REGISTRATION_TYPESERVICE_H
#define PROTOLAYER_REGISTRATION_TYPESERVICE_H

#include <map>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>


namespace protolayer
{

namespace registration
{

class TestType ;

class TypeService
{
public:
  /** @serialise
   */
  int _name;

  /** @serialise
   */
  bool _flag;

public:
  /**
   * @remote
   */
  TypeService();

private:
  /**
   * TODO: Documentation
   *
   */
  TypeService(const TypeService& typeService);

  /**
   * TODO: Documentation
   *
   */
  TypeService& operator=(const TypeService& typeService);

};


}


}


namespace
{
}



#endif // PROTOLAYER_REGISTRATION_TYPESERVICE_H
