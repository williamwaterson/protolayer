#ifndef MESON_RENDERINGSTATE_H
#define MESON_RENDERINGSTATE_H

#include <iostream>

#include "../forward.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class RenderingState
{
private:
  /** TODO: Documentation */
  scenegraph::Shot* _activeShot;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  explicit RenderingState(scenegraph::Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RenderingState();

  /**
   * TODO: Documentation
   * <p>
   */
  void setActiveShot(scenegraph::Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Shot& getActiveShot();

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  RenderingState(const RenderingState& state);

  /**
   * TODO: Documentation
   * <p>
   */  
  RenderingState& operator=(const RenderingState& state);

};


}


}


#endif MESON_RENDERINGSTATE_H
