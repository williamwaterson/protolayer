#ifndef PROTOLAYER_FX_FADEOUTITEM_CPP
#define PROTOLAYER_FX_FADEOUTITEM_CPP


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
class FadeOutItem : public Action
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
  Item* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  FadeOutItem(long timePeriod, Item* target);

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
  FadeOutItem(const FadeOutItem& fadeOutItem);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FadeOutItem& operator=(const FadeOutItem& fadeOutItem);

};


}


}


#endif // PROTOLAYER_FX_FADEOUTITEM_CPP
