#ifndef PROTOLAYER_FX_SWEEPSHOT_H
#define PROTOLAYER_FX_SWEEPSHOT_H


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
class SweepShot : public renderer::Action
{
private:
  /** TODO: Documentation */
  bool _inProgress;

  /** TODO: Documentation */
  long _timeStarted;

  /** TODO: Documentation */
  long _timePeriod;

  /** TODO: Documentation */
  long _timeElapsed;

  /** TODO: Documentation */
  float _fraction;

  /** TODO: Documentation */
  Renderer::Item* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  SweepShot(long timePeriod, Renderer::Item* target);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTarget(Renderer::Item* target);

  /**
   * TODO: Documentation
   * <p>
   */
  void commence(long timeStarted);

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  bool inProgress();

  /**
   * Performs a single increment in the action over time.
   * <p>
   */
  void increment(long timeCurrent);

  /**
   * TODO: Documentation
   * <p>
   */
  void postComplete();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SweepShot(const SweepShot& sweepShot);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SweepShot& operator=(const SweepShot& sweepShot);

};


}


}


#endif // ACTIONS_SWEEPSHOT_H
