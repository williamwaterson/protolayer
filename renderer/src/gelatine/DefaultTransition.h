#ifndef GELATINE_DEFAULTTRANSITION_H
#define GELATINE_DEFAULTTRANSITION_H


#include "Transition.h"


namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class DefaultTransition : public Transition
{
  /** TODO: Documentation */
  bool _inProgress;

public:
  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  DefaultTransition();

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  virtual bool inProgress();

  /**
   * Performs a single increment in the transition from the initial shot
   * to the final shot according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial shot to the final
   * shot.
   * <p>
   * @param initialShot
   *
   * @param finalShot
   *
   */
  virtual void commence(Shot& initialShot, Shot& finalShot);

  /**
   * Performs a single increment in the transition from the initial shot
   * to the final shot according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial shot to the final
   * shot.
   * <p>
   * @param initialShot
   *
   * @param finalShot
   *
   */
  virtual void increment(Shot& initialShot, Shot& finalShot);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void postComplete(Shot& initialShot, Shot& finalShot);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DefaultTransition(const DefaultTransition& defaultTransition);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  DefaultTransition& operator=(const DefaultTransition& defaultTransition);

};


}


#endif // GELATINE_DEFAULTTRANSITION_H
