#ifndef PROTOLAYER_POINT_H
#define PROTOLAYER_POINT_H


namespace protolayer
{

namespace util
{


/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Point
{
  /** TODO: Documentation */
  float* _localCoordinates;

  /** TODO: Documentation */
  float* _coordinates;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Point(float* localCoordinates, float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Point();

  /**
   * TODO: Documentation
   * <p>
   */
  inline float* getLocalCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  inline float* getCoordinates();

  /**
   * TODO: Documentation
   * <p>
   */
  inline void setLocalCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  inline void setCoordinates(float coordinates[4]);

  /**
   * TODO: Documentation
   * <p>
   */
  inline void setLocalCoordinates(float x, float y, float z, float w);

  /**
   * TODO: Documentation
   * <p>
   */
  inline void setCoordinates(float x, float y, float z, float w);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Point(const Point& point);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Point& operator=(const Point& point);

};


float* Point::getLocalCoordinates()
{
  return _localCoordinates;
}


float* Point::getCoordinates()
{
  return _coordinates;
}


void Point::setLocalCoordinates(float coordinates[4])
{
  _localCoordinates[0] = coordinates[0];
  _localCoordinates[1] = coordinates[1];
  _localCoordinates[2] = coordinates[2];
  _localCoordinates[3] = coordinates[3];
}


void Point::setCoordinates(float coordinates[4])
{
  _coordinates[0] = coordinates[0];
  _coordinates[1] = coordinates[1];
  _coordinates[2] = coordinates[2];
  _coordinates[3] = coordinates[3];
}


void Point::setLocalCoordinates(float x, float y, float z, float w)
{
  _localCoordinates[0] = x;
  _localCoordinates[1] = y;
  _localCoordinates[2] = z;
  _localCoordinates[3] = w;
}


void Point::setCoordinates(float x, float y, float z, float w)
{
  _coordinates[0] = x;
  _coordinates[1] = y;
  _coordinates[2] = z;
  _coordinates[3] = w;
}


}


}


#endif // PROTOLAYER_POINT_H
