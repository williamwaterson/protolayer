#ifndef PROTOLAYER_SCENEGRAPH_SCENE_H
#define PROTOLAYER_SCENEGRAPH_SCENE_H

#include <set.h>

#include "Group.h"


namespace protolayer
{

namespace scenegraph
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class Scene
{
public:
  /** Access iterator types */
  typedef std::set <Leaf*>::iterator LeafIteratorType;

  //  typedef std::set <Shape*> ShapeSetType;

  //  typedef ShapeSetType::iterator ShapeIteratorType;

  //  typedef std::map <int, Shape*> ShapeNameMapType;

private:
  /** TODO: Documentation */
  Group& _root;

  /** TODO: Documentation */
  float _alpha;

  /** TODO: Documentation */
  //  std::set <Shape*> _shapes;

  /** TODO: Documentation */
  //  std::map <int, Shape*> _shapeNameMap;

  /** TODO: Documentation */
  util::IDGenerator _idGenerator;

  /** TODO: Documentation */
  struct timeval _tick;

  /** TODO: Documentation */
  float _time;

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
  //  ProjectedMouse& getProjectedMouse();

  /**
   * TODO: Documentation
   * <p>
   */
  void compile();

  /**
   * TODO: Documentation
   * <p>
   */
  float getAlpha() const;

  /**
   * TODO: Documentation
   * <p>
   */
  //  ShapeIteratorType getShapes();

  /**
   * TODO: Documentation
   * <p>
   */
  //  ShapeIteratorType getLastShape();
 
  /**
   * TODO: Documentation
   * <p>
   */
  util::IDGenerator& getIDGenerator();

  /**
   * TODO: Documentation
   */
  void setAlpha(float alpha);

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


}


#endif // PROTOLAYER_SCENEGRAPH_SCENE_H
