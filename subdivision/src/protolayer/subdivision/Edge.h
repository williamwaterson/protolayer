#ifndef PROTOLAYER_SUBDIVISION_EDGE_H
#define PROTOLAYER_SUBDIVISION_EDGE_H

#include <vector.h>

#include "Vertex.h"
#include "HalfEdge.h"


namespace protolayer
{

namespace subdivision
{

class Edge
{
private:
  /** TODO: Documentation */
  bool _isBoundary;

  /** TODO: Documentation */
  HalfEdge* _firstHalfEdge;

  /** TODO: Documentation */
  HalfEdge* _secondHalfEdge;

  /** TODO: Documentation */
  void* _object;

public:
  /**
   * TODO: Documentation
   *
   */
  Edge(std::vector <Vertex*>& vertices,
       int fromIndex,
       int toIndex);

  /**
   * TODO: Documentation
   *
   */
  Edge(Vertex& fromVertex,
       Vertex& toVertex);

  /**
   * TODO: Documentation
   *
   */
  bool isBoundary() const;

  /**
   * TODO: Documentation
   *
   */
  bool isNonmanifold();

  /**
   * TODO: Documentation
   *
   */
  void setBoundary(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void evaluateDirections();

  /**
   * TODO: Documentation
   *
   */
  HalfEdge& getFirstHalf();

  /**
   * TODO: Documentation
   *
   */
  HalfEdge& getSecondHalf();

  /**
   * TODO: Documentation
   *
   */
  HalfEdge* getOtherHalf(HalfEdge& halfEdge);

  /**
   * TODO: Documentation
   *
   */
  bool isSimilar(const Vertex& first, const Vertex& second) const;

  /**
   * TODO: Documentation
   *
   */
  int getFaceCount();

};


}


}


#endif // PROTOLAYER_SUBDIVISION_EDGE_H
