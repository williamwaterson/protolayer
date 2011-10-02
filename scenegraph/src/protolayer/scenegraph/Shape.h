#ifndef PROTOLAYER_SCENEGRAPH_SHAPE_H
#define PROTOLAYER_SCENEGRAPH_SHAPE_H


#include "Leaf.h"


namespace protolayer
{

namespace scenegraph
{

/**
 * TODO: Documentation
 * <p>
 */
class Shape : public Leaf
{
  /** Type Definitions */
  typedef void (*FunctionPointerType)();

private:
  /** TODO: Documentation */
  bool _selected;

  /** TODO: Documentation */
  bool _selectable;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Shape();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Shape() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void render(float alpha) = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shape(const Shape& shape);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shape& operator=(const Shape& shape);

};


}


}


#endif // PROTOLAYER_SCENEGRAPH_SHAPE_H
