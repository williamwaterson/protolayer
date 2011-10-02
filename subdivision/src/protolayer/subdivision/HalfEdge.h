#ifndef PROTOLAYER_SUBDIVISION_HALFEDGE_H
#define PROTOLAYER_SUBDIVISION_HALFEDGE_H

#include <stdio.h>
#include <map.h>

#include "Vertex.h"


namespace protolayer
{

namespace subdivision
{

class HalfEdge
{
public:
  /** TODO: Documentation */
  int _faceCount;

  /** TODO: Documentation */
  bool _isBoundary;

  /** TODO: Documentation */
  Vertex* _midpoint;

  /** TODO: Documentation */
  Vertex* _fromVertex;

  /** TODO: Documentation */
  Vertex* _toVertex;

  /** TODO: Documentation */
  float _direction[4];

  /** TODO: Documentation */
  void* _object;

public:
  /**
   * TODO: Documentation
   *
   */
  HalfEdge(Vertex& fromVertex,
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
  void setBoundary(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setMidpoint(Vertex& midpoint);

  /**
   * TODO: Documentation
   *
   */
  Vertex* getMidpoint();

  /**
   * TODO: Documentation
   *
   */
  Vertex& getFromVertex();

  /**
   * TODO: Documentation
   *
   */
  Vertex& getToVertex();

  /**
   * TODO: Documentation
   *
   */
  bool isFrom(const Vertex& vertex) const;

  /**
   * TODO: Documentation
   *
   */
  bool isTo(const Vertex& vertex) const;

  /**
   * TODO: Documentation
   *
   */
  bool isEquivalent(const Vertex& first,
                    const Vertex& second) const;

  /**
   * TODO: Documentation
   *
   */
  void setObject(void* object);

  /**
   * TODO: Documentation
   *
   */
  void incrementFaceCount();

  /**
   * TODO: Documentation
   *
   */
  void decrementFaceCount();

  /**
   * TODO: Documentation
   *
   */
  int getFaceCount() const;

};


}


}


#endif // PROTOLAYER_GEOMETRY_SPHERE_H
