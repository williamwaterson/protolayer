#ifndef PROTOLAYER_FX_DISSOLVE_H
#define PROTOLAYER_FX_DISSOLVE_H

#include <sys/time.h>

#include "gelatine/protolayer-renderer.h"


namespace protolayer
{

namespace fx
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Dissolve : public Transition
{
  /** The total time period for the overall transition */
  static const long UNITY = 1;

  /** The total time period for the overall transition */
  static const long ZERO = 0;

  /** The total time period for the overall transition */
  bool _inProgress;

  /** TODO: Documentation */
  //  UnsignedWide _tic;k
  struct timeval _tick;

  /** The total time period for the overall transition */
  float _timeStarted;

  /** The time elapsed since the transition was commenced */
  float _timeCurrent;

  /** The time elapsed since the transition was commenced */
  float _timeElapsed;

  /** The total time period for the overall transition */
  float _timePeriod;

public:
  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  Dissolve(float timePeriod);

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  virtual bool inProgress();

  /**
   * Performs a single increment in the transition from the initial shot
   * to the final shot according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial shot to the final
   * shot.
   * <p>
   * @param initialShot
   *
   * @param finalShot
   *
   */
  virtual void commence(Shot& initialShot, Shot& finalShot);

  /**
   * Performs a single increment in the transition from the initial shot
   * to the final shot according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial shot to the final
   * shot.
   * <p>
   * @param initialShot
   *
   * @param finalShot
   *
   */
  virtual void increment(Shot& initialShot, Shot& finalShot);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void postComplete(Shot& initialShot, Shot& finalShot);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Dissolve(const Dissolve& dissolve);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Dissolve& operator=(const Dissolve& dissolve);

};


}


}


#endif // PROTOLAYER_FX_DISSOLVE_H
