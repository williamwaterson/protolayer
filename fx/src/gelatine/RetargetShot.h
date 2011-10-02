#ifndef PROTOLAYER_RETARGETSHOT_H
#define PROTOLAYER_RETARGETSHOT_H


#include "gelatine/gelatine-renderer.h"


namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class RetargetShot : public Action
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
  float _newTarget[3];

  /** TODO: Documentation */
  float _oldTarget[3];

  /** TODO: Documentation */
  float _direction[3];

  /** TODO: Documentation */
  Camera* _camera;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  RetargetShot(long timePeriod,
               Camera* camera,
               float newTarget[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTarget(float newTarget[3]);

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
  RetargetShot(const RetargetShot& retargetShot);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RetargetShot& operator=(const RetargetShot& retargetShot);

};


}


#endif // PROTOLAYER_RETARGETSHOST_CPP
