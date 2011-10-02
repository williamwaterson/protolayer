#include "Scene.h"


namespace protolayer
{

namespace renderer
{

Scene::Scene(Group& root) :
  _root(root)
{
  _alpha = 1.0f;
}


Scene::~Scene()
{
}


void Scene::compile()
{
  //  _renderRoot.compile();
}


Group&
Scene::getRoot()
{
  return _root;
}


void renderGroup(Group& group, float alpha)
{
  typedef std::vector <Group*>::iterator GroupIterType;
  for(GroupIterType iter = group.getOrderedChildGroups(); iter != group.getOrderedLastGroup(); ++iter) {
    renderGroup(**iter, alpha);
  }

  typedef std::vector <Shape*>::iterator LeafIterType;
  for(LeafIterType iter = group.getOrderedChildLeaves(); iter != group.getOrderedLastLeaf(); ++iter) {
    (*iter)->render(alpha);
  }  
}


void renderGroupInSelectionMode(Group& group, float alpha)
{
  if (group.isSelectable()) {
    glPushName(group.getID());

    typedef std::vector <Group*>::iterator GroupIterType;
    for(GroupIterType iter = group.getOrderedChildGroups(); iter != group.getOrderedLastGroup(); ++iter) {
      renderGroupInSelectionMode(**iter, alpha);
    }

    typedef std::vector <Shape*>::iterator LeafIterType;
    for(LeafIterType iter = group.getOrderedChildLeaves(); iter != group.getOrderedLastLeaf(); ++iter) {
      (*iter)->renderInSelectionMode(alpha);
    }

    glPopName();
  }
}


void
Scene::render(float alpha)
{
  renderGroup(_root, alpha);
}


void
Scene::renderInSelectionMode(float alpha)
{
  renderGroupInSelectionMode(_root, alpha);
}


float
Scene::getAlpha() const
{
  return _alpha;
}


Scene::ShapeIteratorType
Scene::getShapes()
{
  return _shapes.begin();
}


Scene::ShapeIteratorType
Scene::getLastShape()
{
  return _shapes.end();
}


/*
void
Scene::add(Shape& shape)
{
  int id = _idGenerator.obtainID();
  shape.getModel().setID(id);
  _shapeNameMap.insert(std::map <int, Shape*>::value_type(id, &shape));
  _shapes.insert(&shape);
}


void
Scene::remove(Shape& shape)
{
  _shapeNameMap.erase(shape.getModel().getID());
  _shapes.erase(&shape);
}
*/

util::IDGenerator&
Scene::getIDGenerator()
{
  return _idGenerator;
}


void
Scene::setAlpha(float alpha)
{
  _alpha = alpha;
}


}


}
