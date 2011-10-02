#include "Space.h"


namespace protolayer
{

namespace renderer
{

Space::Space()
{
  _backgroundColor[0] = 0.5f;
  _backgroundColor[1] = 0.5f;
  _backgroundColor[2] = 0.5f;
  _backgroundColor[3] = 0.5f;
}

Space::Space(scenegraph::Shot& initialShot)
{
  _backgroundColor[0] = 0.5f;
  _backgroundColor[1] = 0.5f;
  _backgroundColor[2] = 0.5f;
  _backgroundColor[3] = 0.5f;

  _shots.insert(&initialShot);

  typedef std::multimap <scenegraph::Scene*, scenegraph::Shot*>::value_type SceneShotValueType;
  scenegraph::Scene& scene = initialShot.getScene();
  _sceneShots.insert(SceneShotValueType(&scene, &initialShot));
}


Space::~Space()
{
}


void
Space::init()
{
  glEnable(GL_BLEND);
  //  glEnable(GL_DEPTH_TEST);
  //  glDepthMask(GL_TRUE);

  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POLYGON_SMOOTH);
  glEnable(GL_POLYGON_SMOOTH_HINT);

  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);
  //  glCullFace(GL_BACK);
}


void
Space::resize(short width, short height)
{
  if (height == 0) {
    height = 1;
  }

  typedef ShotIteratorType ShotIterType;
  for (ShotIterType iter = getShots(); iter.hasNext(); ) {
    iter.next().resize(width, height);
  }

  float fieldOfViewY = 45.0f * getShots().next().getCamera().getZoom();
  glViewport(0, 0, width, height);
  glLoadIdentity();
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


const GLsizei BUFFER_SIZE = 32;


GLuint selectBuffer[BUFFER_SIZE];


/** TODO: Documentation */
GLint _viewport[4];

/** TODO: Documentation */
double _win[3];

/** TODO: Documentation */
double _near[3];

/** TODO: Documentation */
double _far[3];

/** TODO: Documentation */
double _modelMatrix[16];

/** TODO: Documentation */
double _projMatrix[16];


void preSelectionMode(scenegraph::Shot& shot)
{
  // Switch to selection mode
  glSelectBuffer(BUFFER_SIZE, selectBuffer);
  glRenderMode(GL_SELECT);

  // Switch to projection matrix to redefine viewing volume for picking
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();

  // Redefine the viewing volume to the vicinity of the mouse for picking
  glGetIntegerv(GL_VIEWPORT, _viewport);

  gluPickMatrix(shot.getMouse()._x, shot.getMouse()._y, 5, 5, _viewport);

  gluPerspective(45.0f * shot.getCamera().getZoom(),
                 shot.getDimensions().getAspectRatio(), 1.0f, 1000.0f);
  glMatrixMode(GL_MODELVIEW);
  glInitNames();
}


int*
processHits(scenegraph::Shot& shot, int hits, GLuint buffer[], int* numberNames)
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
postSelectionMode(scenegraph::Shot& shot)
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
    hitNames = processHits(shot, hits, selectBuffer, &numberNames);
  } else {
    shot.getHitModel().mouseHit(0);
  }

  // Locate mouse hits with 3D objects
  int name = 0;
  for (int i = 0; i < numberNames; i++) {
    name = hitNames[i];
    shot.getHitModel().mouseHit(shot.getScene().getRoot().getNodeForName(name));
  }
}


void
evalPlanarMousePosition(scenegraph::Shot& shot)
{
  glGetIntegerv(GL_VIEWPORT, _viewport);
  glGetDoublev(GL_MODELVIEW_MATRIX, _modelMatrix);
  glGetDoublev(GL_PROJECTION_MATRIX, _projMatrix);

  _win[0] = (double) shot.getMouse()._x;
  _win[1] = (double) shot.getMouse()._y;

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

  float py = shot.getSelectionPlane().getPositionY();
  float alpha = (py - shot.getCamera().getPosition().getCoordinates()[1]) / (float) _far[1];

  _far[0] *= alpha;
  _far[1] *= alpha;
  _far[2] *= alpha;

  _near[0] = shot.getCamera().getPosition().getCoordinates()[0];
  _near[1] = shot.getCamera().getPosition().getCoordinates()[1];
  _near[2] = shot.getCamera().getPosition().getCoordinates()[2];

  _near[0] += _far[0];
  _near[1] += _far[1];
  _near[2] += _far[2];

  shot.getProjectedMouse()._x = _near[0];
  shot.getProjectedMouse()._y = _near[1];
  shot.getProjectedMouse()._z = _near[2];
}


void renderInSelectionMode(scenegraph::Shot& shot)
{
  if (shot.isSelectable()) {
    preSelectionMode(shot);

    glLoadIdentity();
    targetCamera(shot.getCamera());
    
    renderGroupInSelectionMode(shot.getScene().getRoot(), shot.getCamera().getAlpha());

    postSelectionMode(shot);

    evalPlanarMousePosition(shot);
  }
}


