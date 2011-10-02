#ifndef PROTOLAYER_CARBON_TAB_H
#define PROTOLAYER_CARBON_TAB_H

#include <string>

#include "forward.h"
#include "EmbeddingControl.h"

namespace protolayer
{

namespace carbon
{

// Forward declarations
class TabControl;

/**
 * TODO: Documentation
 * <p>
 */
class Tab
{
  /** TODO: Documentation */
  friend class TabControl;

  /** TODO: Documentation */
  std::string _name;

  /** TODO: Documentation */
  bool _enabled;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Tab(const char* name, bool enabled);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Tab();

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getName() const;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isEnabled() const;

};

}

}

#endif // PROTOLAYER_CARBON_TAB_H
