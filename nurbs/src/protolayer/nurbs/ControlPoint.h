#ifndef PROTOLAYER_CONTROLPOINT_H
#define PROTOLAYER_CONTROLPOINT_H

#include "protolayer/protolayer-util.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ControlPoint : public util::Point
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ControlPoint(float* localCoordinates, float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  ~ControlPoint();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ControlPoint(const ControlPoint& controlPoint);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ControlPoint& operator=(const ControlPoint& controlPoint);

};

}

}

#endif // PROTOLAYER_CONTROLPOINT_H
