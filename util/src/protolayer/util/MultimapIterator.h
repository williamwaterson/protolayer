#ifndef PROTOLAYER_MULTIMAPITERATOR_H
#define PROTOLAYER_MULTIMAPITERATOR_H

#include <algorithm>
#include <multimap.h>

namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class KeyParam, class ValueParam> class MultimapIterator
{
public:
  /** TODO: Documentation */
  typedef KeyParam KeyType;

  /** TODO: Documentation */
  typedef ValueParam ValueType;

  /** TODO: Documentation */
  typedef std::multimap <KeyParam, ValueParam*> CollectionType;

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
  inline MultimapIterator()
  {
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline MultimapIterator(const MultimapIterator& multimapIterator)
  {
    _position = multimapIterator._position;
    _end = multimapIterator._end;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline explicit MultimapIterator(CollectionType& collection)
  {
    _position = collection.begin();
    _end = collection.end();
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline explicit MultimapIterator(CollectionType& collection,
                                   const KeyType& from)
  {
    _position = collection.find(from);
    _end = collection.end();
  }

  /**
   * TODO: Documentation
   *
   */
  inline ~MultimapIterator()
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
   * TODO: Documentation
   *
   */
  inline KeyType& nextKey()
  {
    KeyType* result = _position->first;
    ++_position;
    return *result;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline MultimapIterator& operator=(const MultimapIterator& iterator)
  {
    _position = iterator._position;
    _end = iterator._end;    
    return *this;
  }

};


}


}


#endif // PROTOLAYER_ITERATOR_H
