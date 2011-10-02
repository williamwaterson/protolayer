#ifndef PROTOLAYER_CARBON_CHECKBOX_H
#define PROTOLAYER_CARBON_CHECKBOX_H

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
class CheckBox : public NonEmbeddingControl
{
private:
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  CheckBox(const char* label, short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~CheckBox() = 0;

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


#endif // PROTOLAYER_CARBON_CHECKBOX_H
