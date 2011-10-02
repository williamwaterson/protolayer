#ifndef PROTOLAYER_GEOMETRY_LODGEOMETRY_H
#define PROTOLAYER_GEOMETRY_LODGEOMETRY_H

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
 * @version $Revision: 1.2 $
 */
class LODGeometry : public renderer::Group
{
public:
  /** TODO: Documentation */
  typedef std::vector <subdivision::Vertex*> VertexVectorType;

  /** TODO: Documentation */
  typedef std::vector <subdivision::Edge*> EdgeVectorType;

  /** TODO: Documentation */
  typedef std::vector <subdivision::Face*> FaceVectorType;

  /** TODO: Documentation */
  static const int NUMBER_VERTICES = 20;

private:
  /** TODO: Documentation */
  int _levelOfDetail;

  /** TODO: Documentation */
  int _maximumRecursionDepth;

  /** TODO: Documentation */
  float _radius;

  /** TODO: Documentation */
  renderer::Geometry* _lines;

  /** TODO: Documentation */
  renderer::Geometry* _triangles;

  /** TODO: Documentation */
  renderer::Geometry* _outlineQuads;

  /** TODO: Documentation */
  float** _points;

  /** TODO: Documentation */
  renderer::LegacyShape* _edges;

  /** TODO: Documentation */
  renderer::LegacyShape* _faces;

  /** TODO: Documentation */
  float** _outlinePoints;

  /** TODO: Documentation */
  renderer::LegacyShape* _outlineFaces;

  /** TODO: Documentation */
  subdivision::Mesh _controlMesh;

  /** TODO: Documentation */
  std::vector <subdivision::CatmullClarkLevel*> _subdivisions;

  /** TODO: Documentation */
  std::vector <subdivision::Mesh*> _refinements;

  /** TODO: Documentation */
  renderer::LegacyShape* _outline;

  /** TODO: Documentation */
  renderer::LegacyShape* _arrow;

  /** TODO: Documentation */
  renderer::LegacyShape* _filler;

  /** TODO: Documentation */
  renderer::Geometry* _outlineGeometry;

  /** TODO: Documentation */
  renderer::Geometry* _arrowGeometry;

  /** TODO: Documentation */
  renderer::Geometry* _fillerGeometry;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  LODGeometry(float radius,
	    int maxRecursionLevel,
	    style::Appearance& lightAppearance,
	    style::Appearance& darkAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  int getLevelOfDetail() const;

  /**
   * TODO: Documentation
   * <p>
   */
  int getMaximumRecursionDepth() const;

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
  renderer::LegacyShape& getArrow();

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::LegacyShape& getOutline();


  /**
   * TODO: Documentation
   * <p>
   */
  renderer::LegacyShape& getFiller();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  LODGeometry(const LODGeometry& LOGeometry);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  LODGeometry& operator=(const LODGeometry& lodGeometry);

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
  void initialiseOutline();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseVertices();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseArrow();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseFiller();

  /**
   * TODO: Documentation
   * <p>
   */
  void recalculateVertices();

};


}


}


#endif // PROTOLAYER_GEOMETRY_LODGEOMETRY_H
