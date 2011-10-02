#include "Petal.h"


namespace protolayer
{

namespace subdivision
{

Petal::Petal(Vertex& vertex)
{
}


Petal::~Petal()
{
}


int Petal::getNumberFaces() const
{
  return _faces.size();
}


Vertex& Petal::getVertex()
{
  return *_vertex;
}


Face& Petal::getFace(int index)
{
  return *(_faces[index]);
}


void Petal::addFace(Face& face)
{
  _faces.push_back(&face);
}


void Petal::removeFace(Face& face)
{
}


void Petal::clear()
{
}


}


}
