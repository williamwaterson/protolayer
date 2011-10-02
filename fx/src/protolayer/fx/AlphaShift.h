#ifndef PROTOLAYER_FX_ALPHASHIFT_H
#define PROTOLAYER_FX_ALPHASHIFT_H


#include "protolayer/protolayer-animation.h"
#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-style.h"


namespace protolayer
{

namespace fx
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class AlphaShift : public animation::Action
{
private:
  /** TODO: Documentation */
  bool _inProgress;

  /** TODO: Documentation */
  float _timeStarted;

  /** TODO: Documentation */
  float _timeElapsed;

  /** TODO: Documentation */
  float _timePeriod;

  /** TODO: Documentation */
  float _alphaRate;

  /** TODO: Documentation */
  float _initialAlpha;

  /** TODO: Documentation */
  float _finalAlpha;

  /** TODO: Documentation */
  style::Appearance* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  AlphaShift(float timePeriod, style::Appearance& target, float finalAlpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(float timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTarget(style::Appearance& target);

  /**
   * TODO: Documentation
   * <p>
   */
  void setFinalAlpha(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void commence(float timeStarted);

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  bool inProgress();

  /**
   * Performs a single increment in the action over time.
   * <p>
   */
  void increment(float timeCurrent);

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
  AlphaShift(const AlphaShift& alphaShift);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  AlphaShift& operator=(const AlphaShift& alphaShift);

};


}


}


#endif // PROTOLAYER_FX_ALPHASHIFT_H
