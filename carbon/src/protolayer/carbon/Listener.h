#ifndef PROTOLAYER_CARBON_LISTENER_H
#define PROTOLAYER_CARBON_LISTENER_H

#include "forward.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
void installListener(Listener& listener,
                     EventTargetRef target);


/**
 * TODO: Documentation
 * <p>
 */
void removeListener(Listener& listener);


/**
 * TODO: Documentation
 * <p>
 */
class Listener
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Listener();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Listener() = 0;

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual int getNumberEventTypes() = 0;

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual const EventTypeSpec* getEventTypes() = 0;

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual EventHandlerUPP getEventHandlerUPP() = 0;
  
};

}

}

#endif // PROTOLAYER_CARBON_LISTENER_H
