#include "Shape.h"


namespace protolayer
{

namespace renderer
{

namespace
{

inline void enableCull()
{
}


inline void disableCull()
{
  glDisable(GL_CULL_FACE);
}


inline void frontFaceCull()
{
  glEnable(GL_DEPTH_TEST);
  glCullFace(GL_FRONT);
}


inline void backFaceCull()
{
  glEnable(GL_DEPTH_TEST);  
  glCullFace(GL_BACK);
}


inline void backAndFrontFaceCull()
{
  glEnable(GL_DEPTH_TEST);
  glCullFace(GL_FRONT_AND_BACK);
}


}


Shape::Shape(Geometry& geometry)
{
  _selected = false;
  _selectable = true;

  _geometry = &geometry;

  _mouseDragOffset[0] = 0;
  _mouseDragOffset[1] = 0;
  _mouseDragOffset[2] = 0;

  _appearance = new Appearance();

  typedef Geometry::PointIteratorType PIType;
  for (PIType iter = geometry.getPoints(); iter != geometry.getLastPoint(); iter++) {
    protolayer::renderer::Point* point = new protolayer::renderer::Point(*iter);
    addPoint(*point);
  }

  _cullingFunction = &backFaceCull;
}


Shape::Shape(Geometry& geometry, Appearance& appearance)
{  
  _selected = false;
  _selectable = true;

  _geometry = &geometry;

  _mouseDragOffset[0] = 0;
  _mouseDragOffset[1] = 0;
  _mouseDragOffset[2] = 0;

  _appearance = &appearance;

  typedef Geometry::PointIteratorType PIType;
  for (PIType iter = geometry.getPoints(); iter != geometry.getLastPoint(); iter++) {
    Point* point = new Point(*iter);
    addPoint(*point);
  }

  _cullingFunction = &backFaceCull;
}


Shape::~Shape()
{
}


void Shape::enableFrontFaceCulling()
{
  _cullingFunction = &frontFaceCull;
}


void Shape::enableBackFaceCulling()
{
  _cullingFunction = &backFaceCull;
}


void Shape::enableBackAndFrontFaceCulling()
{
  _cullingFunction = &backAndFrontFaceCull;
}


void Shape::disableCulling()
{
  _cullingFunction = &disableCull;
}


void Shape::render(float alpha)
{
  if (getAppearance().isRenderable()) {
    // Need hidden renderer
    _cullingFunction();

    _register = getAppearance().getColor();
    glColor4f(_register[0], _register[1], _register[2],
              _register[3] * alpha * getAppearance().getModifierAlpha());
    glBegin(getGeometry().getType());
    //    glLineWidth(getGeometry().getLineWidth());
    glLineWidth(10);
    typedef PointIteratorType PIType;
    for (PIType iter = getPoints(); iter != getLastPoint(); ++iter) {
      _register = (*iter)->getGlobalCoordinates();
      glVertex3f(_register[0], _register[1], _register[2]);
    }
    glEnd();

  }
}


/*
void Shape::render(float alpha, Appearance& appearance)
{
  _register = appearance.getColor();
  glColor4f(_register[0], _register[1], _register[2],
            _register[3] * alpha * appearance.getModifierAlpha());
  PointIteratorType iter = getPoints();
  PointIteratorType end = getLastPoint();
  for (iter = getPoints(); iter != end; ++iter) {
    _register = (*iter)->getGlobalCoordinates();
    glVertex3f(_register[0], _register[1], _register[2]);
  }



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

}
*/

void Shape::compile()
{
}


void Shape::renderInSelectionMode(float alpha)
{
  if (isSelectable()) {
    glPopName();
  }

  render(alpha);

  if (isSelectable()) {
    glPopName();
  }
}


void
Shape::setSelectable(bool flag)
{
  _selectable = flag;
}


bool
Shape::isSelectable()
{
  return _selectable;
}


void
Shape::setSelected()
{
  _selected = true;
}


void
Shape::setUnselected()
{
  _selected = false;
}


bool
Shape::isSelected()
{
  return _selected;
}


void
Shape::setSelected(bool flag)
{
  _selected = flag;
}


void
Shape::setMouseDragOffset(float x, float y, float z)
{
  _mouseDragOffset[0] = x;
  _mouseDragOffset[1] = y;
  _mouseDragOffset[2] = z;
}


float*
Shape::getMouseDragOffset()
{
  return _mouseDragOffset;
}


Geometry& Shape::getGeometry()
{
  return *_geometry;
}


Appearance&
Shape::getAppearance()
{
  return *_appearance;
}


void
Shape::setAppearance(Appearance& appearance)
{
  _appearance = &appearance;
}


//const std::string&
//Shape::getTextString() const
//{
//  return _label;
//}


//float*
//Shape::getTextPosition()
//{
//  return 0;
//}


}


}
