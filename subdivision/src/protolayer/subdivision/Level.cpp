#include "Level.h"


namespace protolayer
{

namespace subdivision
{

Level::Level(std::vector <Face*>& faces)
{
  construct(faces);
}


Level::Level(Level& level)
{
  construct(level._faces);  
}


Level::Level(Face& face)
{
  walk(face);
}


void Level::construct(std::vector <Face*>& faces) {
  for (int i = 0; i < faces.size(); i++) {
    Face* face = faces[i];
    walk(*face);
  }  
}


Level::~Level()
{
}


void Level::walk(Face& face)
{
  Propagation* propagation = face.getPropagation();
  if (propagation != 0) {
    for (int i = 0; i < propagation->getNumberFaces(); i++) {
      Face& face = propagation->getFace(i);
      _faces.push_back(&face);
    }
  }
}


int Level::getNumberFaces() const
{
  return _faces.size();
}


Face& Level::getFace(int index)
{
  return *(_faces[index]);
}


}


}
