#ifndef GELATINE_GELATINEPANEVIEW_H
#define GELATINE_GELATINEPANEVIEW_H


#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "protolayer/protolayer-carbon.h"
#include "GelatinePaneModel.h"


namespace gelatine
{


/**
 * TODO: Documentation
 * <p>
 */
class GelatinePaneView : public protolayer::carbon::Listener
{
  /** TODO: Documentation */
  GelatinePaneModel& _model;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  GelatinePaneView(GelatinePaneModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GelatinePaneView();

  /**
   * TODO: Documentation
   * <p>
   */
  GelatinePaneModel& getModel();

  /**
   * TODO: Documentation
   * <p>
   */
  void init();

  /**
   * TODO: Documentation
   * <p>
   */
  void display();

  /**
   * TODO: Documentation
   * <p>
   */
  void resize(short left, short top, short right, short bottom);

  /**
   * TODO: Documentation
   * <p>
   */
  void dispose();

  /**
   * TODO: Documentation
   * <p>
   */
  void swapPortsAndDisplay();

  /**
   * TODO: Documentation
   * <p>
   */  
  int getNumberEventTypes();

  /**
   * TODO: Documentation
   * <p>
   */  
  const EventTypeSpec* getEventTypes();

  /**
   * TODO: Documentation
   * <p>
   */  
  EventHandlerUPP getEventHandlerUPP();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GelatinePaneView(const GelatinePaneView& gelatinePaneView);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GelatinePaneView& operator=(const GelatinePaneView& gelatinePaneView);

};


}


#endif // GELATINE_GELATINEPANEVIEW_H
