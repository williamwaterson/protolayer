#ifndef PROTOLAYER_REPRESENTATION_H
#define PROTOLAYER_REPRESENTATION_H

#include <set>

#include "protolayer/protolayer-util.h"

#include "ControlPoint.h"
#include "Curve.h"
#include "Edge.h"
#include "Face.h"
#include "Loop.h"
#include "Region.h"
#include "Shell.h"
#include "Surface.h"
#include "Vertex.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Representation
{
public:
  /** TODO: Documentation */
  typedef std::set <ControlPoint*>::iterator ControlPointIteratorType;

  /** TODO: Documentation */
  typedef std::set <Vertex*>::iterator VertexIteratorType;

  /** TODO: Documentation */
  typedef std::set <Curve*>::iterator CurveIteratorType;

  /** TODO: Documentation */
  typedef std::set <Edge*>::iterator EdgeIteratorType;

  /** TODO: Documentation */
  typedef std::set <Loop*>::iterator LoopIteratorType;

  /** TODO: Documentation */
  typedef std::set <Surface*>::iterator SurfaceIteratorType;

  /** TODO: Documentation */
  typedef std::set <Face*>::iterator FaceIteratorType;

  /** TODO: Documentation */
  typedef std::set <Shell*>::iterator ShellIteratorType;

  /** TODO: Documentation */
  typedef std::set <Region*>::iterator RegionIteratorType;

private:
  /** TODO: Documentation */
  std::set <ControlPoint*> _controlPoints;

  /** TODO: Documentation */
  std::set <Vertex*> _vertices;

  /** TODO: Documentation */
  std::set <Curve*> _curves;

  /** TODO: Documentation */
  std::set <Edge*> _edges;

  /** TODO: Documentation */
  std::set <Loop*> _loops;

  /** TODO: Documentation */
  std::set <Surface*> _surfaces;

  /** TODO: Documentation */
  std::set <Face*> _faces;

  /** TODO: Documentation */
  std::set <Shell*> _shells;

  /** TODO: Documentation */
  std::set <Region*> _regions;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Representation();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Representation();

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
  ControlPointIteratorType getControlPoints();

  /**
   * TODO: Documentation
   * <p>
   */
  VertexIteratorType getVertices();

  /**
   * TODO: Documentation
   * <p>
   */
  CurveIteratorType getCurves();

  /**
   * TODO: Documentation
   * <p>
   */
  EdgeIteratorType getEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  LoopIteratorType getLoops();

  /**
   * TODO: Documentation
   * <p>
   */
  SurfaceIteratorType getSurfaces();

  /**
   * TODO: Documentation
   * <p>
   */
  FaceIteratorType getFaces();

  /**
   * TODO: Documentation
   * <p>
   */
  ShellIteratorType getShells();

  /**
   * TODO: Documentation
   * <p>
   */
  RegionIteratorType getRegions();

  /**
   * TODO: Documentation
   * <p>
   */
  ControlPointIteratorType getLastControlPoint();

  /**
   * TODO: Documentation
   * <p>
   */
  VertexIteratorType getLastVertex();

  /**
   * TODO: Documentation
   * <p>
   */
  CurveIteratorType getLastCurve();

  /**
   * TODO: Documentation
   * <p>
   */
  EdgeIteratorType getLastEdge();

  /**
   * TODO: Documentation
   * <p>
   */
  LoopIteratorType getLastLoop();

  /**
   * TODO: Documentation
   * <p>
   */
  SurfaceIteratorType getLastSurface();

  /**
   * TODO: Documentation
   * <p>
   */
  FaceIteratorType getLastFace();

  /**
   * TODO: Documentation
   * <p>
   */
  ShellIteratorType getLastShell();

  /**
   * TODO: Documentation
   * <p>
   */
  RegionIteratorType getLastRegion();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Representation(const Representation& representation);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Representation& operator=(const Representation& representation);

};


}


}


#endif // PROTOLAYER_REPRESENTATION_H
