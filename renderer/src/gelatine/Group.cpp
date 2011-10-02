#include "Group.h"


namespace gelatine
{

namespace
{

  float UNIT_QUATERNION[4][4] =
  { {  1,  0,  0 , 0 },
    {  0,  1,  0 , 0 },
    {  0,  0,  1 , 0 },
    {  0,  0,  0 , 1 } };

}


Group::Group() : Node(true)
{
  _multiplier = UNIT_QUATERNION;

  _localTransform[0][0] = 1;
  _localTransform[0][1] = 0;
  _localTransform[0][2] = 0;
  _localTransform[0][3] = 0;

  _localTransform[1][0] = 0;
  _localTransform[1][1] = 1;
  _localTransform[1][2] = 0;
  _localTransform[1][3] = 0;

  _localTransform[2][0] = 0;
  _localTransform[2][1] = 0;
  _localTransform[2][2] = 1;
  _localTransform[2][3] = 0;

  _localTransform[3][0] = 0;
  _localTransform[3][1] = 0;
  _localTransform[3][2] = 0;
  _localTransform[3][3] = 1;

  _globalTransform[0][0] = 1;
  _globalTransform[0][1] = 0;
  _globalTransform[0][2] = 0;
  _globalTransform[0][3] = 0;

  _globalTransform[1][0] = 0;
  _globalTransform[1][1] = 1;
  _globalTransform[1][2] = 0;
  _globalTransform[1][3] = 0;

  _globalTransform[2][0] = 0;
  _globalTransform[2][1] = 0;
  _globalTransform[2][2] = 1;
  _globalTransform[2][3] = 0;

  _globalTransform[3][0] = 0;
  _globalTransform[3][1] = 0;
  _globalTransform[3][2] = 0;
  _globalTransform[3][3] = 1;
}


Group::~Group()
{
}


void Group::addChild(Group& group)
{
  Node& node = group;
  if (node._isOwned) {
    return;
  }

  _childGroups.insert(&group);
  _childGroupsRenderOrder.push_back(&group);
  _nodeNameMap.insert(std::map <int, Node*>::value_type(group.getID(), &group));
  node._isOwned = true;

  update();
}


Node* Group::getNodeForName(unsigned name)
{
  if (_nodeNameMap.count(name) != 0) {
    return _nodeNameMap[name]; 
  }

  GroupIteratorType groupIter;
  GroupIteratorType groupEnd = getLastGroup();
  Node* node;
  for(groupIter = getChildGroups(); groupIter != groupEnd; ++groupIter) {
    node = (*groupIter)->getNodeForName(name);
    if (node != 0) {
      return node;
    }
  }

  return 0;
}


void Group::addChild(Leaf& leaf)
{
  Node& node = leaf;
  if (node._isOwned) {
    return;
  }

  _childLeaves.insert(&leaf);
  _childLeavesRenderOrder.push_back(&leaf);
  _nodeNameMap.insert(std::map <int, Node*>::value_type(leaf.getID(), &leaf));
  node._isOwned = true;

  update();
}


Group::GroupIteratorType Group::getChildGroups()
{
  return _childGroups.begin();
}


Group::GroupIteratorType Group::getLastGroup()
{
  return _childGroups.end();
}


Group::LeafIteratorType Group::getChildLeaves()
{
  return _childLeaves.begin();
}


Group::LeafIteratorType Group::getLastLeaf()
{
  return _childLeaves.end();
}


void Group::removeChild(Group& group)
{
  if (_childGroups.erase(&group) != 0) {    
    GroupVectorIteratorType iter =
      std::find(_childGroupsRenderOrder.begin(),
                _childGroupsRenderOrder.end(),
                &group);
    _childGroupsRenderOrder.erase(iter);

    Node& node = group;
    node._isOwned = false;
  }
}


void Group::removeChild(Leaf& leaf)
{
  if (_childLeaves.erase(&leaf) != 0) {
    LeafVectorIteratorType iter =
      std::find(_childLeavesRenderOrder.begin(),
                _childLeavesRenderOrder.end(),
                &leaf);
    _childLeavesRenderOrder.erase(iter);

    Node& node = leaf;
    node._isOwned = false;
  }
}


void Group::clearChildren()
{
  GroupIteratorType groupIter;
  GroupIteratorType groupEnd = getLastGroup();
  for(groupIter = getChildGroups(); groupIter != groupEnd; ++groupIter) {
    Node& node = **groupIter;
    node._isOwned = false;    
  }

  LeafIteratorType leafIter;
  LeafIteratorType leafEnd = getLastLeaf();
  for(leafIter = getChildLeaves(); leafIter != leafEnd; ++leafIter) {
    Node& node = **leafIter;
    node._isOwned = false;    
  }

  _childGroups.clear();
  _childLeaves.clear();
}


void Group::update(float quaternion[4][4])
{
  _multiplier = quaternion;
  update();
}


void Group::update()
{
  _globalTransform[0][0] =  _multiplier[0][0] * _localTransform[0][0];
  _globalTransform[0][0] += _multiplier[0][1] * _localTransform[1][0];
  _globalTransform[0][0] += _multiplier[0][2] * _localTransform[2][0];
  _globalTransform[0][0] += _multiplier[0][3] * _localTransform[3][0];

  _globalTransform[0][1] =  _multiplier[0][0] * _localTransform[0][1];
  _globalTransform[0][1] += _multiplier[0][1] * _localTransform[1][1];
  _globalTransform[0][1] += _multiplier[0][2] * _localTransform[2][1];
  _globalTransform[0][1] += _multiplier[0][3] * _localTransform[3][1];

  _globalTransform[0][2] =  _multiplier[0][0] * _localTransform[0][2];
  _globalTransform[0][2] += _multiplier[0][1] * _localTransform[1][2];
  _globalTransform[0][2] += _multiplier[0][2] * _localTransform[2][2];
  _globalTransform[0][2] += _multiplier[0][3] * _localTransform[3][2];

  _globalTransform[0][3] =  _multiplier[0][0] * _localTransform[0][3];
  _globalTransform[0][3] += _multiplier[0][1] * _localTransform[1][3];
  _globalTransform[0][3] += _multiplier[0][2] * _localTransform[2][3];
  _globalTransform[0][3] += _multiplier[0][3] * _localTransform[3][3];

  _globalTransform[1][0] =  _multiplier[1][0] * _localTransform[0][0];
  _globalTransform[1][0] += _multiplier[1][1] * _localTransform[1][0];
  _globalTransform[1][0] += _multiplier[1][2] * _localTransform[2][0];
  _globalTransform[1][0] += _multiplier[1][3] * _localTransform[3][0];

  _globalTransform[1][1] =  _multiplier[1][0] * _localTransform[0][1];
  _globalTransform[1][1] += _multiplier[1][1] * _localTransform[1][1];
  _globalTransform[1][1] += _multiplier[1][2] * _localTransform[2][1];
  _globalTransform[1][1] += _multiplier[1][3] * _localTransform[3][1];

  _globalTransform[1][2] =  _multiplier[1][0] * _localTransform[0][2];
  _globalTransform[1][2] += _multiplier[1][1] * _localTransform[1][2];
  _globalTransform[1][2] += _multiplier[1][2] * _localTransform[2][2];
  _globalTransform[1][2] += _multiplier[1][3] * _localTransform[3][2];

  _globalTransform[1][3] =  _multiplier[1][0] * _localTransform[0][3];
  _globalTransform[1][3] += _multiplier[1][1] * _localTransform[1][3];
  _globalTransform[1][3] += _multiplier[1][2] * _localTransform[2][3];
  _globalTransform[1][3] += _multiplier[1][3] * _localTransform[3][3];


  _globalTransform[2][0] =  _multiplier[2][0] * _localTransform[0][0];
  _globalTransform[2][0] += _multiplier[2][1] * _localTransform[1][0];
  _globalTransform[2][0] += _multiplier[2][2] * _localTransform[2][0];
  _globalTransform[2][0] += _multiplier[2][3] * _localTransform[3][0];

  _globalTransform[2][1] =  _multiplier[2][0] * _localTransform[0][1];
  _globalTransform[2][1] += _multiplier[2][1] * _localTransform[1][1];
  _globalTransform[2][1] += _multiplier[2][2] * _localTransform[2][1];
  _globalTransform[2][1] += _multiplier[2][3] * _localTransform[3][1];

  _globalTransform[2][2] =  _multiplier[2][0] * _localTransform[0][2];
  _globalTransform[2][2] += _multiplier[2][1] * _localTransform[1][2];
  _globalTransform[2][2] += _multiplier[2][2] * _localTransform[2][2];
  _globalTransform[2][2] += _multiplier[2][3] * _localTransform[3][2];

  _globalTransform[2][3] =  _multiplier[2][0] * _localTransform[0][3];
  _globalTransform[2][3] += _multiplier[2][1] * _localTransform[1][3];
  _globalTransform[2][3] += _multiplier[2][2] * _localTransform[2][3];
  _globalTransform[2][3] += _multiplier[2][3] * _localTransform[3][3];


  _globalTransform[3][0] =  _multiplier[3][0] * _localTransform[0][0];
  _globalTransform[3][0] += _multiplier[3][1] * _localTransform[1][0];
  _globalTransform[3][0] += _multiplier[3][2] * _localTransform[2][0];
  _globalTransform[3][0] += _multiplier[3][3] * _localTransform[3][0];

  _globalTransform[3][1] =  _multiplier[3][0] * _localTransform[0][1];
  _globalTransform[3][1] += _multiplier[3][1] * _localTransform[1][1];
  _globalTransform[3][1] += _multiplier[3][2] * _localTransform[2][1];
  _globalTransform[3][1] += _multiplier[3][3] * _localTransform[3][1];

  _globalTransform[3][2] =  _multiplier[3][0] * _localTransform[0][2];
  _globalTransform[3][2] += _multiplier[3][1] * _localTransform[1][2];
  _globalTransform[3][2] += _multiplier[3][2] * _localTransform[2][2];
  _globalTransform[3][2] += _multiplier[3][3] * _localTransform[3][2];

  _globalTransform[3][3] =  _multiplier[3][0] * _localTransform[0][3];
  _globalTransform[3][3] += _multiplier[3][1] * _localTransform[1][3];
  _globalTransform[3][3] += _multiplier[3][2] * _localTransform[2][3];
  _globalTransform[3][3] += _multiplier[3][3] * _localTransform[3][3];

  typedef GroupIteratorType GIType;
  for(GIType iter = getChildGroups(); iter != getLastGroup(); ++iter) {
    (*iter)->update(_globalTransform);
  }

  typedef LeafIteratorType LIType;
  for(LIType iter = getChildLeaves(); iter != getLastLeaf(); ++iter) {
    (*iter)->update(_globalTransform);
  }

}


void Group::render(float alpha)
{
  // Render all groups in this scene
  typedef std::vector <Group*>::iterator GroupIterType;
  for(GroupIterType iter = _childGroupsRenderOrder.begin(); iter != _childGroupsRenderOrder.end(); ++iter) {
    (*iter)->render(alpha);
  }

  // Render all leafs in this group
  typedef std::vector <Leaf*>::iterator LeafIterType;
  for(LeafIterType iter = _childLeavesRenderOrder.begin(); iter != _childLeavesRenderOrder.end(); ++iter) {
    (*iter)->render(alpha);
  }
}


void Group::renderInSelectionMode(float alpha)
{
  if (isSelectable()) {
    glPushName(getID());

    // Render all groups in this scene
    typedef std::vector <Group*>::iterator GroupIterType;
    for(GroupIterType iter = _childGroupsRenderOrder.begin(); iter != _childGroupsRenderOrder.end(); ++iter) {
      (*iter)->renderInSelectionMode(alpha);
    }

    // Render all leafs in this group
    typedef std::vector <Leaf*>::iterator LeafIterType;
    for(LeafIterType iter = _childLeavesRenderOrder.begin(); iter != _childLeavesRenderOrder.end(); ++iter) {
      (*iter)->renderInSelectionMode(alpha);
    }

    glPopName();
  }

}


void Group::compile(std::set <Shape*>& shapes)
{
  GroupIteratorType groupIter;
  GroupIteratorType groupEnd = getLastGroup();
  for(groupIter = getChildGroups(); groupIter != groupEnd; ++groupIter) {
    (*groupIter)->compile(shapes);
  }

  Leaf* leaf = 0;
  Shape* shape = 0;
  LeafIteratorType leafIter;
  LeafIteratorType leafEnd = getLastLeaf();
  for(leafIter = getChildLeaves(); leafIter != leafEnd; ++leafIter) {
    leaf = *leafIter;
    if (typeid(*leaf) == typeid(Shape)) {
      shape = dynamic_cast <Shape*> (leaf);
      shapes.insert(shape);
    }
  }
}


Group* Group::getParent(Group& group)
{
  if (_childGroups.count(&group) != 0) {
    return this;
  } else {
    GroupIteratorType groupIter;
    GroupIteratorType groupEnd = getLastGroup();
    for(groupIter = getChildGroups(); groupIter != groupEnd; ++groupIter) {
      Group* tg = (*groupIter)->getParent(group);
      if (tg != 0) {
        return tg;
      }
    }
  }

  return 0;
}


Group* Group::getParent(Leaf& leaf)
{
  if (_childLeaves.count(&leaf) != 0) {
    return this;
  } else {
    GroupIteratorType groupIter;
    GroupIteratorType groupEnd = getLastGroup();
    for(groupIter = getChildGroups(); groupIter != groupEnd; ++groupIter) {
      Group* tg = (*groupIter)->getParent(leaf);
      if (tg != 0) {
        return tg;
      }
    }
  }

  return 0;
}



void Group::triggerHitListeners()
{
  typedef GroupIteratorType GIType;
  for(GIType iter = getChildGroups(); iter != getLastGroup(); ++iter) {
    (**iter).triggerHitListeners();
  }

  typedef LeafIteratorType LIType;
  for(LIType iter = getChildLeaves(); iter != getLastLeaf(); ++iter) {
    (**iter).triggerHitListeners();
  }

  Node::triggerHitListeners();
}


void
Group::getLocalTransform(float matrix[4][4]) const
{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = _localTransform[i][j];
    }
  }
}


