#ifndef GELATINE_ANIMATOR_H
#define GELATINE_ANIMATOR_H

#include <stdio.h>
#include "protolayer/protolayer-carbon.h"
#include "GelatinePane.h"


namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class Animator : public protolayer::carbon::EventLoopTimerListener
{
  /** TODO: Documentation */  
  GelatinePane& _pane;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  Animator(GelatinePane& pane);

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


#endif // GELATINE_ANIMATOR_H
