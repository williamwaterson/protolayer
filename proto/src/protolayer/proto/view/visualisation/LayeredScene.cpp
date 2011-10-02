#include "LayeredScene.h"


namespace protolayer
{

namespace proto
{

const float LayeredScene::VERTICAL_SPACING = 2;


LayeredScene::LayeredScene(assembly::Domain& domain) :
  _root(),
  scenegraph::Scene::Scene(_root),
  _layers(domain.getNumberLayers()),
  _camera(5, 5, 5, 0, 0, 0)
{
  _domain = &domain;

  int numberLayers = domain.getNumberLayers();

  float y = 0;
  LayerHexMesh* layerHexMesh = 0;
  for (int i = 0; i < numberLayers; i++) {
    assembly::Layer& layer = domain.getLayer(i);
    layerHexMesh = new LayerHexMesh(layer);
    getRoot().addChild(*layerHexMesh);
    layerHexMesh->translate(0, y, 0);
    _layers[i] = layerHexMesh;
    y += VERTICAL_SPACING;
  }

  _activeLayer = *(_layers.begin());
  _previousLayer = 0;

  _activeHexMesh = new geometry::HexMesh(1.0f, 10, *(new style::Appearance()));
  _dormantHexMesh = new geometry::HexMesh(1.0f, 10, *(new style::Appearance()));

  _dormantHexMesh->getAppearance().setColor(0.0f, 0.0f, 0.0f, 0.2f);

  _activeHexMesh->getAppearance().setColor(0.0f, 0.0f, 0.0f, 0.2f);
  _activeLayer->addChild(*_activeHexMesh);

  _cameraGroup = new scenegraph::Group();
  _cameraGroup->addChild(_camera);
  getRoot().addChild(*_cameraGroup);
  getRoot().update();

  float displace[3];
  displace[0] = 0;
  displace[1] = -VERTICAL_SPACING;
  displace[2] = 0;
  _moveCameraAction = new fx::AnimationAction(300000,
					      *_cameraGroup,
					      displace, 0, 1);

  _camera.update();

  _alphaShiftDisappear = new fx::AlphaShift(300000, _activeHexMesh->getAppearance(), 0);
  _alphaShiftAppear = new fx::AlphaShift(300000, _dormantHexMesh->getAppearance(), 1);
  //  _alphaShiftDim = new fx::AlphaShift(300000, _previousLayer->getAppearance(), 0.1);
  _alphaShiftDim = new fx::AlphaShift(300000, _activeLayer->getFaceAppearance(), 0.1);
  _alphaShiftBrighten = new fx::AlphaShift(300000, _activeLayer->getFaceAppearance(), 1);
  _alphaShiftNodeDisappear = new fx::AlphaShift(300000, _activeLayer->getFaceAppearance(), 0);

  _alphaShiftDimEdges = new fx::AlphaShift(300000, _activeLayer->getEdgeAppearance(), 0.1);
  _alphaShiftBrightenEdges = new fx::AlphaShift(300000, _activeLayer->getEdgeAppearance(), 1);
  _alphaShiftNodeDisappearEdges = new fx::AlphaShift(300000, _activeLayer->getEdgeAppearance(), 0);
}


LayeredSceneSelectionModel& LayeredScene::getSelectionModel()
{
  return _selectionModel;
}


/*
LayeredScene::LayeredScene(assembly::Assembly& assembly) :
  _root(),
  scenegraph::Scene::Scene(_root),
  _layers(assembly.getNumberLayers()),
  _camera(5, 5, 5, 0, 0, 0)
{
  int numberLayers = assembly.getNumberLayers();
  //  _assembly = &assembly;

  float y = 0;
  LayerHexMesh* layer = 0;
  for (int i = 0; i < numberLayers; i++) {
    layer = new LayerHexMesh();
    getRoot().addChild(*layer);
    layer->translate(0, y, 0);
    _layers[i] = layer;
    y += VERTICAL_SPACING;
  }

  _activeLayer = *(_layers.begin());
  _previousLayer = 0;

  _activeHexMesh = new geometry::HexMesh(1.0f, 10, *(new style::Appearance()));
  _dormantHexMesh = new geometry::HexMesh(1.0f, 10, *(new style::Appearance()));

  _activeHexMesh->getAppearance().setColor(0.0f, 0.0f, 0.0f, 1.0f);
  _dormantHexMesh->getAppearance().setColor(0.0f, 0.0f, 0.0f, 1.0f);

  _activeLayer->addChild(*_activeHexMesh);

  _cameraGroup = new scenegraph::Group();
  _cameraGroup->addChild(_camera);
  getRoot().addChild(*_cameraGroup);
  getRoot().update();

  float displace[3];
  displace[0] = 0;
  displace[1] = -VERTICAL_SPACING;
  displace[2] = 0;
  _moveCameraDownLayerAction = new fx::AnimationAction(300000,
                                                       *_cameraGroup,
                                                       displace, 0, 1);

  displace[0] = 0;
  displace[1] = VERTICAL_SPACING;
  displace[2] = 0;
  _moveCameraUpLayerAction = new fx::AnimationAction(300000,
                                                     *_cameraGroup,
                                                     displace, 0, 1);

  _camera.update();

  _alphaShiftDisappear = new fx::AlphaShift(300000, _activeHexMesh->getAppearance(), 0);
  _alphaShiftAppear = new fx::AlphaShift(300000, _dormantHexMesh->getAppearance(), 1);
  //  _alphaShiftDim = new fx::AlphaShift(300000, _previousLayer->getAppearance(), 0.1);
  _alphaShiftDim = new fx::AlphaShift(300000, _activeLayer->getFaceAppearance(), 0.1);
  _alphaShiftBrighten = new fx::AlphaShift(300000, _activeLayer->getFaceAppearance(), 1);
  _alphaShiftNodeDisappear = new fx::AlphaShift(300000, _activeLayer->getFaceAppearance(), 0);

  _alphaShiftDimEdges = new fx::AlphaShift(300000, _activeLayer->getEdgeAppearance(), 0.1);
  _alphaShiftBrightenEdges = new fx::AlphaShift(300000, _activeLayer->getEdgeAppearance(), 1);
  _alphaShiftNodeDisappearEdges = new fx::AlphaShift(300000, _activeLayer->getEdgeAppearance(), 0);

  //  Group* tg0 = new Group();

  //  Group* tg = new Group();
  //  tg->addChild(*(new LayerHexMesh(0, 0, 0)));
  //  tg->addChild(*(new InstanceNode(0, 0, 0)));

  //  InstanceNode* np = new InstanceNode(1, 0, 0);
  //  np->rotateX(3.142/2);
  //tg->addChild(*np);
  //  tg0->addChild(*tg);

  //    getView().addChild(*tg0);
  //  getView().addChild(_camera);

  //  DomainNode* prism = new DomainNode(3);
  //  getView().addChild(*prism);
  //prism->rotateY(3.2);

  //  getView().update();

  //  getRoot().addChild(_camera);
  //  getRoot().update();
*/
  //  NurbsGeometry* ng = new NurbsGeometry();
  /*
  ng->add(*(new ControlPoint ( -1.5, -1.5,  4.0)));
  ng->add(*(new ControlPoint ( -0.5, -1.5,  2.0)));
  ng->add(*(new ControlPoint (  0.5, -1.5, -1.0)));
  ng->add(*(new ControlPoint (  1.5, -1.5,  2.0)));

  ng->add(*(new ControlPoint ( -1.5, -0.5,  1.0)));
  ng->add(*(new ControlPoint ( -0.5, -0.5,  3.0)));
  ng->add(*(new ControlPoint (  0.5, -0.5,  0.0)));
  ng->add(*(new ControlPoint (  1.5, -0.5, -1.0)));

  ng->add(*(new ControlPoint ( -1.5,  0.5,  4.0)));
  ng->add(*(new ControlPoint ( -0.5,  0.5,  0.0)));
  ng->add(*(new ControlPoint (  0.5,  0.5,  3.0)));
  ng->add(*(new ControlPoint (  1.5,  0.5,  4.0)));

  ng->add(*(new ControlPoint ( -1.5, 1.5, -2.0)));
  ng->add(*(new ControlPoint ( -0.5, 1.5, -2.0)));
  ng->add(*(new ControlPoint (  0.5, 1.5,  0.0)));
  ng->add(*(new ControlPoint (  1.5, 1.5, -1.0)));
  */

