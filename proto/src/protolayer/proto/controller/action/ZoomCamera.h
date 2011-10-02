#ifndef PROTOLAYER_PROTO_ZOOMCAMERA_H
#define PROTOLAYER_PROTO_ZOOMCAMERA_H

#include <map>
#include <set>

#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-workflow.h>


namespace protolayer
{

namespace proto
{

namespace action
{

/**
 * TODO: Documentation
 * <p>
 */
class ZoomCamera : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ZoomCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ZoomCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void doit();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void undo();

private:
  /**
   * TODO: Documentation
   *
   */
  ZoomCamera(const ZoomCamera& zoomCamera);

  /**
   * TODO: Documentation
   *
   */
  ZoomCamera& operator=(const ZoomCamera& zoomCamera);

};


}


}


}


#endif // PROTOLAYER_PROTO_ZOOMCAMERA_H
