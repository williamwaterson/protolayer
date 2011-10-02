#include "AddressLoop.h"


namespace protolayer
{

namespace nameservice
{


AddressLoop::AddressLoop()
{
  pthread_mutexattr_init(&_mutexattr);
  pthread_mutex_init(&_mutex, &_mutexattr);
}


AddressLoop::~AddressLoop()
{
  pthread_mutex_lock(&_mutex);
  pthread_mutex_destroy(&_mutex);
  pthread_mutexattr_destroy(&_mutexattr);
}


void AddressLoop::addAddress(const std::string& address)
{
  pthread_mutex_lock(&_mutex);

  _addresses.insert(address);
  _iterator = _addresses.begin();

  pthread_mutex_unlock(&_mutex);
}


void AddressLoop::removeAddress(const std::string& address)
{
  pthread_mutex_lock(&_mutex);

  _addresses.erase(address);
  _iterator = _addresses.begin();

  pthread_mutex_unlock(&_mutex);
}


int AddressLoop::getNumberAddresses() const
{
  return _addresses.size();
}


bool AddressLoop::containsAddresses() const
{
  return _addresses.size() != 0;
}


bool AddressLoop::isEmpty() const
{
  return _addresses.size() == 0;
}


std::string AddressLoop::next() throw (Exception)
{
  std::string result;

  pthread_mutex_lock(&_mutex);

  if (isEmpty()) {
    pthread_mutex_unlock(&_mutex);    
    throw Exception("Unavailable");
  }

  result = *_iterator;
  _iterator++;
  if (_iterator == _addresses.end()) {
    _iterator = _addresses.begin();
  }

  pthread_mutex_unlock(&_mutex);

  return result;
}


}


}
