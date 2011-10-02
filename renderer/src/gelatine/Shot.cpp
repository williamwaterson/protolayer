#include "Shot.h"


namespace gelatine
{


Shot::Shot(Scene& scene, Camera& camera) :
  _camera(camera), _scene(scene) 
{
  if (!scene.getRoot().isPart(camera)) {
    throw;
  }
}


Camera& Shot::getCamera()
{
  return _camera;
}


Scene& Shot::getScene()
{
  return _scene;
}


void Shot::render()
{
  glLoadIdentity();
  _camera.targetCamera();
  _scene.render(_camera._alpha);
}


void Shot::renderInSelectionMode()
{
  glLoadIdentity();
  _camera.targetCamera();
  _scene.renderInSelectionMode(_camera._alpha);
}


}
