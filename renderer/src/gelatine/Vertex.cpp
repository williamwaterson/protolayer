#include "Vertex.h"


namespace gelatine
{


// Explicit Instantiations
template class HitListener <Vertex>;


Vertex::Vertex()
{
}


Vertex::Vertex(float x, float y, float z) :
  protolayer::nurbs::Vertex(x, y, z)
{
  _id = protolayer::IDGenerator::getInstance().obtainID();
}


Vertex::Vertex(float coordinates[3]) :
  protolayer::nurbs::Vertex(coordinates)
{
  _id = protolayer::IDGenerator::getInstance().obtainID();
}


Vertex::~Vertex()
{
}


void Vertex::render(float alpha, Appearance& appearance)
{
  glPointSize(5.0);
  glColor4f(0.0, 0.0, 0.0, 1.0f);
  glBegin(GL_POINTS);
  glVertex3fv(getCoordinates());
  glEnd();
}


void
Vertex::addHitListener(HitListenerType& listener)
{
  _hitListeners.insert(&listener);
}


void
Vertex::removeHitListener(HitListenerType& listener)
{
  _hitListeners.erase(&listener);
}


void
Vertex::clearHitListeners()
{
  _hitListeners.clear();
}


void Vertex::renderInSelectionMode(float alpha, Appearance& appearance)
{
  render(alpha, appearance);
}


void Vertex::triggerHitListeners()
{
  HitListenerIteratorType iter;
  HitListenerIteratorType end = _hitListeners.end();
  for (iter = _hitListeners.begin(); iter != end; ++iter) {
    (*iter)->mouseHit(*this);
  }
}


}
