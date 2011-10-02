#ifndef PROTOLAYER_IOSTREAM_XDRINPUTSTREAM_H
#define PROTOLAYER_IOSTREAM_XDRINPUTSTREAM_H

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
#include "InputStream.h"


namespace protolayer
{

namespace iostream
{

/**
 * TODO: Documentation
 * <p>
 */
class XdrInputStream : public InputStream
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
  explicit XdrInputStream(int socketFd) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  explicit XdrInputStream(char* fileName) throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  ~XdrInputStream();

  /**
   * TODO: Documentation
   *
   */
  void close() throw (Exception);

  /**
   * TODO: Documentation
   *
   */
  void read(bool& value);

  /**
   * TODO: Documentation
   *
   */
  void read(char& value);

  /**
   * TODO: Documentation
   *
   */
  void read(short& value);

  /**
   * TODO: Documentation
   *
   */
  void read(int& value);

  /**
   * TODO: Documentation
   *
   */
  void read(long& value);

  /**
   * TODO: Documentation
   *
   */
  void read(float& value);

  /**
   * TODO: Documentation
   *
   */
  void read(double& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::string& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <bool>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <char>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <short>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <int>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <long>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <float>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <double>& value);

  /**
   * TODO: Documentation
   *
   */
  void read(std::set <std::string>& value);

private:
  /**
   * TODO: Documentation
   *
   */
  XdrInputStream(const XdrInputStream& stream);

  /**
   * TODO: Documentation
   *
   */
  XdrInputStream& operator=(const XdrInputStream& stream);

};


}


void decode(iostream::XdrInputStream& stream, bool& value);


void decode(iostream::XdrInputStream& stream, char& value);


void decode(iostream::XdrInputStream& stream, short& value);


void decode(iostream::XdrInputStream& stream, int& value);


void decode(iostream::XdrInputStream& stream, long& value);


void decode(iostream::XdrInputStream& stream, float& value);


void decode(iostream::XdrInputStream& stream, double& value);


void decode(iostream::XdrInputStream& stream, std::string& value);


}


#endif // PROTOLAYER_IOSTREAM_XDRINPUTSTREAM_H
