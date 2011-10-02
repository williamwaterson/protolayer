#ifndef GELATINE_NURBSGEOMETRY_H
#define GELATINE_NURBSGEOMETRY_H


#include <map.h>

#include "protolayer/protolayer-nurbs.h"

#include "forward.h"
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
class NurbsGeometry : public Geometry
{
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
  //  GLfloat _ctlpoints[4][3];

  /** TODO: Documentation */
  //  GLfloat _meshPoints[4][4][3];

  /** TODO: Documentation */
  //  GLfloat _knots[8];

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
  NurbsGeometry();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~NurbsGeometry();

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
  const ::protolayer::Representation& getRepresentation() const;

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

  /**
   * TODO: Documentation
   * <p>
   */ 
  virtual void triggerHitListeners(unsigned int name);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NurbsGeometry(const NurbsGeometry& geometry);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NurbsGeometry& operator=(const NurbsGeometry& geometry);

};


}


#endif // GELATINE_NURBSGEOMETRY_H
