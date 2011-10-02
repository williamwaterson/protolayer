#include "Scene.h"


namespace protolayer
{

namespace scenegraph
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
  //  _root.compile();
}


Group&
Scene::getRoot()
{
  return _root;
}


float
Scene::getAlpha() const
{
  return _alpha;
}


//Scene::ShapeIteratorType
//Scene::getShapes()
//{
//  return _shapes.begin();
//}


//Scene::ShapeIteratorType
//Scene::getLastShape()
//{
//  return _shapes.end();
//}


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
