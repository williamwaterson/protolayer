#ifndef GELATINE_DIRECTSHAPE_H
#define GELATINE_DIRECTSHAPE_H


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
class DirectShape : public Leaf
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
  explicit DirectShape(ShapeModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit DirectShape(Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~DirectShape();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeModel& getModel();

  /**
   * Todo: Documentation
   * <p>
   */
  virtual const Geometry& getGeometry() const;

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
  DirectShape(const DirectShape& directShape);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DirectShape& operator=(const DirectShape& directShape);

};


}


#endif // GELATINE_DIRECTSHAPE_H
