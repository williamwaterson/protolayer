#ifndef GELATINE_NONSHAPE_H
#define GELATINE_NONSHAPE_H

#include <assert.h>
#include <iostream>
#include <string>
#include <set.h>

#include "forward.h"
#include "Geometry.h"
#include "Leaf.h"

namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class NonShape : public Leaf
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  NonShape();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~NonShape();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NonShape(const NonShape& nonShape);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NonShape& operator=(const NonShape& nonShape);

};


}


#endif // GELATINE_NONSHAPE_H
