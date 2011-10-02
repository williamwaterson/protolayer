#include "GroupBox.h"

namespace protolayer
{

namespace carbon
{

Environment::Environment()
{
  _screenWidth = 1152;
  _screenHeight = 768;
}


Environment::~Environment()
{
}


short Environment::getScreenWidth()
{
  return _screenWidth;
}


short Environment::getScreenHeight()
{
  return _screenHeight;
}


}


}
