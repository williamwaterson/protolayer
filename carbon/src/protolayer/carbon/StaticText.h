#ifndef PROTOLAYER_CARBON_STATICTEXT_H
#define PROTOLAYER_CARBON_STATICTEXT_H

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
class StaticText : public NonEmbeddingControl
{
private:
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  StaticText(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  StaticText(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~StaticText();

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

#endif // PROTOLAYER_CARBON_STATICTEXT_H
