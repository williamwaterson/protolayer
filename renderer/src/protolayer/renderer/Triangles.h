#ifndef PROTOLAYER_GLREP_TRIANGLES_H
#define PROTOLAYER_GLREP_TRIANGLES_H

#include <vector>

#include "protolayer/protolayer-scenegraph.h"
#include "protolayer/protolayer-util.h"


namespace protolayer
{

namespace glrep
{

/**
 * TODO: Documentation
 * <p>
 */
class Triangles
{
public:
  /** TODO: Documentation */
  typedef ::std::vector <scenegraph::Point*>::iterator PointIteratorType;

private:
  /** TODO: Documentation */
  ::std::vector <scenegraph::Point*> _points;

  /** TODO: Documentation */
  float _lineWidth;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Triangles();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Triangles();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberPoints() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float getLineWidth() const;

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Point& getPoint(int index);

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
  void addPoint(scenegraph::Point& point);

  /**
   * TODO: Documentation
   * <p>
   */
  void removePoint(PointIteratorType iterator);

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
  Triangles(const Triangles& triangles);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Triangles& operator=(const Triangles& triangles);

};


}


}


#endif // PROTOLAYER_GLREP_TRIANGLES_H
