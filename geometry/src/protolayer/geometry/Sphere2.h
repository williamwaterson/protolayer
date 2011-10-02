#ifndef PROTOLAYER_GEOMETRY_SPHERE_H
#define PROTOLAYER_GEOMETRY_SPHERE_H

#include <stdio.h>
#include "protolayer/protolayer-renderer.h"

namespace protolayer
{

namespace geometry
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Sphere : public renderer::Group
{
private:
  /** TODO: Documentation */
  float _radius;

  /** TODO: Documentation */
  renderer::Surface* _surface;
	 
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Sphere(float radius);

  /**
   * TODO: Documentation
   * <p>
   */
  float getRadius();

  /**
   * TODO: Documentation
   * <p>
   */
  void setRadius(float radius);

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::Surface& getSurface();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Sphere(const Sphere& sphere);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Sphere& operator=(const Sphere& sphere);

};


}


}


#endif // PROTOLAYER_GEOMETRY_SPHERE_H
