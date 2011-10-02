#ifndef MESON_PERSPECTIVE_H
#define MESON_PERSPECTIVE_H

#include <iostream>

#include "../forward.h"

#include "../view/ViewLayer.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Perspective
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Perspective();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Perspective() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void activate(ViewLayer& view) = 0;

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  Perspective(const Perspective& perspective);

  /**
   * TODO: Documentation
   * <p>
   */
  Perspective& operator=(const Perspective& perspective);

};


}


}


#endif MESON_PERSPECTIVE_H
