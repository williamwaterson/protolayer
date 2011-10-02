#ifndef PROTOLAYER_ITERATOR_H
#define PROTOLAYER_ITERATOR_H


#include <algorithm>


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class CollectionParam> class Iterator
{
  /** TODO: Documentation */
  typedef CollectionParam CollectionType;

  /** TODO: Documentation */
  typedef typename CollectionParam::iterator StdIteratorType;

  /** TODO: Documentation */
  typedef typename StdIteratorType::value_type Type;

  /** TODO: Documentation */
  typedef typename StdIteratorType::pointer PointerType;

  /** TODO: Documentation */
  typedef typename StdIteratorType::reference ReferenceType;

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
  inline Iterator()
  {
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline Iterator(const Iterator& iterator)
  {
    _position = iterator._position;
    _end = iterator._end;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline explicit Iterator(CollectionParam& collection)
  {
    _position = collection.begin();
    _end = collection.end();
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline Iterator(CollectionParam& collection,
                  Type& from)
  {
    _end = collection.end();
    _position = find(collection.begin(), _end, from);
  }

  /**
   * TODO: Documentation
   *
   */
  inline ~Iterator()
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
  inline Type& next()
  {
    return *(*_position++);
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline Iterator& operator=(const Iterator& iterator)
  {
    _position = iterator._position;
    _end = iterator._end;    
    return *this;
  }

};


}


}


#endif // PROTOLAYER_ITERATOR_H