void render(scenegraph::Shot& shot)
{
  //  glViewport(0, 0, _dimensions.getWidth(), _dimensions.getHeight());
  //  glLoadIdentity();

  if (shot.isRenderable()) {

    if (shot.hasDepthCulling()) {
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
    gluPerspective(45.0f * shot.getCamera().getZoom(),
                   shot.getDimensions().getAspectRatio(),
                   1.0f, 1000.0f);

    targetCamera(shot.getCamera());

    renderGroup(shot.getScene().getRoot(), shot.getCamera().getAlpha());
    renderInSelectionMode(shot);

    glDisable(GL_DEPTH_TEST);
    //    glDepthMask(GL_FALSE);
    //    glDisable(GL_CULL_FACE);
  }
}


void
Space::display()
{
  // Reset and render the specific scene
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Perform housekeeping related to Actions
  releaseCompletedActions();
  commenceTriggeredActions();
  incrementActions();

  // Set background colour
  float* background = getBackgroundColor();
  glClearColor(background[0], background[1], background[2], 1.0f);

  // Perform the rendering
  typedef ShotIteratorType ShotIterType;
  for (ShotIterType iter = getShots(); iter.hasNext(); ) {
    render(iter.next());
  }
}


void
Space::dispose()
{
}


void Space::addShot(scenegraph::Shot& shot)
{
  _shots.insert(&shot);

  typedef std::multimap <scenegraph::Scene*, scenegraph::Shot*>::value_type SceneShotValueType;
  scenegraph::Scene& scene = shot.getScene();
  _sceneShots.insert(SceneShotValueType(&scene, &shot));
}


void Space::removeShot(scenegraph::Shot& shot)
{
  _shots.erase(&shot);

  typedef std::multimap <scenegraph::Scene*, scenegraph::Shot*>::iterator IterType;

  scenegraph::Scene& scene = shot.getScene();
  for (IterType iter = _sceneShots.find(&scene); iter != _sceneShots.end(); iter++) {
    if (iter->second == &shot) {
      _sceneShots.erase(iter);
      break;
    }
  }
}


Space::ShotIteratorType Space::getShots()
{
  return ShotIteratorType(_shots);
}


Space::SceneShotIteratorType Space::getShots(scenegraph::Scene& scene)
{
  return SceneShotIteratorType(_sceneShots);
}


int Space::countShots(scenegraph::Scene& scene)
{
  return _sceneShots.count(&scene);
}


void
Space::trigger(animation::Action& action)
{
  if (!action.inProgress()) {
    _actionsForTriggering.insert(&action);
  }
}


Space::ActionIteratorType
Space::getActionsForTriggering()
{
  return _actionsForTriggering.begin();
}


Space::ActionIteratorType
Space::getActionsInProgress()
{
  return _actionsInProgress.begin();
}


void
Space::incrementActions()
{
  animation::Action* action;
  ActionIteratorType iter;
  ActionIteratorType end = _actionsInProgress.end();
  for (iter = _actionsInProgress.begin(); iter != end; ++iter) {
    action = *iter;
    //    Microseconds(&_tick);
    //    _time = (float) UnsignedWideToUInt64(_tick);

    struct timeval tick;
    gettimeofday(&tick, NULL);
    double doubleTime = tick.tv_usec;
    doubleTime += tick.tv_sec * 1000000;
    _time = (float) doubleTime;

    action->increment(doubleTime);
  }
}


void
Space::commenceTriggeredActions()
{
  animation::Action* action;
  ActionIteratorType iter;
  ActionIteratorType end = _actionsForTriggering.end();    
  for (iter = getActionsForTriggering(); iter != end; ++iter) {
    action = *iter;
    // Microseconds(&_tick);
    //_time = (float) UnsignedWideToUInt64(_tick);

    struct timeval tick;
    gettimeofday(&tick, NULL);
    double doubleTime = tick.tv_usec;
    doubleTime += tick.tv_sec * 1000000;
    _time = (float) doubleTime;

    //    std::cout << _time << std::endl;
    //    gettimeofday(&_tick, NULL);    
    //    double doubleTime = _tick.tv_usec;
    //    doubleTime /= 1000000;
    //    doubleTime += _tick.tv_sec;
    //    _time = (float) doubleTime;

    action->commence(doubleTime);
    _actionsInProgress.insert(action);
  }

  _actionsForTriggering.clear();
}


void
Space::releaseCompletedActions()
{
  animation::Action* action;
  ActionIteratorType iter;
  ActionIteratorType end = _actionsInProgress.end();
  for (iter = _actionsInProgress.begin(); iter != end; ++iter) {
    action = *iter;
    if (!action->inProgress()) {
      _actionsInProgress.erase(action);
      action->postComplete();
    }
  }
}


void
Space::setMousePosition(short x, short y)
{
  typedef Space::ShotIteratorType ShotIterType;
  for (ShotIterType iter = getShots(); iter.hasNext(); ) {
    scenegraph::Mouse& mouse = iter.next().getMouse();
    mouse._x = x;
    mouse._y = y;
  }
}


void
Space::setBackgroundColor(float red,
			  float blue,
			  float green,
			  float alpha)
{
  _backgroundColor[0] = red;
  _backgroundColor[1] = blue;
  _backgroundColor[2] = green;
  _backgroundColor[3] = alpha;
}


float*
Space::getBackgroundColor()
{
  return _backgroundColor;
}


void
Space::setDimensions(short width, short height)
{
  typedef Space::ShotIteratorType ShotIterType;
  for (ShotIterType iter = getShots(); iter.hasNext(); ) {
    iter.next().getDimensions().setDimensions(width, height);
  }
}


}


}
