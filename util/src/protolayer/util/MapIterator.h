#ifndef PROTOLAYER_MAPITERATOR_H
#define PROTOLAYER_MAPITERATOR_H


#include <algorithm>
#include <map>


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class KeyParam, class ValueParam> class MapIterator
{
public:
  /** TODO: Documentation */
  typedef ValueParam ValueType;

  /** TODO: Documentation */
  typedef ::std::map < KeyParam, ValueParam* > CollectionType;

  /** TODO: Documentation */
  typedef typename CollectionType::iterator StdIteratorType;

private:
  /** TODO: Documentation */
  StdIteratorType _position;

  /** TODO: Documentation */
  StdIteratorType _end;

public:
  /**
   * TODO: Documentation
   *
   */
  inline MapIterator()
  {
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline MapIterator(const MapIterator& mapIterator)
  {
    _position = mapIterator._position;
    _end = mapIterator._end;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline explicit MapIterator(CollectionType& collection)
  {
    _position = collection.begin();
    _end = collection.end();
  }

  /**
   * TODO: Documentation
   *
   */
  inline ~MapIterator()
  {
  }

  /**
   * TODO: Documentation
   *
   */
  inline bool hasNext() const
  {
    return _position != _end;
  }

  /**
   * TODO: Documentation
   *
   */
  inline ValueType& next()
  {
    ValueType* result = _position->second;
    ++_position;
    return *result;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline MapIterator& operator=(const MapIterator& iterator)
  {
    _position = iterator._position;
    _end = iterator._end;    
    return *this;
  }

};


}


}


#endif // PROTOLAYER_ITERATOR_H
