#ifndef PROTOLAYER_CONCURRENCY_MUTEX_H
#define PROTOLAYER_CONCURRENCY_MUTEX_H

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


namespace protolayer
{

namespace concurrency
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Mutex
{
private:
  /** TODO: Documentation */
  pthread_mutex_t _mutex;

  /** TODO: Documentation */
  pthread_mutexattr_t _mutexAttributes;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Mutex();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Mutex();

  void acquire();

  void release();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  Mutex(const Mutex& mutex);

  /**
   * TODO: Documentation
   * <p>
   */
  Mutex& operator=(const Mutex& mutex);

};


}


}


#endif // PROTOLAYER_CONCURRENCY_MUTEX_H
