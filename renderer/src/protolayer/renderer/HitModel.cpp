#include "HitModel.h"

namespace protolayer
{

namespace renderer
{

HitModel::HitModel() :
  _node(0)
{
}


HitModel::~HitModel()
{
}


Node* HitModel::getHit()
{
  return _node;
}


void HitModel::mouseHit(Node* node)
{
  _node = node;
}


}


}
