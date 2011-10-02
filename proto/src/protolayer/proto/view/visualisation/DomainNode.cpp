#include "DomainNode.h"


namespace protolayer
{

namespace proto
{

assembly::Domain& DomainNode::getDomain()
{
  return getLayeredScene().getDomain();
}


bool DomainNode::isDomain(assembly::Domain& domain)
{
  return &_domain == &domain;
}


DomainNode::DomainNode(assembly::Domain& domain,
                         style::Appearance& edgeAppearance,
                         style::Appearance& faceAppearance) :
  geometry::QuadSphere(0.5f, 3, edgeAppearance, faceAppearance),
  _domain(domain)
{
  _layeredScene = new LayeredScene(domain);
  scenegraph::Camera& camera = _layeredScene->getCamera();
  _shot = new scenegraph::Shot(*_layeredScene, camera);

  //  int numberLayers = scene.getNumberLayers();
  //  float height = numberLayers * LayerPrism::HEIGHT +
  //    (numberLayers - 1) * VERTICAL_SPACING + 2 * VERTICAL_INSET;
  //  float length = LayerPrism::LENGTH + 2 * HORIZONTAL_INSET;


  //  float length = 2;
  //  float height = 4;
  //  geometry::RectangularPrism* prism =
  //    new geometry::RectangularPrism(length, height, length,
  //                                   *edgeAppearance,
  //                                   *faceAppearance);
  //  _item = new renderer::Shape(*prism);
  //  addChild(*prism);
  //  prism->setSelectable(true);

  /*
  LayerPrism* layerPrism = 0;
  float y = VERTICAL_INSET - height/2 + LayerPrism::HEIGHT/2;
  LayeredScene::LayerHexMeshIteratorType iter;
  LayeredScene::LayerHexMeshIteratorType end =
    scene.getUpwardsLayerHexMeshEnd();
  for (iter = scene.getLayerHexMeshesUpwards(); iter != end; ++iter) {
    layerPrism = new LayerPrism(**iter);
    layerPrism->translate(0, y, 0);
    addChild(*layerPrism);
    _layerPrisms.push_back(layerPrism);
    y += VERTICAL_SPACING + LayerPrism::HEIGHT;
  }
  */
}


scenegraph::Shot& DomainNode::getShot()
{
  return *_shot;
}


LayeredScene&
DomainNode::getLayeredScene()
{
  return *_layeredScene;
}


/*
DomainNode::LayerPrismIteratorType
DomainNode::getLayerPrismsUpwards()
{
  return _layerPrisms.begin();
}


DomainNode::LayerPrismIteratorType
DomainNode::getLayerPrismsUpwards(const LayerPrism& prism)
{
  return _layerPrisms.begin();
}


DomainNode::DownwardsLayerPrismIteratorType
DomainNode::getLayerPrismsDownwards()
{
  return _layerPrisms.rbegin();
}


DomainNode::DownwardsLayerPrismIteratorType
DomainNode::getLayerPrismsDownwards(const LayerPrism& prism)
{
  return _layerPrisms.rbegin();
}


DomainNode::LayerPrismIteratorType
DomainNode::getUpwardsEnd()
{
  return _layerPrisms.end();
}


DomainNode::DownwardsLayerPrismIteratorType
DomainNode::getDownwardsEnd()
{
  return _layerPrisms.rend();
}
*/

}


}
