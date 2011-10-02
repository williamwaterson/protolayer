#ifndef PROTOLAYER_RENDERER_SHAPE_H
#define PROTOLAYER_RENDERER_SHAPE_H


#include <assert.h>
#include <string>
#include <set.h>

#include "forward.h"
#include "Geometry.h"
#include "Leaf.h"


namespace protolayer
{

namespace renderer
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
  FunctionPointerType _cullingFunction;

  /** TODO: Documentation */
  bool _selected;

  /** TODO: Documentation */
  bool _selectable;

  /** TODO: Documentation */
  const float* _register;

  /** TODO: Documentation */
  float _mouseDragOffset[3];

  /** TODO: Documentation */
  Geometry* _geometry;

  /** TODO: Documentation */
  Appearance* _appearance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Shape()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Shape(Geometry& geometry);

  /**
   * TODO: Documentation
   * <p>
   */
  Shape(Geometry& geometry,
        Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Shape();


  /**
   * TODO: Documentation
   * <p>
   */
  void setSelected();

  /**
   * TODO: Documentation
   * <p>
   */
  void setUnselected();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelected();

  /**
   * TODO: Documentation
   * <p>
   */
  void setSelected(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setMouseDragOffset(float x,
                          float y,
                          float z);

  /**
   * TODO: Documentation
   *
   */
  float* getMouseDragOffset();

  /**
   * TODO: Documentation
   * <p>
   */
  Appearance& getAppearance();

  /**
   * TODO: Documentation
   * <p>
   */
  void setAppearance(Appearance& appearance);

  /**
   * Todo: Documentation
   * <p>
   */
  virtual Geometry& getGeometry();

  /**
   * TODO: Documentation
   * <p>
   */
  void setSelectable(bool flag);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelectable();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void render(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void renderInSelectionMode(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void compile();

  /**
   * TODO: Documentation
   * <p>
   */
  void enableFrontFaceCulling();

  /**
   * TODO: Documentation
   * <p>
   */
  void enableBackFaceCulling();

  /**
   * TODO: Documentation
   * <p>
   */
  void enableBackAndFrontFaceCulling();

  /**
   * TODO: Documentation
   * <p>
   */
  void disableCulling();

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


#endif // PROTOLAYER_RENDERER_SHAPE_H
