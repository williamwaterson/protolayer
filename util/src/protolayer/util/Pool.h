#ifndef PROTOLAYER_UTIL_POOL_H
#define PROTOLAYER_UTIL_POOL_H

#include <sys/time.h>

#include <map>
#include <string>

namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <typename Param> class Pool
{
public:
  /** TODO: Documentation */
  typedef Param Type;

  /** TODO: Documentation */
  typedef std::map <Type*, float> MapType;

private:
  /** Time to expire in milliseconds */
  float _expirationTime;

  /** TODO: Documentation */
  MapType _unlocked;

  /** TODO: Documentation */
  MapType _locked;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Pool(long expirationTime) :
    _expirationTime(expirationTime)
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  Param& acquire()
  {
    //    UnsignedWide tick;
    //    Microseconds(&tick);
    //    float now = (float) UnsignedWideToUInt64(tick);

    struct timeval tick;
    gettimeofday(&tick, NULL);    

    double time = tick.tv_usec;
    time /= 1000000;
    time += tick.tv_sec;

    float now = (float) time;

    Param* object = 0;

    if (_unlocked.size() > 0) {
      typename std::map <Param*, float>::iterator iterator;

      while (iterator != _unlocked.end()) {
        object = iterator->first;

        if ((now - _unlocked[object]) > _expirationTime) {
          _unlocked.erase(object);
          delete (&object);

        } else {
          _unlocked.erase(object);
          _locked[object] = now;
          return *object;

        }
      }

    } else {
      object = new Param();
      _locked[object] = now;

    }

    return *object;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  void release(Param& object)
  {
    //    UnsignedWide tick;
    //    Microseconds(&tick);

    //    _locked.erase(&object);
    //    _unlocked[&object] = (float) UnsignedWideToUInt64(tick);

    struct timeval tick;
    gettimeofday(&tick, NULL);    

    double time = tick.tv_usec;
    time /= 1000000;
    time += tick.tv_sec;

    _unlocked[&object] = (float) time;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  ~Pool()
  {
  }

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


#endif // PROTOLAYER_UTIL_POOL_H
