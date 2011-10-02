#include "HitModel.h"

namespace protolayer
{

namespace scenegraph
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
