#ifndef PROTOLAYER_IOSTREAM_OUTPUTSTREAM_H
#define PROTOLAYER_IOSTREAM_OUTPUTSTREAM_H

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
#include <rpc/rpc.h>
#include <iostream.h>
#include <errno.h>

#include "Exception.h"

namespace protolayer
{

namespace iostream
{

/**
 * TODO: Documentation
 * <p>
 */
class OutputStream
{
public:
  /**
   * TODO: Documentation
   *
   */
  OutputStream();

  /**
   * TODO: Documentation
   *
   */
  ~OutputStream();

  /**
   * TODO: Documentation
   *
   */
  virtual void write(bool value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(char value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(short value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(int value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(long value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(float value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(double value) = 0;

  /**
   * TODO: Documentation
   *
   */
  virtual void write(const std::string& value) = 0;

private:
  /**
   * TODO: Documentation
   *
   */
  OutputStream(const OutputStream& stream);

  /**
   * TODO: Documentation
   *
   */
  OutputStream& operator=(const OutputStream& stream);

};

}

}

#endif // PROTOLAYER_IOSTREAM_OUTPUTSTREAM_H
