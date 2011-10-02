#include "DirectShapeModel.h"


namespace gelatine
{


DirectShapeModel::DirectShapeModel(Appearance& appearance)
{
  _selected = false;
  _selectable = true;

  _mouseDragOffset[0] = 0;
  _mouseDragOffset[1] = 0;
  _mouseDragOffset[2] = 0;

  _appearance = &appearance;
}


DirectShapeModel::~DirectShapeModel()
{
}


void
DirectShapeModel::setSelectable(bool flag)
{
  _selectable = flag;
}


bool
DirectShapeModel::isSelectable()
{
  return _selectable;
}


void
DirectShapeModel::setSelected()
{
  _selected = true;
}


void
DirectShapeModel::setUnselected()
{
  _selected = false;
}


bool
DirectShapeModel::isSelected()
{
  return _selected;
}


void
DirectShapeModel::setSelected(bool flag)
{
  _selected = flag;
}


void
DirectShapeModel::setMouseDragOffset(float x,
                              float y,
                              float z)
{
  _mouseDragOffset[0] = x;
  _mouseDragOffset[1] = y;
  _mouseDragOffset[2] = z;
}


float*
DirectShapeModel::getMouseDragOffset()
{
  return _mouseDragOffset;
}


Appearance&
DirectShapeModel::getAppearance()
{
  return *_appearance;
}


void
DirectShapeModel::setAppearance(Appearance& appearance)
{
  _appearance = &appearance;
}


//const std::string&
//DirectShapeModel::getTextString() const
//{
//  return _label;
//}


//float*
//DirectShapeModel::getTextPosition()
//{
//  return 0;
//}


}
