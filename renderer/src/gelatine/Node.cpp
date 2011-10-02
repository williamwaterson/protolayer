#include "Node.h"


namespace gelatine
{


unsigned int Node::_nextID = 1;


template class HitListener <Node>;


unsigned int Node::obtainID()
{
  return _nextID++;
}


  //void Node::releaseID(unsigned int id)
  //{
  //}


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


void Node::addHitListener(HitListener <Node>& listener)
{
  _hitListeners.insert(&listener);
}


void Node::removeHitListener(HitListener <Node>& listener)
{
  _hitListeners.erase(&listener);
}


void Node::clearHitListeners()
{
  _hitListeners.clear();
}


void Node::triggerHitListeners()
{
  typedef std::set <HitListenerType*>::iterator HLIType;
  for (HLIType iter = _hitListeners.begin(); iter != _hitListeners.end(); ++iter) {
    (**iter).mouseHit(*this);
  }
}


}
