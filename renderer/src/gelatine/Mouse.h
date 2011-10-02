#ifndef GELATINE_MOUSE_H
#define GELATINE_MOUSE_H


namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class Mouse
{
public:
  /** TODO: Documentation */
  short _x;

  /** TODO: Documentation */
  short _y;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Mouse();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Mouse(const Mouse& mouse);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Mouse& operator=(const Mouse& mouse);

};


}


#endif // GELATINE_MOUSE_H
