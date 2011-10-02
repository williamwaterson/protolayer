#include "NurbsGeometry.h"


namespace gelatine
{


NurbsGeometry::NurbsGeometry()
{
  //  _ctlpoints[0][0] = -4.0;
  //  _ctlpoints[0][1] = -4.0;
  //_ctlpoints[0][2] = 0.0;

  //  _ctlpoints[1][0] = -2.0;
  //_ctlpoints[1][1] = 4.0;
  //_ctlpoints[1][2] = 0.0;

  //  _ctlpoints[2][0] = 2.0;
  //_ctlpoints[2][1] = -4.0;
  //_ctlpoints[2][2] = 0.0;

  //  _ctlpoints[3][0] = 4.0;
  //_ctlpoints[3][1] = 4.0;
  //_ctlpoints[3][2] = 0.0;
 

  //  _meshPoints[0][0][0] = -1.5;
  //_meshPoints[0][0][1] = -1.5;
  //_meshPoints[0][0][2] =  4.0;

  //  _meshPoints[0][1][0] = -0.5;
  //_meshPoints[0][1][1] = -1.5;
  //_meshPoints[0][1][2] = 2.0;

  //  _meshPoints[0][2][0] =  0.5;
  //_meshPoints[0][2][1] = -1.5;
  //_meshPoints[0][2][2] = -1.0;

  //  _meshPoints[0][3][0] =  1.5;
  //_meshPoints[0][3][1] = -1.5;
  //_meshPoints[0][3][2] =  2.0;



  //  _meshPoints[1][0][0] = -1.5;
  //_meshPoints[1][0][1] = -0.5;
  //_meshPoints[1][0][2] =  1.0;

  //  _meshPoints[1][1][0] = -0.5;
  //_meshPoints[1][1][1] = -0.5;
  //_meshPoints[1][1][2] =  3.0;

  //  _meshPoints[1][2][0] =  0.5;
  //_meshPoints[1][2][1] = -0.5;
  //_meshPoints[1][2][2] =  0.0;

  //  _meshPoints[1][3][0] =  1.5;
  //_meshPoints[1][3][1] = -0.5;
  //_meshPoints[1][3][2] = -1.0;

  /*
  _meshPoints[2][0][0] = -1.5;
  _meshPoints[2][0][1] =  0.5;
  _meshPoints[2][0][2] =  4.0;

  _meshPoints[2][1][0] = -0.5;
  _meshPoints[2][1][1] =  0.5;
  _meshPoints[2][1][2] =  0.0;

  _meshPoints[2][2][0] =  0.5;
  _meshPoints[2][2][1] =  0.5;
  _meshPoints[2][2][2] =  3.0;

  _meshPoints[2][3][0] =  1.5;
  _meshPoints[2][3][1] =  0.5;
  _meshPoints[2][3][2] =  4.0;


  _meshPoints[3][0][0] = -1.5;
  _meshPoints[3][0][1] =  1.5;
  _meshPoints[3][0][2] = -2.0;

  _meshPoints[3][1][0] = -0.5;
  _meshPoints[3][1][1] =  1.5;
  _meshPoints[3][1][2] = -2.0;

  _meshPoints[3][2][0] =  0.5;
  _meshPoints[3][2][1] =  1.5;
  _meshPoints[3][2][2] =  0.0;

  _meshPoints[3][3][0] =  1.5;
  _meshPoints[3][3][1] =  1.5;
  _meshPoints[3][3][2] = -1.0;
  */

  /*
  int u, v;
  for (u = 0; u < 4; u++) {
    for (v = 0; v < 4; v++) {
      _ctlpoints[u][v][0] = 2.0*((GLfloat)u - 1.5);
      _ctlpoints[u][v][1] = 2.0*((GLfloat)v - 1.5);

      if ( (u == 1 || u == 2) && (v == 1 || v == 2)) {
        _ctlpoints[u][v][2] = 3.0;
      } else {
        _ctlpoints[u][v][2] = -3.0;
      }
    }
  }
  */

  /*
  _knots[0] = 0.0f;
  _knots[1] = 0.0f;
  _knots[2] = 0.0f;
  _knots[3] = 0.0f;
  _knots[4] = 1.0f;
  _knots[5] = 1.0f;
  _knots[6] = 1.0f;
  _knots[7] = 1.0f;
  */

  //  GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
  //  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  //  GLfloat mat_shininess[] = { 100.0 };

  //  glClearColor (0.0, 0.0, 0.0, 0.0);
  //  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

  //  glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  //glEnable(GL_DEPTH_TEST);
  //glEnable(GL_AUTO_NORMAL);
  //glEnable(GL_NORMALIZE);

  //  _nurb = gluNewNurbsRenderer();
  //  gluNurbsProperty(_nurb, GLU_SAMPLING_TOLERANCE, 25.0);
  //  gluNurbsProperty(_nurb, GLU_DISPLAY_MODE, GLU_FILL);
  //  gluNurbsCallback(_nurb, GLU_ERROR, nurbsError);
}


NurbsGeometry::~NurbsGeometry()
{
}


void
NurbsGeometry::add(Vertex& vertex)
{
  _representation.add(vertex);
  _vertexNameMap.insert(std::map <int, Vertex*>::value_type(vertex._id, &vertex));
  addPoint(vertex);
}


void
NurbsGeometry::remove(Vertex& vertex)
{
  removePoint(vertex);
  _vertexNameMap.erase(vertex._id);
  _representation.remove(vertex);
}


void NurbsGeometry::add(Curve& curve)
{
  ControlPoint* point = 0;
  Curve::ControlPointIteratorType iter = curve.getControlPoints();
  Curve::ControlPointIteratorType end = curve.getLastControlPoint();
  for ( ; iter != end; iter++) {
    point = (ControlPoint*) *iter;
    _controlPointNameMap.insert(std::map <int, ControlPoint*>::value_type(point->_id, point));
    addPoint(*(*iter));
  }

  _representation.add(curve);
  _curveNameMap.insert(std::map <int, Curve*>::value_type(curve._id, &curve));
}


void NurbsGeometry::remove(Curve& curve)
{
  _representation.remove(curve);

  Curve::ControlPointIteratorType iter = curve.getControlPoints();
  Curve::ControlPointIteratorType end = curve.getLastControlPoint();
  for ( ; iter != end; iter++) {
    removePoint(*(*iter));
  }
}


void
NurbsGeometry::add(Edge& edge)
{
  _representation.add(edge);
}


void
NurbsGeometry::remove(Edge& edge)
{
  _representation.remove(edge);
}


void
NurbsGeometry::add(Loop& loop)
{
  _representation.add(loop);
}


void
NurbsGeometry::remove(Loop& loop)
{
  _representation.remove(loop);
}


void
NurbsGeometry::add(Surface& surface)
{
  ControlPoint* point;
  Surface::ControlPointIteratorType iter = surface.getControlPoints();
  Surface::ControlPointIteratorType end = surface.getLastControlPoint();
  for ( ; iter != end; iter++) {
    point = (ControlPoint*) *iter;
    _controlPointNameMap.insert(std::map <int, ControlPoint*>::value_type(point->_id, point));
    addPoint(*(*iter));
  }

  _representation.add(surface);
  _surfaceNameMap.insert(std::map <int, Surface*>::value_type(surface._id, &surface));
}


void
NurbsGeometry::remove(Surface& surface)
{
  _representation.remove(surface);

  Surface::ControlPointIteratorType iter = surface.getControlPoints();
  Surface::ControlPointIteratorType end = surface.getLastControlPoint();
  for ( ; iter != end; iter++) {
    removePoint(*(*iter));
  }
}


void
NurbsGeometry::add(Face& face)
{
  _representation.add(face);
}


void
NurbsGeometry::remove(Face& face)
{
  _representation.remove(face);
}


void
NurbsGeometry::add(Shell& shell)
{
  _representation.add(shell);
}


void
NurbsGeometry::remove(Shell& shell)
{
  _representation.remove(shell);
}


void
NurbsGeometry::add(Region& region)
{
  _representation.add(region);
}


void
NurbsGeometry::remove(Region& region)
{
  _representation.remove(region);
}


const ::protolayer::Representation& NurbsGeometry::getRepresentation() const
{
  return _representation;
}


ControlPoint*
NurbsGeometry::getControlPointForName(unsigned int name)
{
  if (_controlPointNameMap.count(name) != 0) {
    return _controlPointNameMap[name]; 
  }
  return 0;
}


Vertex*
NurbsGeometry::getVertexForName(unsigned int name)
{
  if (_vertexNameMap.count(name) != 0) {
    return _vertexNameMap[name]; 
  }
  return 0;
}


Curve*
NurbsGeometry::getCurveForName(unsigned int name)
{
  if (_curveNameMap.count(name) != 0) {
    return _curveNameMap[name]; 
  }
  return 0;
}


Surface*
NurbsGeometry::getSurfaceForName(unsigned int name)
{
  if (_surfaceNameMap.count(name) != 0) {
    return _surfaceNameMap[name]; 
  }
  return 0;
}


void NurbsGeometry::triggerHitListeners(unsigned int name)
{
  printf("NurbsGeometry::triggerHitListeners called\n");
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
NurbsGeometry::render(float alpha, Appearance& appearance)
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
NurbsGeometry::renderInSelectionMode(float alpha, Appearance& appearance)
{
  protolayer::Representation::ControlPointIteratorType cpIter = _representation.getControlPoints();
  protolayer::Representation::ControlPointIteratorType cpEnd = _representation.getLastControlPoint();
  for ( ; cpIter != cpEnd; ++cpIter) {
    (dynamic_cast <ControlPoint*> (*cpIter))->renderInSelectionMode(alpha, appearance);
  }

  protolayer::Representation::VertexIteratorType vIter = _representation.getVertices();
  protolayer::Representation::VertexIteratorType vEnd = _representation.getLastVertex();
  for ( ; vIter != vEnd; ++vIter) {
    (dynamic_cast <Vertex*> (*vIter))->renderInSelectionMode(alpha, appearance);
  }

  protolayer::Representation::CurveIteratorType cIter = _representation.getCurves();
  protolayer::Representation::CurveIteratorType cEnd = _representation.getLastCurve();
  for ( ; cIter != cEnd; ++cIter) {
    (dynamic_cast <Curve*> (*cIter))->renderInSelectionMode(alpha, appearance);
  }

  protolayer::Representation::SurfaceIteratorType sIter = _representation.getSurfaces();
  protolayer::Representation::SurfaceIteratorType sEnd = _representation.getLastSurface();
  for ( ; sIter != sEnd; ++sIter) {
    (dynamic_cast <Surface*> (*sIter))->renderFacesInSelectionMode(alpha, appearance);
    (dynamic_cast <Surface*> (*sIter))->renderMeshesInSelectionMode(alpha, appearance);
  }
}


}
