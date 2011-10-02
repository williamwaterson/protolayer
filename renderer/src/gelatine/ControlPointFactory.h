#ifndef GELATINE_CONTROLPOINTFACTORY_H
#define GELATINE_CONTROLPOINTFACTORY_H


#include "protolayer/protolayer-common.h"
#include "protolayer/protolayer-nurbs.h"

#include "ControlPoint.h"


namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ControlPointFactory :
  public ::protolayer::AbstractFactory < ::protolayer::nurbs::ControlPoint >
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ControlPointFactory();

  /**
   * TODO: Documentation
   * <p>
   */
  ~ControlPointFactory();

  /**
   * TODO: Documentation
   * <p>
   */
  ::protolayer::nurbs::ControlPoint* create(float* localCoordinates, float* coordinates);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ControlPointFactory(const ControlPointFactory& ControlPointFactory);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ControlPointFactory& operator=(const ControlPointFactory& ControlPointFactory);

};


}


#endif // GELATINE_CONTROLPOINTFACTORY_H
