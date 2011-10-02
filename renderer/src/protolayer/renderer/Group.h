#ifndef PROTOLAYER_RENDERER_GROUP_H
#define PROTOLAYER_RENDERER_GROUP_H


#include <assert.h>
#include <map.h>
#include <math.h>
#include <set.h>
#include <typeinfo>
#include <vector.h>

#include "forward.h"
#include "Node.h"
#include "Leaf.h"
#include "Shape.h"
#include "Camera.h"


namespace protolayer
{

namespace renderer
{

/** TODO: Documentation */
class Scene;


/**
 * TODO: Documentation
 * <p>
 */
class Group : public Node
{
public:
  /** Access iterator types */
  typedef std::set <Leaf*>::iterator LeafIteratorType;

  /** Access iterator types */
  typedef std::set <Group*>::iterator GroupIteratorType;

  /** Access iterator types */
  typedef std::vector <Shape*>::iterator LeafVectorIteratorType;

  /** Access iterator types */
  typedef std::vector <Group*>::iterator GroupVectorIteratorType;

  /** Friend classes */
  friend class Scene;

private:
  /** TODO: Documentation */
  std::set <Leaf*> _childLeaves;

  /** TODO: Documentation */
  std::set <Group*> _childGroups;

  /** TODO: Documentation */
  std::vector <Shape*> _childShapeRenderOrder;

  /** TODO: Documentation */
  std::vector <Group*> _childGroupsRenderOrder;

  /** TODO: Documentation */
  std::map <unsigned, Node*> _nodeNameMap;

  /** TODO: Documentation */
  float _localTransform[4][4];

  /** TODO: Documentation */
  float (*_multiplier)[4];

  /** TODO: Documentation */
  float _globalTransform[4][4];

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Group();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Group();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void addChild(Group& group);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void addChild(Shape& shape);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void addChild(Camera& camera);

  /**
   * TODO: Documentation
   * <p>
   */
  Node* getNodeForName(unsigned name);

  /**
   * TODO: Documentation
   * <p>
   */
  GroupIteratorType getChildGroups();

  /**
   * TODO: Documentation
   * <p>
   */
  GroupIteratorType getLastGroup();

  /**
   * TODO: Documentation
   * <p>
   */
  LeafIteratorType getChildLeaves();

  /**
   * TODO: Documentation
   * <p>
   */
  LeafIteratorType getLastLeaf();

  /**
   * TODO: Documentation
   * <p>
   */
  GroupVectorIteratorType getOrderedChildGroups();

  /**
   * TODO: Documentation
   * <p>
   */
  GroupVectorIteratorType getOrderedLastGroup();

  /**
   * TODO: Documentation
   * <p>
   */
  LeafVectorIteratorType getOrderedChildLeaves();

  /**
   * TODO: Documentation
   * <p>
   */
  LeafVectorIteratorType getOrderedLastLeaf();

  /**
   * TODO: Documentation
   * <p>
   */
  void removeChild(Group& group);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeChild(Shape& shape);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeChild(Camera& camera);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearChildren();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void update(float quaternion[4][4]);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void update();

  /**
   * TODO: Documentation
   * <p>
   */
  Group* getParent(Group& group);

  /**
   * TODO: Documentation
   * <p>
   */
  Group* getParent(Leaf& leaf);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isPart(Leaf& leaf);

  /**
   * TODO: Documentation
   * <p>
   */
  void getLocalTransform(float matrix[4][4]) const;

  /**
   * TODO: Documentation
   * <p>
   */
  void getGlobalTransform(float matrix[4][4]) const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setLocalTransform(float matrix[4][4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void rotateX(float angleRadians);

  /**
   * TODO: Documentation
   * <p>
   */
  void rotateY(float angleRadians);

  /**
   * TODO: Documentation
   * <p>
   */
  void rotateZ(float angleRadians);

  /**
   * TODO: Documentation
   * <p>
   */
  void rotate(float angleRadians, float axis[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  void displace(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  void translate(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  void scale(float factor);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Group(const Group& group);

  /**
   * TODO: Documentation
   * <p>
   */
  void compile(std::set <Shape*>& shapes);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Group& operator=(const Group& group);

};


}


}


#endif // PROTOLAYER_RENDERER_GROUP_H
