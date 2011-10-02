#ifndef PROTOLAYER_RENDERER_FONT_H
#define PROTOLAYER_RENDERER_FONT_H

#include <assert.h>
#include <string>
#include <set.h>

#include "forward.h"
#include "Geometry.h"


namespace protolayer
{

namespace renderer
{

/**
 * TODO: Documentation
 * <p>
 */
class Font
{
private:
  /** TODO: Documentation */
  friend class Text;

  /** TODO: Documentation */
  GLuint _id;

  /** TODO: Documentation */
  short _fontType;

public:
  /**
   * TODO: Documentation
   *
   */
  Font();

  /**
   * TODO: Documentation
   *
   */
  ~Font();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Font(const Font& font);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Font& operator=(const Font& font);

};


}


}


#endif // PROTOLAYER_RENDERER_FONT_H
