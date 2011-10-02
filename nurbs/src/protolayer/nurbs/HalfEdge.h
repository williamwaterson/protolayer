#ifndef PROTOLAYER_EDGEUSE_H
#define PROTOLAYER_EDGEUSE_H

#include "Vertex.h"

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class HalfEdge
{
  /** TODO: Documentation */
  Vertex& _fromVertex;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  HalfEdge(Vertex& fromVertex);

  /**
   * TODO: Documentation
   * <p>
   */
  ~HalfEdge();

  /**
   * TODO: Documentation
   * <p>
   */
  Vertex& getFromVertex();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HalfEdge(const HalfEdge& edgeUse);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  HalfEdge& operator=(const HalfEdge& edgeUse);

};


}


}


#endif // PROTOLAYER_EDGEUSE_H
