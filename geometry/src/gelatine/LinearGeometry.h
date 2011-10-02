#ifndef GELATINE_LINEARGEOMETRY_H
#define GELATINE_LINEARGEOMETRY_H

#include <OpenGL/gl.h>
#include "gelatine/gelatine-renderer.h"

namespace gelatine
{

/**
 * TODO: Documentation
 * <p>
 */
class LinearGeometry : public Geometry
{
  /** TODO: Documentation */
  float* _register;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  LinearGeometry();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~LinearGeometry() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual int getNumberEdges() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual int getNumberTriangles() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual int getNumberQuads() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual float*** getEdges() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual float*** getTriangles() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual float*** getQuads() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  void render(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderEdges(float alpha, Appearance& appearance);

  /**
   * TODO: Documentation
   * <p>
   */
  void renderFaces(float alpha, Appearance& appearance);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  LinearGeometry(const LinearGeometry& geometry);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  LinearGeometry& operator=(const LinearGeometry& geometry);

};


}


#endif // GELATINE_LINEARGEOMETRY_H
