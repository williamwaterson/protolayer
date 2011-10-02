#ifndef PROTOLAYER_MOVENODE_H
#define PROTOLAYER_MOVENODE_H


#include "gelatine/gelatine-renderer.h"


namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class TransformAnimation : public Action
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
  float _displacement[3];

  /** TODO: Documentation */
  float _scale;

  /** TODO: Documentation */
  float _rotate;

  /** TODO: Documentation */
  float _originalTransform[4][4];

  /** TODO: Documentation */
  Group* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  MoveNode(long timePeriod,
           Group& target,
           float displace[3],
           float rotate,
           float scale);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setDisplacement(displacement[3]);

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


#endif // PROTOLAYER_MOVENODE_H
