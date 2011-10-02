#ifndef PROTOLAYEREXCEPTION_H
#define PROTOLAYEREXCEPTION_H

#include <string>

namespace protolayer
{

namespace renderer
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.2 $
 */
class RendererException
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit RendererException(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit RendererException(const ::std::string& message);

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RendererException(const RendererException& exception);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~RendererException();

  /**
   * Private and unimplemented to enforce reference semantics
   * <p>
   */  
  RendererException& operator=(const RendererException& exception);

};


}


}


#endif // PROTOLAYEREXCEPTION_H
