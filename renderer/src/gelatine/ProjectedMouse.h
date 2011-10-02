#ifndef GELATINE_PROJECTEDMOUSE_H
#define GELATINE_PROJECTEDMOUSE_H


namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
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


#endif // GELATINE_PROJECTEDMOUSE_H
