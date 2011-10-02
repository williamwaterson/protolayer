#ifndef PROTOLAYER_ABSTRACTFACTORY_H
#define PROTOLAYER_ABSTRACTFACTORY_H


namespace protolayer
{

namespace util
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
template <class Param> class AbstractFactory
{
public:
  /** TODO: Documentation */
  typedef Param Type;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  AbstractFactory()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~AbstractFactory()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  virtual Type* create(float* arg1, float* arg2) = 0;

private:
  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  AbstractFactory(const AbstractFactory& abstractFactory);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  AbstractFactory& operator=(const AbstractFactory& abstractFactory);

};


}


}


#endif // PROTOLAYER_ABSTRACTFACTORY_H
