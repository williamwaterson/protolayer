#ifndef GELATINE_ICOSAHEDRON_H
#define GELATINE_ICOSAHEDRON_H

#include <stdio.h>
#include "gelatine/gelatine-renderer.h"

namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class Icosahedron : public Group
{
private:
  /** TODO: Documentation */
  static const int NUMBER_VERTICES = 12;

  /** TODO: Documentation */
  float _radius;

  /** TODO: Documentation */
  SpecificGeometry* _lines;

  /** TODO: Documentation */
  SpecificGeometry* _triangles;

  /** TODO: Documentation */
  float** _points;

  /** TODO: Documentation */
  Shape* _edges;

  /** TODO: Documentation */
  Shape* _faces;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Icosahedron(float radius,
              Appearance& edgeAppearance,
              Appearance& faceAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  float getRadius();

  /**
   * TODO: Documentation
   * <p>
   */
  void setRadius(float radius);

  /**
   * TODO: Documentation
   * <p>
   */
  gelatine::Shape& getEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  gelatine::Shape& getFaces();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Icosahedron(const Icosahedron& icosahedron);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Icosahedron& operator=(const Icosahedron& icosahedron);

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseVertices();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseFaces();

  /**
   * TODO: Documentation
   * <p>
   */
  void recalculateVertices();

};


}


#endif // GELATINE_ICOSAHEDRON_H
