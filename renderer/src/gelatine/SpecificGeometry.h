#ifndef GELATINE_SPECIFICGEOMETRY_H
#define GELATINE_SPECIFICGEOMETRY_H

#include "forward.h"
#include "Geometry.h"

namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class SpecificGeometry : public Geometry
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

private:
  /** TODO: Documentation */
  GeometryTypeEnum _geometryType;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  SpecificGeometry(GeometryTypeEnum geometryType);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~SpecificGeometry();

  /**
   * TODO: Documentation
   * <p>
   */
  //  void render(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  int getType();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SpecificGeometry(const SpecificGeometry& geometry);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  SpecificGeometry& operator=(const SpecificGeometry& geometry);

};


}


#endif // GELATINE_SPECIFICGEOMETRY_H
