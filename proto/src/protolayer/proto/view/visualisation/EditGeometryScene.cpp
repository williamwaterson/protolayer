#include "EditGeometryScene.h"


/** TODO: Documentation */
namespace protolayer
{


EditGeometryScene::EditGeometryScene() :
  scenegraph::Scene::Scene(_root),
  _camera(5, 5, 5, 0, 0, 0)
{
  scenegraph::Group* cameraGroup = new scenegraph::Group();
  cameraGroup->addChild(_camera);
  getRoot().addChild(*cameraGroup);
  getRoot().update();
}


EditGeometryScene::~EditGeometryScene()
{
}


scenegraph::Camera& EditGeometryScene::getCamera()
{
  return _camera;
}


}
