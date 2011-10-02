#ifndef PROTOLAYER_GLREP_POINTS_H
#define PROTOLAYER_GLREP_POINTS_H

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
class Points
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
  Points();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Points();

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
  Points(const Points& points);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Points& operator=(const Points& points);

};


}


}


#endif // PROTOLAYER_GLREP_POINTS_H
