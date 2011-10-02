#ifndef MESON_GRAPHINTERACTIONSTATE_H
#define MESON_GRAPHINTERACTIONSTATE_H


#include "../forward.h"


namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class GraphInteractionState : public MouseListener, public KeyboardListener
{
  /** TODO: Documentation */
  bool _enabled;

  /** TODO: Documentation */
  ::Point _mousePosition;

  /** TODO: Documentation */
  osx::Pane& _pane;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  GraphInteractionState(osx::Pane& pane);

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~GraphInteractionState() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  bool isEnabled() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void enable();

  /**
   * TODO: Documentation
   * <p>
   */
  void disable();

  /**
   * TODO: Documentation
   * <p>
   */
  osx::Pane& getRenderPane();

  /**
   * TODO: Documentation
   * <p>
   */  
  OSStatus mouseDown(EventHandlerCallRef callRef,
                     EventRef event);

  /**
   * TODO: Documentation
   * <p>
   */  
  OSStatus mouseUp(EventHandlerCallRef callRef,
                   EventRef event);

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

  /**
   * TODO: Documentation
   * <p>
   */   
  OSStatus mouseWheelMoved(EventHandlerCallRef callRef,
                           EventRef event);

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  GraphInteractionState(const GraphInteractionState& state);

  /**
   * TODO: Documentation
   * <p>
   */  
  GraphInteractionState& operator=(const GraphInteractionState& state);

};


}


}


#endif MESON_GRAPHINTERACTIONSTATE_H
