#include "DirectShape.h"


namespace gelatine
{


DirectShape::DirectShape(ShapeModel& model) :
  _model(model)
{
}


DirectShape::DirectShape(Appearance& appearance) :
  _model(*(new ShapeModel(appearance)))
{  
}


DirectShape::~DirectShape()
{
}


ShapeModel&
DirectShape::getModel()
{
  return _model;
}


const Geometry& DirectShape::getGeometry() const
{
  return _model.getGeometry();
}


void DirectShape::update(float quaternion[4][4])
{
  _quaternion = quaternion;
  getGeometry().update(quaternion);
}


void DirectShape::render(float alpha)
{
  if (getModel().getAppearance().isRenderable()) {
    getGeometry().render(alpha, _model.getAppearance());
  }
}


void DirectShape::renderInSelectionMode(float alpha)
{
  if (isSelectable()) {
    glPushName(getID());
    getGeometry().render(alpha, _model.getAppearance());
    glPopName();
  }
}


void DirectShape::triggerHitListeners(unsigned int name)
{
  getGeometry().triggerHitListeners(name);
}


}
