#ifndef PROTOLAYER_IOSTREAM_XDROUTPUTSTREAM_H
#define PROTOLAYER_IOSTREAM_XDROUTPUTSTREAM_H

#include <map>
#include <set>
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

#include "protolayer/protolayer-logger.h"

#include "Exception.h"
#include "OutputStream.h"

namespace protolayer
{

namespace iostream
{

/**
 * TODO: Documentation
 * <p>
 */
class XdrOutputStream : public OutputStream
{
  /** TODO: Documentation */
  FILE* _file;

  /** TODO: Documentation */
  XDR _xdr;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit XdrOutputStream(int socketFd);

  /**
   * TODO: Documentation
   *
   */
  explicit XdrOutputStream(char* fileName);

  /**
   * TODO: Documentation
   *
   */
  ~XdrOutputStream();

  /**
   * TODO: Documentation
   *
   */
  void close();

  /**
   * TODO: Documentation
   *
   */
  void write(bool value);

  /**
   * TODO: Documentation
   *
   */
  void write(char value);

  /**
   * TODO: Documentation
   *
   */
  void write(short value);

  /**
   * TODO: Documentation
   *
   */
  void write(int value);

  /**
   * TODO: Documentation
   *
   */
  void write(long value);

  /**
   * TODO: Documentation
   *
   */
  void write(float value);

  /**
   * TODO: Documentation
   *
   */
  void write(double value);

  /**
   * TODO: Documentation
   *
   */
  void write(const std::string& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <bool>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <char>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <short>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <int>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <long>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <float>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(std::set <double>& value);

  /**
   * TODO: Documentation
   *
   */
  void write(const std::set <std::string>& value);

  /**
   * TODO: Documentation
   *
   */
  void flush();

private:
  /**
   * TODO: Documentation
   *
   */
  XdrOutputStream(const XdrOutputStream& stream);

  /**
   * TODO: Documentation
   *
   */
  XdrOutputStream& operator=(const XdrOutputStream& stream);

};


}


namespace reflection
{

bool isSimpleType(const std::string& value);

}


void encode(iostream::XdrOutputStream& stream, bool value);


void encode(iostream::XdrOutputStream& stream, char value);


void encode(iostream::XdrOutputStream& stream, short value);


void encode(iostream::XdrOutputStream& stream, int value);


void encode(iostream::XdrOutputStream& stream, long value);


void encode(iostream::XdrOutputStream& stream, float value);


void encode(iostream::XdrOutputStream& stream, double value);


void encode(iostream::XdrOutputStream& stream, std::string& value);


}


#endif // PROTOLAYER_IOSTREAM_XDROUTPUTSTREAM_H
