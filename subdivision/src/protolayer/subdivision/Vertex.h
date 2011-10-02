#ifndef PROTOLAYER_SUBDIVISION_VERTEX_H
#define PROTOLAYER_SUBDIVISION_VERTEX_H


namespace protolayer
{

namespace subdivision
{

class Vertex
{
public:
  /** TODO: Documentation */
  bool _isCorner;

  /** TODO: Documentation */
  bool _isBoundary;

  /** TODO: Documentation */
  bool _isNonmanifold;

  /** TODO: Documentation */
  int _edgeCount;

  /** TODO: Documentation */
  int _faceCount;

  /** TODO: Documentation */
  int _petalCount;

  /** TODO: Documentation */
  int _flowerCount;

  /** TODO: Documentation */
  int _valency;

  /** TODO: Documentation */
  float _alpha;

  /** TODO: Documentation */
  float _beta;

  /** TODO: Documentation */
  float _gamma;

  /** TODO: Documentation */
  float _offset;

  /** TODO: Documentation */
  float _coordinates[4];

  /** TODO: Documentation */
  float _offsetCoordinates[4];

  /** TODO: Documentation */
  float _normal[4];

  /** TODO: Documentation */
  Vertex* _mapping;

public:
  /**
   * TODO: Documentation
   *
   */
  Vertex();

  /**
   * TODO: Documentation
   *
   */
  virtual ~Vertex();

  /**
   * TODO: Documentation
   *
   */
  float* getCoordinates();

  /**
   * TODO: Documentation
   *
   */
  bool isCorner() const;

  /**
   * TODO: Documentation
   *
   */
  void setCorner(bool flag);

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

  /**
   * TODO: Documentation
   *
   */
  int getPetalCount() const;

  /**
   * TODO: Documentation
   *
   */
  bool isBoundary() const;

  /**
   * TODO: Documentation
   *
   */
  bool isNonmanifold() const;

  /**
   * TODO: Documentation
   *
   */
  void setBoundary(bool flag);

  /**
   * TODO: Documentation
   *
   */
  void setMapping(Vertex& vertex);

  /**
   * TODO: Documentation
   *
   */
  Vertex* getMapping();

  /**
   * TODO: Documentation
   *
   */
  void evaluateOffset();

  /**
   * TODO: Documentation
   *
   */
  void setValency(int valency);

  /**
   * TODO: Documentation
   *
   */
  int getValency() const;

  /**
   * TODO: Documentation
   *
   */
  void incrementValency();

  /**
   * TODO: Documentation
   *
   */
  void decrementValency();

};


}


}


#endif // PROTOLAYER_SUBDIVISION_VERTEX_H
