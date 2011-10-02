#ifndef GELATINE_HEXMESH_H
#define GELATINE_HEXMESH_H

#include <math.h>
#include <Carbon/Carbon.h>
#include "gelatine/gelatine-renderer.h"

namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class HexMesh : public Group
{
private:
  /** TODO: Documentation */
  static const double ANGLE_RADIANS;

  /** Delta-X offset of consequetive points in the XZ-plane */
  static const double DELTA_X;

  /** Delta-Z offset of consequetive points in the XZ-plane */
  static const double DELTA_Z;

  /** TODO: Documentation */
  static float*** EMPTY;

  /** TODO: Documentation */
  int _order;

  /** TODO: Documentation */
  float _radius;

  /** TODO: Documentation */
  float _corner[3];

  /** TODO: Documentation */
  float** _vertices;

  /** TODO: Documentation */
  SpecificGeometry* _lines;

  /** TODO: Documentation */
  Shape* _edges;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HexMesh(float radius, int order, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberTriangles();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberQuads();

  /**
   * TODO: Documentation
   * <p>
   */
  float*** getEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  float*** getTriangles();

  /**
   * TODO: Documentation
   * <p>
   */
  float*** getQuads();

  /**
   * TODO: Documentation
   * <p>
   */
  Appearance& getAppearance();

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasVertices();

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasFaces();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HexMesh(const HexMesh& hexMesh);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HexMesh& operator=(const HexMesh& hexMesh);

  /**
   * TODO: Documentation
   * <p>
   */
  static int evaluateNumberVertices(int order);

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluateUnitStructure();

};


}


#endif // GELATINE_HEXMESH_H
