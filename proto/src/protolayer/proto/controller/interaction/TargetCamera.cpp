#include "TargetCamera.h"
#include <iostream.h>

namespace protolayer
{ 

namespace proto
{

namespace interaction
{

TargetCamera::TargetCamera(StateLayer& stateLayer) :
  protolayer::proto::GraphInteraction(stateLayer)
{
}


TargetCamera::~TargetCamera()
{
}


void TargetCamera::mouseDown(float x, float y, int clickCount)
{
  protolayer::proto::GraphInteraction::mouseDown(x, y, clickCount);

  /** TODO: Documentation */
  float _targetTransform[4][4];

  /** TODO: Documentation */
  float _inverse[4][4];

  /** TODO: Documentation */
  scenegraph::Camera* _camera;

  /** TODO: Documentation */
  scenegraph::Group* _cameraGroup;

  /** TODO: Documentation */
  scenegraph::HitModel* _hitModel;

  scenegraph::Shot& shot = getStateLayer().getViewLayer().getCurrentShot();
  scenegraph::HitModel& hitModel = shot.getHitModel();
  scenegraph::Camera& camera = shot.getCamera();
  scenegraph::Scene& scene = shot.getScene();
  scenegraph::Group* cameraGroup = scene.getRoot().getParent(camera);

  //  Pick a new camera target based on the hits
  scenegraph::Node* node = hitModel.getHit();
  if (node != 0) {
    InstanceNode* np = dynamic_cast <InstanceNode*> (node);
    if (np != 0) {
      float position[4];
      float target[4];
      //      np->getLocalTransform(_targetTransform);
      //      np->getLocalTransform(_targetTransform);
      np->getGlobalTransform(_targetTransform);
      position[0] = _targetTransform[0][3];
      position[1] = _targetTransform[1][3];
      position[2] = _targetTransform[2][3];
      position[3] = _targetTransform[3][3];

      //      cameraGroup->getLocalTransform(_targetTransform);
      cameraGroup->getGlobalTransform(_targetTransform);
      renderer::inverse(_targetTransform, _inverse);
      renderer::multiply(_inverse, position, target);

      camera.getTarget().getLocalPoint().getCoordinates()[0] = target[0];
      camera.getTarget().getLocalPoint().getCoordinates()[1] = target[1];
      camera.getTarget().getLocalPoint().getCoordinates()[2] = target[2];
      camera.update();
    //    float* target = item->getGeometry().getPosition();
    //    camera->_target[0] = target[0];
    //    camera->_target[1] = target[1];
    //    camera->_target[2] = target[2];
    }

    DomainNode* domainNode = dynamic_cast <DomainNode*> (node);
    if (domainNode != 0) {
      float position[4];
      float target[4];
      domainNode->getLocalTransform(_targetTransform);
      position[0] = _targetTransform[0][3];
      position[1] = _targetTransform[1][3];
      position[2] = _targetTransform[2][3];
      position[3] = _targetTransform[3][3];

      cameraGroup->getLocalTransform(_targetTransform);
      renderer::inverse(_targetTransform, _inverse);
      renderer::multiply(_inverse, position, target);

      camera.getTarget().getLocalPoint().getCoordinates()[0] = target[0];
      camera.getTarget().getLocalPoint().getCoordinates()[1] = target[1];
      camera.getTarget().getLocalPoint().getCoordinates()[2] = target[2];
      camera.update();
    }

    getStateLayer().getViewLayer().swapRendererPortsAndDisplay();    
  }
}


}


}


}
