#ifndef PROTOLAYER_GELATINEOSXEXCEPTION_H
#define PROTOLAYER_GELATINEOSXEXCEPTION_H

#include <string>

namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class GelatineOSXException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit GelatineOSXException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit GelatineOSXException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GelatineOSXException(const GelatineOSXException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GelatineOSXException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GelatineOSXException& operator=(const GelatineOSXException& exception);

};


}


#endif // PROTOLAYER_GELATINEOSXEXCEPTION_H
