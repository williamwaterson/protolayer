#ifndef PROTOLAYER_SCENEGRAPH_GLOBALPOINT_H
#define PROTOLAYER_SCENEGRAPH_GLOBALPOINT_H


#include <set.h>

#include "protolayer/protolayer-util.h"

#include "Point.h"


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
class GlobalPoint : public Point
{
public:
  /** TODO: Documentation */
  friend class Leaf;

private:
  /** TODO: Documentation */
  Point* _localPoint;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit GlobalPoint(Point& localPoint);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GlobalPoint();

  /**
   * TODO: Documentation
   * <p>
   */
  bool isLocalPoint(Point& point);

  /**
   * TODO: Documentation
   * <p>
   */
  Point& getLocalPoint();

  /**
   * TODO: Documentation
   * <p>
   */
  void update(float quaternion[4][4]);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GlobalPoint(const GlobalPoint& globalPoint);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GlobalPoint& operator=(const GlobalPoint& globalPoint);

};


}


}


#endif // PROTOLAYER_SCENEGRAPH_GLOBALPOINT_H
