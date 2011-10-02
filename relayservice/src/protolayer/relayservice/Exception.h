#ifndef PROTOLAYER_RELAYSERVICEEXCEPTION_H
#define PROTOLAYER_RELAYSERVICEEXCEPTION_H

#include <string>

#include <protolayer/protolayer.h>

namespace protolayer
{

namespace relayservice
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
class Exception : public ::protolayer::Exception
{
public:
  /**
   * TODO: Documentation
   * <p>
   */
  explicit Exception(const char* message);

  /**
   * TODO: Documentation
   * <p>
   */
  explicit Exception(const std::string& message);

  /**
   * TODO: Documentation
   * <p>
   */
  Exception(const Exception& ex);

  /**
   * TODO: Documentation
   * <p>
   */
  virtual ~Exception();

  /**
   * TODO: Documentation
   * <p>
   */
  Exception& operator=(const Exception& ex);

};


}


}


#endif // PROTOLAYER_RELAYSERVICEEXCEPTION_H
