#ifndef PROTOLAYER_EDGE_H
#define PROTOLAYER_EDGE_H

#include "Curve.h"
#include "HalfEdge.h"
#include "Vertex.h"

namespace protolayer
{

namespace nurbs
{

// Forward declarations
class Loop;


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Edge
{
  /** TODO: Documentation */
  friend class Loop;

  /** TODO: Documentation */
  Curve& _curve;

  /** TODO: Documentation */
  HalfEdge _firstHalfEdge;

  /** TODO: Documentation */
  HalfEdge _secondHalfEdge;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Edge(Curve& curve, Vertex& firstVertex, Vertex& secondVertex);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Edge();

  /**
   * TODO: Documentation
   * <p>
   */
  Curve& getCurve();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfEdge& getFirstHalfEdge();

  /**
   * TODO: Documentation
   * <p>
   */
  HalfEdge& getSecondHalfEdge();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Edge(const Edge& edge);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Edge& operator=(const Edge& edge);

};


}


}


#endif // PROTOLAYER_EDGE_H
