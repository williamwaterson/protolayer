#ifndef PROTOLAYER_RENDERER_SHOT_H
#define PROTOLAYER_RENDERER_SHOT_H

#include "Mouse.h"
#include "ProjectedMouse.h"
#include "SelectionPlane.h"
#include "forward.h"

#include <protolayer/protolayer-scenegraph.h>


namespace protolayer
{

namespace renderer
{

/**
 * TODO: Documentation
 * <p>
 */
class Shot
{
private:
  /** TODO: Documentation */
  static const GLsizei BUFFER_SIZE = 32;

  /** TODO: Documentation */
  GLuint _selectBuffer[BUFFER_SIZE];

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
  GLint _viewport[4];

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
  bool isRenderable();

  /**
   * TODO: Documentation
   *
   */
  bool isSelectable();

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

  /**
   * TODO: Documentation
   *
   */
  void render();

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

  /**
   * TODO: Documentation
   *
   */
  void renderInSelectionMode();

  /**
   * TODO: Documentation
   *
   */
  void preSelectionMode();

  /**
   * TODO: Documentation
   *
   */
  void postSelectionMode();

  /**
   * TODO: Documentation
   *
   */
  int* processHits(int hits, GLuint buffer[], int* numberNames);

  /**
   * TODO: Documentation
   *
   */
  void evalPlanarMousePosition();

  /**
   * TODO: Documentation
   *
   */
  GLuint* getSelectBuffer();

};


}


}


#endif // PROTOLAYER_RENDERER_SHOT_H
