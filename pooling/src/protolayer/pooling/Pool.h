#ifndef PROTOLAYER_POOLING_POOL_H
#define PROTOLAYER_POOLING_POOL_H

#include <sys/time.h>

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#include <map>
#include <string>

#include "protolayer/protolayer-concurrency.h"
#include "protolayer/protolayer-logger.h"
#include "protolayer/protolayer-util.h"


namespace protolayer
{

namespace pooling
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Pool
{
public:
  /** TODO: Documentation */
  typedef std::map <void*, float> MapType;

private:
  /** Time to expire in milliseconds */
  float _expirationTime;

  /** TODO: Documentation */
  MapType _unlocked;

  /** TODO: Documentation */
  MapType _locked;

  /** TODO: Documentation */
  concurrency::Mutex _mutex;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Pool(long expirationTime);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Pool();

  /**
   * TODO: Documentation
   * <p>
   */
  void* acquire(size_t byteSize);

  /**
   * TODO: Documentation
   * <p>
   */
  void release(void* object);

private:
  /**
   * TODO: Documentation
   * <p>
   */
  Pool(const Pool& pool);

  /**
   * TODO: Documentation
   * <p>
   */
  Pool& operator=(const Pool& pool);

};


}


}


#endif // PROTOLAYER_POOLING_POOL_H
