#ifndef PROTOLAYER_PROTO_LAYERHEXMESH_H
#define PROTOLAYER_PROTO_LAYERHEXMESH_H


#include "../../forward.h"
#include "InstanceNode.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class LayerHexMesh : public scenegraph::Group
{
  /** TODO: Documentation */
  ::std::set <InstanceNode*> _instanceNode;

  /** TODO: Documentation */
  style::Appearance* _selectedNodeEdgeAppearance;

  /** TODO: Documentation */
  style::Appearance* _selectedNodeFaceAppearance;

  /** TODO: Documentation */
  style::Appearance* _nodeEdgeAppearance;

  /** TODO: Documentation */
  style::Appearance* _nodeFaceAppearance;

  /** TODO: Documentation */
  assembly::Layer* _layer;

  /** TODO: Documentation */
  ontology::Type* _activeType;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit LayerHexMesh(assembly::Layer& layer);

  /**
   * TODO: Documentation
   *
   */
  //  LayerHexMesh();

  /**
   * TODO: Documentation
   *
   */
  ~LayerHexMesh();

  /**
   * TODO: Documentation
   *
   */
  assembly::Layer& getLayer();

  /**
   * TODO: Documentation
   *
   */
  ontology::Type& getActiveType();

  /**
   * TODO: Documentation
   *
   */
  style::Appearance& getEdgeAppearance();

  /**
   * TODO: Documentation
   *
   */
  style::Appearance& getFaceAppearance();

  /**
   * TODO: Documentation
   *
   */
  style::Appearance& getSelectedEdgeAppearance();

  /**
   * TODO: Documentation
   *
   */
  style::Appearance& getSelectedFaceAppearance();

public:
  /**
   * TODO: Documentation
   *
   */
  LayerHexMesh(const LayerHexMesh& mesh);

  /**
   * TODO: Documentation
   *
   */
  LayerHexMesh& operator=(const LayerHexMesh& mesh);

};


}


}


#endif // PROTOLAYER_PROTO_LAYERHEXMESH_H
