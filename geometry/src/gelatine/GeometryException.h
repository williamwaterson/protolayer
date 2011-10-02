#ifndef PROTOLAYER_GEOMETRYEXCEPTION_H
#define PROTOLAYER_GEOMETRYEXCEPTION_H

#include <string>

namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
class GeometryException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit GeometryException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit GeometryException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GeometryException(const GeometryException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~GeometryException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  GeometryException& operator=(const GeometryException& exception);

};


}


#endif // PROTOLAYER_GEOMETRYEXCEPTION_H
