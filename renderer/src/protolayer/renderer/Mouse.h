#ifndef PROTOLAYER_RENDERER_MOUSE_H
#define PROTOLAYER_RENDERER_MOUSE_H


namespace protolayer
{

namespace renderer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
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


}


#endif // PROTOLAYER_RENDERER_MOUSE_H
