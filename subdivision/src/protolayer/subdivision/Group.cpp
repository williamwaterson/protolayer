#include "Group.h"


namespace protolayer
{

namespace subdivision
{

Group::Group()
{
}


Group::~Group()
{
}


int Group::getNumberFaces() const
{
  return _faces.size();
}


void Group::addFace(Face& face)
{
  _faces.push_back(&face);
}


Face& Group::getFace(int index)
{
  return *(_faces[index]);
}


void Group::walk()
{
}


}


}
