#ifndef PROTOLAYER_RUNTIMETYPE_H
#define PROTOLAYER_RUNTIMETYPE_H


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class RuntimeType
{
public:
  enum type {BOOLEAN,
             INTEGER,
             DOUBLE,
             STRING,     
  };

private:
  /** TODO: Documentation */
  type _type;

  /** TODO: Documentation */
  void* _value;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  RuntimeType(float* localCoordinates, float* coordinates);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RuntimeType();

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
  RuntimeType(const RuntimeType& runtimeType);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RuntimeType& operator=(const RuntimeType& runtimeType);

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
