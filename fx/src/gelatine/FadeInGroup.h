#ifndef PROTOLAYER_FADEINNODE_H
#define PROTOLAYER_FADEINNODE_H


#include "gelatine/gelatine-renderer.h"


namespace protolayer
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class FadeInNode : public Action
{
private:
  /** TODO: Documentation */
  bool _inProgress;

  /** TODO: Documentation */
  long _timeStarted;

  /** TODO: Documentation */
  long _timeElapsed;

  /** TODO: Documentation */
  long _timePeriod;

  /** TODO: Documentation */
  float _fraction;

  /** TODO: Documentation */
  Node* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  FadeInNode(long timePeriod, Node& target);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTarget(Node& target);

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
  FadeInNode(const FadeInNode& fadeInNode);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FadeInNode& operator=(const FadeInNode& fadeInNode);

};


}


#endif // PROTOLAYER_FADEINNODE_H
