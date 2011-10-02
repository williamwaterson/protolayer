#ifndef MESON_EDITGEOMETRYSCENE_H
#define MESON_EDITGEOMETRYSCENE_H


/** File header inclusions */
#include <vector>

#include "../../forward.h"
#include "ReferenceArrow.h"
#include "LayerHexMesh.h"
#include "DomainNode.h"


/** TODO: Documentation */
namespace protolayer
{


class EditGeometryScene : public scenegraph::Scene
{
private:
  /** TODO: Documentation */
  scenegraph::Camera _camera;

  /** TODO: Documentation */
  scenegraph::Group _root;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  EditGeometryScene();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~EditGeometryScene();

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Camera& getCamera();

private:
  /**
   * TODO: Documentation
   * <p>
   */
  EditGeometryScene(const EditGeometryScene& scene);

  /**
   * TODO: Documentation
   * <p>
   */
  EditGeometryScene& operator=(const EditGeometryScene& scene);

};


}


#endif // MESON_EDITGEOMETRYSCENE_H
