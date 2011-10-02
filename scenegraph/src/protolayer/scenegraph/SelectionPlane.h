#ifndef PROTOLAYER_SCENEGRAPH_SELECTIONPLANE_H
#define PROTOLAYER_SCENEGRAPH_SELECTIONPLANE_H


namespace protolayer
{

namespace scenegraph
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class SelectionPlane
{
  /** TODO: Documentation */
  float _positionY;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  SelectionPlane();

  /**
   * TODO: Documentation
   * <p>
   */
  float getPositionY();

  /**
   * TODO: Documentation
   * <p>
   */
  void setPositionY(float value);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SelectionPlane(const SelectionPlane& selectionPlane);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SelectionPlane& operator=(const SelectionPlane& selectionPlane);
  
};


}


}


#endif // PROTOLAYER_SCENEGRAPH_SELECTIONPLANE_H
