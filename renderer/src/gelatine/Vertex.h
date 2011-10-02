#ifndef GELATINE_VERTEX_H
#define GELATINE_VERTEX_H

#include <set.h>

#include "protolayer/protolayer-common.h"
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
class Vertex : public ::protolayer::nurbs::Vertex
{
public:
  /** TODO: Documentation */
  typedef HitListener <Vertex> HitListenerType;

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
  Vertex();

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex(float coordinates[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Vertex();

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
  Vertex(const Vertex& vertex);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Vertex& operator=(const Vertex& vertex);

};


}


#endif // GELATINE_VERTEX_H
