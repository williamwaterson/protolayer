#ifndef PROTOLAYER_OSX_PANEMODEL_H
#define PROTOLAYER_OSX_PANEMODEL_H

#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-carbon.h"

namespace protolayer
{

namespace osx
{

// Forward declarations
class Pane;
class PaneView;

/**
 * TODO: Documentation
 * <p>
 */
class PaneModel
{
  /** TODO: Documentation */
  friend class PaneView;

  /** TODO: Documentation */  
  friend class Pane;

  /** TODO: Documentation */
  static const GLint attrib[];

  /** TODO: Documentation */
  WindowRef _windowRef;

public:
  /** TODO: Documentation */
  Rect* _bounds;

  /** TODO: Documentation */
  AGLContext _aglContext;

  /** TODO: Documentation */
  AGLPixelFormat _aglPixelFormat;

  /** TODO: Documentation */
  renderer::Space* _space;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  PaneModel(renderer::Space& space,
            short left,
            short top,
            short right,
            short bottom);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~PaneModel();

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::Space& getSpace();

  /**
   * TODO: Documentation
   * <p>
   */
  const WindowRef& getWindowRef() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void setPosition(short left, short top);

  /**
   * TODO: Documentation
   * <p>
   */
  void setSize(short width, short height);

  /**
   * TODO: Documentation
   * <p>
   */
  //  void setMousePosition(Point position);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  PaneModel(const PaneModel& paneModel);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  PaneModel& operator=(const PaneModel& paneModel);

};


}


}


#endif // PROTOLAYER_OSX_PANEMODEL_H
