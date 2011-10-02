#ifndef PROTOLAYER_SCENEGRAPH_PROJECTEDMOUSE_H
#define PROTOLAYER_SCENEGRAPH_PROJECTEDMOUSE_H


namespace protolayer
{

namespace scenegraph
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class ProjectedMouse
{
public:
  /** TODO: Documentation */
  float _x;

  /** TODO: Documentation */
  float _y;

  /** TODO: Documentation */
  float _z;

public:
  /**
   * TODO: Documentation
   */
  ProjectedMouse();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ProjectedMouse(const ProjectedMouse& projectedMouse);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  ProjectedMouse& operator=(const ProjectedMouse& projectedMouse);
  
};


}


}


#endif // PROTOLAYER_SCENEGRAPH_PROJECTEDMOUSE_H
