#ifndef PROTOLAYER_CARBON_GROUPBOX_H
#define PROTOLAYER_CARBON_GROUPBOX_H

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
class GroupBox : public EmbeddingControl
{
  /** TODO: Documentation */
  CFStringRef _title;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  GroupBox(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  GroupBox(const char* title, short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GroupBox();

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

#endif // PROTOLAYER_CARBON_GROUPBOX_H
