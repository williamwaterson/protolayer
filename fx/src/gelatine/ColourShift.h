#ifndef PROTOLAYER_COLOURSHIFT_H
#define PROTOLAYER_COLOURSHIFT_H


#include "gelatine/gelatine-renderer.h"


namespace protolayer
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ColourShift : public Action
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
  float _finalEdgeColour[4];

  /** TODO: Documentation */
  float _finalFaceColour[4];

  /** TODO: Documentation */
  float _initialEdgeColour[4];

  /** TODO: Documentation */
  float _initialFaceColour[4];

  /** TODO: Documentation */
  float _deltaEdgeColour[4];

  /** TODO: Documentation */
  float _deltaFaceColour[4];

  /** TODO: Documentation */
  Item* _target;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ColourShift(long timePeriod,
              Item& target,
              float finalColour[4]);

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
  ColourShift(const ColourShift& colourShift);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ColourShift& operator=(const ColourShift& colourShift);

};


}


#endif // PROTOLAYER_COLOURSHIFT_H
