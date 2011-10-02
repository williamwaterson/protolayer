#ifndef PROTOLAYER_VECTORITERATOR_H
#define PROTOLAYER_VECTORITERATOR_H


#include <algorithm>
#include <vector>


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class Param> class VectorIterator
{
  /** TODO: Documentation */
  typedef Param Type;

  /** TODO: Documentation */
  typedef ::std::vector <Param*> CollectionType;

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
  inline VectorIterator()
  {
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline VectorIterator(const VectorIterator& vectorIterator)
  {
    _position = vectorIterator._position;
    _end = vectorIterator._end;
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline explicit VectorIterator(CollectionType& collection)
  {
    _position = collection.begin();
    _end = collection.end();
  }

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */
  inline VectorIterator(CollectionType& collection,
                     Type& from)
  {
    _end = collection.end();
    _position = find(collection.begin(), _end, &from);
  }

  /**
   * TODO: Documentation
   *
   */
  inline ~VectorIterator()
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
  inline VectorIterator& operator=(const VectorIterator& iterator)
  {
    _position = iterator._position;
    _end = iterator._end;    
    return *this;
  }

};


}


}


#endif // PROTOLAYER_ITERATOR_H
