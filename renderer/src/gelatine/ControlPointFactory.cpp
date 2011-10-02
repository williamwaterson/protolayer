#include "ControlPointFactory.h"


namespace gelatine
{


ControlPointFactory::ControlPointFactory()
{
}


ControlPointFactory::~ControlPointFactory()
{
}


protolayer::nurbs::ControlPoint* ControlPointFactory::create(float* localCoordinates,
                                                           float* coordinates)
{
  return new ::gelatine::ControlPoint(localCoordinates, coordinates);
}


}
