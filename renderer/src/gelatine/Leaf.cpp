#include "Leaf.h"


namespace gelatine
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


unsigned int Leaf::getID() const
{
  return _id;
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


void Leaf::addPoint(Point& point)
{
  _points.push_back(&point);
}


void Leaf::removePoint(Point& point)
{
  typedef std::vector <Point*>::iterator PIter;
  PIter position = std::find(_points.begin(), _points.end(), &point);
  if (position != _points.end()) {
    _points.erase(position);
  }
}


void Leaf::clearPoints()
{
  _points.clear();
}


Point* Leaf::getPointForID(unsigned int id)
{
  if (_idPointMap.count(id) != 0) {
    return _idPointMap[id]; 
  }

  return 0;
}


bool Leaf::isPart(Point& point)
{
  typedef std::vector <Point*>::iterator PIter;
  PIter position = std::find(_points.begin(), _points.end(), &point);
  return position != _points.end();
}


void Leaf::update(float quaternion[4][4])
{
  _quaternion = quaternion;
  float* local;
  float* global;
  typedef PointIteratorType PIType;
  for (PIType iter = _points.begin(); iter != _points.end(); iter++) {
    local = (*iter)->getLocalCoordinates();
    global = (*iter)->getCoordinates();

    global[0] =  quaternion[0][0] * local[0];
    global[0] += quaternion[0][1] * local[1];
    global[0] += quaternion[0][2] * local[2];
    global[0] += quaternion[0][3] * local[3];

    global[1] =  quaternion[1][0] * local[0];
    global[1] += quaternion[1][1] * local[1];
    global[1] += quaternion[1][2] * local[2];
    global[1] += quaternion[1][3] * local[3];

    global[2] =  quaternion[2][0] * local[0];
    global[2] += quaternion[2][1] * local[1];
    global[2] += quaternion[2][2] * local[2];
    global[2] += quaternion[2][3] * local[3];

    global[3] =  quaternion[3][0] * local[0];
    global[3] += quaternion[3][1] * local[1];
    global[3] += quaternion[3][2] * local[2];
    global[3] += quaternion[3][3] * local[3];
  }
}


void Leaf::update()
{
  update(_quaternion);
}


void Leaf::render(float alpha)
{
}


void Leaf::renderInSelectionMode(float alpha)
{
}


}
