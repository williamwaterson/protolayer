#ifndef PROTOLAYER_SCENEGRAPH_MOUSE_H
#define PROTOLAYER_SCENEGRAPH_MOUSE_H


namespace protolayer
{

namespace scenegraph
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


#endif // PROTOLAYER_SCENEGRAPH_MOUSE_H
