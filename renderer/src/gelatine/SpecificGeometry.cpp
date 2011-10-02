#include "SpecificGeometry.h"


namespace gelatine
{


SpecificGeometry::SpecificGeometry(GeometryTypeEnum geometryType)
{
  _geometryType = geometryType;
}


SpecificGeometry::~SpecificGeometry()
{
}


int SpecificGeometry::getType()
{
  return _geometryType;
}


//void
//SpecificGeometry::render(float alpha, Appearance& appearance)
//{
  //  glBegin(_geometryType);
  //  renderPoints(alpha, appearance);

  //  glColor4f(0.0, 0.0, 0.0, 1.0f);
  //  glPointSize(4.0);
  //  glBegin(GL_POINTS);
  //  for (int i = 0; i < getNumberPoints(); i++) {
  //    glVertex3fv(&(getRawPoints()[i*4]));
  //  }
  //  glEnd();

  //  glEnd();
//}


}
