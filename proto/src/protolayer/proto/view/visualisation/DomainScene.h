#ifndef PROTO_DOMAINSCENE_H
#define PROTO_DOMAINSCENE_H

#include <vector>

#include "../../forward.h"
#include "DependencyArrow.h"
#include "DomainSceneSelectionModel.h"
#include "LayerHexMesh.h"
#include "DomainNode.h"


/** TODO: Documentation */
namespace protolayer
{

/** TODO: Documentation */
namespace proto
{

class DomainScene : public scenegraph::Scene
{
public:
  /** TODO: Documentation */
  typedef util::SetIterator <DomainNode> DomainNodeIteratorType;

  /** TODO: Documentation */
  static const float VERTICAL_SPACING = 2;

private:
  /** TODO: Documentation */
  assembly::Assembly* _assembly;

  /** TODO: Documentation */
  scenegraph::Group _root;

  /** TODO: Documentation */
  scenegraph::Group* _cameraGroup;

  /** TODO: Documentation */
  style::Appearance* _selectedDomainAppearance;

  /** TODO: Documentation */
  style::Appearance* _defaultDomainAppearance;

  /** TODO: Documentation */
  scenegraph::Camera* _camera;

  /** TODO: Documentation */
  std::set <DomainNode*> _domainNodes;

  /** TODO: Documentation */
  std::set <DependencyArrow*> _dependencyArrows;

  /** TODO: Documentation */
  DomainNode* _selectedDomainNode;

  /** TODO: Documentation */
  style::Appearance* _edgeAppearance;

  /** TODO: Documentation */
  style::Appearance* _faceAppearance;

  /** TODO: Documentation */
  DomainSceneSelectionModel* _selectionModel;

  /** TODO: Documentation */
  //  renderer::Shot* _shot;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit DomainScene(assembly::Assembly& assembly);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DomainScene();

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Camera& getCamera();

  /**
   * TODO: Documentation
   *
   */
  assembly::Assembly& getAssembly();

  /**
   * TODO: Documentation
   *
   */
  scenegraph::Shot& getShot();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNode* getSelectedDomainNode();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainSceneSelectionModel& getSelectionModel();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNodeIteratorType getDomainNodes();

  /**
   * TODO: Documentation
   * <p>
   */
  DomainNode* getDomainNode(assembly::Domain& domain);

  /**
   * TODO: Documentation
   * <p>
   */
  DependencyArrow* getDependencyArrow(assembly::DomainDependency& domainDependency);

};


}


}


#endif // PROTO_DOMAINSCENE_H
