#include "LayeredSceneSelectionModel.h"


namespace protolayer
{

namespace proto
{

LayeredSceneSelectionModel::LayeredSceneSelectionModel()
{
}


LayeredSceneSelectionModel::~LayeredSceneSelectionModel()
{
}


bool
LayeredSceneSelectionModel::isSelected(scenegraph::Node& node) const
{
  return _selected.count(&node) != 0;
}


void
LayeredSceneSelectionModel::add(InstanceNode& node)
{
  _selected.insert(&node);
  _nodes.insert(&node);
}


void
LayeredSceneSelectionModel::add(ReferenceArrow& connection)
{
  _selected.insert(&connection);
  _connections.insert(&connection);
}


void
LayeredSceneSelectionModel::remove(InstanceNode& node)
{
  _selected.erase(&node);
  _nodes.erase(&node);
}


void
LayeredSceneSelectionModel::remove(ReferenceArrow& connection)
{
  _selected.erase(&connection);
  _connections.erase(&connection);
}


void
LayeredSceneSelectionModel::clear()
{
  _nodes.clear();
  _connections.clear();
  _selected.clear();
}


LayeredSceneSelectionModel::ShapeIteratorType
LayeredSceneSelectionModel::getItems()
{
  return _selected.begin();
}


LayeredSceneSelectionModel::InstanceNodeIteratorType
LayeredSceneSelectionModel::getInstanceNode()
{
  return _nodes.begin();
}


LayeredSceneSelectionModel::ReferenceArrowIteratorType
LayeredSceneSelectionModel::getReferenceArrows()
{
  return _connections.begin();
}


LayeredSceneSelectionModel::ShapeIteratorType
LayeredSceneSelectionModel::getLastItem()
{
  return _selected.end();
}


LayeredSceneSelectionModel::InstanceNodeIteratorType
LayeredSceneSelectionModel::getLastInstanceNode()
{
  return _nodes.end();
}


LayeredSceneSelectionModel::ReferenceArrowIteratorType
LayeredSceneSelectionModel::getLastReferenceArrow()
{
  return _connections.end();
}


}


}
