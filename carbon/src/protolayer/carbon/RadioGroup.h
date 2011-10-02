#ifndef PROTOLAYER_CARBON_RADIOGROUP_H
#define PROTOLAYER_CARBON_RADIOGROUP_H

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
class RadioGroup : public EmbeddingControl
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  RadioGroup(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RadioGroup();

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

#endif // PROTOLAYER_CARBON_RADIOGROUP_H
