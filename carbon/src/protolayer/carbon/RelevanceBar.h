#ifndef PROTOLAYER_CARBON_RELEVANCEBAR_H
#define PROTOLAYER_CARBON_RELEVANCEBAR_H

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
class RelevanceBar : public NonEmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  RelevanceBar(short x, short y, short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RelevanceBar();

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

#endif // PROTOLAYER_CARBON_RELEVANCEBAR_H
