#ifndef PROTOLAYER_CARBON_SEARCHFIELD_H
#define PROTOLAYER_CARBON_SEARCHFIELD_H

#include "forward.h"
#include "NonEmbeddingControl.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class SearchField : public NonEmbeddingControl
{
private:
  /** TODO: Documentation */
  CFStringRef _label;

  /** TODO: Documentation */
  HIRect _bounds;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  SearchField(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  SearchField(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SearchField();

  /**
   * TODO: Documentation
   * <p>
   */
  void setText(const char* text);

private:
  /**
   * TODO: Documentation
   * <p>
   */
  virtual OSStatus create(WindowRef windowRef);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void dispose();

};

}

}

#endif // PROTOLAYER_CARBON_SEARCHFIELD_H
