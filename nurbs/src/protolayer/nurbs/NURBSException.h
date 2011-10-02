#ifndef PROTOLAYER_NURBSEXCEPTION_H
#define PROTOLAYER_NURBSEXCEPTION_H

#include <string>

namespace protolayer
{

namespace nurbs
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class NURBSException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit NURBSException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit NURBSException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NURBSException(const NURBSException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~NURBSException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  NURBSException& operator=(const NURBSException& exception);

};


}


}


#endif // PROTOLAYER_NURBSEXCEPTION_H
