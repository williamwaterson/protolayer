#ifndef PROTOLAYER_OSX_ANIMATOR_H
#define PROTOLAYER_OSX_ANIMATOR_H

#include <stdio.h>
#include "protolayer/protolayer-carbon.h"
#include "Pane.h"


namespace protolayer
{

namespace osx
{

/**
 * TODO: Documentation
 * <p>
 */
class Animator : public protolayer::carbon::EventLoopTimerListener
{
  /** TODO: Documentation */  
  Pane& _pane;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  Animator(Pane& pane);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Animator();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void timerTriggered();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Animator(const Animator& animator);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Animator& operator=(const Animator& animator);

};


}


}


#endif // PROTOLAYER_OSX_ANIMATOR_H
