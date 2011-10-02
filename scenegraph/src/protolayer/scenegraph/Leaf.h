#ifndef PROTOLAYER_SCENEGRAPH_LEAF_H
#define PROTOLAYER_SCENEGRAPH_LEAF_H


#include <assert.h>
#include <string>

#include <map>
#include <vector>

#include "protolayer/protolayer-util.h"

#include "TransformedPoint.h"
#include "Node.h"


namespace protolayer
{

namespace scenegraph
{

/**
 * TODO: Documentation
 * <p>
 */
class Leaf : public Node
{
public:
  /** TODO: Documentation */
  typedef ::std::vector <TransformedPoint*>::iterator PointIteratorType;

private:
  /** TODO: Documentation */
  float (*_quaternion)[4];

  /** TODO: Documentation */
  ::std::vector <TransformedPoint*> _points;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Leaf();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Leaf();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberPoints() const;

  /**
   * TODO: Documentation
   * <p>
   */
  PointIteratorType getPoints();

  /**
   * TODO: Documentation
   * <p>
   */
  PointIteratorType getLastPoint();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isPart(Point& point);

  /**
   * TODO: Documentation
   * <p>
   */
  void update(float quaternion[4][4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void update();

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  TransformedPoint& addPoint(Point& point);

  /**
   * TODO: Documentation
   * <p>
   */
  void removePoint(Point& point);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearPoints();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Leaf(const Leaf& leaf);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Leaf& operator=(const Leaf& leaf);

};


}


}


#endif // PROTOLAYER_SCENEGRAPH_LEAF_H
