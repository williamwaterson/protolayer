#ifndef PROTOLAYER_OSX_PANEVIEW_H
#define PROTOLAYER_OSX_PANEVIEW_H


#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "protolayer/protolayer-carbon.h"
#include "PaneModel.h"


namespace protolayer
{

namespace osx
{

/**
 * TODO: Documentation
 * <p>
 */
class PaneView : public protolayer::carbon::Listener
{
  /** TODO: Documentation */
  PaneModel& _model;

public:
  /**
   * TODO: Documentation
   * <p>
   */  
  PaneView(PaneModel& model);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~PaneView();

  /**
   * TODO: Documentation
   * <p>
   */
  PaneModel& getModel();

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
  PaneView(const PaneView& protolayerPaneView);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  PaneView& operator=(const PaneView& protolayerPaneView);

};


}


}


#endif // PROTOLAYER_OSX_PANEVIEW_H
