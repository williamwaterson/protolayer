#ifndef PROTOLAYER_XMLEXCEPTION_H
#define PROTOLAYER_XMLEXCEPTION_H

#include <string>

namespace protolayer
{

namespace xml
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class XMLException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit XMLException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit XMLException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  XMLException(const XMLException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~XMLException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  XMLException& operator=(const XMLException& exception);

};


}


}


#endif // PROTOLAYER_XMLEXCEPTION_H
