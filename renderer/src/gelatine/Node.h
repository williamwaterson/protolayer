#ifndef GELATINE_NODE_H
#define GELATINE_NODE_H

#include <set>

#include "forward.h"
#include "HitListener.h"

namespace gelatine
{

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
  friend class Space;

  /** TODO: Documentation */
  typedef HitListener <Node> HitListenerType;

private:
  /** TODO: Documentation */
  static unsigned int _nextID;

  /** TODO: Documentation */
  bool _isOwned;

  /** TODO: Documentation */
  bool _isSelectable;

  /** TODO: Documentation */
  unsigned int _id;

  /** TODO: Documentation */
  std::set <HitListenerType*> _hitListeners;

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

  /**
   * TODO: Documentation
   * <p>
   */
  void addHitListener(HitListener <Node>& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeHitListener(HitListener <Node>& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearHitListeners();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void triggerHitListeners();

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


#endif // GELATINE_NODE_H
