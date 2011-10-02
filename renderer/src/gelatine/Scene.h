#ifndef GELATINE_SCENE_H
#define GELATINE_SCENE_H

#include <set.h>

#include "Action.h"
#include "Group.h"
#include "Mouse.h"
#include "Mouse.h"
#include "ProjectedMouse.h"
#include "SceneModel.h"

namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class Scene
{
public:
  /** Access iterator types */
  typedef std::set <Leaf*>::iterator LeafIteratorType;

private:
  /** TODO: Documentation */
  Group& _root;

  /** TODO: Documentation */
  SceneModel _model;

  /** TODO: Documentation */
  std::set <Shape*> _childShapes;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Scene(Group& root);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Scene();

  /**
   * TODO: Documentation
   * <p>
   */
  Group& getRoot();

  /**
   * TODO: Documentation
   * <p>
   */
  SceneModel& getModel();

  /**
   * TODO: Documentation
   * <p>
   */
  ProjectedMouse& getProjectedMouse();

  /**
   * TODO: Documentation
   * <p>
   */
  void trigger(Action& action);

  /**
   * TODO: Documentation
   * <p>
   */
  void render(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderInSelectionMode(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  void compile();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Scene(const Scene& scene);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Scene& operator=(const Scene& scene);

};


}


#endif // GELATINE_SCENE_H
