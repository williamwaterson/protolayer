#ifndef PROTOLAYER_CARBON_PLACARD_H
#define PROTOLAYER_CARBON_PLACARD_H

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
class Placard : public EmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Placard(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Placard();

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

#endif // PROTOLAYER_CARBON_PLACARD_H
