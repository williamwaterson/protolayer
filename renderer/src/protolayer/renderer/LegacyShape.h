#ifndef PROTOLAYER_RENDERER_LEGACYSHAPE_H
#define PROTOLAYER_RENDERER_LEGACYSHAPE_H


#include <assert.h>
#include <string>
#include <set.h>

#include "forward.h"
#include "Geometry.h"

#include "protolayer/protolayer-scenegraph.h"
#include "protolayer/protolayer-style.h"


namespace protolayer
{

namespace renderer
{

/**
 * TODO: Documentation
 * <p>
 */
class LegacyShape : public scenegraph::Shape
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
  style::Appearance* _appearance;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  LegacyShape()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  explicit LegacyShape(Geometry& geometry);

  /**
   * TODO: Documentation
   * <p>
   */
  LegacyShape(Geometry& geometry,
	      style::Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~LegacyShape();


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
  style::Appearance& getAppearance();

  /**
   * TODO: Documentation
   * <p>
   */
  void setAppearance(style::Appearance& appearance);

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
  LegacyShape(const LegacyShape& shape);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  LegacyShape& operator=(const LegacyShape& shape);

};


}


}


#endif // PROTOLAYER_RENDERER_SHAPE_H
