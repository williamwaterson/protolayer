#ifndef MESON_INSTANCEPERSPECTIVE_H
#define MESON_INSTANCEPERSPECTIVE_H

#include <iostream>

#include "../forward.h"

#include "Perspective.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class InstancePerspective : public Perspective
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  InstancePerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~InstancePerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void activate(ViewLayer& view);

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  InstancePerspective(const InstancePerspective& instancePerspective);

  /**
   * TODO: Documentation
   * <p>
   */
  InstancePerspective& operator=(const InstancePerspective& instancePerspective);

};


}


}


#endif MESON_INSTANCEPERSPECTIVE_H
