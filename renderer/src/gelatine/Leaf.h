#ifndef GELATINE_LEAF_H
#define GELATINE_LEAF_H


#include <assert.h>
#include <iostream>
#include <string>

#include <map>
#include <vector>

#include "protolayer/protolayer-common.h"

#include "forward.h"
#include "Geometry.h"
#include "Node.h"


namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class Leaf : public Node
{
public:
  /** TODO: Documentation */
  typedef ::std::vector <Point*>::iterator PointIteratorType;

private:
  /** TODO: Documentation */
  unsigned int _id;

  /** TODO: Documentation */
  float (*_quaternion)[4];

  /** TODO: Documentation */
  ::std::vector <Point*> _points;

  /** TODO: Documentation */
  ::std::map <unsigned, Point*> _idPointMap;

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
  virtual ~Leaf() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  unsigned int getID() const;

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
  Point* getPointForID(unsigned name);

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

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void render(float alpha);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void renderInSelectionMode(float alpha);

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  void addPoint(Point& point);

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


#endif // GELATINE_LEAF_H
