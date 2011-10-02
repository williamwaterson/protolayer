#ifndef PROTOLAYER_RENDERER_TEXT_H
#define PROTOLAYER_RENDERER_TEXT_H

#include <string>

#include "forward.h"
#include "Geometry.h"
#include "Font.h"

#include <protolayer/protolayer-scenegraph.h>


namespace protolayer
{

namespace renderer
{

/**
 * TODO: Documentation
 * <p>
 */
class Text : public scenegraph::Shape
{
private:
  /** TODO: Documentation */
  Font* _font;

  /** TODO: Documentation */
  std::string* _string;

public:
  /**
   * TODO: Documentation
   *
   */
  explicit Text(Font& font);

  /**
   * TODO: Documentation
   *
   */
  Text(Font& font, const std::string& string);

  /**
   * TODO: Documentation
   *
   */
  ~Text();

  /**
   * TODO: Documentation
   *
   */
  void render(float alpha);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Text(const Text& text);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Text& operator=(const Text& text);

};


}


}


#endif // PROTOLAYER_RENDERER_TEXT_H
