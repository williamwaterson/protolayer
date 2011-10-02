#include "Shot.h"


namespace protolayer
{

namespace scenegraph
{

Shot::Shot(Scene& scene, Camera& camera) :
  _camera(camera), _scene(scene) 
{
  _hitModel = new HitModel();

  _renderable = true;
  _selectable = true;
  _depthCulling = true;

  _cullFaceBack = false;
  _cullFaceFront = false;

  if (!scene.getRoot().isPart(camera)) {
    throw;
  }
}


Shot::~Shot()
{
  delete _hitModel;
}


bool
Shot::isRenderable() const
{
  return _renderable;
}


bool
Shot::isSelectable() const
{
  return _selectable;
}


/**
 *  TODO: Documentation
 *
 */
bool Shot::hasDepthCulling() const
{
  return _depthCulling;
}


/**
 *  TODO: Documentation
 *
 */
bool Shot::hasBackFaceCulling() const
{
  return _cullFaceBack;
}


/**
 *  TODO: Documentation
 *
 */
bool Shot::hasFrontFaceCulling() const
{
  return _cullFaceFront;
}


void
Shot::setBackFaceCull(bool flag)
{
  _cullFaceBack = flag;
}


void
Shot::setFrontFaceCull(bool flag)
{
  _cullFaceFront = flag;
}


void
Shot::setDepthCulling(bool flag)
{
  _depthCulling = flag;
}


void
Shot::setRenderable(bool flag)
{
  _renderable = flag;
}


void
Shot::setSelectable(bool flag)
{
  _selectable = flag;
}


Camera& Shot::getCamera()
{
  return _camera;
}


Scene& Shot::getScene()
{
  return _scene;
}


Mouse& Shot::getMouse()
{
  return _mouse;
}


ProjectedMouse& Shot::getProjectedMouse()
{
  return _projectedMouse;
}


Dimensions& Shot::getDimensions()
{
  return _dimensions;
}


HitModel& Shot::getHitModel()
{
  return *_hitModel;
}


SelectionPlane& Shot::getSelectionPlane()
{
  return _selectionPlane;
}


void Shot::resize(short width, short height)
{
  _dimensions.setDimensions(width, height);
}


}


}
