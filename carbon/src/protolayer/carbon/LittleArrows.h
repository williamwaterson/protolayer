#ifndef PROTOLAYER_CARBON_LITTLEARROWS_H
#define PROTOLAYER_CARBON_LITTLEARROWS_H

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
class LittleArrows : public NonEmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  LittleArrows(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~LittleArrows() = 0;

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

#endif // PROTOLAYER_CARBON_LITTLEARROWS_H
