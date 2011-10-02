#ifndef GELATINE_SPACEMODEL_H
#define GELATINE_SPACEMODEL_H


#include "DefaultTransition.h"
#include "HitModel.h"
#include "Mouse.h"
#include "Dimensions.h"
#include "Shot.h"
#include "Transition.h"


namespace gelatine
{


/**
 * TODO: Documentation
 * <p>
 */
class SpaceModel
{
public:
  /** TODO: Documentation */
  static const GLsizei BUFFER_SIZE = 32;

private:
  /** TODO: Documentation */
  GLuint _selectBuffer[BUFFER_SIZE];

  /** TODO: Documentation */
  Shot* _currentShot;

  /** TODO: Documentation */
  Shot* _nextShot;

  /** TODO: Documentation */
  Transition* _transition;

  /** TODO: Documentation */
  DefaultTransition* _defaultTransition;

  /** TODO: Documentation */
  Dimensions _renderingDimensions;

  /** TODO: Documentation */
  HitModel _hitModel;

  /** TODO: Documentation */
  Mouse _mouse;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  explicit SpaceModel(Shot& initialShot);

  /**
   * TODO: Documentation
   * <p>
   */
  SpaceModel(Shot& initialShot,
             Transition& transition);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SpaceModel();

  /**
   * TODO: Documentation
   * <p>
   */
  HitModel& getHitModel();

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
  Transition& getTransition();

  /**
   * TODO: Documentation
   * <p>
   */
  Dimensions& getDimensions();

  /**
   * TODO: Documentation
   * <p>
   */
  Mouse& getMouse();

  /**
   * TODO: Documentation
   * <p>
   */
  GLuint* getSelectBuffer();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseBuffer();

  /**
   * TODO: Documentation
   * <p>
   */
  void setTransition(Transition& transition);

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasNextShot();

  /**
   * TODO: Documentation
   * <p>
   */
  void setNextShot(Shot& shot);

  /**
   * TODO: Documentation
   * <p>
   */
  void makeNextShotCurrent();

};


}


#endif // GELATINE_SPACEMODEL_H
