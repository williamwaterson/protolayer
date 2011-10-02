#ifndef GELATINE_CAMERA_H
#define GELATINE_CAMERA_H

#include "forward.h"
#include "Leaf.h"
#include "Point.h"

namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class Camera : public Leaf
{
  friend class Shot;

private:
  /** TODO: Documentation */
  float _orient[3];

  /** TODO: Documentation */
  Point* _positionPoint;

  /** TODO: Documentation */
  Point* _targetPoint;

  /** TODO: Documentation */
  float _localPosition[4];

  /** TODO: Documentation */
  float _localTarget[4];

  /** TODO: Documentation */
  float _position[4];

  /** TODO: Documentation */
  float _target[4];

  /** TODO: Documentation */
  float _alpha;

  /** TODO: Documentation */
  float _fieldOfView;

  /** TODO: Documentation */
  float _zoom;

public:
  /**
   * TODO: Documentation
   *
   */
  Camera(float x,
         float y,
         float z);

  /**
   * TODO: Documentation
   *
   */
  Camera(float x,
         float y,
         float z,
         float targetx,
         float targety,
         float targerz);

  /**
   * TODO: Documentation
   *
   */
  void targetCamera();

  /**
   * TODO: Documentation
   *
   */
  float getZoom() const;

  /**
   * TODO: Documentation
   *
   */
  float getAlpha() const;

  /**
   * TODO: Documentation
   *
   */
  const float* getOrient() const;

  /**
   * TODO: Documentation
   *
   */
  const float* getPosition() const;

  /**
   * TODO: Documentation
   *
   */
  const float* getTarget() const;

  /**
   * TODO: Documentation
   *
   */
  const float* getGlobalPosition() const;

  /**
   * TODO: Documentation
   *
   */
  const float* getGlobalTarget() const;

  /**
   * TODO: Documentation
   *
   */
  Point& getPositionPoint();

  /**
   * TODO: Documentation
   *
   */
  Point& getTargetPoint();

  /**
   * TODO: Documentation
   *
   */
  void setAlpha(float alpha);

  /**
   * TODO: Documentation
   *
   */
  void setZoom(float zoom);

  /**
   * TODO: Documentation
   *
   */
  void setTarget(float target[3]);

  /**
   * TODO: Documentation
   *
   */
  void setPosition(float position[3]);

  /**
   * TODO: Documentation
   *
   */
  void prepareShot();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Camera(const Camera& camera);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Camera& operator=(const Camera& camera);

};


}


#endif // GELATINE_CAMERA_H
