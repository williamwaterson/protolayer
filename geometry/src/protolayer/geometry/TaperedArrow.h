#ifndef PROTOLAYER_GEOMETRY_TAPEREDARROW_H
#define PROTOLAYER_GEOMETRY_TAPEREDARROW_H

#include "protolayer/protolayer-renderer.h"
#include "protolayer/protolayer-scenegraph.h"
#include "protolayer/protolayer-style.h"
#include "protolayer/protolayer-util.h"


namespace protolayer
{

namespace geometry
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class TaperedArrow : public scenegraph::Group
{
private:
  /** TODO: Documentation */
  static const int NUMBER_VERTICES = 6;

  /** TODO: Documentation */
  static const float A = 0.25f;

  /** TODO: Documentation */
  static const float B = 0.5f;

  /** TODO: Documentation */
  static const float ARROW_WIDTH = 2;

  /** TODO: Documentation */
  static float _headUnitVertices[5][4];

private:
  /** TODO: Documentation */
  float** _vertices;

  /** TODO: Documentation */
  renderer::Geometry* _lines;

  /** TODO: Documentation */
  renderer::Geometry* _triangles;

  /** TODO: Documentation */
  renderer::LegacyShape* _edges;

  /** TODO: Documentation */
  renderer::LegacyShape* _faces;

  /** TODO: Documentation */
  float _scale;

  /** TODO: Documentation */
  float _xaxis[3];

  /** TODO: Documentation */
  float _yaxis[3];

  /** TODO: Documentation */
  float _zaxis[3];

  /** TODO: Documentation */
  float _midpoint[3];

  /** TODO: Documentation */
  float _normal[3];

public:
  /**
   * TODO: Documentation
   * <p>
   */
  TaperedArrow(float startX,
               float startY,
               float startZ,
               float endX,
               float endY,
               float endZ,
               style::Appearance& edgeAppearance,
               style::Appearance& faceAppearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void setOrthonormalBasis(float xaxis[3],
                           float yaxis[3],
                           float zaxis[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setStart(float x,
                        float y,
                        float z);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual void setEnd(float x,
                      float y,
                      float z);

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
  
  /**
   * TODO: Documentation
   * <p>
   */
  float* getStart();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getEnd();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getPosition();

  /**
   * TODO: Documentation
   * <p>
   */
  bool hasVertices();

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

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TaperedArrow(const TaperedArrow& taperedArrow);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  TaperedArrow& operator=(const TaperedArrow& taperedArrow);

  /**
   * TODO: Documentation
   * <p>
   */
  void evaluatePosition();

  /**
   * TODO: Documentation
   * <p>
   */
  void recalculateVertices();

};


}


}


#endif // PROTOLAYER_GEOMETRY_TAPEREDARROW_H
