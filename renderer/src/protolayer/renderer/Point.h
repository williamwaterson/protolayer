#ifndef PROTOLAYER_RENDERER_POINT_H
#define PROTOLAYER_RENDERER_POINT_H


#include <set.h>

#include "protolayer/protolayer-util.h"

#include "forward.h"
#include "Appearance.h"


namespace protolayer
{

namespace renderer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class Point
{
public:
  /** TODO: Documentation */
  friend class Leaf;

private:
  /** TODO: Documentation */
  unsigned int _id;

  /** TODO: Documentation */
  float* _localCoordinates;

  /** TODO: Documentation */
  float* _globalCoordinates;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Point();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Point(float* localCoordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  Point(float* localCoordinates,
        float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Point();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getLocalCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  //  float* getGlobalCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  const float* getLocalCoordinates() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const float* getGlobalCoordinates() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setLocalCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setLocalCoordinates(float x, float y, float z, float w);

  /**
   * TODO: Documentation
   * <p>
   */
  void render(float alpha, Appearance& appearance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Point(const Point& point);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Point& operator=(const Point& point);

  /**
   * TODO: Documentation
   * <p>
   */
  void setCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setCoordinates(float x, float y, float z, float w);

};


}


}


#endif // PROTOLAYER_RENDERER_POINT_H
