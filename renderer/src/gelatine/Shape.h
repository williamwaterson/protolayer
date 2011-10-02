#ifndef GELATINE_SHAPE_H
#define GELATINE_SHAPE_H


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
class Shape : public Leaf
{
private:
  /** TODO: Documentation */
  bool _selected;

  /** TODO: Documentation */
  bool _selectable;

  /** TODO: Documentation */
  float* _register;

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
  void render(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderInSelectionMode(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void compile();

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


#endif // GELATINE_SHAPE_H
