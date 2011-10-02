#ifndef GELATINE_GELATINEMOUSELISTENER_H
#define GELATINE_GELATINEMOUSELISTENER_H

#include <Carbon/Carbon.h>

#include "gelatine/gelatine-renderer.h"
#include "protolayer/protolayer-carbon.h"

#include "GelatinePane.h"

namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class GelatineMouseListener : public protolayer::carbon::MouseListener
{
  /** TODO: Documentation */
  protolayer::carbon::Window& _window;

  /** TODO: Documentation */
  GelatinePane& _pane;

  /** TODO: Documentation */
  ::Point _mousePosition;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  GelatineMouseListener(protolayer::carbon::Window& window, GelatinePane& pane);

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~GelatineMouseListener();

  /**
   * TODO: Documentation
   * <p>
   */  
  OSStatus mouseMoved(EventHandlerCallRef callRef,
                      EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */  
  OSStatus mouseDragged(EventHandlerCallRef callRef,
                        EventRef event);

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  GelatineMouseListener(const GelatineMouseListener& state);

  /**
   * TODO: Documentation
   * <p>
   */  
  GelatineMouseListener& operator=(const GelatineMouseListener& state);

};

}

#endif GELATINE_GELATINEMOUSELISTENER_H
