#include "DomainSceneSelectionModel.h"


namespace protolayer
{

namespace proto
{

DomainSceneSelectionModel::DomainSceneSelectionModel()
{
}


DomainSceneSelectionModel::~DomainSceneSelectionModel()
{
}


//bool
//DomainSceneSelectionModel::isSelected(DomainNode& prism)
//{
//  return _domainNodes.find(
//}


//bool
//DomainSceneSelectionModel::isSelected(DependencyArrow& arrow)
//{
//}


void
DomainSceneSelectionModel::add(DependencyArrow& dependency)
{
  _dependencies.insert(&dependency);
}


void
DomainSceneSelectionModel::add(DomainNode& domainNode)
{
  _domains.insert(&domainNode);
}


void
DomainSceneSelectionModel::remove(DependencyArrow& dependency)
{
  _dependencies.erase(&dependency);
}


void
DomainSceneSelectionModel::remove(DomainNode& domainNode)
{
  _domains.erase(&domainNode);
}


void
DomainSceneSelectionModel::clearDomainNodes()
{
  _domains.clear();
}


void
DomainSceneSelectionModel::clearDependencyArrows()
{
  _dependencies.clear();
}


DomainSceneSelectionModel::DependencyArrowIteratorType
DomainSceneSelectionModel::getDependencyArrows()
{
  return _dependencies.begin();
}


DomainSceneSelectionModel::DomainNodeIteratorType
DomainSceneSelectionModel::getDomainNodes()
{
  return _domains.begin();
}


DomainSceneSelectionModel::DependencyArrowIteratorType
DomainSceneSelectionModel::getLastDependencyArrow()
{
  return _dependencies.end();
}


DomainSceneSelectionModel::DomainNodeIteratorType
DomainSceneSelectionModel::getLastDomainNode()
{
  return _domains.end();
}


}


}
