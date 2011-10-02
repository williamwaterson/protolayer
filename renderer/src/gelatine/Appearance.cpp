#include "Appearance.h"


namespace gelatine
{

Appearance::Appearance()
{
  _renderable = true;

  _modifierAlpha = 1.0f;

  _color[0] = 0.3f;
  _color[1] = 0.3f;
  _color[2] = 0.3f;
  _color[3] = 0.3f;

  _lineWidth = 2.0f;
}


Appearance::~Appearance()
{
}


float
Appearance::getLineWidth() const
{
  return _lineWidth;
}


float
Appearance::getModifierAlpha() const
{
  return _modifierAlpha;
}


bool
Appearance::isRenderable() const
{
  return _renderable;
}


float*
Appearance::getColor()
{
  return _color;
}


void
Appearance::setRenderable(bool flag)
{
  _renderable = flag;
}


void
Appearance::setModifierAlpha(float alpha)
{
  _modifierAlpha = alpha;
}


void
Appearance::setColor3(float color[3])
{
  _color[0] = color[0];
  _color[1] = color[1];
  _color[2] = color[2];
}


void
Appearance::setColor(float color[4])
{
  _color[0] = color[0];
  _color[1] = color[1];
  _color[2] = color[2];
  _color[3] = color[3];
}


void
Appearance::setColor(float red, float green, float blue, float alpha)
{
  _color[0] = red;
  _color[1] = green;
  _color[2] = blue;
  _color[3] = alpha;
}


}
