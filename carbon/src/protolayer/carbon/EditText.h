#ifndef PROTOLAYER_CARBON_EDITTEXT_H
#define PROTOLAYER_CARBON_EDITTEXT_H

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
class EditText : public NonEmbeddingControl
{
private:
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  EditText(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  EditText(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~EditText();

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

#endif // PROTOLAYER_CARBON_EDITTEXT_H
