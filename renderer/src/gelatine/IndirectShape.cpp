#include "IndirectShape.h"


namespace gelatine
{


IndirectShape::IndirectShape(ShapeModel& model) :
  _model(model)
{
}


IndirectShape::IndirectShape(Geometry& geometry) :
  _model(*(new ShapeModel(geometry)))
{  
}


IndirectShape::IndirectShape(Geometry& geometry, Appearance& appearance) :
  _model(*(new ShapeModel(geometry, appearance)))
{  
}


IndirectShape::~IndirectShape()
{
}


ShapeModel&
IndirectShape::getModel()
{
  return _model;
}


Geometry& IndirectShape::getGeometry()
{
  return _model.getGeometry();
}


void IndirectShape::update(float quaternion[4][4])
{
  _quaternion = quaternion;
  getGeometry().update(quaternion);
}


void IndirectShape::render(float alpha)
{
  if (getModel().getAppearance().isRenderable()) {
    getGeometry().render(alpha, _model.getAppearance());
  }
}


void IndirectShape::renderInSelectionMode(float alpha)
{
  if (isSelectable()) {
    glPushName(getID());
    getGeometry().render(alpha, _model.getAppearance());
    glPopName();
  }
}


void IndirectShape::triggerHitListeners(unsigned int name)
{
  getGeometry().triggerHitListeners(name);
}


}
