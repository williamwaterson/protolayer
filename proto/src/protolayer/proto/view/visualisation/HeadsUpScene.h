#ifndef MESON_HEADSUPSCENE_H
#define MESON_HEADSUPSCENE_H

#include <vector>
#include <vector>

#include "../../forward.h"
#include "HeadsUpControl.h"


/** TODO: Documentation */
namespace protolayer
{

namespace proto
{

class HeadsUpScene : public scenegraph::Scene
{
private:
  /** TODO: Documentation */
  scenegraph::Group _root;

  /** TODO: Documentation */
  scenegraph::Camera _camera;

  /** TODO: Documentation */
  HeadsUpControl* _headsUpControl;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HeadsUpScene();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~HeadsUpScene();

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Camera& getCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  HeadsUpControl& getHeadsUpControl();

};


}


}


#endif // MESON_HEADSUPSCENE_H
