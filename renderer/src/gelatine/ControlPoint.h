#ifndef GELATINE_CONTROLPOINT_H
#define GELATINE_CONTROLPOINT_H

#include <set.h>

#include "protolayer/protolayer-nurbs.h"

#include "forward.h"
#include "Appearance.h"
#include "HitListener.h"

namespace gelatine
{


/** TODO: Documentation */
class NurbsGeometry;


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ControlPoint : public ::protolayer::nurbs::ControlPoint
{
public:
  /** TODO: Documentation */
  typedef HitListener <ControlPoint> HitListenerType;

  /** TODO: Documentation */
  typedef std::set <HitListenerType*> HitListenerSetType;

  /** TODO: Documentation */
  typedef HitListenerSetType::iterator HitListenerIteratorType;

  /** TODO: Documentation */
  friend class NurbsGeometry;

  /** TODO: Documentation */
  friend class NurbsShape;

private:
  /** TODO: Documentation */
  unsigned int _id;

  /** TODO: Documentation */
  ::std::set <HitListenerType*> _hitListeners;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  ControlPoint(float* localCoordinates, float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  ~ControlPoint();

  /**
   * TODO: Documentation
   * <p>
   */
  void render(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderInSelectionMode(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void addHitListener(HitListenerType& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void removeHitListener(HitListenerType& listener);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearHitListeners();

  /**
   * TODO: Documentation
   * <p>
   */
  void triggerHitListeners();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ControlPoint(const ControlPoint& controlPoint);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ControlPoint& operator=(const ControlPoint& controlPoint);

};


}


#endif // GELATINE_CONTROLPOINT_H
