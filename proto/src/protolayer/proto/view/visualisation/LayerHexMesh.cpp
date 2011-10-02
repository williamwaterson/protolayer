#include "LayerHexMesh.h"
 

namespace protolayer
{

namespace proto
{

ontology::Type& LayerHexMesh::getActiveType()
{
  return *_activeType;
}


LayerHexMesh::LayerHexMesh(assembly::Layer& layer)
{
  _layer = &layer;
  _activeType = &(layer.getTypeLayer().getTypes().next());

  _nodeEdgeAppearance = new style::Appearance();
  _nodeEdgeAppearance->getColor()[0] = 0.0f;
  _nodeEdgeAppearance->getColor()[1] = 0.0f;
  _nodeEdgeAppearance->getColor()[2] = 0.0f;
  _nodeEdgeAppearance->getColor()[3] = 1.0f;

  _nodeFaceAppearance = new style::Appearance();
  _nodeFaceAppearance->getColor()[0] = 1.0f;
  _nodeFaceAppearance->getColor()[1] = 1.0f;
  _nodeFaceAppearance->getColor()[2] = 1.0f;
  _nodeFaceAppearance->getColor()[3] = 1.0f;

  _selectedNodeEdgeAppearance = new style::Appearance();
  _selectedNodeEdgeAppearance->getColor()[0] = 0.0f;
  _selectedNodeEdgeAppearance->getColor()[1] = 0.0f;
  _selectedNodeEdgeAppearance->getColor()[2] = 0.0f;
  _selectedNodeEdgeAppearance->getColor()[3] = 1.0f;

  _selectedNodeFaceAppearance = new style::Appearance();
  _selectedNodeFaceAppearance->getColor()[0] = 1.0f;
  _selectedNodeFaceAppearance->getColor()[1] = 1.8f;
  _selectedNodeFaceAppearance->getColor()[2] = 1.0f;
  _selectedNodeFaceAppearance->getColor()[3] = 1.0f;
}


LayerHexMesh::~LayerHexMesh()
{
}


assembly::Layer& LayerHexMesh::getLayer()
{
  return *_layer;
}


style::Appearance& LayerHexMesh::getEdgeAppearance()
{
  return *_nodeEdgeAppearance;
}


style::Appearance& LayerHexMesh::getFaceAppearance()
{
  return *_nodeFaceAppearance;
}


style::Appearance& LayerHexMesh::getSelectedEdgeAppearance()
{
  return *_selectedNodeEdgeAppearance;
}


style::Appearance& LayerHexMesh::getSelectedFaceAppearance()
{
  return *_selectedNodeFaceAppearance;
}


}


}
