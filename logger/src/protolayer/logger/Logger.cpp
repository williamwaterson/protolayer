#include "Logger.h"


namespace protolayer
{

namespace logger
{

namespace
{

Logger _logger;

}


Logger& Logger::getSingleton()
{
  return _logger;
}


Logger::Logger()
{
}


Logger::~Logger()
{
}


void Logger::debug(const char* message)
{
  _mutex.acquire();
  std::cout << " DEBUG  " << message << std::endl;
  _mutex.release();
}


void Logger::info(const char* message)
{
  _mutex.acquire();
  std::cout << " INFO  " << message << std::endl;
  _mutex.release();
}


void Logger::warn(const char* message)
{
  _mutex.acquire();
  std::cout << " WARNING  " << message << std::endl;
  _mutex.release();
}


void Logger::error(const char* message)
{
  _mutex.acquire();
  std::cout << " ERROR  " << message << std::endl;
  _mutex.release();
}


void Logger::fatal(const char* message)
{
  _mutex.acquire();
  std::cout << " FATAL  " << message << std::endl;
  _mutex.release();
}


void Logger::debug(const std::string& message)
{
  debug(message.c_str());
}


void Logger::info(const std::string& message)
{
  info(message.c_str());
}


void Logger::warn(const std::string& message)
{
  warn(message.c_str());
}


void Logger::error(const std::string& message)
{
  error(message.c_str());
}


void Logger::fatal(const std::string& message)
{
  fatal(message.c_str());
}


void Logger::debug(const std::string& source, const std::string& message)
{
  debug(source.c_str(), message.c_str());
}


void Logger::info(const std::string& source, const std::string& message)
{
  info(source.c_str(), message.c_str());
}


void Logger::warn(const std::string& source, const std::string& message)
{
  warn(source.c_str(), message.c_str());
}


void Logger::error(const std::string& source, const std::string& message)
{
  error(source.c_str(), message.c_str());
}


void Logger::fatal(const std::string& source, const std::string& message)
{
  fatal(source.c_str(), message.c_str());  
}


void Logger::debug(const char* source, const char* message)
{
  _mutex.acquire();
  std::cout << " DEBUG " << "[" << source << "] " << message << std::endl;
  _mutex.release();
}


void Logger::info(const char* source, const char* message)
{
  _mutex.acquire();
  std::cout << " INFO  " << "[" << source << "] " << message << std::endl;
  _mutex.release();
}


void Logger::warn(const char* source, const char* message)
{
  _mutex.acquire();
  std::cout << " WARN  " << "[" << source << "] " << message << std::endl;
  _mutex.release();
}


void Logger::error(const char* source, const char* message)
{
  _mutex.acquire();
  std::cout << " ERROR  " << "[" << source << "] " << message << std::endl;
  _mutex.release();
}


void Logger::fatal(const char* source, const char* message)
{
  _mutex.acquire();
  std::cout << " FATAL  " << "[" << source << "] " << message << std::endl;
  _mutex.release();
}


Logger& getLogger()
{
  return Logger::getSingleton();
}


}


logger::Logger& getLogger()
{
  return logger::Logger::getSingleton();
}


}
