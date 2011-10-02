#ifndef MESON_SEARCHPERSPECTIVE_H
#define MESON_SEARCHPERSPECTIVE_H

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
class SearchPerspective : public Perspective
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  SearchPerspective();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SearchPerspective();

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
  SearchPerspective(const SearchPerspective& searchPerspective);

  /**
   * TODO: Documentation
   * <p>
   */
  SearchPerspective& operator=(const SearchPerspective& searchPerspective);

};


}


}


#endif MESON_SEARCHPERSPECTIVE_H
