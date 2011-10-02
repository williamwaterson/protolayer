#ifndef PROTOLAYER_GLREP_MODEL_H
#define PROTOLAYER_GLREP_MODEL_H

#include <set.h>

#include "protolayer/protolayer-util.h"

#include "Object.h"


namespace protolayer
{

namespace glrep
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Model
{
public:
  /** TODO: Documentation */
  typedef std::set <Object*>::iterator ObjectIteratorType;

private:
  /** TODO: Documentation */
  std::set <Object*> _objects;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Model();

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Model();

  /**
   * TODO: Documentation
   * <p>
   */
  void add(Object& object);

  /**
   * TODO: Documentation
   * <p>
   */
  void remove(Object& object);

  /**
   * TODO: Documentation
   * <p>
   */
  ObjectIteratorType getObjects();

  /**
   * TODO: Documentation
   * <p>
   */
  ObjectIteratorType getLastObject();

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Model(const Model& model);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Model& operator=(const Model& model);

};


}


}


#endif // PROTOLAYER_GLREP_MODEL_H
