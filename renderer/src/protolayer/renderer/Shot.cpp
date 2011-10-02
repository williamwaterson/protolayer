#include "Shot.h"


namespace protolayer
{

namespace renderer
{

Shot::Shot(scenegraph::Scene& scene, scenegraph::Camera& camera) :
  _camera(camera), _scene(scene) 
{
  _hitModel = new scenegraph::HitModel();

  _renderable = true;
  _selectable = true;
  _depthCulling = true;

  _cullFaceBack = false;
  _cullFaceFront = false;

  if (!scene.getRoot().isPart(camera)) {
    throw;
  }

  for (int i = 0; i < BUFFER_SIZE; i++) {
    _selectBuffer[i] = 0;
  }
}


Shot::~Shot()
{
  delete _hitModel;
}


bool
Shot::isRenderable()
{
  return _renderable;
}


bool
Shot::isSelectable()
{
  return _selectable;
}


void
Shot::setBackFaceCull(bool flag)
{
  _cullFaceBack = flag;
}


void
Shot::setFrontFaceCull(bool flag)
{
  _cullFaceFront = flag;
}


void
Shot::setDepthCulling(bool flag)
{
  _depthCulling = flag;
}


void
Shot::setRenderable(bool flag)
{
  _renderable = flag;
}


void
Shot::setSelectable(bool flag)
{
  _selectable = flag;
}


scenegraph::Camera& Shot::getCamera()
{
  return _camera;
}


scenegraph::Scene& Shot::getScene()
{
  return _scene;
}


Mouse& Shot::getMouse()
{
  return _mouse;
}


ProjectedMouse& Shot::getProjectedMouse()
{
  return _projectedMouse;
}


scenegraph::Dimensions& Shot::getDimensions()
{
  return _dimensions;
}


scenegraph::HitModel& Shot::getHitModel()
{
  return *_hitModel;
}


SelectionPlane& Shot::getSelectionPlane()
{
  return _selectionPlane;
}


void Shot::resize(short width, short height)
{
  _dimensions.setDimensions(width, height);
}



void renderShapeInSelectionMode(scenegraph::Shape& shape, float alpha)
{
  if (shape.isSelectable()) {
    glPopName();
  }

  shape.render(alpha);

  if (shape.isSelectable()) {
    glPopName();
  }
}


void renderGroup(scenegraph::Group& group, float alpha)
{
  typedef std::vector <scenegraph::Group*>::iterator GroupIterType;
  for(GroupIterType iter = group.getOrderedChildGroups(); iter != group.getOrderedLastGroup(); ++iter) {
    renderGroup(**iter, alpha);
  }

  typedef std::vector <scenegraph::Shape*>::iterator ShapeIterType;
  for(ShapeIterType iter = group.getOrderedChildShapes(); iter != group.getOrderedLastShape(); ++iter) {
    (*iter)->render(alpha);
  }
}


void renderGroupInSelectionMode(scenegraph::Group& group, float alpha)
{
  if (group.isSelectable()) {
    glPushName(group.getID());

    typedef std::vector <scenegraph::Group*>::iterator GroupIterType;
    for(GroupIterType iter = group.getOrderedChildGroups(); iter != group.getOrderedLastGroup(); ++iter) {
      renderGroupInSelectionMode(**iter, alpha);
    }

    typedef std::vector <scenegraph::Shape*>::iterator ShapeIterType;
    for(ShapeIterType iter = group.getOrderedChildShapes(); iter != group.getOrderedLastShape(); ++iter) {
      renderShapeInSelectionMode(**iter, alpha);
    }

    glPopName();
  }
}



/** TODO RIP OUT AND MAKE PUBLIC */
void targetCamera(scenegraph::Camera& camera)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(camera.getPosition().getCoordinates()[0],
            camera.getPosition().getCoordinates()[1],
            camera.getPosition().getCoordinates()[2],
            camera.getTarget().getCoordinates()[0],
            camera.getTarget().getCoordinates()[1],
            camera.getTarget().getCoordinates()[2],
            camera.getOrient()[0],
            camera.getOrient()[1],
            camera.getOrient()[2]);
}


void Shot::render()
{
  //  glViewport(0, 0, _dimensions.getWidth(), _dimensions.getHeight());
  //  glLoadIdentity();

  if (_renderable) {

    if (_depthCulling) {
      glEnable(GL_DEPTH_TEST);
      //      glDepthMask(GL_TRUE);
    }

    //    if (_cullFaceBack || _cullFaceFront) {
    //      glEnable(GL_CULL_FACE);
    //  }

    //    if (_cullFaceFront) {
    //      glCullFace(GL_FRONT);
    //}

    //    if (_cullFaceBack) {
    //      glCullFace(GL_BACK);
    //    }

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f * getCamera().getZoom(),
                   getDimensions().getAspectRatio(),
                   1.0f, 1000.0f);

    targetCamera(getCamera());

    renderGroup(getScene().getRoot(), getCamera().getAlpha());
    renderInSelectionMode();

    glDisable(GL_DEPTH_TEST);
    //    glDepthMask(GL_FALSE);
    //    glDisable(GL_CULL_FACE);
  }
}


