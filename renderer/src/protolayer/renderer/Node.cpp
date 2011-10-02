#include "Node.h"


namespace protolayer
{

namespace renderer
{

unsigned int Node::_nextID = 1;


unsigned int Node::obtainID()
{
  return _nextID++;
}


Node::Node() : _isOwned(false), _isSelectable(true)
{
  _id = obtainID();
}


Node::Node(bool isSelectable) : _isOwned(false), _isSelectable(isSelectable)
{
  _id = obtainID();
}


Node::~Node()
{
  // releaseID(_id);
}


unsigned int Node::getID() const
{
  return _id;
}


void Node::setSelectable(bool flag)
{
  _isSelectable = flag;
}


bool Node::isSelectable() const
{
  return _isSelectable;
}


}


}
