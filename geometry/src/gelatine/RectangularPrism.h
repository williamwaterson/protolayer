#ifndef GELATINE_RECTANGULARPRISM_H
#define GELATINE_RECTANGULARPRISM_H

#include "gelatine/gelatine-renderer.h"

namespace gelatine
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class RectangularPrism : public Group
{
private:
  /** TODO: Documentation */
  static const int NUMBER_VERTICES = 8;

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
  float** _vertices;

  /** TODO: Documentation */
  SpecificGeometry _lines;

  /** TODO: Documentation */
  SpecificGeometry _quads;

  /** TODO: Documentation */
  Shape _edges;

  /** TODO: Documentation */
  Shape _faces;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  RectangularPrism(float length,
                   float height,
                   float width,
                   Appearance& edgeAppearance,
                   Appearance& faceAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void initialise();

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


#endif // GELATINE_RECTANGULARPRISM_H
