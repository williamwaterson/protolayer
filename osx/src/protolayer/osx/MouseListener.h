#ifndef PROTOLAYER_OSX_MOUSELISTENER_H
#define PROTOLAYER_OSX_MOUSELISTENER_H

#include <Carbon/Carbon.h>

#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-carbon.h"

#include "Pane.h"

namespace protolayer
{

namespace osx
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class MouseListener : public protolayer::carbon::MouseListener
{
  /** TODO: Documentation */
  protolayer::carbon::Window& _window;

  /** TODO: Documentation */
  Pane& _pane;

  /** TODO: Documentation */
  ::Point _mousePosition;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  MouseListener(protolayer::carbon::Window& window, Pane& pane);

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~MouseListener();

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
  MouseListener(const MouseListener& state);

  /**
   * TODO: Documentation
   * <p>
   */  
  MouseListener& operator=(const MouseListener& state);

};


}


}

#endif PROTOLAYER_OSX_MOUSELISTENER_H
