#ifndef GELATINE_SPACE_H
#define GELATINE_SPACE_H


#include "DefaultTransition.h"
#include "SpaceModel.h"
#include "SpaceView.h"


namespace gelatine
{


/**
 * TODO: Documentation
 * <p>
 */
class Space
{
public:
  /** Access iterator types */
  typedef std::set <Scene*>::iterator SceneIteratorType;

private:
  /** TODO: Documentation */
  SpaceView* _view;

  /** TODO: Documentation */
  bool _ownsModel;

  /** TODO: Documentation */
  bool _ownsView;

public: 
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Space(Shot& initialShot);

  /**
   * TODO: Documentation
   * <p>
   */  
  Space(Shot& initialShot, Transition& transition);

  /**
   * TODO: Documentation
   * <p>
   */  
  explicit Space(SpaceModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Space(SpaceView& view);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Space();

  /**
   * TODO: Documentation
   * <p>
   */
  SpaceView& getView();

  /**
   * TODO: Documentation
   * <p>
   */
  SpaceModel& getModel();

  /**
   * TODO: Documentation
   * <p>
   */
  Mouse& getMouse();

  /**
   * TODO: Documentation
   * <p>
   */
  Shot& getCurrentShot();

  /**
   * TODO: Documentation
   * <p>
   */
  Shot* getNextShot();

  /**
   * TODO: Documentation
   * <p>
   */
  void setNextShot(Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  void updateMouse(short x, short y);

};


}


#endif // GELATINE_SPACE_H
