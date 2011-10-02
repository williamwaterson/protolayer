#include "NonEmbeddingControl.h"


namespace protolayer
{

namespace carbon
{


NonEmbeddingControl::NonEmbeddingControl()
{
}


NonEmbeddingControl::NonEmbeddingControl(Control::Size size) :
  Control(size)
{
}


NonEmbeddingControl::NonEmbeddingControl(short x, short y, short w, short h) :
  Control(x, y, w, h)
{
}


NonEmbeddingControl::NonEmbeddingControl(Control::Size size,
                                         short x, short y, short w, short h) :
  Control(size, x, y, w, h)
{
}


NonEmbeddingControl::~NonEmbeddingControl()
{
}


}


}
