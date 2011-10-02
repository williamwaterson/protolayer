#include "ReferenceArrow.h"


namespace protolayer
{

namespace proto
{

ReferenceArrow::ReferenceArrow(assembly::Reference& reference,
                               InstanceNode& fromNode, InstanceNode& toNode,
                               scenegraph::Camera& camera) :
  geometry::TaperedArrow(10.0f, 10.0f, 10.0f, 3.0f, 3.0f, 3.0f,
                         *(new style::Appearance()),
                         *(new style::Appearance()))
{
  _reference = &reference;

  _fromNode = &fromNode;
  _toNode = &toNode;
  _camera = &camera;

  _isGhosted = false;

  float temp[4][4];
  fromNode.getGlobalTransform(temp);
  geometry::TaperedArrow::setStart(temp[0][3], temp[1][3], temp[2][3]);
  toNode.getGlobalTransform(temp);
  geometry::TaperedArrow::setEnd(temp[0][3], temp[1][3], temp[2][3]);

  //  getFaceAppearance().setColor(0.0f, 0.0f, 0.0f, 1.0f);
  updateEndPositions();
}


ReferenceArrow::ReferenceArrow(InstanceNode& fromNode,
                                 InstanceNode& toNode,
			         scenegraph::Camera& camera) :
  geometry::TaperedArrow(10.0f, 10.0f, 10.0f, 3.0f, 3.0f, 3.0f,
                         *(new style::Appearance()),
                         *(new style::Appearance()))
{
  _fromNode = &fromNode;
  _toNode = &toNode;
  _camera = &camera;

  _isGhosted = false;

  float temp[4][4];
  fromNode.getGlobalTransform(temp);
  geometry::TaperedArrow::setStart(temp[0][3], temp[1][3], temp[2][3]);
  toNode.getGlobalTransform(temp);
  geometry::TaperedArrow::setEnd(temp[0][3], temp[1][3], temp[2][3]);

  //  getFaceAppearance().setColor(0.0f, 0.0f, 0.0f, 1.0f);
  updateEndPositions();
}


assembly::Reference& ReferenceArrow::getReference()
{
  return *_reference;
}

bool ReferenceArrow::isFromNode(InstanceNode& node)
{
  return _fromNode == &node;
}


bool ReferenceArrow::isToNode(InstanceNode& node)
{
  return _toNode == &node;
}


InstanceNode& ReferenceArrow::getFromNode()
{
  return *_fromNode;
}


InstanceNode& ReferenceArrow::getToNode()
{
  return *_toNode;
}


void ReferenceArrow::setGhosted(bool flag)
{
  _isGhosted = flag;
}


bool ReferenceArrow::isGhosted()
{
  return _isGhosted;
}


void ReferenceArrow::updateEndPositions()
{
  // Evaluate direction vector
  update();
  float temp[4][4];
  float* direction = new float[3];

  _toNode->getGlobalTransform(temp);
  direction[0] = temp[0][3];
  direction[1] = temp[1][3];
  direction[2] = temp[2][3];
  
  _fromNode->getGlobalTransform(temp);
  direction[0] -= temp[0][3];
  direction[1] -= temp[1][3];
  direction[2] -= temp[2][3];
  
  float length = (float) sqrt(direction[0] * direction[0] +
                              direction[1] * direction[1] +
                              direction[2] * direction[2]);
    
  direction[0] /= length;
  direction[1] /= length;
  direction[2] /= length;

  float radius = _fromNode->getRadius();    

  direction[0] *= radius;
  direction[1] *= radius;
  direction[2] *= radius;
    
  _fromNode->getGlobalTransform(temp);
  direction[0] += temp[0][3];
  direction[1] += temp[1][3];
  direction[2] += temp[2][3];

  setStart(direction[0], direction[1], direction[2]);

  // Evaluate direction vector
  _fromNode->getGlobalTransform(temp);
  direction[0] = temp[0][3];
  direction[1] = temp[1][3];
  direction[2] = temp[2][3];

  _toNode->getGlobalTransform(temp);
  direction[0] -= temp[0][3];
  direction[1] -= temp[1][3];
  direction[2] -= temp[2][3];

  length = (float) sqrt(direction[0] * direction[0] +
                        direction[1] * direction[1] +
                        direction[2] * direction[2]);

  direction[0] /= length;
  direction[1] /= length;
  direction[2] /= length;

  radius = _toNode->getRadius();  

  direction[0] *= radius;
  direction[1] *= radius;
  direction[2] *= radius;

  _toNode->getGlobalTransform(temp);
  direction[0] += temp[0][3];
  direction[1] += temp[1][3];
  direction[2] += temp[2][3];

  setEnd(direction[0], direction[1], direction[2]);
    
    float normX[3];
    float normY[3];
    float normZ[3];

    _toNode->getGlobalTransform(temp);
    normX[0] = temp[0][3];
    normX[1] = temp[1][3];
    normX[2] = temp[2][3];

    float startToCamera[3];
    startToCamera[0] = _camera->getPosition().getCoordinates()[0];
    startToCamera[1] = _camera->getPosition().getCoordinates()[1];
    startToCamera[2] = _camera->getPosition().getCoordinates()[2];

    _fromNode->getGlobalTransform(temp);
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