  /*
  float** cpts;
  cpts = new float* [4];
  for (int i = 0; i < 4; i++) {
    cpts[i] = new float [4];
  }

  cpts[0][0] = -4.0;
  cpts[0][1] = -4.0;
  cpts[0][2] = 0.0;
  cpts[0][3] = 1.0;

  cpts[1][0] = -2.0;
  cpts[1][1] = 4.0;
  cpts[1][2] = 0.0;
  cpts[1][3] = 1.0;

  cpts[2][0] = 2.0;
  cpts[2][1] = -4.0;
  cpts[2][2] = 0.0;
  cpts[2][3] = 1.0;

  cpts[3][0] = 4.0;
  cpts[3][1] = 4.0;
  cpts[3][2] = 0.0;
  cpts[3][3] = 1.0;

  renderer::Curve* curve = new gelatine::Curve(4, cpts);
  ng->add(*curve);

  float*** cpts2;
  cpts2 = new float** [4];
  for (int i = 0; i < 4; i++) {
    cpts2[i] = new float* [4];
    for (int j = 0; j < 4; j++) {
      cpts2[i][j] = new float [4];
    }
  }

  cpts2[0][0][0] = -1.5;
  cpts2[0][0][1] = -1.5;
  cpts2[0][0][2] =  4.0;
  cpts2[0][0][3] =  1.0;

  cpts2[0][1][0] = -0.5;
  cpts2[0][1][1] = -1.5;
  cpts2[0][1][2] =  2.0;
  cpts2[0][1][3] =  1.0;

  cpts2[0][2][0] =  0.5;
  cpts2[0][2][1] = -1.5;
  cpts2[0][2][2] = -1.0;
  cpts2[0][2][3] =  1.0;

  cpts2[0][3][0] =  1.5;
  cpts2[0][3][1] = -1.5;
  cpts2[0][3][2] =  2.0;
  cpts2[0][3][3] =  1.0;

  cpts2[1][0][0] = -1.5;
  cpts2[1][0][1] = -0.5;
  cpts2[1][0][2] =  1.0;
  cpts2[1][0][3] =  1.0;

  cpts2[1][1][0] =-0.5;
  cpts2[1][1][1] =-0.5;
  cpts2[1][1][2] = 3.0;
  cpts2[1][1][3] = 1.0;

  cpts2[1][2][0] =  0.5;
  cpts2[1][2][1] = -0.5;
  cpts2[1][2][2] =  0.0;
  cpts2[1][2][3] =  1.0;

  cpts2[1][3][0] =  1.5;
  cpts2[1][3][1] = -0.5;
  cpts2[1][3][2] = -1.0;
  cpts2[1][3][3] =  1.0;


  cpts2[2][0][0] = -1.5;
  cpts2[2][0][1] = 0.5;
  cpts2[2][0][2] = 4.0;
  cpts2[2][0][3] = 1.0;

  cpts2[2][1][0] = -0.5;
  cpts2[2][1][1] = 0.5;
  cpts2[2][1][2] = 0.0;
  cpts2[2][1][3] = 1.0;

  cpts2[2][2][0] = 0.5;
  cpts2[2][2][1] = 0.5;
  cpts2[2][2][2] = 3.0;
  cpts2[2][2][3] = 1.0;

  cpts2[2][3][0] = 1.5;
  cpts2[2][3][1] = 0.5;
  cpts2[2][3][2] = 4.0;
  cpts2[2][3][3] = 1.0;


  cpts2[3][0][0] = -1.5;
  cpts2[3][0][1] =  1.5;
  cpts2[3][0][2] = -2.0;
  cpts2[3][0][3] = 1.0;

  cpts2[3][1][0] = -0.5;
  cpts2[3][1][1] =  1.5;
  cpts2[3][1][2] = -2.0;
  cpts2[3][1][3] =  1.0;
  
  cpts2[3][2][0] = 0.5;
  cpts2[3][2][1] = 1.5;
  cpts2[3][2][2] = 0.0;
  cpts2[3][2][3] = 1.0;

  cpts2[3][3][0] =  1.5;
  cpts2[3][3][1] =  1.5;
  cpts2[3][3][2] = -1.0;
  cpts2[3][3][3] =  1.0;

  renderer::Surface* surface = new gelatine::Surface(4, 4, cpts2);
  ng->add(*surface);

  getRoot().addChild(*(new renderer::Shape(*(ng))));
  */
  //  NurbsShape* nurbsShape = new NurbsShape(*(new DirectShapeModel()));
  //  getRoot().addChild(*nurbsShape);
/*  
}
*/

LayeredScene::~LayeredScene()
{
}


bool LayeredScene::hasReachedBottomLayer()
{
  bool result = false;
  if (_activeLayer == *(_layers.begin())) {
    result = true;
  }
  return result;
}


bool LayeredScene::hasReachedTopLayer()
{
  bool result = false;
  if (_activeLayer == *(_layers.rbegin())) {
    result = true;
  }
  return result;
}


void LayeredScene::moveToTopLayer()
{
  LayerHexMesh& nextLayer = **(_layers.end());
  triggerMoveToLayer(nextLayer);
}


void LayeredScene::moveToBottomLayer()
{
  LayerHexMesh& nextLayer = **(_layers.begin());
  triggerMoveToLayer(nextLayer);
}


void LayeredScene::triggerUpLayer()
{
  if (_moveCameraAction->inProgress() ||
      _alphaShiftAppear->inProgress() ||
      _alphaShiftDisappear->inProgress()) {
    return;
  };

  LayerHexMesh* nextLayer;
  LayerHexMeshIteratorType temp;
  LayerHexMeshIteratorType iter;

  for (iter = _layers.begin(); iter != _layers.end(); iter++) {
    temp = iter;
    if (++temp == _layers.end()) {
      return;
    } else if (*iter == _activeLayer) {
      if (_previousLayer != 0) {
        _previousLayer->removeChild(*_dormantHexMesh);
      }

      nextLayer = *(++iter);
      triggerMoveToLayer(*nextLayer);
      return;
    }
  }
}


void LayeredScene::triggerDownLayer()
{
  if (_moveCameraAction->inProgress() ||
      _alphaShiftAppear->inProgress() ||
      _alphaShiftDisappear->inProgress()) {
    return;
  };

  LayerHexMesh* nextLayer;
  DownwardsLayerHexMeshIteratorType temp;
  DownwardsLayerHexMeshIteratorType iter = _layers.rbegin();
  DownwardsLayerHexMeshIteratorType end = _layers.rend();

  for ( ; iter != end; iter++) {
    temp = iter;
    if (++temp == end) {
      return;
    } else if (*iter == _activeLayer) {
      if (_previousLayer != 0) {
        _previousLayer->removeChild(*_dormantHexMesh);
      }

      nextLayer = *(++iter);
      triggerMoveToLayer(*nextLayer);
      return;
    }
  }

}


void LayeredScene::triggerMoveToLayer(assembly::Layer& nextLayer)
{
  typedef LayerHexMeshIteratorType IterType;

  for (IterType iter = _layers.begin(); iter != _layers.end(); iter++) {
    assembly::Layer& mappedLayer = (*iter)->getLayer();
    if (&nextLayer == &mappedLayer) {
      triggerMoveToLayer(**iter);
      break;
    }
  }
}


void LayeredScene::triggerMoveToLayer(LayerHexMesh& layer)
{
  // Make this mutex thread locked
  if (_moveCameraAction->inProgress() ||
      _alphaShiftAppear->inProgress() ||
      _alphaShiftDisappear->inProgress()) {
    return;
  };

  LayerHexMeshIteratorType temp;
  LayerHexMeshIteratorType iter;
  LayerHexMeshIteratorType end = _layers.end();

  if (_activeLayer == &layer) {
    return;
  }

  _dormantHexMesh->getAppearance().setModifierAlpha(0);
  _activeHexMesh->getAppearance().setModifierAlpha(1);
  _alphaShiftAppear->setTarget(_dormantHexMesh->getAppearance());
  _alphaShiftDisappear->setTarget(_activeHexMesh->getAppearance());

  _alphaShiftDim->setTarget(_activeLayer->getFaceAppearance());
  _alphaShiftBrighten->setTarget(layer.getFaceAppearance());

  _alphaShiftDimEdges->setTarget(_activeLayer->getEdgeAppearance());
  _alphaShiftBrightenEdges->setTarget(layer.getEdgeAppearance());

  float nextTransform[4][4];
  layer.getGlobalTransform(nextTransform);

  float currentTransform[4][4];
  _activeLayer->getGlobalTransform(currentTransform);

  float displacement[3];
  displacement[0] = 0;
  displacement[1] = nextTransform[1][3] - currentTransform[1][3];
  displacement[2] = 0;

  _moveCameraAction->setDisplacement(displacement);

  _activeLayer->setSelectable(false);
  _previousLayer = _activeLayer;
  _activeLayer = &layer;
  _activeLayer->addChild(*_dormantHexMesh);
  _activeLayer->setSelectable(true);

  geometry::HexMesh* tempHexMesh = _dormantHexMesh;
  _dormantHexMesh = _activeHexMesh;
  _activeHexMesh = tempHexMesh;

  //  trigger(*_alphaShiftAppear);
  //  trigger(*_alphaShiftDisappear);

  //  //  trigger(*_alphaShiftBrighten);
  //  //  trigger(*_alphaShiftDim);

  //  trigger(*_moveCameraAction);
}


fx::AlphaShift& LayeredScene::getAlphaShiftDim()
{
  return *_alphaShiftDim;
}


fx::AlphaShift& LayeredScene::getAlphaShiftBrighten()
{
  return *_alphaShiftBrighten;
}


fx::AlphaShift& LayeredScene::getAlphaShiftDimEdges()
{
  return *_alphaShiftDimEdges;
}


fx::AlphaShift& LayeredScene::getAlphaShiftBrightenEdges()
{
  return *_alphaShiftBrightenEdges;
}


fx::AlphaShift& LayeredScene::getAlphaShiftDisappear()
{
  return *_alphaShiftDisappear;
}


fx::AlphaShift& LayeredScene::getAlphaShiftNodeDissappear()
{
  return *_alphaShiftNodeDisappear;
}


fx::AlphaShift& LayeredScene::getAlphaShiftNodeDissappearEdges()
{
  return *_alphaShiftNodeDisappearEdges;
}


fx::AlphaShift& LayeredScene::getAlphaShiftAppear()
{
  return *_alphaShiftAppear;
}


fx::AnimationAction& LayeredScene::getMoveCameraAction()
{
  return *_moveCameraAction;
}


assembly::Domain& LayeredScene::getDomain()
{
  return *_domain;
}


scenegraph::Camera& LayeredScene::getCamera()
{
  return _camera;
}


bool LayeredScene::isActiveLayer(LayerHexMesh& layer)
{
  return _activeLayer == &layer;
}


LayerHexMesh& LayeredScene::getActiveLayer()
{
  return *_activeLayer;
}


LayerHexMesh* LayeredScene::getPreviousLayer()
{
  return _previousLayer;
}


geometry::HexMesh& LayeredScene::getActiveHexMesh()
{
  return *_activeHexMesh;
}


geometry::HexMesh& LayeredScene::getDormantHexMesh()
{
  return *_dormantHexMesh;
}


LayeredScene::LayerHexMeshIteratorType
LayeredScene::getLayerHexMeshesUpwards()
{
  return _layers.begin();
}


LayeredScene::DownwardsLayerHexMeshIteratorType
LayeredScene::getLayerHexMeshesDownwards()
{
  return _layers.rbegin();
}


LayeredScene::LayerHexMeshIteratorType
LayeredScene::getUpwardsLayerHexMeshEnd()
{
  return _layers.end();
}


LayeredScene::DownwardsLayerHexMeshIteratorType
LayeredScene::getDownwardsLayerHexMeshEnd()
{
  return _layers.rend();
}


int LayeredScene::getNumberLayers() const
{
  return _layers.size();
}


}


}
