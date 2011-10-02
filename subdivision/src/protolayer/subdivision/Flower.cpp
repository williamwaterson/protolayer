#include "Flower.h"


namespace protolayer
{

namespace subdivision
{

Flower::Flower(Vertex& vertex)
{
  _vertex = &vertex;
}


Flower::~Flower()
{
}


int Flower::getNumberFaces() const
{
  return _faces.size();
}


Vertex& Flower::getVertex()
{
  return *_vertex;
}


Face& Flower::getFace(int index)
{
  return *(_faces[index]);
}


void Flower::addFace(Face& face)
{
  _faces.push_back(&face);
}


void Flower::removeFace(Face& face)
{
}


void Flower::clear()
{
}


}


}
