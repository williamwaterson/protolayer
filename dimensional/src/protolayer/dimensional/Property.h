#ifndef PROTOLAYER_DIMENSIONAL_PROPERTY_H
#define PROTOLAYER_DIMENSIONAL_PROPERTY_H

#include <string>

namespace protolayer
{

namespace dimensional
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Property
{
private:
  /** TODO: Documentation */
  std::string _message;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Property(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Property(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Property(const Property& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getMessage() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Property();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Property& operator=(const Property& exception);

};


}


}


#endif // PROTOLAYER_DIMENSIONAL_PROPERTY_H
