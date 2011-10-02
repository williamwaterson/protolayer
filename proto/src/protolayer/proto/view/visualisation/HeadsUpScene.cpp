#include "HeadsUpScene.h"


/** TODO: Documentation */
namespace protolayer
{

namespace proto
{

HeadsUpScene::HeadsUpScene() :
  _camera(0, 0, 10, 0, 0, 0),
  _root(),
  scenegraph::Scene::Scene(_root)
{
  _root.addChild(_camera);

  _headsUpControl = new HeadsUpControl(0, 0, 0);
  //  _root.addChild(*_headsUpControl);

  _headsUpControl->translate(2.0f, -2.0f, 0);
}


HeadsUpScene::~HeadsUpScene()
{
}


scenegraph::Camera& HeadsUpScene::getCamera()
{
  return _camera;
}


HeadsUpControl& HeadsUpScene::getHeadsUpControl()
{
  return *_headsUpControl;
}


}


}
