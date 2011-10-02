#ifndef GELATINE_TRANSITION_H
#define GELATINE_TRANSITION_H


#include "Shot.h"


namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class Transition
{
public:
  /**
   * TODO: Documentation
   * <p>
   */  
  Transition();

  /**
   * TODO: Documentation
   * <p>
   */  
  virtual ~Transition() = 0;

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  virtual bool inProgress() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void commence(Shot& initialShot, Shot& finalShot) = 0;

  /**
   * Performs a single increment in the transition from the initial scene
   * to the final scene according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial scene to the final
   * scene.
   * <p>
   * @param initialScene
   *
   * @param finalScene
   *
   */
  virtual void increment(Shot& initialShot, Shot& finalShot) = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void postComplete(Shot& initialShot, Shot& finalShot) = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Transition(const Transition& transition);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Transition& operator=(const Transition& transition);

};


}


#endif // GELATINE_TRANSITION_H
