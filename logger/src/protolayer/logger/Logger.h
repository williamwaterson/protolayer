#ifndef PROTOLAYER_LOGGER_LOGGER_H
#define PROTOLAYER_LOGGER_LOGGER_H

#include <set>
#include <iostream.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pthread.h>

#include <protolayer/protolayer-concurrency.h>

namespace protolayer
{

namespace logger
{

/**
 * TODO: Documentation
 * <p>
 */
class Logger
{
private:
  /** TODO: Documentation */
  concurrency::Mutex _mutex;

public:
  /**
   * TODO: Documentation
   *
   */
  static Logger& getSingleton();

public:
  /**
   * TODO: Documentation
   *
   */
  Logger();

  /**
   * TODO: Documentation
   *
   */
  virtual ~Logger();

  /**
   * TODO: Documentation
   *
   */
  void debug(const char* message);

  /**
   * TODO: Documentation
   *
   */
  void info(const char* message);

  /**
   * TODO: Documentation
   *
   */
  void warn(const char* message);

  /**
   * TODO: Documentation
   *
   */
  void error(const char* message);

  /**
   * TODO: Documentation
   *
   */
  void fatal(const char* message);

  /**
   * TODO: Documentation
   *
   */
  void debug(const char* origin, const char* message);

  /**
   * TODO: Documentation
   *
   */
  void info(const char* origin, const char* message);

  /**
   * TODO: Documentation
   *
   */
  void warn(const char* origin, const char* message);

  /**
   * TODO: Documentation
   *
   */
  void error(const char* origin, const char* message);

  /**
   * TODO: Documentation
   *
   */
  void fatal(const char* origin, const char* message);

  /**
   * TODO: Documentation
   *
   */
  void debug(const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void info(const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void warn(const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void error(const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void fatal(const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void debug(const std::string& source, const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void info(const std::string& source, const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void warn(const std::string& source, const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void error(const std::string& source, const std::string& message);

  /**
   * TODO: Documentation
   *
   */
  void fatal(const std::string& source, const std::string& message);

};


Logger& getLogger();


}


logger::Logger& getLogger();


}


#endif // PROTOLAYER_LOGGER_LOGGER_H
