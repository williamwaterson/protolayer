#ifndef PROTOLAYER_CARBON_SLIDER_H
#define PROTOLAYER_CARBON_SLIDER_H

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
class Slider : public NonEmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  Slider(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Slider() = 0;

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

#endif // PROTOLAYER_CARBON_SLIDER_H
