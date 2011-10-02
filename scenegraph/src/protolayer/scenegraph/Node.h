#ifndef PROTOLAYER_SCENEGRAPH_NODE_H
#define PROTOLAYER_SCENEGRAPH_NODE_H

#include <set>

#include "Point.h"


namespace protolayer
{

namespace scenegraph
{

/** Forward declarations */
class Group;
class Scene;

/**
 * TODO: Documentation
 * <p>
 */
class Node
{
public:
  /** TODO: Documentation */
  friend class Group;
  friend class Scene;

private:
  /** TODO: Documentation */
  static unsigned int _nextID;

  /** TODO: Documentation */
  bool _isOwned;

  /** TODO: Documentation */
  bool _isSelectable;

  /** TODO: Documentation */
  unsigned int _id;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Node();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Node(bool isSelectable);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Node() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  unsigned int getID() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setSelectable(bool flag);

  /**
   * TODO: Documentation
   * <p>
   */
  bool isSelectable() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void update(float quaternion[4][4]) = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  static unsigned int obtainID();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Node(const Node& node);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Node& operator=(const Node& node);

};


}


}


#endif // PROTOLAYER_SCENEGRAPH_NODE_H
