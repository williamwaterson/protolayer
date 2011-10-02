#include "FaceNormalsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

FaceNormalsEvaluator::FaceNormalsEvaluator(subdivision::Mesh& mesh) :
  _mesh(&mesh)
{
  for (int i = 0; i < mesh.getNumberFaces(); i++) {
    subdivision::Face& face = mesh.getFace(i);
    _faceIntermediates[&face] = new FaceIntermediates(face);
  }
}


subdivision::Mesh& FaceNormalsEvaluator::getMesh()
{
  return *_mesh;
}


float* FaceNormalsEvaluator::getNormal(subdivision::Face& face)
{
  return _faceIntermediates[&face]->getNormal();
}


}


}
