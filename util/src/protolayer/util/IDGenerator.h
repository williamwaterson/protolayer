#ifndef PROTOLAYER_IDGENERATOR_H
#define PROTOLAYER_IDGENERATOR_H


#include <set.h>


namespace protolayer
{

namespace util
{

/**
 * TODO: Documentation
 * <p>
 */
class IDGenerator
{
private:
  /** TODO: Documentation */
  std::set <int> _freeIDs;

  /** TODO: Documentation */
  int _nextID;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  static IDGenerator& getInstance();

  /**
   * TODO: Documentation
   * <p>
   */
  IDGenerator();

  /**
   * TODO: Documentation
   * <p>
   */
  int obtainID();

  /**
   * TODO: Documentation
   * <p>
   */
  void free(int id);

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  IDGenerator(const IDGenerator& idGenerator);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  IDGenerator& operator=(const IDGenerator& idGenerator);

};


}


}


#endif // PROTOLAYER_IDGENERATOR_H