void
Group::setLocalTransform(float matrix[4][4])
{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      _localTransform[i][j] = matrix[i][j];
    }
  }

  update();
}


void
Group::getGlobalTransform(float matrix[4][4]) const
{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = _globalTransform[i][j];
    }
  }
}


void
Group::rotateX(float angle)
{
  _localTransform[0][0] = 1;
  _localTransform[0][1] = 0;
  _localTransform[0][2] = 0;

  _localTransform[1][0] = 0;
  _localTransform[1][1] = cos(angle);
  _localTransform[1][2] = -sin(angle);

  _localTransform[2][0] = 0;
  _localTransform[2][1] = sin(angle);
  _localTransform[2][2] = cos(angle);

  update();
}


void
Group::rotateY(float angle)
{
  _localTransform[0][0] = cos(angle);
  _localTransform[0][1] = 0;
  _localTransform[0][2] = -sin(angle);

  _localTransform[1][0] = 0;
  _localTransform[1][1] = 1;
  _localTransform[1][2] = 0;

  _localTransform[2][0] = sin(angle);
  _localTransform[2][1] = 0;
  _localTransform[2][2] = cos(angle);

  update();
}


void
Group::rotateZ(float angle)
{
  _localTransform[0][0] = cos(angle);
  _localTransform[0][1] = -sin(angle);
  _localTransform[0][2] = 0;

  _localTransform[1][0] = sin(angle);
  _localTransform[1][1] = cos(angle);
  _localTransform[1][2] = 0;

  _localTransform[2][0] = 0;
  _localTransform[2][1] = 0;
  _localTransform[2][2] = 1;

  update();
}


