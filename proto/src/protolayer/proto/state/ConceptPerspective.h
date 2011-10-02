#ifndef MESON_CONCEPTPERSPECTIVE_H
#define MESON_CONCEPTPERSPECTIVE_H

#include <iostream>

#include "../forward.h"

#include "Perspective.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ConceptPerspective : public Perspective
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  ConceptPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ConceptPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  void activate(ViewLayer& view);

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  ConceptPerspective(const ConceptPerspective& conceptPerspective);

  /**
   * TODO: Documentation
   * <p>
   */
  ConceptPerspective& operator=(const ConceptPerspective& conceptPerspective);

};


}


}


#endif MESON_CONCEPTPERSPECTIVE_H
