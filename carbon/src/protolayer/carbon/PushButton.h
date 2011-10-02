#ifndef PROTOLAYER_CARBON_PUSHBUTTON_H
#define PROTOLAYER_CARBON_PUSHBUTTON_H

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
class PushButton : public NonEmbeddingControl
{
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  PushButton(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  PushButton(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~PushButton();

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

#endif // PROTOLAYER_CARBON_PUSHBUTTON_H
