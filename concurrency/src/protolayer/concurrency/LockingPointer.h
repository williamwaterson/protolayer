#ifndef PROTOLAYER_CONCURRENCY_LOCKINGPOINTER_H
#define PROTOLAYER_CONCURRENCY_LOCKINGPOINTER_H

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

#include "Mutex.h"


namespace protolayer
{

namespace concurrency
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class A> class LockingPointer
{
  /** TODO: Documentation */
  A& _target;

  /** TODO: Documentation */
  Mutex& _mutex;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  inline LockingPointer(volatile A& a, Mutex& mutex) :
    _target(const_cast <A&> (a)), _mutex(mutex)
  {
    _mutex.acquire();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline ~LockingPointer()
  {
    _mutex.release();
  }

  /**
   * TODO: Documentation
   *
   */
  inline A& operator*()
  {
    return *_target;
  }

  /**
   * TODO: Documentation
   *
   */
  inline const A& operator*() const
  {
    return *_target;
  }

  /**
   * TODO: Documentation
   *
   */
  inline A* operator->()
  {
    return _target;
  }

  /**
   * TODO: Documentation
   *
   */
  inline const A* operator->() const
  {
    return _target;
  }

private:
  /**
   * TODO: Documentation
   * <p>
   */
  LockingPointer(const LockingPointer& lockingPointer);

  /**
   * TODO: Documentation
   * <p>
   */
  LockingPointer& operator=(const LockingPointer& lockingPointer);

};


}


}


#endif // PROTOLAYER_CONCURRENCY_LOCKINGPOINTER_H
