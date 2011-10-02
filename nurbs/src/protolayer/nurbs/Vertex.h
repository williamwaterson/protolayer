#ifndef PROTOLAYER_VERTEX_H
#define PROTOLAYER_VERTEX_H

#include "protolayer/protolayer-util.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Vertex : public util::Point
{
private:
  /** TODO: Documentation */
  float _parametricCoordinates[2];

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Vertex();

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex(float x, float y, float z);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Vertex(float coordinates[3]);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Vertex();

  /**
   * TODO: Documentation
   * <p>
   */
  float* getParametricCoordinates();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Vertex(const Vertex& vertex);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Vertex& operator=(const Vertex& vertex);

};


}


}


#endif // PROTOLAYER_VERTEX_H
