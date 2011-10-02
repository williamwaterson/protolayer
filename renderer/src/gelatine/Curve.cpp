#include "Curve.h"


namespace gelatine
{

ControlPointFactory controlPointFactory;


Curve::Curve()
{
}


Curve::~Curve()
{
}


void Curve::render(float alpha, Appearance& appearance)
{
  //  glColor4f(0.0, 0.0, 0.0, 1.0f);
  //  glPointSize(4.0);
  //  glBegin(GL_POINTS);
  //  for (int i = 0; i < getNumberPoints(); i++) {
  //    glVertex3fv(&(getRawPoints()[i*4]));
  //  }
  //  glEnd();

  glColor4f(0.0, 0.0, 0.0, 1.0f);
  glPointSize(4.0);
  glBegin(GL_POINTS);
  //  for (int i = 0; i < getNumberPoints(); i++) {
  //    glVertex3fv(&(getRawPoints()[i*4]));
  //  }
  glEnd();

  /* This was put later
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 4, getNumberPoints(), getRawPoints());
  glColor4f(0.0, 0.0, 0.0, 1.0);
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i <= 30; i++) {
    glEvalCoord1f((GLfloat) i/30.0);
  }
  glEnd();
  */
}


void Curve::renderInSelectionMode(float alpha, Appearance& appearance)
{
  render(alpha, appearance);
}


}
