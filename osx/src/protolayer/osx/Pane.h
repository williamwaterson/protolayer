#ifndef PROTOLAYER_OSX_PANE_H
#define PROTOLAYER_OSX_PANE_H

#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "protolayer/protolayer-carbon.h"
#include "protolayer/protolayer-renderer.h"

#include "PaneView.h"


namespace protolayer
{

namespace osx
{

/** TODO: Documentation */
pascal OSStatus protolayerPaneEventHandler(EventHandlerCallRef handler,
                                         EventRef event,
                                         void* userData);


/**
 * TODO: Documentation
 * <p>
 */
class Pane : public protolayer::carbon::NonEmbeddingControl
{
  /** TODO: Documentation */
  friend pascal OSStatus protolayerPaneEventHandler(EventHandlerCallRef, EventRef, void*);

  /** TODO: Documentation */
  PaneView* _view;

  /** TODO: Documentation */
  ::Point _mousePosition;

  /** TODO: Documentation */
  Rect _windowBounds;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Pane(renderer::Space& space,
       short left, short top, short right, short bottom);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Pane();

  /**
   * TODO: Documentation
   * <p>
   */
  PaneView& getView();

  /**
   * TODO: Documentation
   * <p>
   */
  PaneModel& getModel();

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::Space& getSpace();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setSize(short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setPosition(short x, short y);

  /**
   * TODO: Documentation
   * <p>
   */
  void updateBounds();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Pane(const Pane& pane);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Pane& operator=(const Pane& pane);

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


#endif // PROTOLAYER_OSX_PANE_H
