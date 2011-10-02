#ifndef PROTOLAYER_SETITERATOR_H
#define PROTOLAYER_SETITERATOR_H


#include <algorithm>
#include <set>


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class Param> class SetIterator
{
  /** TODO: Documentation */
  typedef Param Type;

  /** TODO: Documentation */
  typedef ::std::set <Param*> CollectionType;

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
  inline SetIterator()
  {
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline SetIterator(const SetIterator& setIterator)
  {
    _position = setIterator._position;
    _end = setIterator._end;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline explicit SetIterator(CollectionType& collection)
  {
    _position = collection.begin();
    _end = collection.end();
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline SetIterator(CollectionType& collection,
                     Type& from)
  {
    _end = collection.end();
    _position = find(collection.begin(), _end, &from);
  }

  /**
   * TODO: Documentation
   *
   */
  inline ~SetIterator()
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
    Type* result = *_position;
    ++_position;
    return *result;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline SetIterator& operator=(const SetIterator& iterator)
  {
    _position = iterator._position;
    _end = iterator._end;    
    return *this;
  }

};


}


}


#endif // PROTOLAYER_ITERATOR_H
