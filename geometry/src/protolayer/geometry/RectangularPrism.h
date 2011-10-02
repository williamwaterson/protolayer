#ifndef PROTOLAYER_GEOMETRY_RECTANGULARPRISM_H
#define PROTOLAYER_GEOMETRY_RECTANGULARPRISM_H

#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-scenegraph.h"


namespace protolayer
{

namespace geometry
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.4 $
 */
class RectangularPrism : public scenegraph::Group
{
private:
  /** TODO: Documentation */
  static const int NUMBER_VERTICES = 8;

  /** TODO: Documentation */
  static const int NUMBER_EDGES = 12;

  /** TODO: Documentation */
  static const int NUMBER_QUADS = 6;

  /** TODO: Documentation */
  static float H;

  /** TODO: Documentation */
  static float _unitVertices[8][4];

  /** TODO: Documentation */
  float _length;

  /** TODO: Documentation */
  float _height;

  /** TODO: Documentation */
  float _width;

  /** TODO: Documentation */
  float** _points;

  /** TODO: Documentation */
  renderer::Geometry* _lines;

  /** TODO: Documentation */
  renderer::Geometry* _quads;

  /** TODO: Documentation */
  renderer::LegacyShape* _edges;

  /** TODO: Documentation */
  renderer::LegacyShape* _faces;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  RectangularPrism(float length,
                   float height,
                   float width,
                   style::Appearance& edgeAppearance,
                   style::Appearance& faceAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseVertices();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseEdges();

  /**
   * TODO: Documentation
   * <p>
   */
  void initialiseQuads();

  /**
   * TODO: Documentation
   * <p>
   */
  void setDimensions(float length,
                     float height,
                     float width);

  /**
   * TODO: Documentation
   * <p>
   */
  renderer::LegacyShape& getFaces();

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
  float getLength() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float getHeight() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float getWidth() const;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RectangularPrism(const RectangularPrism& rectangularPrism);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RectangularPrism& operator=(const RectangularPrism& rectangularPrism);

  /**
   * TODO: Documentation
   * <p>
   */
  void recalculateVertices();

};


}


}


#endif // PROTOLAYER_GEOMETRY_RECTANGULARPRISM_H
