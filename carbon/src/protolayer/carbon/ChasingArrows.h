#ifndef PROTOLAYER_CARBON_CHASINGARROWS_H
#define PROTOLAYER_CARBON_CHASINGARROWS_H

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
class ChasingArrows : public NonEmbeddingControl
{
public:
  /** TODO: Documentation */
  

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  ChasingArrows(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */  
  ChasingArrows(Control::Size, short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~ChasingArrows();

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


#endif // PROTOLAYER_CARBON_CHASINGARROWS_H
