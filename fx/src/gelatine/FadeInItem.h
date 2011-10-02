#ifndef PROTOLAYER_FADEINITEM_H
#define PROTOLAYER_FADEINITEM_H


#include "gelatine/gelatine-renderer.h"


namespace protolayer
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class FadeInItem : public Action
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
  Item* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  FadeInItem(long timePeriod, Item* target);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTarget(Item* target);

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
  FadeInItem(const FadeInItem& fadeInItem);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FadeInItem& operator=(const FadeInItem& fadeInItem);

};


}


#endif // PROTOLAYER_FADEINITEM_H
