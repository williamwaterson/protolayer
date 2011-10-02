#ifndef GELATINE_INDIRECTSHAPE_H
#define GELATINE_INDIRECTSHAPE_H


#include <assert.h>
#include <set.h>

#include "forward.h"
#include "Geometry.h"
#include "ShapeModel.h"
#include "Leaf.h"


namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class IndirectShape : public Leaf
{
  /** TODO: Documentation */
  float (*_quaternion)[4];
            
  /** TODO: Documentation */
  ShapeModel& _model;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit IndirectShape(ShapeModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit IndirectShape(Geometry& geometry);

  /**
   * TODO: Documentation
   * <p>
   */
  IndirectShape(Geometry& geometry,
                Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~IndirectShape();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeModel& getModel();

  /**
   * Todo: Documentation
   * <p>
   */
  virtual Geometry& getGeometry();

  /**
   * TODO: Documentation
   * <p>
   */
  void update(float quaternion[4][4]);

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
  void triggerHitListeners(unsigned int name);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  IndirectShape(const IndirectShape& indirectShape);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  IndirectShape& operator=(const IndirectShape& indirectShape);

};


}


#endif // GELATINE_INDIRECTSHAPE_H
