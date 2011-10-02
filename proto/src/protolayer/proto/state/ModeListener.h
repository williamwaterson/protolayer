#ifndef MESON_MODELISTENER_H
#define MESON_MODELISTENER_H

#include "InstanceCreation.h"

namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ModeListener
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  ModeListener();

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~ModeListener() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void changeModeToDomainScene() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void changeModeToLayeredScene(DomainPrism& domainPrism) = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void changeToCreateReferenceMode(InstanceCreation& state) = 0;

private:
  /**
   * TODO: Documentation
   * <p>
   */  
  ModeListener(const ModeListener& listener);

  /**
   * TODO: Documentation
   * <p>
   */  
  ModeListener& operator=(const ModeListener& listener);

};


}


#endif MESON_MODELISTENER_H
