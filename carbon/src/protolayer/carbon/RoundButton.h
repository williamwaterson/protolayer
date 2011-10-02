#ifndef PROTOLAYER_CARBON_ROUNDBUTTON_H
#define PROTOLAYER_CARBON_ROUNDBUTTON_H

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
class RoundButton : public NonEmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  RoundButton(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RoundButton();

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

#endif // PROTOLAYER_CARBON_ROUNDBUTTON_H
