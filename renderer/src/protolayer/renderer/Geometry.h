#ifndef PROTOLAYER_RENDERER_GEOMETRY_H
#define PROTOLAYER_RENDERER_GEOMETRY_H

#include <vector>

#include "protolayer/protolayer-style.h"
#include "protolayer/protolayer-util.h"

#include "forward.h"


namespace protolayer
{

namespace renderer
{

/**
 * TODO: Documentation
 * <p>
 */
class Geometry
{
public:
  /** TODO: Documentation */
  enum GeometryTypeEnum { POINTS = GL_POINTS,
                          LINES = GL_LINES,
                          LINE_STRIP = GL_LINE_STRIP,
                          LINE_LOOP = GL_LINE_LOOP,
                          TRIANGLES = GL_TRIANGLES,
                          TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
                          TRIANGLE_FAN = GL_TRIANGLE_FAN,
                          QUADS = GL_QUADS,
                          QUAD_STRIP = GL_QUAD_STRIP,
                          POLYGON = GL_POLYGON };

  /** TODO: Documentation */
  typedef ::std::vector <float*>::iterator PointIteratorType;

private:
  /** TODO: Documentation */
  GeometryTypeEnum _geometryType;

  /** TODO: Documentation */
  ::std::vector <float*> _points;

  /** TODO: Documentation */
  float _lineWidth;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Geometry(GeometryTypeEnum geometryType);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Geometry();

  /**
   * TODO: Documentation
   * <p>
   */
  int getType();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberPoints() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float getLineWidth() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float* getPoint(int index);

  /**
   * TODO: Documentation
   * <p>
   */
  PointIteratorType getPoints();

  /**
   * TODO: Documentation
   * <p>
   */
  PointIteratorType getLastPoint();

  /**
   * TODO: Documentation
   * <p>
   */
  void addPoint(float* point);

  /**
   * TODO: Documentation
   * <p>
   */
  void removePoint(PointIteratorType iterator);

  /**
   * TODO: Documentation
   * <p>
   */
  void clearPoints();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Geometry(const Geometry& geometry);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Geometry& operator=(const Geometry& geometry);

};


}


}


#endif // PROTOLAYER_RENDERER_GEOMETRY_H
