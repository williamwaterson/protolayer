#ifndef PROTOLAYER_IOSTREAM_INPUTSTREAM_H
#define PROTOLAYER_IOSTREAM_INPUTSTREAM_H

#include <string>

#include "Exception.h"


namespace protolayer
{

namespace iostream
{

/**
 * TODO: Documentation
 * <p>
 */
class InputStream
{
public:
  /**
   * TODO: Documentation
   *
   */
  InputStream();

  /**
   * TODO: Documentation
   *
   */
  ~InputStream();

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

private:
  /**
   * TODO: Documentation
   *
   */
  InputStream(const InputStream& stream);

  /**
   * TODO: Documentation
   *
   */
  InputStream& operator=(const InputStream& stream);

};

}

}

#endif // PROTOLAYER_IOSTREAM_INPUTSTREAM_H
