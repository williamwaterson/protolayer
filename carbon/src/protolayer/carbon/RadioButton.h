#ifndef PROTOLAYER_CARBON_RADIOBUTTON_H
#define PROTOLAYER_CARBON_RADIOBUTTON_H

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
class RadioButton : public NonEmbeddingControl
{
private:
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  RadioButton(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  RadioButton(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RadioButton() = 0;

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

#endif // PROTOLAYER_CARBON_RADIOBUTTON_H
