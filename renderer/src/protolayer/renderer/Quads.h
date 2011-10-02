#ifndef PROTOLAYER_GLREP_QUADS_H
#define PROTOLAYER_GLREP_QUADS_H

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
class Quads
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
  Quads();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Quads();

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
  Quads(const Quads& quads);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Quads& operator=(const Quads& quads);

};


}


}


#endif // PROTOLAYER_GLREP_QUADS_H
