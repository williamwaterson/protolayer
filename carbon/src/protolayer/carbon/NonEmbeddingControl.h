#ifndef PROTOLAYER_CARBON_NONEMBEDDINGCONTROL_H
#define PROTOLAYER_CARBON_NONEMBEDDINGCONTROL_H

#include "forward.h"
#include "Control.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class NonEmbeddingControl : public Control
{
  /** TODO: Documentation */
  friend class EmbeddingControl;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  NonEmbeddingControl();

  /**
   * TODO: Documentation
   * <p>
   */
  NonEmbeddingControl(Control::Size size);

  /**
   * TODO: Documentation
   * <p>
   */
  NonEmbeddingControl(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  NonEmbeddingControl(Control::Size size, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~NonEmbeddingControl() = 0;

};


}


}


#endif // PROTOLAYER_CARBON_NONEMBEDDINGCONTROL_H
