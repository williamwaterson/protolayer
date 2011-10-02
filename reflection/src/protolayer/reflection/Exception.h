#ifndef PROTOLAYER_ONTOLOGYDTO_EXCEPTION_H
#define PROTOLAYER_ONTOLOGYDTO_EXCEPTION_H

#include <string>

#include <protolayer/protolayer.h>

namespace protolayer
{

namespace ontologydto
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


#endif // PROTOLAYER_ONTOLOGYEXCEPTION_H
