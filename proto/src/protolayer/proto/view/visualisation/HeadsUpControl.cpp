#include "HeadsUpControl.h"


namespace protolayer
{

namespace proto
{

HeadsUpControl::HeadsUpControl(float x, float y, float z)
{
  style::Appearance* black = new style::Appearance();
  black->setColor(0.0f, 0.0f, 0.0f, 1.0f);

  style::Appearance* white = new style::Appearance();
  white->setColor(1.0f, 1.0f, 1.0f, 1.0f);

  _upArrow = new geometry::ArrowDisk(0.3f, 2, *white, *black);
  _downArrow = new geometry::ArrowDisk(0.3f, 2, *white, *black);

  addChild(*_upArrow);
  addChild(*_downArrow);

  _upArrow->translate(0, 0.3, 0);

  _downArrow->translate(0, -0.3, 0);
  _downArrow->rotateZ(M_PI);

  _upArrow->setSelectable(true);
  _downArrow->setSelectable(true);

  setSelectable(true);

  //  _viewChangeControl = new geometry::Target(0.1f, 1, *white, *black);
  //  addChild(*_viewChangeControl);
  //  _viewChangeControl->translate(0.3f, 0, 0);
}


geometry::ArrowDisk& HeadsUpControl::getUpArrow()
{
  return *_upArrow;
}


geometry::ArrowDisk& HeadsUpControl::getDownArrow()
{
  return *_downArrow;
}


geometry::Target& HeadsUpControl::getViewChangeControl()
{
  return *_viewChangeControl;
}


}


}
