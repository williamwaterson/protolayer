#ifndef PROTOLAYER_CARBON_ENVIRONMENT_H
#define PROTOLAYER_CARBON_ENVIRONMENT_H

#include "forward.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class Environment
{
  /** TODO: Documentation */
  short _screenWidth;

  /** TODO: Documentation */
  short _screenHeight;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Environment();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Environment();

  /**
   * TODO: Documentation
   * <p>
   */
  short getScreenWidth();

  /**
   * TODO: Documentation
   * <p>
   */
  short getScreenHeight();

};

}

}

#endif // PROTOLAYER_CARBON_GROUPBOX_H
