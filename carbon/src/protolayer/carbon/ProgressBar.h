#ifndef PROTOLAYER_CARBON_PROGRESSBAR_H
#define PROTOLAYER_CARBON_PROGRESSBAR_H

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
class ProgressBar : public NonEmbeddingControl
{
  /** TODO: Documentation */
  CFStringRef _label;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  ProgressBar(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  ProgressBar(const char* label, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ProgressBar();

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

#endif // PROTOLAYER_CARBON_PROGRESSBAR_H
