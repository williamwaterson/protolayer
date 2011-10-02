#include "NurbsShape.h"


namespace gelatine
{


NurbsShape::NurbsShape(DirectShapeModel& model) :
  _model(model)
{
}


NurbsShape::NurbsShape(Appearance& appearance) :
  _model(*(new DirectShapeModel(appearance)))
{  
}


NurbsShape::~NurbsShape()
{
}


DirectShapeModel&
NurbsShape::getModel()
{
  return _model;
}


void NurbsShape::update(float quaternion[4][4])
{
  _quaternion = quaternion;
  //  getGeometry().update(quaternion);
  float* local;
  float* global;
  PointIteratorType iter = getPoints();
  PointIteratorType end = getLastPoint();
  for ( ; iter != end; iter++) {
    local = (*iter)->getLocalCoordinates();
    global = (*iter)->getCoordinates();

    global[0] =  quaternion[0][0] * local[0];
    global[0] += quaternion[0][1] * local[1];
    global[0] += quaternion[0][2] * local[2];
    global[0] += quaternion[0][3] * local[3];

    global[1] =  quaternion[1][0] * local[0];
    global[1] += quaternion[1][1] * local[1];
    global[1] += quaternion[1][2] * local[2];
    global[1] += quaternion[1][3] * local[3];

    global[2] =  quaternion[2][0] * local[0];
    global[2] += quaternion[2][1] * local[1];
    global[2] += quaternion[2][2] * local[2];
    global[2] += quaternion[2][3] * local[3];

    global[3] =  quaternion[3][0] * local[0];
    global[3] += quaternion[3][1] * local[1];
    global[3] += quaternion[3][2] * local[2];
    global[3] += quaternion[3][3] * local[3];
  }
}


void NurbsShape::render(float alpha)
{
  if (getModel().getAppearance().isRenderable()) {
    render(alpha, _model.getAppearance());
  }
}


void NurbsShape::renderInSelectionMode(float alpha)
{
  if (isSelectable()) {
    glPushName(getID());
    render(alpha, _model.getAppearance());
    glPopName();
  }
}


void
NurbsShape::add(Vertex& vertex)
{
  _representation.add(vertex);
  _vertexNameMap.insert(VertexNameMapType::value_type(vertex._id, &vertex));
  addPoint(vertex);
}


void
NurbsShape::remove(Vertex& vertex)
{
  removePoint(vertex);
  _vertexNameMap.erase(vertex._id);
  _representation.remove(vertex);
}


void NurbsShape::add(Curve& curve)
{
  ControlPoint* point = 0;
  Curve::ControlPointIteratorType iter = curve.getControlPoints();
  Curve::ControlPointIteratorType end = curve.getLastControlPoint();
  for ( ; iter != end; iter++) {
    point = (ControlPoint*) *iter;
    _controlPointNameMap.insert(ControlPointNameMapType::value_type(point->_id, point));
    addPoint(*(*iter));
  }

  _representation.add(curve);
  _curveNameMap.insert(CurveNameMapType::value_type(curve._id, &curve));
}


void NurbsShape::remove(Curve& curve)
{
  _representation.remove(curve);

  Curve::ControlPointIteratorType iter = curve.getControlPoints();
  Curve::ControlPointIteratorType end = curve.getLastControlPoint();
  for ( ; iter != end; iter++) {
    removePoint(*(*iter));
  }
}


void
NurbsShape::add(Edge& edge)
{
  _representation.add(edge);
}


void
NurbsShape::remove(Edge& edge)
{
  _representation.remove(edge);
}


void
NurbsShape::add(Loop& loop)
{
  _representation.add(loop);
}


void
NurbsShape::remove(Loop& loop)
{
  _representation.remove(loop);
}


void
NurbsShape::add(Surface& surface)
{
  ControlPoint* point;
  Surface::ControlPointIteratorType iter = surface.getControlPoints();
  Surface::ControlPointIteratorType end = surface.getLastControlPoint();
  for ( ; iter != end; iter++) {
    point = (ControlPoint*) *iter;
    _controlPointNameMap.insert(ControlPointNameMapType::value_type(point->_id, point));
    addPoint(*(*iter));
  }

  _representation.add(surface);

  _surfaceNameMap.insert( SurfaceNameMapType::value_type(surface._id, &surface) );
}


void
NurbsShape::remove(Surface& surface)
{
  _representation.remove(surface);

  Surface::ControlPointIteratorType iter = surface.getControlPoints();
  Surface::ControlPointIteratorType end = surface.getLastControlPoint();
  for ( ; iter != end; iter++) {
    removePoint(*(*iter));
  }
}


void
NurbsShape::add(Face& face)
{
  _representation.add(face);
}


void
NurbsShape::remove(Face& face)
{
  _representation.remove(face);
}


void
NurbsShape::add(Shell& shell)
{
  _representation.add(shell);
}


void
NurbsShape::remove(Shell& shell)
{
  _representation.remove(shell);
}


void
NurbsShape::add(Region& region)
{
  _representation.add(region);
}


void
NurbsShape::remove(Region& region)
{
  _representation.remove(region);
}


ControlPoint*
NurbsShape::getControlPointForName(unsigned int name)
{
  if (_controlPointNameMap.count(name) != 0) {
    return _controlPointNameMap[name]; 
  }
  return 0;
}


Vertex*
NurbsShape::getVertexForName(unsigned int name)
{
  if (_vertexNameMap.count(name) != 0) {
    return _vertexNameMap[name]; 
  }
  return 0;
}


Curve*
NurbsShape::getCurveForName(unsigned int name)
{
  if (_curveNameMap.count(name) != 0) {
    return _curveNameMap[name]; 
  }
  return 0;
}


Surface*
NurbsShape::getSurfaceForName(unsigned int name)
{
  if (_surfaceNameMap.count(name) != 0) {
    return _surfaceNameMap[name]; 
  }
  return 0;
}


void NurbsShape::triggerHitListeners(unsigned int name)
{
  printf("NurbsShape::triggerHitListeners called\n");
  if (_vertexNameMap.count(name) != 0) {
    _vertexNameMap[name]->triggerHitListeners();
  } else if (_controlPointNameMap.count(name) != 0) {
    _controlPointNameMap[name]->triggerHitListeners();
  } else if (_curveNameMap.count(name) != 0) {
    _curveNameMap[name]->triggerHitListeners(); 
  } else if (_surfaceNameMap.count(name) != 0) {
    _surfaceNameMap[name]->triggerHitListeners();
  }
}


void
NurbsShape::render(float alpha, Appearance& appearance)
{
  protolayer::Representation::ControlPointIteratorType cpIter = _representation.getControlPoints();
  protolayer::Representation::ControlPointIteratorType cpEnd = _representation.getLastControlPoint();
  for ( ; cpIter != cpEnd; ++cpIter) {
    (dynamic_cast <ControlPoint*> (*cpIter))->render(alpha, appearance);
  }

  protolayer::Representation::VertexIteratorType vIter = _representation.getVertices();
  protolayer::Representation::VertexIteratorType vEnd = _representation.getLastVertex();
  for ( ; vIter != vEnd; ++vIter) {
    (dynamic_cast <Vertex*> (*vIter))->render(alpha, appearance);
  }

  protolayer::Representation::CurveIteratorType cIter = _representation.getCurves();
  protolayer::Representation::CurveIteratorType cEnd = _representation.getLastCurve();
  for ( ; cIter != cEnd; ++cIter) {
    (dynamic_cast <Curve*> (*cIter))->render(alpha, appearance);
  }

  protolayer::Representation::SurfaceIteratorType sIter = _representation.getSurfaces();
  protolayer::Representation::SurfaceIteratorType sEnd = _representation.getLastSurface();
  for ( ; sIter != sEnd; ++sIter) {
    (dynamic_cast <Surface*> (*sIter))->renderFaces(alpha, appearance);
    (dynamic_cast <Surface*> (*sIter))->renderMeshes(alpha, appearance);
  }
}


void
NurbsShape::renderInSelectionMode(float alpha,
                                  Appearance& appearance)
{
  protolayer::Representation::ControlPointIteratorType cpIter =
    _representation.getControlPoints();
  protolayer::Representation::ControlPointIteratorType cpEnd =
    _representation.getLastControlPoint();
  for ( ; cpIter != cpEnd; ++cpIter) {
    (dynamic_cast <ControlPoint*> (*cpIter))->renderInSelectionMode(alpha, appearance);
  }

  protolayer::Representation::VertexIteratorType vIter =
    _representation.getVertices();
  protolayer::Representation::VertexIteratorType vEnd =
    _representation.getLastVertex();
  for ( ; vIter != vEnd; ++vIter) {
    (dynamic_cast <Vertex*> (*vIter))->renderInSelectionMode(alpha, appearance);
  }

  protolayer::Representation::CurveIteratorType cIter =
    _representation.getCurves();
  protolayer::Representation::CurveIteratorType cEnd =
    _representation.getLastCurve();
  for ( ; cIter != cEnd; ++cIter) {
    (dynamic_cast <Curve*> (*cIter))->renderInSelectionMode(alpha, appearance);
  }

  protolayer::Representation::SurfaceIteratorType sIter =
    _representation.getSurfaces();
  protolayer::Representation::SurfaceIteratorType sEnd =
    _representation.getLastSurface();
  for ( ; sIter != sEnd; ++sIter) {
    (dynamic_cast <Surface*> (*sIter))->renderFacesInSelectionMode(alpha, appearance);
    (dynamic_cast <Surface*> (*sIter))->renderMeshesInSelectionMode(alpha, appearance);
  }
}


}
