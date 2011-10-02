#include "Representation.h"


namespace protolayer
{

namespace nurbs
{

Representation::Representation()
{
}


Representation::~Representation()
{
}


void Representation::add(Vertex& vertex)
{
  _vertices.insert(&vertex);
}


void Representation::remove(Vertex& vertex)
{
  _vertices.erase(&vertex);
}


void Representation::add(Curve& curve)
{
  _curves.insert(&curve);
}


void Representation::remove(Curve& curve)
{
  _curves.erase(&curve);
}


void Representation::add(Edge& edge)
{
  _edges.insert(&edge);
}


void Representation::remove(Edge& edge)
{
  _edges.erase(&edge);
}


void Representation::add(Loop& loop)
{
  _loops.insert(&loop);
}


void Representation::remove(Loop& loop)
{
  _loops.erase(&loop);
}


void Representation::add(Surface& surface)
{
  _surfaces.insert(&surface);
}


void Representation::remove(Surface& surface)
{
  _surfaces.erase(&surface);
}


void Representation::add(Face& face)
{
  _faces.insert(&face);
}


void Representation::remove(Face& face)
{
  _faces.erase(&face);
}


void Representation::add(Shell& shell)
{
  _shells.insert(&shell);
}


void Representation::remove(Shell& shell)
{
  _shells.erase(&shell);
}


void Representation::add(Region& region)
{
  _regions.insert(&region);
}


void Representation::remove(Region& region)
{
  _regions.erase(&region);
}


Representation::ControlPointIteratorType Representation::getControlPoints()
{
  return _controlPoints.begin();
}


Representation::VertexIteratorType Representation::getVertices()
{
  return _vertices.begin();
}


Representation::CurveIteratorType Representation::getCurves()
{
  return _curves.begin();
}


Representation::EdgeIteratorType Representation::getEdges()
{
  return _edges.begin();
}


Representation::LoopIteratorType Representation::getLoops()
{
  return _loops.begin();
}


Representation::SurfaceIteratorType Representation::getSurfaces()
{
  return _surfaces.begin();
}


Representation::FaceIteratorType Representation::getFaces()
{
  return _faces.begin();
}


Representation::ShellIteratorType Representation::getShells()
{
  return _shells.begin();
}


Representation::RegionIteratorType Representation::getRegions()
{
  return _regions.begin();
}


Representation::ControlPointIteratorType Representation::getLastControlPoint()
{
  return _controlPoints.end();
}


Representation::VertexIteratorType Representation::getLastVertex()
{
  return _vertices.end();
}


Representation::CurveIteratorType Representation::getLastCurve()
{
  return _curves.end();
}


Representation::EdgeIteratorType Representation::getLastEdge()
{
  return _edges.end();
}


Representation::LoopIteratorType Representation::getLastLoop()
{
  return _loops.end();
}


Representation::SurfaceIteratorType Representation::getLastSurface()
{
  return _surfaces.end();
}


Representation::FaceIteratorType Representation::getLastFace()
{
  return _faces.end();
}


Representation::ShellIteratorType Representation::getLastShell()
{
  return _shells.end();
}


Representation::RegionIteratorType Representation::getLastRegion()
{
  return _regions.end();
}


}


}
