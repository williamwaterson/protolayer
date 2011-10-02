#ifndef PROTOLAYER_FX_ANIMATIONACTION_H
#define PROTOLAYER_FX_ANIMATIONACTION_H

#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-scenegraph.h"


namespace protolayer
{

namespace fx
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class AnimationAction : public animation::Action
{
private:
  /** TODO: Documentation */
  bool _inProgress;

  /** TODO: Documentation */
  float _timeStarted;

  /** TODO: Documentation */
  float _timePeriod;

  /** TODO: Documentation */
  float _timeElapsed;

  /** TODO: Documentation */
  float _fraction;

  /** TODO: Documentation */
  float _displace[3];

  /** TODO: Documentation */
  float _scale;

  /** TODO: Documentation */
  float _rotate;

  /** TODO: Documentation */
  float _originalTransform[4][4];

  /** TODO: Documentation */
  float _currentTransform[4][4];

  /** TODO: Documentation */
  float _multiplier[4][4];

  /** TODO: Documentation */
  scenegraph::Group* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  AnimationAction(long timePeriod,
                  scenegraph::Group& target,
                  float displace[3],
                  float rotate,
                  float scale);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(float timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setRotate(float rotate);

  /**
   * TODO: Documentation
   * <p>
   */
  void setScale(float scale);

  /**
   * TODO: Documentation
   * <p>
   */
  void setDisplacement(float displace[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setGroup(scenegraph::Group& group);

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
  AnimationAction(const AnimationAction& animationAction);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  AnimationAction& operator=(const AnimationAction& animationAction);

};


}


}


#endif // PROTOLAYER_FX_ANIMATIONACTION_H
