#ifndef PROTOLAYER_OBJECT_H
#define PROTOLAYER_OBJECT_H


#include <set.h>
#include <map.h>


namespace protolayer
{

namespace util
{

/**
 * TODO: Documentation
 * <p>
 */
class Object
{
private:
  /** TODO: Documentation */
  unsigned int _id;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  static Object* getObject(unsigned int id);

  /**
   * TODO: Documentation
   * <p>
   */
  Object();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Object() = 0;

  /**
   * TODO: Documentation
   * <p>
   */
  unsigned int getId();

  /**
   * TODO: Documentation
   * <p>
   */
  //  virtual std::string toString();

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


#endif // PROTOLAYER_OBJECT_H
