#ifndef PROTOLAYER_SERIALISER_H
#define PROTOLAYER_SERIALISER_H

#include <string>
#include <protolayer/protolayer-iostream.h>
#include "Exception.h"


namespace protolayer
{

namespace serialization
{

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.3 $
 */
template <class Type, class Protocol>
class Serialiser
{
public:
/**
 * TODO: Documentation
 * <p>
 */
static inline void encode(iostream::OutputStream& stream, const Type& instance)
{
  throw serialisation::Exception("Not implemented");
}

/**
 * TODO: Documentation
 * <p>
 */
static inline void decode(iostream::InputStream& stream, const Type& instance)
{
  throw serialisation::Exception("Not implemented");
}


};


}


}


#endif // PROTOLAYER_SERIALISATION_H
