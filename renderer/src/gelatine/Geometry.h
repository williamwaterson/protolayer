#ifndef GELATINE_GEOMETRY_H
#define GELATINE_GEOMETRY_H

#include <iostream>
#include <vector>

#include "protolayer/protolayer-common.h"

#include "forward.h"
#include "Appearance.h"
#include "Point.h"

namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class Geometry
{
public:
  /** TODO: Documentation */
  typedef ::std::vector <float*>::iterator PointIteratorType;

private:
  /** TODO: Documentation */
  ::std::vector <float*> _points;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Geometry();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Geometry() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberPoints() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float* getPoint(int index);

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
  void addPoint(float* point);

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

  /**
   * TODO: Documentation
   * <p>
   */
  virtual int getType();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Geometry(const Geometry& geometry);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Geometry& operator=(const Geometry& geometry);

};


}


#endif // GELATINE_GEOMETRY_H
