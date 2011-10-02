#ifndef PROTOLAYER_CARBON_TEXTFIELD_H
#define PROTOLAYER_CARBON_TEXTFIELD_H

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
class TextField : public NonEmbeddingControl
{
private:
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  TextField(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  TextField(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~TextField();

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

#endif // PROTOLAYER_CARBON_TEXTFIELD_H
