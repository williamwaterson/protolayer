#ifndef PROTOLAYER_PUSHDISSOLVE_H
#define PROTOLAYER_PUSHDISSOLVE_H


#include <AGL/agl.h>
#include "gelatine/gelatine-renderer.h"


namespace protolayer
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class PushDissolve : public Transition
{
  /** The total time period for the overall transition */
  static const long UNITY = 1;

  /** The total time period for the overall transition */
  static const long ZERO = 0;

  /** The total time period for the overall transition */
  bool _inProgress;

  /** TODO: Documentation */
  UnsignedWide _tick;

  /** The total time period for the overall transition */
  float _timeStarted;

  /** The time elapsed since the transition was commenced */
  float _timeCurrent;

  /** The time elapsed since the transition was commenced */
  float _timeElapsed;

  /** The total time period for the overall transition */
  float _timePeriod;

  /** The total time period for the overall transition */
  float _startPosition[3];

  /** The total time period for the overall transition */
  float _startTarget[3];

  /** TODO: Documentation */
  float _finalStartPosition[3];

  /** TODO: Documentation */
  float _finalStartTarget[3];

  /** The total time period for the overall transition */
  float _targetPosition[3];

  /** The total time period for the overall transition */
  float _transitionDirection[3];

  /** The total time period for the overall transition */
  float _transitionDirection2[3];

  /** The total time period for the overall transition */
  float _displacement[3];

public:
  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  PushDissolve(float timePeriod);

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  void setTargetPoint(float x, float y, float z);

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
  PushDissolve(const PushDissolve& pushDissolve);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  PushDissolve& operator=(const PushDissolve& pushDissolve);

};


}


#endif // PROTOLAYER_PUSHDISSOLVE_H
