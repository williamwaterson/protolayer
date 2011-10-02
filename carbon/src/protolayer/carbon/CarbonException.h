#ifndef PROTOLAYER_CARBON_CARBONEXCEPTION_H
#define PROTOLAYER_CARBON_CARBONEXCEPTION_H

#include <string>

namespace protolayer
{

namespace carbon
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class CarbonException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit CarbonException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit CarbonException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  CarbonException(const CarbonException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~CarbonException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  CarbonException& operator=(const CarbonException& exception);

};


}


}


#endif // PROTOLAYER_CARBON_CARBONEXCEPTION_H
