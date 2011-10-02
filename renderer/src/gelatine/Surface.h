#ifndef GELATINE_SURFACE_H
#define GELATINE_SURFACE_H


#include <set.h>

#include "protolayer/protolayer-nurbs.h"

#include "Appearance.h"
#include "ControlPointFactory.h"
#include "HitListener.h"
#include "Vertex.h"


namespace gelatine
{


/** TODO: Documentation */
class NurbsGeometry;


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Surface : public Leaf
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  Surface(int m, int n);

  /**
   * TODO: Documentation
   * <p>
   */
  Surface(int m, int n, float*** positions);

  /**
   * TODO: Documentation
   * <p>
   */
  ~Surface();

  /**
   * TODO: Documentation
   * <p>
   */
  void renderMeshes(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderFaces(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderMeshesInSelectionMode(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderFacesInSelectionMode(float alpha, Appearance& appearance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Surface(const Surface& Surface);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Surface& operator=(const Surface& Surface);

};


}


#endif // GELATINE_SURFACE_H
