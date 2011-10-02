#include "Scene.h"


namespace gelatine
{


Scene::Scene(Group& root) :
  _root(root) // , _renderRoot(root)
{
}


Scene::~Scene()
{
}


void Scene::compile()
{
  //  _renderRoot.compile();
}


ProjectedMouse&
Scene::getProjectedMouse()
{
  return _model.getProjectedMouse();
}


void
Scene::trigger(Action& action)
{
  _model.trigger(action);
}


Group&
Scene::getRoot()
{
  return _root;
}


void
Scene::render(float alpha)
{
  // Perform housekeeping related to Actions
  _model.releaseCompletedActions();
  _model.commenceTriggeredActions();
  _model.incrementActions();

  // Set background colour and render all subviews
  float* background = _model.getBackgroundColor();
  glClearColor(background[0], background[1], background[2], alpha);
  //_renderRoot.render(alpha);
  _root.render(alpha);
}


void
Scene::renderInSelectionMode(float alpha)
{
  //_renderRoot.renderInSelectionMode(alpha);
  _root.renderInSelectionMode(alpha);
}


SceneModel& Scene::getModel()
{
  return _model;
}


}
