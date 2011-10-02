#ifndef GELATINE_GELATINEPANE_H
#define GELATINE_GELATINEPANE_H

#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "protolayer/protolayer-carbon.h"
#include "gelatine/gelatine-renderer.h"

#include "GelatinePaneView.h"


namespace gelatine
{


/** TODO: Documentation */
pascal OSStatus gelatinePaneEventHandler(EventHandlerCallRef handler,
                                         EventRef event,
                                         void* userData);


/**
 * TODO: Documentation
 * <p>
 */
class GelatinePane : public protolayer::carbon::NonEmbeddingControl
{
  /** TODO: Documentation */
  friend pascal OSStatus gelatinePaneEventHandler(EventHandlerCallRef, EventRef, void*);

  /** TODO: Documentation */
  GelatinePaneView* _view;

  /** TODO: Documentation */
  ::Point _mousePosition;

  /** TODO: Documentation */
  Rect _windowBounds;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  GelatinePane(Shot& shot, short left, short top, short right, short bottom);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GelatinePane();

  /**
   * TODO: Documentation
   * <p>
   */
  GelatinePaneView& getView();

  /**
   * TODO: Documentation
   * <p>
   */
  GelatinePaneModel& getModel();

  /**
   * TODO: Documentation
   * <p>
   */
  Space& getSpace();

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
  GelatinePane(const GelatinePane& gelatinePane);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GelatinePane& operator=(const GelatinePane& gelatinePane);

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


#endif // GELATINE_GELATINEPANE_H
