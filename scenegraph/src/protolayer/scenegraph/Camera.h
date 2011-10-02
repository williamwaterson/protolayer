#ifndef PROTOLAYER_SCENEGRAPH_CAMERA_H
#define PROTOLAYER_SCENEGRAPH_CAMERA_H

#include "Leaf.h"
#include "Point.h"
#include "TransformedPoint.h"


namespace protolayer
{

namespace scenegraph
{

/**
 * TODO: Documentation
 * <p>
 */
class Camera : public Leaf
{
private:
  /** TODO: Documentation */
  float _alpha;

  /** TODO: Documentation */
  float _fieldOfView;

  /** TODO: Documentation */
  float _zoom;

  /** TODO: Documentation */
  float _orient[3];

  /** TODO: Documentation */
  Point* _localPosition;

  /** TODO: Documentation */
  Point* _localTarget;

  /** TODO: Documentation */
  TransformedPoint* _globalPosition;

  /** TODO: Documentation */
  TransformedPoint* _globalTarget;

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
  ~Camera();

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
  TransformedPoint& getPosition();

  /**
   * TODO: Documentation
   *
   */
  TransformedPoint& getTarget();

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


}


#endif // PROTOLAYER_SCENEGRAPH_CAMERA_H
