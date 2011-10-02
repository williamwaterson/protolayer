#ifndef GELATINE_POINT_H
#define GELATINE_POINT_H


#include <set.h>

#include "protolayer/protolayer-common.h"
#include "protolayer/protolayer-nurbs.h"

#include "forward.h"
#include "Appearance.h"
#include "HitListener.h"

namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Point
{
public:
  /** TODO: Documentation */
  typedef HitListener <Point> HitListenerType;

  /** TODO: Documentation */
  typedef std::set <HitListenerType*> HitListenerSetType;

  /** TODO: Documentation */
  typedef HitListenerSetType::iterator HitListenerIteratorType;

private:
  /** TODO: Documentation */
  unsigned int _id;

  /** TODO: Documentation */
  std::set <HitListenerType*> _hitListeners;

  /** TODO: Documentation */
  float* _localCoordinates;

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
  explicit Point(float* localCoordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  Point(float* localCoordinates,
        float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Point();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getLocalCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  const float* getLocalCoordinates() const;

  /**
   * TODO: Documentation
   * <p>
   */
  const float* getCoordinates() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setLocalCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  void setLocalCoordinates(float x, float y, float z, float w);

  /**
   * TODO: Documentation
   * <p>
   */
  void setCoordinates(float x, float y, float z, float w);

  /**
   * TODO: Documentation
   * <p>
   */
  void render(float alpha, Appearance& appearance);

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


#endif // GELATINE_POINT_H
