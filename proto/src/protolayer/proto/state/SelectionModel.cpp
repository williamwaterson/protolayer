#include "SelectionModel.h"


namespace protolayer
{

namespace proto
{

SelectionModel::SelectionModel()
{
}


SelectionModel::~SelectionModel()
{
}


bool
SelectionModel::isSelected(scenegraph::Node& node) const
{
  return _selected.count(&node) != 0;
}


bool
SelectionModel::contains(scenegraph::Node& node) const
{
  return isSelected(node);
}


void
SelectionModel::add(scenegraph::Node& node)
{
  _selected.insert(&node);
}


void
SelectionModel::remove(scenegraph::Node& node)
{
  _selected.erase(&node);
}


void
SelectionModel::clear()
{
  _selected.clear();
}


SelectionModel::NodeIteratorType SelectionModel::getNodes()
{
  return _selected.begin();
}


SelectionModel::NodeIteratorType SelectionModel::getLastNode()
{
  return _selected.end();
}


}


}
