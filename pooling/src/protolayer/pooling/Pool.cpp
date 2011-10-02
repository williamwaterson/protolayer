#include "Pool.h"


namespace protolayer
{

namespace pooling
{

Pool::Pool(long expirationTime) :
  _expirationTime(expirationTime)
{
}


Pool::~Pool()
{
}


void* Pool::acquire(size_t byteSize)
{
  /*
  pthread_mutex_lock(&_mutex);

  struct timeval tick;
  gettimeofday(&tick, NULL);    

  double time = tick.tv_usec;
  time /= 1000000;
  time += tick.tv_sec;

  float now = (float) time;

  void* object = 0;

  if (_unlocked.size() > 0) {
    std::map <void*, float>::iterator iterator;

    while (iterator != _unlocked.end()) {
      object = iterator->first;

      if ((now - _unlocked[object]) > _expirationTime) {
	//getLogger().debug("Pool", "Erasing unlocked object _unlocked.size() " + util::itoa(_unlocked.size()));
	//	_unlocked.erase(object);
	//getLogger().debug("Pool", "Deleting unlocked object _unlocked.size() " + util::itoa(_unlocked.size()));
	//	free(object);

      } else {
	getLogger().debug("Pool", "Erasing unlocked object for locking _unlocked.size() " + util::itoa(_unlocked.size()));
	_unlocked.erase(object);
	getLogger().debug("Pool", "Locking this object _unlocked.size() " + util::itoa(_unlocked.size()));
	_locked[object] = now;
	getLogger().debug("Pool", "Returning locked object _locked.size() " + util::itoa(_locked.size()));
	
	pthread_mutex_unlock(&_mutex);

	return object;

      }
    }
    
  } else {
    getLogger().debug("Pool", "Creating new locked object");
    object = malloc(byteSize);
    _locked[object] = now;
    getLogger().debug("Pool", "Creating new locked object" + util::itoa(_locked.size()));
  }

  pthread_mutex_unlock(&_mutex);

  return object;
  */

  return malloc(byteSize);
}


void Pool::release(void* object)
{
  free(object);

  /*
  pthread_mutex_lock(&_mutex);

  struct timeval tick;
  gettimeofday(&tick, NULL);    

  double time = tick.tv_usec;
  time /= 1000000;
  time += tick.tv_sec;

  getLogger().debug("Pool", "Erasing locked object _locked.size() " + util::itoa(_locked.size()));
  _locked.erase(object);
  getLogger().debug("Pool", "Adding object to unlocked objects _unlocked.size() " + util::itoa(_unlocked.size()));
  _unlocked[object] = (float) time;
  getLogger().debug("Pool", "Completed release _unlocked.size() " + util::itoa(_unlocked.size()));

  pthread_mutex_unlock(&_mutex);
  */
}


}


}
