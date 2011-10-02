#ifndef PROTOLAYER_GEOMETRY_DISK_H
#define PROTOLAYER_GEOMETRY_DISK_H

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
class Disk
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
  Disk(float radius);

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
  Disk(const Disk& disk);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Disk& operator=(const Disk& disk);

};


}


}


#endif // PROTOLAYER_GEOMETRY_DISK_H
