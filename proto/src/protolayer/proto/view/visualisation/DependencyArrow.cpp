#include "DependencyArrow.h"


namespace protolayer
{

namespace proto
{

DependencyArrow::DependencyArrow(assembly::DomainDependency& dependency,
                                 DomainNode& fromDomainNode,
                                 DomainNode& toDomainNode,
                                 scenegraph::Camera& camera) :
  geometry::TaperedArrow(10.0f, 10.0f, 10.0f, 3.0f, 3.0f, 3.0f,
                         *(new style::Appearance()),
                         *(new style::Appearance()))
{
  _dependency = &dependency;

  _fromDomainNode = &fromDomainNode;
  _toDomainNode = &toDomainNode;
  _camera = &camera;

  _isGhosted = false;

  float temp[4][4];
  fromDomainNode.getGlobalTransform(temp);
  geometry::TaperedArrow::setStart(temp[0][3], temp[1][3], temp[2][3]);
  toDomainNode.getGlobalTransform(temp);
  geometry::TaperedArrow::setEnd(temp[0][3], temp[1][3], temp[2][3]);

  //  getFaceAppearance().setColor(0.0f, 0.0f, 0.0f, 1.0f);
  updateEndPositions();
}


bool DependencyArrow::isFrom(DomainNode& domainNode)
{
  return _fromDomainNode == &domainNode;
}


bool DependencyArrow::isTo(DomainNode& domainNode)
{
  return _toDomainNode == &domainNode;
}


DomainNode& DependencyArrow::getFromDomainNode()
{
  return *_fromDomainNode;
}


DomainNode& DependencyArrow::getToDomainNode()
{
  return *_toDomainNode;
}


void DependencyArrow::setGhosted(bool flag)
{
  _isGhosted = flag;
}


bool DependencyArrow::isGhosted()
{
  return _isGhosted;
}


void DependencyArrow::updateEndPositions()
{
  // Evaluate direction vector
  update();
  float temp[4][4];
  float* direction = new float[3];

  _toDomainNode->getGlobalTransform(temp);
  direction[0] = temp[0][3];
  direction[1] = temp[1][3];
  direction[2] = temp[2][3];
  
  _fromDomainNode->getGlobalTransform(temp);
  direction[0] -= temp[0][3];
  direction[1] -= temp[1][3];
  direction[2] -= temp[2][3];
  
  float length = (float) sqrt(direction[0] * direction[0] +
                              direction[1] * direction[1] +
                              direction[2] * direction[2]);
    
  direction[0] /= length;
  direction[1] /= length;
  direction[2] /= length;

  //  float radius = _fromDomainNode->getHeight();
  float radius = 0; //5; //_fromDomainNode->getHeight();

  direction[0] *= radius;
  direction[1] *= radius;
  direction[2] *= radius;
    
  _fromDomainNode->getGlobalTransform(temp);
  direction[0] += temp[0][3];
  direction[1] += temp[1][3];
  direction[2] += temp[2][3];

  setStart(direction[0], direction[1], direction[2]);

  // Evaluate direction vector
  _fromDomainNode->getGlobalTransform(temp);
  direction[0] = temp[0][3];
  direction[1] = temp[1][3];
  direction[2] = temp[2][3];

  _toDomainNode->getGlobalTransform(temp);
  direction[0] -= temp[0][3];
  direction[1] -= temp[1][3];
  direction[2] -= temp[2][3];

  length = (float) sqrt(direction[0] * direction[0] +
                        direction[1] * direction[1] +
                        direction[2] * direction[2]);

  direction[0] /= length;
  direction[1] /= length;
  direction[2] /= length;

  //  radius = _toDomainNode->getHeight();
  radius = 0; //5; //_toDomainNode->getHeight();

  direction[0] *= radius;
  direction[1] *= radius;
  direction[2] *= radius;

  _toDomainNode->getGlobalTransform(temp);
  direction[0] += temp[0][3];
  direction[1] += temp[1][3];
  direction[2] += temp[2][3];

  setEnd(direction[0], direction[1], direction[2]);
    
    float normX[3];
    float normY[3];
    float normZ[3];

    _toDomainNode->getGlobalTransform(temp);
    normX[0] = temp[0][3];
    normX[1] = temp[1][3];
    normX[2] = temp[2][3];

    float startToCamera[3];
    startToCamera[0] = _camera->getPosition().getCoordinates()[0];
    startToCamera[1] = _camera->getPosition().getCoordinates()[1];
    startToCamera[2] = _camera->getPosition().getCoordinates()[2];

    _fromDomainNode->getGlobalTransform(temp);
    startToCamera[0] -= temp[0][3];
    startToCamera[1] -= temp[1][3];
    startToCamera[2] -= temp[2][3];

    normX[0] -= temp[0][3];
    normX[1] -= temp[1][3];
    normX[2] -= temp[2][3];

    renderer::normalise(normX);

    renderer::crossProduct(startToCamera, normX, normY);
    renderer::normalise(normY);

    renderer::crossProduct(normX, normY, normZ);
    renderer::normalise(normZ);

    setOrthonormalBasis(normX, normY, normZ);
  update();
}


}


}
