#ifndef PROTOLAYER_EXCEPTION_H
#define PROTOLAYER_EXCEPTION_H

#include <string>

namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class Exception
{
private:
  /** TODO: Documentation */
  std::string _message;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  Exception();

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Exception(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Exception(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Exception(const Exception& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getMessage() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Exception();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Exception& operator=(const Exception& exception);

};


}


#endif // PROTOLAYER_EXCEPTION_H
