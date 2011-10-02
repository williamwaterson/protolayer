#ifndef PROTOLAYER_FX_FADEOUTNODE_H
#define PROTOLAYER_FX_FADEOUTNODE_H


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
class FadeOutNode : public animation::Action
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
  style::Appearance* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  FadeOutNode(long timePeriod, style::Appearance* target);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTarget(style::Appearance* target);

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
  FadeOutNode(const FadeOutNode& fadeOutNode);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FadeOutNode& operator=(const FadeOutNode& fadeOutNode);

};


}


}


#endif // PROTOLAYER_FX_FADEOUTNODE_H
