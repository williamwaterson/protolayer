#include "SpaceView.h"


namespace gelatine
{


SpaceView::SpaceView(SpaceModel& model) :
  _model(model)
{
}


SpaceView::~SpaceView()
{
}


SpaceModel&
SpaceView::getModel()
{
  return _model;
}


void
SpaceView::init()
{
  glEnable(GL_BLEND);
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_LINE_SMOOTH);

  glEnable(GL_MAP1_VERTEX_3);
  glEnable(GL_MAP2_VERTEX_3);

  glDisable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void
SpaceView::resize(short width, short height)
{
  if (height == 0) {
    height = 1;
  }

  _model.getDimensions().setDimensions(width, height);
  float fieldOfViewY = 45.0f * _model.getCurrentShot().getCamera().getZoom();
  glViewport(0, 0, width, height);
  glLoadIdentity();
}


void
SpaceView::display()
{
  // Reset and render the specific scene
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Handle either transitioning or ordinary rendering
  if (_model.getTransition().inProgress()) {
    _model.getTransition().increment(_model.getCurrentShot(),
                                     *(_model.getNextShot()));
    _model.getCurrentShot().render();
    _model.getNextShot()->render();

    if (!getModel().getTransition().inProgress()) {
      _model.getTransition().postComplete(_model.getCurrentShot(),
                                          *(_model.getNextShot()));
      _model.makeNextShotCurrent();
    }

  // Detect new scene to trigger transition
  } else if (_model.hasNextShot()) {
    _model.getTransition().commence(_model.getCurrentShot(),
                                    *(_model.getNextShot()));
    _model.getCurrentShot().render();
    _model.getNextShot()->render();

  // Otherwise, no transition so perform normal rendering and hit testing
  } else {
    _model.getCurrentShot().render();

    preSelectionMode();
    _model.getCurrentShot().renderInSelectionMode();
    postSelectionMode();

    // Unproject window clicks to locate selected point in the projected plane
    evalPlanarMousePosition();
  }
}


void
SpaceView::dispose()
{
}


void
SpaceView::preSelectionMode()
{
  // Switch to selection mode
  glSelectBuffer(SpaceModel::BUFFER_SIZE, _model.getSelectBuffer());
  glRenderMode(GL_SELECT);

  // Switch to projection matrix to redefine viewing volume for picking
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();

  // Redefine the viewing volume to the vicinity of the mouse for picking
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  gluPickMatrix(_model.getMouse()._x, _model.getMouse()._y, 5, 5, viewport);

  gluPerspective(45.0f * _model.getCurrentShot().getCamera().getZoom(),
                 _model.getDimensions().getAspectRatio(), 1.0f, 1000.0f);
  glMatrixMode(GL_MODELVIEW);
  glInitNames();
}


void
SpaceView::postSelectionMode()
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
    hitNames = processHits(hits, _model.getSelectBuffer(), &numberNames);
  }

  // Locate mouse hits with 3D objects
  int name;
  for (int i = 0; i < numberNames; i++) {
    name = hitNames[i];
    _model.getHitModel()._node = _model.getCurrentShot().getScene().getRoot().getNodeForName(name);
    if (_model.getHitModel()._node != 0) {
      _model.getHitModel()._node->triggerHitListeners();
    }
  }
}


int*
SpaceView::processHits(int hits, GLuint buffer[], int* numberNames)
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
SpaceView::evalPlanarMousePosition()
{
  GLint viewport[4];
  double modelMatrix[16];
  double projMatrix[16];

  double win[3];
  double near[3];
  double far[3];

  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
  glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);

  win[0] = (double) _model.getMouse()._x;
  win[1] = (double) _model.getMouse()._y;

  win[2] = 0.0;
  gluUnProject(win[0], win[1], win[2],
               modelMatrix, projMatrix, viewport,
               &near[0], &near[1], &near[2]);

  win[2] = 1.0;
  gluUnProject(win[0], win[1], win[2],
               modelMatrix, projMatrix, viewport,
               &far[0], &far[1], &far[2]);

  far[0] -= near[0];
  far[1] -= near[1];
  far[2] -= near[2];

  Camera& camera = _model.getCurrentShot().getCamera();
  float py = _model.getCurrentShot().getScene().getModel().getSelectionPlane().getPositionY();
  float alpha = (py - camera.getGlobalPosition()[1]) / (float) far[1];

  far[0] *= alpha;
  far[1] *= alpha;
  far[2] *= alpha;

  near[0] = camera.getGlobalPosition()[0];
  near[1] = camera.getGlobalPosition()[1];
  near[2] = camera.getGlobalPosition()[2];

  near[0] += far[0];
  near[1] += far[1];
  near[2] += far[2];

  _model.getCurrentShot().getScene().getModel().getProjectedMouse()._x = near[0];
  _model.getCurrentShot().getScene().getModel().getProjectedMouse()._y = near[1];
  _model.getCurrentShot().getScene().getModel().getProjectedMouse()._z = near[2];
}


}
