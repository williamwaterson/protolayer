#ifndef PROTOLAYER_RENDEREREXCEPTION_H
#define PROTOLAYER_RENDEREREXCEPTION_H

#include <string>

namespace gelatine
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
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


#endif // PROTOLAYER_RENDEREREXCEPTION_H
