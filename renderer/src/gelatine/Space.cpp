#include "Space.h"


namespace gelatine
{


Space::Space(Shot& initialShot)
{
  _ownsModel = true;
  SpaceModel* model = new SpaceModel(initialShot);
  _view = new SpaceView(*model);
  _ownsView = true;
}


Space::Space(Shot& initialShot,
             Transition& transition)
{
  _ownsModel = true;
  SpaceModel* model = new SpaceModel(initialShot, transition);
  _view = new SpaceView(*model);
  _ownsView = true;
}


//Space::Space(SpaceModel& model)
//{
//  _view = new SpaceView(model);
//  _ownsModel = false;
//  _ownsView = true;
//}


//Space::Space(SpaceView& view)
//{
//  _view = &view;
//  _ownsView = false;
//}


Space::~Space()
{
  SpaceModel* model = &getModel();

  if (_ownsView) {
    delete _view;
  }

  if (_ownsModel) {
    delete model;
  }
}


SpaceView&
Space::getView()
{
  return *_view;
}


SpaceModel&
Space::getModel()
{
  return _view->getModel();
}


Mouse&
Space::getMouse()
{
  return getModel().getMouse();
}


Shot&
Space::getCurrentShot()
{
  return getModel().getCurrentShot();
}


Shot*
Space::getNextShot()
{
  return getModel().getNextShot();
}

void
Space::setNextShot(Shot& shot)
{
  getModel().setNextShot(shot);
}


void
Space::updateMouse(short x, short y)
{
  getMouse()._x = x;
  getMouse()._y = y;
}


}
