#ifndef PROTOLAYER_PROTO_POSITIONCAMERA_H
#define PROTOLAYER_PROTO_POSITIONCAMERA_H

#include <map>
#include <set>

#include <protolayer/protolayer-assembly.h>
#include <protolayer/protolayer-ontology.h>
#include <protolayer/protolayer-workflow.h>


namespace protolayer
{

namespace proto
{

/**
 * TODO: Documentation
 * <p>
 */
class PositionCamera : public workflow::Action
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  PositionCamera();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~PositionCamera();

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
  PositionCamera(const PositionCamera& positionCamera);

  /**
   * TODO: Documentation
   *
   */
  PositionCamera& operator=(const PositionCamera& positionCamera);

};


}


}


#endif // PROTOLAYER_PROTO_POSITIONCAMERA_H
