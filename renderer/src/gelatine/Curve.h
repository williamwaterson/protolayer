#ifndef GELATINE_CURVE_H
#define GELATINE_CURVE_H

#include <set.h>

#include "protolayer/protolayer-common.h"
#include "protolayer/protolayer-nurbs.h"

#include "ControlPointFactory.h"
#include "Vertex.h"
#include "Shape.h"

namespace gelatine
{

/**
 * A NURBS-based curve.
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Curve : public Leaf
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Curve();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Curve();

  /**
   * TODO: Documentation
   * <p>
   */
  void render(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderInSelectionMode(float alpha, Appearance& appearance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Curve(const Curve& Curve);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Curve& operator=(const Curve& Curve);

};


}


#endif // GELATINE_CURVE_H
