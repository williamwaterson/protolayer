#ifndef PROTOLAYER_GLREP_OBJECT_H
#define PROTOLAYER_GLREP_OBJECT_H

#include <vector>

#include "protolayer/protolayer-scenegraph.h"
#include "protolayer/protolayer-util.h"


namespace protolayer
{

namespace glrep
{

/**
 * TODO: Documentation
 * <p>
 */
class Object
{
public:
  /** TODO: Documentation */
  typedef ::std::vector <scenegraph::Point*>::iterator PointIteratorType;

  /** TODO: Documentation */
  enum Type { Points,
	      Lines,
	      LineStrip,
	      LineLoop,
	      Triangles,
	      TriangleStrip,
	      TriangleFan,
	      Quads,
	      QuadStrip,
	      Polygon };  

private:
  /** TODO: Documentation */
  float _size;

  /** TODO: Documentation */
  Type _type;

  /** TODO: Documentation */
  ::std::vector <scenegraph::Point*> _points;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Object(Type type, float size);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Object();

  /**
   * TODO: Documentation
   * <p>
   */
  int getNumberPoints() const;

  /**
   * TODO: Documentation
   * <p>
   */
  float getSize() const;

  /**
   * TODO: Documentation
   * <p>
   */
  scenegraph::Point& getPoint(int index);

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
  void setType(Type type);

  /**
   * TODO: Documentation
   * <p>
   */
  void setSize(float size);

  /**
   * TODO: Documentation
   * <p>
   */
  Type getType() const;

  /**
   * TODO: Documentation
   * <p>
   */
  void addPoint(scenegraph::Point& point);

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
  Object(const Object& object);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Object& operator=(const Object& object);

};


}


}


#endif // PROTOLAYER_GLREP_OBJECT_H
