#ifndef PROTOLAYER_DEPENDENCY_H
#define PROTOLAYER_DEPENDENCY_H


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class Param> class Dependency
{
public:
  /** TODO: Documentation */
  typedef Param Type;

private:
  /** TODO: Documentation */
  bool _tagFlag;

  /** TODO: Documentation */
  Param& _from;

  /** TODO: Documentation */
  Param& _to;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  inline Dependency(Param& from, Param& to) :
    _from(from), _to(to)
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline ~Dependency()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline Param& getFrom()
  {
    return _from;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline Param& getTo()
  {
    return _to;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline bool isFrom(Param& instance)
  {
    return &_from == &instance;;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  inline bool isTo(Param& instance)
  {
    return &_to == &instance;;
  }

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Dependency(const Dependency& dependency);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Dependency& operator=(const Dependency& dependency);

};


}


}


#endif // PROTOLAYER_DEPENDENCY_H
