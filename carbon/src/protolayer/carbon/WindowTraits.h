#ifndef PROTOLAYER_CARBON_WINDOWTRAITS_H
#define PROTOLAYER_CARBON_WINDOWTRAITS_H

#include <map>

#include "forward.h"
#include "Window.h"

namespace protolayer
{

namespace carbon
{

template <int WindowClassParam>
class WindowTraits
{
 public:
  enum { DefaultWindowAttributes = kWindowStandardDocumentAttributes |
         kWindowStandardHandlerAttribute };

};

}

}

#endif // PROTOLAYER_CARBON_WINDOWTRAITS_H
