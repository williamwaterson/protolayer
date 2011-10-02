#ifndef MESON_SELECTSTATE_H
#define MESON_SELECTSTATE_H

#include <iostream>

#include "../forward.h"
#include "InteractionState.h"
#include "RenderingState.h"

namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class SelectState : public InteractionState
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  explicit SelectState(RenderingState& renderingState);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SelectState();

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  SelectState(const SelectState& state);

  /**
   * TODO: Documentation
   * <p>
   */  
  SelectState& operator=(const SelectState& state);

};


}


}


#endif MESON_SELECTSTATE_H
