#ifndef GELATINE_GELATINEPANEMODEL_H
#define GELATINE_GELATINEPANEMODEL_H

#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "gelatine/gelatine-renderer.h"
#include "protolayer/protolayer-carbon.h"

namespace gelatine
{

// Forward declarations
class GelatinePane;
class GelatinePaneView;

/**
 * TODO: Documentation
 * <p>
 */
class GelatinePaneModel
{
  /** TODO: Documentation */
  friend class GelatinePaneView;

  /** TODO: Documentation */  
  friend class GelatinePane;

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
  Space* _space;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  GelatinePaneModel(Shot& shot,
                    short left,
                    short top,
                    short right,
                    short bottom);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GelatinePaneModel();

  /**
   * TODO: Documentation
   * <p>
   */
  Space& getSpace();

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
  GelatinePaneModel(const GelatinePaneModel& gelatinePaneModel);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GelatinePaneModel& operator=(const GelatinePaneModel& gelatinePaneModel);

};


}


#endif // GELATINE_GELATINEPANEMODEL_H
