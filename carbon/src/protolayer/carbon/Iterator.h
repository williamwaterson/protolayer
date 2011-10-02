#ifndef PROTOLAYER_CARBON_ITERATOR_H
#define PROTOLAYER_CARBON_ITERATOR_H

#include <set>
#include "forward.h"

namespace protolayer
{

namespace carbon
{

/**
 * TODO: Documentation
 * <p>
 */
template <class ItemParam>
class Iterator
{
  /** TODO: Documentation */
  typedef ItemParam ItemType;

  /** TODO: Documentation */
  typedef ::std::set <ItemParam*> StdSetType;

  /** TODO: Documentation */
  typedef typename StdSetType::iterator StdIteratorType;

  /** TODO: Documentation */
  StdIteratorType _position;
 
  /** TODO: Documentation */
  StdIteratorType _end;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  inline Iterator(StdSetType collection)
  {
    _position = collection.begin();
    _end = collection.end();
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline ~Iterator()
  {
  }

  /**
   *
   *
   */
  inline bool hasNext() const
  {
    return _position != _end;
  }

  /**
   *
   *
   */
  inline ItemType* next()
  {
    ItemType* item = *_position;
    ++_position;
    return item;
  }

};

}

}

#endif // PROTOLAYER_CARBON_ITERATOR_H
