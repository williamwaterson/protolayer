#include "DomainScene.h"


namespace protolayer
{

namespace proto
{

DomainScene::DomainScene(assembly::Assembly& assembly) : 
  _root(),
  scenegraph::Scene::Scene(_root)  
{
  _camera = new scenegraph::Camera(5, 5, 5, 0, 0, 0);
  _selectionModel = new DomainSceneSelectionModel();

  //  _shot = new renderer::Shot(*this, _camera);

  _edgeAppearance = new style::Appearance();
  _edgeAppearance->getColor()[0] = 0.0f;
  _edgeAppearance->getColor()[1] = 0.0f;
  _edgeAppearance->getColor()[2] = 0.0f;
  _edgeAppearance->getColor()[3] = 1.0f;

  _faceAppearance = new style::Appearance();
  _faceAppearance->getColor()[0] = 1.0f;
  _faceAppearance->getColor()[1] = 1.0f;
  _faceAppearance->getColor()[2] = 1.0f;
  _faceAppearance->getColor()[3] = 1.0f;

  _assembly = &assembly;

  float x = 0;
  typedef assembly::Assembly::DomainIteratorType IterType;
  for (IterType iter = _assembly->getDomains(); iter.hasNext(); ) {
    assembly::Domain& domain = iter.next();

    DomainNode* prism = new DomainNode(domain,
                                         *_edgeAppearance,
                                         *_faceAppearance);
    prism->translate(x, 0, 0);
    _domainNodes.insert(prism);

    getRoot().addChild(*prism);
    x += 3;
  }

  typedef assembly::Assembly::DomainDependencyIteratorType DIDIterType;
  for (DIDIterType iter = _assembly->getDomainDependencies(); iter.hasNext(); ) {
    assembly::DomainDependency& dependency = iter.next();
    assembly::Domain& from = dependency.getFromDomain();
    assembly::Domain& to = dependency.getToDomain();

    DomainNode* fromPrism = getDomainNode(from);
    DomainNode* toPrism = getDomainNode(to);

    DependencyArrow* arrow = new DependencyArrow(dependency, *fromPrism, *toPrism, *_camera);
    _dependencyArrows.insert(arrow);

    getRoot().addChild(*arrow);
    arrow->updateEndPositions();
  }


  //  renderer::Surface* surface = new renderer::Surface(8, 8, 4, 4, 4, 4);
  //  geometry::Sphere* sphere = new geometry::Sphere(1);
  //  getRoot().addChild(sphere->getSurface());

  //  geometry::Disk* disk = new geometry::Disk(1);
  //  getRoot().addChild(disk->getSurface());

  _cameraGroup = new scenegraph::Group();
  _cameraGroup->addChild(*_camera);
  getRoot().addChild(*_cameraGroup);
  getRoot().update();

  _camera->update();

  _selectedDomainNode = 0;
}


DomainScene::~DomainScene()
{
}


assembly::Assembly& DomainScene::getAssembly()
{
  return *_assembly;
}


DomainSceneSelectionModel& DomainScene::getSelectionModel()
{
  return *_selectionModel;
}


scenegraph::Camera& DomainScene::getCamera()
{
  return *_camera;
}


DomainScene::DomainNodeIteratorType DomainScene::getDomainNodes()
{
  return DomainNodeIteratorType(_domainNodes);
}


DomainNode* DomainScene::getDomainNode(assembly::Domain& domain)
{
  DomainNode* result = 0;
  for (DomainNodeIteratorType iter = getDomainNodes(); iter.hasNext(); ) {
    DomainNode& prism = iter.next();
    if (prism.isDomain(domain)) {
      result = &prism;
    } 
  }
  return result;
}


DomainNode* DomainScene::getSelectedDomainNode()
{
  return _selectedDomainNode;
}


}


}
