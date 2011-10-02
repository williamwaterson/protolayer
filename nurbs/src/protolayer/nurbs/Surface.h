#ifndef PROTOLAYER_SURFACE_H
#define PROTOLAYER_SURFACE_H

#include <vector>

#include "ControlPoint.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Surface
{
  /** TODO: Documentation */
  int _m;

  /** TODO: Documentation */
  int _n;

  /** TODO: Documentatino */
  int _uOrder;

  /** TODO: Documentatino */
  int _vOrder;

  /** TODO: Documentation */
  float* _uKnots;

  /** TODO: Documentation */
  float* _vKnots;

  /** TODO: Documentation */
  ControlPoint** _points;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Surface(int m, int n);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Surface();

  /**
   * TODO: Documentation
   * <p>
   */
  //  virtual ControlPointIteratorType getControlPoints();

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluate(float u, float v, float result[3]);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Surface(const Surface& Surface);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Surface& operator=(const Surface& Surface);

  /**
   * TODO: Documentation
   * <p>
   */
  float basisFunction(int i, int k, float t, float* knots);

};


}


}


#endif // PROTOLAYER_SURFACE_H
