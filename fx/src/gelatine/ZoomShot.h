#ifndef PROTOLAYER_ZOOMSHOT_H
#define PROTOLAYER_ZOOMSHOT_H


#include "gelatine/gelatine-renderer.h"


namespace protolayer
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ZoomShot : public Action
{
private:
  /** TODO: Documentation */
  bool _inProgress;

  /** TODO: Documentation */
  Camera* _camera;

  /** TODO: Documentation */
  long _timeStarted;

  /** TODO: Documentation */
  long _timePeriod;

  /** TODO: Documentation */
  long _timeElapsed;

  /** TODO: Documentation */
  float _finalZoom;

  /** TODO: Documentation */
  float _initialZoom;

  /** TODO: Documentation */
  float _differenceZoom;

  /** TODO: Documentation */
  float _fraction;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ZoomShot(long timePeriod,
           Camera* camera,
           float finalZoom);

  /**
   * TODO: Documentation
   * <p>
   */
  void setTimePeriod(long timePeriod);

  /**
   * TODO: Documentation
   * <p>
   */
  void setFinalPosition(float finalZoom);

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
  ZoomShot(const ZoomShot& zoomShot);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ZoomShot& operator=(const ZoomShot& zoomShot);

};


}


#endif // PROTOLAYER_ZOOMSHOT_H
