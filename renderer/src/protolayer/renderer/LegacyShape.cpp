#include "LegacyShape.h"


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


LegacyShape::LegacyShape(Geometry& geometry)
{
  _selected = false;
  _selectable = true;

  _geometry = &geometry;

  _mouseDragOffset[0] = 0;
  _mouseDragOffset[1] = 0;
  _mouseDragOffset[2] = 0;

  _appearance = new style::Appearance();

  typedef Geometry::PointIteratorType PIType;
  for (PIType iter = geometry.getPoints(); iter != geometry.getLastPoint(); iter++) {
    scenegraph::Point* point = new scenegraph::Point(*iter);
    addPoint(*point);
  }

  _cullingFunction = &backFaceCull;
}


LegacyShape::LegacyShape(Geometry& geometry,
			 style::Appearance& appearance)
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
    scenegraph::Point* point = new scenegraph::Point(*iter);
    addPoint(*point);
  }

  _cullingFunction = &backFaceCull;
}


LegacyShape::~LegacyShape()
{
}


void LegacyShape::enableFrontFaceCulling()
{
  _cullingFunction = &frontFaceCull;
}


void LegacyShape::enableBackFaceCulling()
{
  _cullingFunction = &backFaceCull;
}


void LegacyShape::enableBackAndFrontFaceCulling()
{
  _cullingFunction = &backAndFrontFaceCull;
}


void LegacyShape::disableCulling()
{
  _cullingFunction = &disableCull;
}


void LegacyShape::render(float alpha)
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
      _register = (*iter)->getCoordinates();
      glVertex3f(_register[0], _register[1], _register[2]);
    }
    glEnd();

  }
}


/*
void LegacyShape::render(float alpha, style::Appearance& appearance)
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

void LegacyShape::compile()
{
}


void LegacyShape::renderInSelectionMode(float alpha)
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
LegacyShape::setSelectable(bool flag)
{
  _selectable = flag;
}


bool
LegacyShape::isSelectable()
{
  return _selectable;
}


void
LegacyShape::setSelected()
{
  _selected = true;
}


void
LegacyShape::setUnselected()
{
  _selected = false;
}


bool
LegacyShape::isSelected()
{
  return _selected;
}


void
LegacyShape::setSelected(bool flag)
{
  _selected = flag;
}


void
LegacyShape::setMouseDragOffset(float x, float y, float z)
{
  _mouseDragOffset[0] = x;
  _mouseDragOffset[1] = y;
  _mouseDragOffset[2] = z;
}


float*
LegacyShape::getMouseDragOffset()
{
  return _mouseDragOffset;
}


Geometry& LegacyShape::getGeometry()
{
  return *_geometry;
}


style::Appearance&
LegacyShape::getAppearance()
{
  return *_appearance;
}


void
LegacyShape::setAppearance(style::Appearance& appearance)
{
  _appearance = &appearance;
}


//const std::string&
//LegacyShape::getTextString() const
//{
//  return _label;
//}


//float*
//LegacyShape::getTextPosition()
//{
//  return 0;
//}


}


}
