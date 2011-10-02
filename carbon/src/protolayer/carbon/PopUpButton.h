#ifndef PROTOLAYER_CARBON_POPUPBUTTON_H
#define PROTOLAYER_CARBON_POPUPBUTTON_H

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
class PopUpButton : public NonEmbeddingControl
{
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  PopUpButton(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  PopUpButton(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~PopUpButton();

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

#endif // PROTOLAYER_CARBON_POPUPBUTTON_H
