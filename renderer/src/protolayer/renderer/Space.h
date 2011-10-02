#ifndef PROTOLAYER_RENDERER_SPACE_H
#define PROTOLAYER_RENDERER_SPACE_H

#include <map>
#include <set.h>
#include <sys/time.h>

#include <protolayer/protolayer-scenegraph.h>
#include <protolayer/protolayer-animation.h>

#include "forward.h"


namespace protolayer
{

namespace renderer
{

/**
 * TODO: Documentation
 * <p>
 */
class Space
{
public:
  /** Access iterator types */
  typedef std::set <scenegraph::Scene*>::iterator SceneIteratorType;

  /** TODO: Documentation */
  typedef util::SetIterator <scenegraph::Shot> ShotIteratorType;

  /** TODO: Documentation */
  typedef util::MultimapIterator <scenegraph::Scene*, scenegraph::Shot> SceneShotIteratorType;

  /** TODO: Documentation */
  typedef std::set <animation::Action*> ActionSetType;

  /** TODO: Documentation */
  typedef ActionSetType::iterator ActionIteratorType;

private:
  /** TODO: Documentation */
  float _backgroundColor[4];

  /** TODO: Documentation */
  scenegraph::Mouse* _mouse;

  /** TODO: Documentation */
  std::set <scenegraph::Shot*> _shots;

  /** TODO: Documentation */
  std::multimap <scenegraph::Scene*, scenegraph::Shot*> _sceneShots;

  /** TODO: Documentation */
  std::set <animation::Action*>  _actionsForTriggering;

  /** TODO: Documentation */
  std::set <animation::Action*> _actionsInProgress;

  /** TODO: Documentation */
  struct timeval _tick;

  /** TODO: Documentation */
  float _time;

  /** TODO: Documentation */
  bool _ownsModel;

  /** TODO: Documentation */
  bool _ownsView;

public: 
  /**
   * TODO: Documentation
   * <p>
   */
  Space();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Space(scenegraph::Shot& initialShot);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Space();

  /**
   * TODO: Documentation
   * <p>
   */
  void init();

  /**
   * TODO: Documentation
   * <p>
   */
  void resize(short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  void display();

  /**
   * TODO: Documentation
   * <p>
   */
  void dispose();

  /**
   * TODO: Documentation
   * <p>
   */
  int countShots(scenegraph::Scene& scene);

  /**
   * TODO: Documentation
   * <p>
   */
  void addShot(scenegraph::Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeShot(scenegraph::Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  ShotIteratorType getShots();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getBackgroundColor();

  /**
   * TODO: Documentation
   * <p>
   */
  void setBackgroundColor(float red,
                          float blue,
                          float green,
                          float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  SceneShotIteratorType getShots(scenegraph::Scene& scene);

  /**
   * TODO: Documentation
   * <p>
   */
  void setMousePosition(short x, short y);

  /**
   * TODO: Documentation
   * <p>
   */
  void setDimensions(short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  void trigger(animation::Action& action);

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

};


}


}


#endif // PROTOLAYER_RENDERER_SPACE_H
