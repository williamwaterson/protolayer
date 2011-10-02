#ifndef PROTOLAYER_FX_MOVENODE_H
#define PROTOLAYER_FX_MOVENODE_H


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
class MoveNode : public renderer::Action
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
  float _finalPosition[3];

  /** TODO: Documentation */
  float _oldPosition[3];

  /** TODO: Documentation */
  float _direction[3];

  /** TODO: Documentation */
  float _targetDirection[3];

  /** TODO: Documentation */
  renderer::Camera* _camera;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  MoveNode(long timePeriod,
           renderer::Node& node,
           float finalPosition[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setFinalPosition(float finalPosition[3]);

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
  MoveNode(const MoveNode& moveNode);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  MoveNode& operator=(const MoveNode& moveNode);

};


}


}


#endif // PROTOLAYER_FX_MOVENODE_H
