#include "Mutex.h"


namespace protolayer
{

namespace concurrency
{

Mutex::Mutex()
{    
  pthread_mutexattr_init(&_mutexAttributes);
  pthread_mutex_init(&_mutex, &_mutexAttributes);
}


Mutex::~Mutex()
{
  pthread_mutex_lock(&_mutex);
  pthread_mutex_destroy(&_mutex);
  pthread_mutexattr_destroy(&_mutexAttributes);
}


void Mutex::acquire()
{
  pthread_mutex_lock(&_mutex);
}


void Mutex::release()
{
  pthread_mutex_unlock(&_mutex);
}


}


}
