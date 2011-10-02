#ifndef PROTOLAYER_INSTANCEDEPENDENCY_H
#define PROTOLAYER_INSTANCEDEPENDENCY_H

#include <protolayer/protolayer-util.h>

#include "Instance.h"

namespace protolayer
{

namespace assembly
{

/** Explicitly instantiated within associated source file */
typedef util::Dependency <Instance> InstanceDependency;


}


}


#endif // PROTOLAYER_INSTANCEDEPENDENCY_H
