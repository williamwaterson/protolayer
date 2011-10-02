#ifndef PROTOLAYER_RENDERER_ACTION_H
#define PROTOLAYER_RENDERER_ACTION_H


namespace protolayer
{

namespace renderer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Action
{
public:
  /** The total time period for the overall transition */
  static const long UNITY = 1;

  /** The total time period for the overall transition */
  static const long ZERO = 0;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Action();

  /**
   * TODO: Documentation
   * <p>
   */
  ~Action();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void commence(float timeStarted) = 0;

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  virtual bool inProgress() = 0;

  /**
   * Performs a single increment in the action over time according
   * to the particular action type implemented by the derived class.
   * <p>
   */
  virtual void increment(float timeCurrent) = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void postComplete() = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Action(const Action& action);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Action& operator=(const Action& action);

};


}


}


#endif // PROTOLAYER_RENDERER_ACTION_H
