#include "ControlPoint.h"


namespace gelatine
{


// Explicit Instantiations
template class HitListener <ControlPoint>;


ControlPoint::ControlPoint(float* localCoordinates,
                           float* coordinates) :
  protolayer::nurbs::ControlPoint(localCoordinates, coordinates)
{
  _id = protolayer::IDGenerator::getInstance().obtainID();
}


ControlPoint::~ControlPoint()
{
}


void ControlPoint::render(float alpha, Appearance& appearance)
{
  glPointSize(2.0);
  glColor4f(0.0, 0.0, 0.0, 1.0f);
  glBegin(GL_POINTS);
  glVertex3fv(getCoordinates());
  glEnd();
}


void ControlPoint::renderInSelectionMode(float alpha, Appearance& appearance)
{
  render(alpha, appearance);
}


void
ControlPoint::addHitListener(HitListenerType& listener)
{
  _hitListeners.insert(&listener);
}


void
ControlPoint::removeHitListener(HitListenerType& listener)
{
  _hitListeners.erase(&listener);
}


void
ControlPoint::clearHitListeners()
{
  _hitListeners.clear();
}


void ControlPoint::triggerHitListeners()
{
  HitListenerIteratorType iter;
  HitListenerIteratorType end = _hitListeners.end();
  for (iter = _hitListeners.begin(); iter != end; ++iter) {
    (*iter)->mouseHit(*this);
  }
}


}

