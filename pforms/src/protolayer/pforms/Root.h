#ifndef PROTOLAYER_ROOT_H
#define PROTOLAYER_ROOT_H

#include <string>

namespace protolayer
{

namespace pforms
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class Root
{
private:
  /** TODO: Documentation */
  std::string _message;

public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Root(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Root(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Root(const Root& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  const std::string& getMessage() const;

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Root();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  Root& operator=(const Root& exception);

};


}


}


#endif // PROTOLAYER_ROOT_H