void
Group::rotate(float angle, float axis[3])
{
  float x = axis[0];
  float y = axis[1];
  float z = axis[2];

  _localTransform[0][0] = 1 + (1-cos(angle))*(x*x-1);
  _localTransform[0][1] = -z*sin(angle)+(1-cos(angle))*x*y;
  _localTransform[0][2] = y*sin(angle)+(1-cos(angle))*x*z;

  _localTransform[1][0] = z*sin(angle)+(1-cos(angle))*x*y;
  _localTransform[1][1] = 1 + (1-cos(angle))*(y*y-1);
  _localTransform[1][2] = -x*sin(angle)+(1-cos(angle))*y*z;

  _localTransform[2][0] = -y*sin(angle)+(1-cos(angle))*x*z;
  _localTransform[2][1] = x*sin(angle)+(1-cos(angle))*y*z;
  _localTransform[2][2] = 1 + (1-cos(angle))*(z*z-1);

  update();
}


void
Group::displace(float x, float y, float z)
{
  _localTransform[0][3] += x;
  _localTransform[1][3] += y;
  _localTransform[2][3] += z;
  update();
}


void
Group::translate(float x, float y, float z)
{
  _localTransform[0][3] = x;
  _localTransform[1][3] = y;
  _localTransform[2][3] = z;
  update();
}


bool Group::isPart(Leaf& leaf)
{
  if (_childLeaves.count(&leaf) != 0) {
    return true;
  } else {
    GroupIteratorType groupIter;
    GroupIteratorType groupEnd = getLastGroup();
    for(groupIter = getChildGroups(); groupIter != groupEnd; ++groupIter) {
      if ((*groupIter)->isPart(leaf)) {
        return true;
      }
    }
  }

  return false;
}


void
Group::scale(float factor)
{
  _localTransform[3][3] = factor;
  update();
}


}
