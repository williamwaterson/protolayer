#ifndef GELATINE_SCENEMODEL_H
#define GELATINE_SCENEMODEL_H

#include <set.h>
#include <map.h>

#include "forward.h"
#include "Action.h"
#include "Camera.h"
#include "Shape.h"
#include "Mouse.h"
#include "ProjectedMouse.h"
#include "SelectionPlane.h"

namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class SceneModel
{
public:
  /** Type definitions */
  typedef std::set <Shape*> ShapeSetType;
  typedef ShapeSetType::iterator ShapeIteratorType;
  typedef std::set <Action*> ActionSetType;
  typedef ActionSetType::iterator ActionIteratorType;
  typedef std::map <int, Shape*> ShapeNameMapType;

  /** Initial width */
  static const int INITIAL_WIDTH = 640;

  /** Initial height */
  static const int INITIAL_HEIGHT = 480;

private:
  /** TODO: Documentation */
  float _alpha;

  /** TODO: Documentation */
  float _backgroundColor[4];

  /** TODO: Documentation */
  std::set <Shape*> _shapes;

  /** TODO: Documentation */
  std::map <int, Shape*> _shapeNameMap;

  /** TODO: Documentation */
  std::set <Action*>  _actionsForTriggering;

  /** TODO: Documentation */
  std::set <Action*> _actionsInProgress;

  /** TODO: Documentation */
  ProjectedMouse _projectedMouse;

  /** TODO: Documentation */
  SelectionPlane _selectionPlane;

  /** TODO: Documentation */
  protolayer::IDGenerator _idGenerator;

  /** TODO: Documentation */
  UnsignedWide _tick;

  /** TODO: Documentation */
  float _time;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  SceneModel();

  /**
   * TODO: Documentation
   * <p>
   */
  float getAlpha() const;

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeIteratorType getShapes();

  /**
   * TODO: Documentation
   * <p>
   */
  ShapeIteratorType getLastShape();
 
  /**
   * TODO: Documentation
   * <p>
   */
  //  void add(Shape& shape);

  /**
   * TODO: Documentation
   * <p>
   */
  //  void remove(Shape& shape);

  /**
   * TODO: Documentation
   * <p>
   */
  void trigger(Action& action);

  /**
   * TODO: Documentation
   * <p>
   */
  ActionIteratorType getActionsForTriggering();

  /**
   * TODO: Documentation
   * <p>
   */
  ActionIteratorType getActionsInProgress();

  /**
   * TODO: Documentation
   * <p>
   */
  void incrementActions();

  /**
   * TODO: Documentation
   * <p>
   */
  void commenceTriggeredActions();

  /**
   * TODO: Documentation
   * <p>
   */
  void releaseCompletedActions();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getBackgroundColor();

  /**
   * TODO: Documentation
   * <p>
   */
  ProjectedMouse& getProjectedMouse();

  /**
   * TODO: Documentation
   * <p>
   */
  SelectionPlane& getSelectionPlane();

  /**
   * TODO: Documentation
   * <p>
   */
  protolayer::IDGenerator& getIDGenerator();

  /**
   * TODO: Documentation
   * <p>
   */
  //  Shape* getShapeForName(int name);

  /**
   * TODO: Documentation
   */
  void setAlpha(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void setBackgroundColor(float red,
                          float blue,
                          float green,
                          float alpha);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SceneModel(const SceneModel& sceneModel);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SceneModel& operator=(const SceneModel& sceneModel);

};


}


#endif // GELATINE_SCENEMODEL_H
