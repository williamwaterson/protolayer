#ifndef GELATINE_DIRECTSHAPEMODEL_H
#define GELATINE_DIRECTSHAPEMODEL_H


#include <string>
#include "Geometry.h"
#include "Appearance.h"


namespace gelatine
{


/**
 * TODO: Documentation
 * <p>
 */
class DirectShapeModel
{
private:
  /** TODO: Documentation */
  bool _selected;

  /** TODO: Documentation */
  bool _selectable;

  /** TODO: Documentation */
  float _mouseDragOffset[3];

  /** TODO: Documentation */
  float** _vertices;

  /** TODO: Documentation */
  Appearance* _appearance;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  DirectShapeModel();

  /**
   * TODO: Documentation
   * <p>
   */  
  explicit DirectShapeModel(Appearance& appearance);

  /**
   * TODO: Documentation
   *
   */
  virtual ~DirectShapeModel();

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

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DirectShapeModel(const DirectShapeModel& directShapeModel);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DirectShapeModel& operator=(const DirectShapeModel& directShapeModel);

};


}


#endif // GELATINE_DIRECTSHAPEMODEL_H
