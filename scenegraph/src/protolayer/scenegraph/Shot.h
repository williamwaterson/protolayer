#ifndef PROTOLAYER_SCENEGRAPH_SHOT_H
#define PROTOLAYER_SCENEGRAPH_SHOT_H

#include "Mouse.h"
#include "ProjectedMouse.h"
#include "SelectionPlane.h"

#include "Camera.h"
#include "Scene.h"
#include "Dimensions.h"
#include "HitModel.h"


namespace protolayer
{

namespace scenegraph
{

/**
 * TODO: Documentation
 * <p>
 */
class Shot
{
private:
  /** TODO: Documentation */
  bool _depthCulling;

  /** TODO: Documentation */
  bool _renderable;

  /** TODO: Documentation */
  bool _selectable;

  /** TODO: Documentation */
  bool _cullFaceBack;

  /** TODO: Documentation */
  bool _cullFaceFront;

  /** TODO: Documentation */
  double _win[3];

  /** TODO: Documentation */
  double _near[3];

  /** TODO: Documentation */
  double _far[3];

  /** TODO: Documentation */
  double _modelMatrix[16];

  /** TODO: Documentation */
  double _projMatrix[16];

  /** TODO: Documentation */
  scenegraph::Camera& _camera;

  /** TODO: Documentation */
  Mouse _mouse;

  /** TODO: Documentation */
  scenegraph::Scene& _scene;

  /** TODO: Documentation */
  scenegraph::Dimensions _dimensions;

  /** TODO: Documentation */
  scenegraph::HitModel* _hitModel;

  /** TODO: Documentation */
  ProjectedMouse _projectedMouse;

  /** TODO: Documentation */
  SelectionPlane _selectionPlane;

public:
  /**
   * TODO: Documentation
   *
   */
  Shot(scenegraph::Scene& scene, scenegraph::Camera& camera);

  /**
   * TODO: Documentation
   *
   */
  virtual ~Shot();

  /**
   * TODO: Documentation
   *
   */
  bool isRenderable() const;

  /**
   * TODO: Documentation
   *
   */
  bool isSelectable() const;

  /**
   *  TODO: Documentation
   *
   */
  bool hasDepthCulling() const;

  /**
   *  TODO: Documentation
   *
   */
  bool hasBackFaceCulling() const;

  /**
   *  TODO: Documentation
   *
   */
  bool hasFrontFaceCulling() const;

  /**
   * TODO: Documentation
   *
   */
  void setDepthCulling(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setBackFaceCull(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setFrontFaceCull(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setRenderable(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setSelectable(bool flag);

  /**
   * TODO: Documentation
   *
   */
  scenegraph::Scene& getScene();

  /**
   * TODO: Documentation
   *
   */
  scenegraph::Camera& getCamera();

  /**
   * TODO: Documentation
   *
   */
  Mouse& getMouse();

  /**
   * TODO: Documentation
   *
   */
  ProjectedMouse& getProjectedMouse();

  /**
   * TODO: Documentation
   *
   */
  SelectionPlane& getSelectionPlane();

  /**
   * TODO: Documentation
   *
   */
  scenegraph::Dimensions& getDimensions();

  /**
   * TODO: Documentation
   *
   */
  scenegraph::HitModel& getHitModel();

  /**
   * TODO: Documentation
   *
   */
  void resize(short width, short height);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shot(const Shot& Shot);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shot& operator=(const Shot& Shot);

};


}


}


#endif // PROTOLAYER_SCENEGRAPH_SHOT_H
