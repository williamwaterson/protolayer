#ifndef PROTOLAYER_CARBON_ROOTCONTROL_H
#define PROTOLAYER_CARBON_ROOTCONTROL_H

#include <map>

#include "forward.h"
#include "EmbeddingControl.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class RootControl : public EmbeddingControl
{
  /** TODO: Documentation */
  friend class Window;

private:
  /**
   * TODO: Documentation
   * <p>
   */
  RootControl(WindowRef windowRef);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RootControl();

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

#endif // PROTOLAYER_CARBON_ROOTCONTROL_H
