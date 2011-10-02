#ifndef PROTOLAYER_PROTO_EXCEPTION_H
#define PROTOLAYER_ONLOAY_EXCEPTION_H

#include <string>

namespace protolayer
{

namespace proto
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Exception
{
public:
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
  virtual ~Exception();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Exception& operator=(const Exception& exception);

};


}


}


#endif // PROTOLAYER_PROTO_EXCEPTION_H
