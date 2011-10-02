#ifndef MESON_HEADSUPCONTROL_H
#define MESON_HEADSUPCONTROL_H

#include "protolayer/protolayer-geometry.h"

#include "../../forward.h"

namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class HeadsUpControl : public scenegraph::Group
{
  /** TODO: Documentation */
  geometry::ArrowDisk* _upArrow;

  /** TODO: Documentation */
  geometry::ArrowDisk* _downArrow;

  /** TODO: Documentation */
  geometry::Target* _viewChangeControl;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HeadsUpControl(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  geometry::ArrowDisk& getUpArrow();

  /**
   * TODO: Documentation
   * <p>
   */
  geometry::ArrowDisk& getDownArrow();

  /**
   * TODO: Documentation
   * <p>
   */
  geometry::Target& getViewChangeControl();

};


}


}


#endif // MESON_HEADSUPCONTROL_H
