#ifndef PROTOLAYER_GEOMETRY_SPHERE_H
#define PROTOLAYER_GEOMETRY_SPHERE_H

#include <stdio.h>
#include <map.h>
#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-style.h"
#include "protolayer/protolayer-subdivision.h"

namespace protolayer
{

namespace geometry
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.5 $
 */
class Sphere : public scenegraph::Group
{
private:
  /** TODO: Documentation */
  typedef std::vector <subdivision::Vertex*> VertexVectorType;

  /** TODO: Documentation */
  typedef std::vector <subdivision::Edge*> EdgeVectorType;

  /** TODO: Documentation */
  typedef std::vector <subdivision::Face*> FaceVectorType;

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

  /** TODO: Documentation */
  subdivision::Mesh _mesh;

  /** TODO: Documentation */
  std::vector <subdivision::LoopLevel*> _subdivisions;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Sphere(float radius,
         int recursionLevel,
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
  Sphere(const Sphere& sphere);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  Sphere& operator=(const Sphere& sphere);

  /**
   * TODO: Documentation
   * <p>
   */
  void subdivide();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseBaseGeometry();

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


#endif // PROTOLAYER_GEOMETRY_SPHERE_H