void Shot::renderInSelectionMode()
{
  if (isSelectable()) {
    preSelectionMode();

    glLoadIdentity();
    targetCamera(getCamera());
    
    renderGroupInSelectionMode(getScene().getRoot(), getCamera().getAlpha());

    postSelectionMode();

    evalPlanarMousePosition();
  }
}


void Shot::preSelectionMode()
{
  // Switch to selection mode
  glSelectBuffer(BUFFER_SIZE, getSelectBuffer());
  glRenderMode(GL_SELECT);

  // Switch to projection matrix to redefine viewing volume for picking
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();

  // Redefine the viewing volume to the vicinity of the mouse for picking
  glGetIntegerv(GL_VIEWPORT, _viewport);

  gluPickMatrix(getMouse()._x, getMouse()._y, 5, 5, _viewport);

  gluPerspective(45.0f * getCamera().getZoom(),
                 _dimensions.getAspectRatio(), 1.0f, 1000.0f);
  glMatrixMode(GL_MODELVIEW);
  glInitNames();
}


void
Shot::postSelectionMode()
{
  // Restore the original projection matrix
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glFlush();

  // Revert to render mode and identify hits under the mouse pointer.
  int hits = glRenderMode(GL_RENDER);
  int numberNames = 0;
  int* hitNames = 0;

  if (hits != 0) {
    hitNames = processHits(hits, getSelectBuffer(), &numberNames);
  } else {
    getHitModel().mouseHit(0);
  }

  // Locate mouse hits with 3D objects
  int name = 0;
  for (int i = 0; i < numberNames; i++) {
    name = hitNames[i];
    getHitModel().mouseHit(getScene().getRoot().getNodeForName(name));
  }
}


int*
Shot::processHits(int hits, GLuint buffer[], int* numberNames)
{
  int index = 0;
  int indexNames = 0;
  int nameCount = 0;
  int numberOfNames = 0;
  GLuint depth;
  GLuint minDepth = 0xffffffff;
  for (int i = 0; i < hits; i++) {
    nameCount = buffer[index];
    index++;

    depth = buffer[index];
    if (depth < minDepth) {
      numberOfNames = nameCount;
      minDepth = depth;
      indexNames = index + 2;
    }

    index += nameCount + 2;
  }

  *numberNames = numberOfNames;
  int* names = new int[numberOfNames];
  for (int i = 0; i < numberOfNames; i++) {
    names[i] = buffer[indexNames];
    indexNames++;
  }
  return names;
}


void
Shot::evalPlanarMousePosition()
{
  glGetIntegerv(GL_VIEWPORT, _viewport);
  glGetDoublev(GL_MODELVIEW_MATRIX, _modelMatrix);
  glGetDoublev(GL_PROJECTION_MATRIX, _projMatrix);

  _win[0] = (double) getMouse()._x;
  _win[1] = (double) getMouse()._y;

  _win[2] = 0.0;
  gluUnProject(_win[0], _win[1], _win[2],
               _modelMatrix, _projMatrix, _viewport,
               &_near[0], &_near[1], &_near[2]);

  _win[2] = 1.0;
  gluUnProject(_win[0], _win[1], _win[2],
               _modelMatrix, _projMatrix, _viewport,
               &_far[0], &_far[1], &_far[2]);

  _far[0] -= _near[0];
  _far[1] -= _near[1];
  _far[2] -= _near[2];

  float py = getSelectionPlane().getPositionY();
  float alpha = (py - getCamera().getPosition().getCoordinates()[1]) / (float) _far[1];

  _far[0] *= alpha;
  _far[1] *= alpha;
  _far[2] *= alpha;

  _near[0] = getCamera().getPosition().getCoordinates()[0];
  _near[1] = getCamera().getPosition().getCoordinates()[1];
  _near[2] = getCamera().getPosition().getCoordinates()[2];

  _near[0] += _far[0];
  _near[1] += _far[1];
  _near[2] += _far[2];

  getProjectedMouse()._x = _near[0];
  getProjectedMouse()._y = _near[1];
  getProjectedMouse()._z = _near[2];
}


GLuint* Shot::getSelectBuffer()
{
  return _selectBuffer;
}


}


}
