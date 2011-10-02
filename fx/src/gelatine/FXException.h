#ifndef PROTOLAYER_FXEXCEPTION_H
#define PROTOLAYER_FXEXCEPTION_H

#include <string>

namespace protolayer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class FXException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit FXException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit FXException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FXException(const FXException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~FXException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  FXException& operator=(const FXException& exception);

};


}


#endif // PROTOLAYER_FXEXCEPTION_H
