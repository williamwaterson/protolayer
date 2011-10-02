#ifndef PROTOLAYER_BSPLINECURVE_H
#define PROTOLAYER_BSPLINECURVE_H

#include <math.h>
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
class Curve
{
public:
  /** TODO: Documentation */
  typedef std::vector <ControlPoint*>::iterator ControlPointIteratorType;

 private:
  /** TODO: Documentatino */
  int _order;

  /** TODO: Documentation */
  std::vector <float> _knots;

  /** TODO: Documentation */
  std::vector <ControlPoint*> _points;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Curve(int order);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Curve();

  /**
   * TODO: Documentation
   * <p>
   */
  ControlPointIteratorType getControlPoints();

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluate(float t, float result[3]);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Curve(const Curve& curve);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Curve& operator=(const Curve& curve);

  /**
   * TODO: Documentation
   * <p>
   */
  float basisFunction(int i, int k, float t);

};


}


}


#endif // PROTOLAYER_BSPLINECURVE_H
