#ifndef PROTOLAYER_SCENEGRAPH_TEXT_H
#define PROTOLAYER_SCENEGRAPH_TEXT_H

#include <string>

#include "Leaf.h"
#include "Font.h"


namespace protolayer
{

namespace scenegraph
{

/**
 * TODO: Documentation
 * <p>
 */
class Text : public Leaf
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


#endif // PROTOLAYER_SCENEGRAPH_TEXT_H
