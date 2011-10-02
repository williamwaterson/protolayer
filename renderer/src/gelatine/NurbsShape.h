#ifndef GELATINE_NURBSSHAPE_H
#define GELATINE_NURBSSHAPE_H


#include <assert.h>
#include <set.h>

#include "protolayer/protolayer-nurbs.h"

#include "forward.h"
#include "Geometry.h"
#include "DirectShapeModel.h"
#include "Leaf.h"
#include "Shape.h"

#include "ControlPoint.h"
#include "Curve.h"
#include "Edge.h"
#include "Face.h"
#include "Geometry.h"
#include "Loop.h"
#include "Region.h"
#include "Shell.h"
#include "Vertex.h"


namespace gelatine
{


/**
 * TODO: Documentation
 * <p>
 */
class NurbsShape : public Leaf
{
  /** TODO: Documentation */
  float (*_quaternion)[4];
            
  /** TODO: Documentation */
  DirectShapeModel& _model;

  /** TODO: Documentation */
  typedef std::map <unsigned int, ControlPoint*> ControlPointNameMapType;

  /** TODO: Documentation */
  typedef std::map <unsigned int, Vertex*> VertexNameMapType;

  /** TODO: Documentation */
  typedef std::map <unsigned int, Curve*> CurveNameMapType;

  /** TODO: Documentation */
  typedef std::map <unsigned int, Surface*> SurfaceNameMapType;

  /** TODO: Documentation */
  float* _register;

  /** TODO: Documentation */
  ::protolayer::Representation _representation;

  /** TODO: Documentation */
  ControlPointNameMapType _controlPointNameMap;

  /** TODO: Documentation */
  VertexNameMapType _vertexNameMap;

  /** TODO: Documentation */
  CurveNameMapType _curveNameMap;

  /** TODO: Documentation */
  SurfaceNameMapType _surfaceNameMap;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit NurbsShape(DirectShapeModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit NurbsShape(Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~NurbsShape();

  /**
   * TODO: Documentation
   * <p>
   */
  DirectShapeModel& getModel();

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

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Vertex& vertex);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Vertex& vertex);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Curve& curve);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Curve& curve);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Edge& edge);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Edge& edge);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Loop& loop);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Loop& loop);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Surface& surface);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Surface& surface);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Face& face);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Face& face);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Shell& shell);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Shell& shell);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Region& region);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Region& region);

  /**
   * TODO: Documentation
   * <p>
   */
  ControlPoint* getControlPointForName(unsigned int name);

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex* getVertexForName(unsigned int name);

  /**
   * TODO: Documentation
   * <p>
   */
  Curve* getCurveForName(unsigned int name);

  /**
   * TODO: Documentation
   * <p>
   */
  Surface* getSurfaceForName(unsigned int name);

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
  NurbsShape(const NurbsShape& nurbsShape);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NurbsShape& operator=(const NurbsShape& nurbsShape);

};


}


#endif // GELATINE_NURBSSHAPE_H
