#include "Leaf.h"


namespace protolayer
{

namespace scenegraph
{

namespace {

  float UNIT_QUATERNION[4][4] =
  { {  1,  0,  0 , 0 },
    {  0,  1,  0 , 0 },
    {  0,  0,  1 , 0 },
    {  0,  0,  0 , 1 } };

}


Leaf::Leaf()
{
  _quaternion = UNIT_QUATERNION;
}


Leaf::~Leaf()
{
}


int Leaf::getNumberPoints() const
{
  return _points.size();
}


Leaf::PointIteratorType Leaf::getPoints()
{
  return _points.begin();
}


Leaf::PointIteratorType Leaf::getLastPoint()
{
  return _points.end();
}


TransformedPoint& Leaf::addPoint(Point& point)
{
  TransformedPoint* created = new TransformedPoint(point);
  _points.push_back(created);

  return *created;
}


void Leaf::removePoint(Point& point)
{
  PointIteratorType position = _points.end();
  for (PointIteratorType iter = _points.begin(); iter != _points.end(); iter++) {
    if ((*iter)->isLocalPoint(point)) {
      position = iter;
    }
  }

  if (position != _points.end()) {
    TransformedPoint* transformedPoint = *position;
    _points.erase(position);
    delete transformedPoint;
  }
}


void Leaf::clearPoints()
{
  for (PointIteratorType iter = _points.begin(); iter != _points.end(); iter++) {
    TransformedPoint* transformedPoint = *iter;
    delete transformedPoint;
  }
  _points.clear();
}


bool Leaf::isPart(Point& point)
{
  PointIteratorType position = std::find(_points.begin(), _points.end(), &point);
  return position != _points.end();
}


void Leaf::update(float quaternion[4][4])
{
  _quaternion = quaternion;
  for (PointIteratorType iter = _points.begin(); iter != _points.end(); iter++) {
    (*iter)->update(quaternion);
  }
}


void Leaf::update()
{
  update(_quaternion);
}


}


}
