#ifndef PROTOLAYER_CARBON_SEPARATOR_H
#define PROTOLAYER_CARBON_SEPARATOR_H

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
class Separator : public NonEmbeddingControl
{
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  Separator(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  Separator(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Separator();

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

#endif // PROTOLAYER_CARBON_SEPARATOR_H
