#include "Propagation.h"


namespace protolayer
{

namespace subdivision
{

Propagation::Propagation()
{
}


int Propagation::getNumberFaces() const
{
  return _faces.size();
}


Face& Propagation::getFace(int index)
{
  return *_faces[index];
}


void Propagation::addFace(Face& face)
{
  _faces.push_back(&face);
}


}


}
