#ifndef GELATINE_SPACEVIEW_H
#define GELATINE_SPACEVIEW_H


#include "SpaceModel.h"
#include <AGL/agl.h>



namespace gelatine
{


/**
 * TODO: Documentation
 * <p>
 */
class SpaceView
{
  /** TODO: Documentation */
  SpaceModel& _model;

  /** TODO: Documentation */
  UnsignedWide _tick;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  explicit SpaceView(SpaceModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SpaceView();

  /**
   * TODO: Documentation
   * <p>
   */
  SpaceModel& getModel();

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
  void preSelectionMode();

  /**
   * TODO: Documentation
   * <p>
   */
  void postSelectionMode();

  /**
   * TODO: Documentation
   * <p>
   */
  int* processHits(int hits, GLuint buffer[], int* numberNames);

  /**
   * TODO: Documentation
   * <p>
   */
  void evalPlanarMousePosition();

private:
  /**
   * TODO: Documentation
   *
   */
  SpaceView(const SpaceView& spaceView);

  /**
   * TODO: Documentation
   *
   */
  SpaceView& operator=(const SpaceView& spaceView);

};


}


#endif // GELATINE_SPACEVIEW_H
