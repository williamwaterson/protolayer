#ifndef PROTOLAYER_CARBON_USERPANE_H
#define PROTOLAYER_CARBON_USERPANE_H

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
class UserPane : public EmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  UserPane(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~UserPane();

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

#endif // PROTOLAYER_CARBON_USERPANE_H
