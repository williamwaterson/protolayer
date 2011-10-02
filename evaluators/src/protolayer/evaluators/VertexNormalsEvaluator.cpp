#include "VertexNormalsEvaluator.h"


namespace protolayer
{

namespace evaluators
{

VertexNormalsEvaluator::VertexNormalsEvaluator(FaceNormalsEvaluator& evaluator) :
  _faceNormalsEvaluator(&evaluator)
{
  subdivision::Mesh& mesh = evaluator.getMesh();  
  for (int i = 0; i < mesh.getNumberVertices(); i++) {
    subdivision::Vertex& vertex = mesh.getVertex(i);

    float* normal = new float [4];
    normal[0] = 0;
    normal[1] = 0;
    normal[2] = 0;
    normal[3] = 1;

    _vertexNormals[&vertex] = normal;
  }

  for (int i = 0; i < mesh.getNumberFaces(); i++) {
    subdivision::Face& face = mesh.getFace(i);
    float* faceNormal = _faceNormalsEvaluator->getNormal(face);
    for (int j = 0; j < face.getNumberVertices(); j++) {
      subdivision::Vertex& vertex = face.getVertex(j);
      float* vertexNormal = _vertexNormals[&vertex];

      vertexNormal[0] += faceNormal[0];
      vertexNormal[1] += faceNormal[1];
      vertexNormal[2] += faceNormal[2];
    }
  }
}


VertexNormalsEvaluator::~VertexNormalsEvaluator()
{
  VertexNormalsMapType::iterator iter;
  for(iter = _vertexNormals.begin(); iter != _vertexNormals.end(); iter++) {
    delete[] iter->second;
  }
}


float* VertexNormalsEvaluator::getNormal(subdivision::Vertex& vertex)
{
  return _vertexNormals[&vertex];
}


}


}
