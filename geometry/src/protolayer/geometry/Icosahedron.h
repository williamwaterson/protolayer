#ifndef PROTOLAYER_GEOMETRY_ICOSAHEDRON_H
#define PROTOLAYER_GEOMETRY_ICOSAHEDRON_H

#include <stdio.h>
#include "protolayer/protolayer-scenegraph.h"
#include "protolayer/protolayer-renderer.h"


namespace protolayer
{

namespace geometry
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class Icosahedron : public scenegraph::Group
{
private:
  /** TODO: Documentation */
  static const int NUMBER_VERTICES = 12;

  /** TODO: Documentation */
  float _radius;

  /** TODO: Documentation */
  renderer::Geometry* _lines;

  /** TODO: Documentation */
  renderer::Geometry* _triangles;

  /** TODO: Documentation */
  float** _points;

  /** TODO: Documentation */
  renderer::LegacyShape* _edges;

  /** TODO: Documentation */
  renderer::LegacyShape* _faces;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Icosahedron(float radius,
              style::Appearance& edgeAppearance,
              style::Appearance& faceAppearance);

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
  renderer::LegacyShape& getEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::LegacyShape& getFaces();

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


}


#endif // PROTOLAYER_GEOMETRY_ICOSAHEDRON_H
