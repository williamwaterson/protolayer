#ifndef PROTOLAYER_SCENEGRAPH_FONT_H
#define PROTOLAYER_SCENEGRAPH_FONT_H

#include <assert.h>
#include <string>
#include <set.h>


namespace protolayer
{

namespace scenegraph
{

/**
 * TODO: Documentation
 * <p>
 */
class Font
{
  /** TODO: Documentation */
  std::string _style;

  /** TODO: Documentation */
  int _size;

public:
  /**
   * TODO: Documentation
   *
   */
  Font(const std::string& style, int size);

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


#endif // PROTOLAYER_SCENEGRAPH_FONT_H
