#ifndef GELATINE_SHOT_H
#define GELATINE_SHOT_H


#include "Camera.h"
#include "Scene.h"


namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class Shot
{
private:
  /** TODO: Documentation */
  Camera& _camera;

  /** TODO: Documentation */
  Scene& _scene;

public:
  /**
   * TODO: Documentation
   *
   */
  Shot(Scene& scene, Camera& camera);

  /**
   * TODO: Documentation
   *
   */
  Scene& getScene();

  /**
   * TODO: Documentation
   *
   */
  Camera& getCamera();

  /**
   * TODO: Documentation
   *
   */
  void render();

  /**
   * TODO: Documentation
   *
   */
  void renderInSelectionMode();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shot(const Shot& shot);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Shot& operator=(const Shot& shot);

};


}


#endif // GELATINE_SHOT_H
