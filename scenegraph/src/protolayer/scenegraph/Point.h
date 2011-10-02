#ifndef PROTOLAYER_SCENEGRAPH_POINT_H
#define PROTOLAYER_SCENEGRAPH_POINT_H


#include <set.h>

#include "protolayer/protolayer-util.h"


namespace protolayer
{

namespace scenegraph
{

/** Forward declarations */
class Leaf;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class Point
{
public:
  /** TODO: Documentation */
  friend class Leaf;

private:
  /** TODO: Documentation */
  float* _coordinates;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Point();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Point(float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  Point(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  Point(Point& point, bool copyFlag);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Point();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  const float* getCoordinates() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setCoordinates(float x, float y, float z, float w);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Point(const Point& point);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Point& operator=(const Point& point);

};


}


}


#endif // PROTOLAYER_SCENEGRAPH_POINT_H
