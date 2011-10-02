#ifndef PROTOLAYER_FX_TRANSITION_H
#define PROTOLAYER_FX_TRANSITION_H

#include <sys/time.h>

#include "protolayer/protolayer-renderer.h"

namespace protolayer
{

namespace fx
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Transition : public animation::TransitionAction
{
  /** The total time period for the overall transition */
  static const long UNITY = 1;

  /** The total time period for the overall transition */
  static const long ZERO = 0;

  /** The total time period for the overall transition */
  bool _inProgress;

  /** TODO: Documentation */
  //  UnsignedWide _tick;
  struct timeval _tick;

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
  float _secondShotStartPosition[3];

  /** TODO: Documentation */
  float _secondShotStartTarget[3];

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
  Transition(float timePeriod,
             scenegraph::Shot& initialShot,
	     scenegraph::Shot& finalShot);

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
  virtual void commence(float timeStarted);

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
  virtual void increment(float timeCurrent);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void postComplete();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Transition(const Transition& transition);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Transition& operator=(const Transition& transition);

};


}


}


#endif // PROTOLAYER_FX_TRANSITION_H
