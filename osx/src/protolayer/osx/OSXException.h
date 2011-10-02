#ifndef PROTOLAYER_OSX_OSXEXCEPTION_H
#define PROTOLAYER_OSX_OSXEXCEPTION_H

#include <string>

namespace protolayer
{

namespace osx
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class OSXException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit OSXException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit OSXException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  OSXException(const OSXException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~OSXException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  OSXException& operator=(const OSXException& exception);

};


}


}


#endif // PROTOLAYER_OSX_OSXEXCEPTION_H
