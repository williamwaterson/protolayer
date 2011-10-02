#ifndef PROTOLAYER_CARBON_EMBEDDINGCONTROL_H
#define PROTOLAYER_CARBON_EMBEDDINGCONTROL_H

#include <set>

#include "forward.h"
#include "Control.h"
#include "Iterator.h"
#include "NonEmbeddingControl.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
class EmbeddingControl : public Control
{
  /** TODO: Documentation */
  friend class Window;

  /** TODO: Documentation */
  typedef Iterator <Control> IteratorType;

private:
  /** TODO: Documentation */
  std::set <Control*> _controls;

  /** TODO: Documentation */
  WindowRef _ownerWindowRef;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  EmbeddingControl();

  /**
   * TODO: Documentation
   * <p>
   */
  EmbeddingControl(short x, short y, short w, short h);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~EmbeddingControl() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  void add(NonEmbeddingControl& control);

  /**
   * TODO: Documentation
   * <p>
   */
  void add(EmbeddingControl& control);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(NonEmbeddingControl& control);
 
  /**
   * TODO: Documentation
   * <p>
   */
  void remove(EmbeddingControl& control);

  /**
   * TODO: Documentation
   * <p>
   */
  bool contains(Control& control) const;

  /**
   * TODO: Documentation
   * <p>
   */
  Iterator <Control> getEmbeddedControls();

  /**
   * TODO: Documentation
   * <p>
   */
  void setPort();

protected:
  /**
   * TODO: Documentation
   * <p>
   */
  EmbeddingControl(WindowRef windowRef);

  /**
   * TODO: Documentation
   * <p>
   */
  void setWindowRef(WindowRef windowRef);

  /**
   * TODO: Documentation
   * <p>
   */
  void createEmbeddedControls();

  /**
   * TODO: Documentation
   * <p>
   */
  void disposeEmbeddedControls();

};

}

}

#endif // PROTOLAYER_CARBON_EMBEDDINGCONTROL_H
