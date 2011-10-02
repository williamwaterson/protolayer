#include "InstanceNode.h"


namespace protolayer
{

namespace proto
{

  /** TODO: Documentation */
  //  xercesc::DOMImplementation* _implementation;

  /** TODO: Documentation */
  //  xercesc::DOMDocument* _document;

  //  _xulCarbonRoot = new protolayer::xulcarbon::Root("gui-descriptor.xml");
  //  if (_xulCarbonRoot != 0) {
  //    std::string id("node-technique-dialog");
  //    if (_xulCarbonRoot->getXULRoot().countDialogs(id) == 1) {
  //      typedef protolayer::xulcarbon::Root::DialogIteratorType DIType;
  //      DIType iter = _xulCarbonRoot->getDialog(id);
  //      _techniqueDialog = &(iter.next());
  //    }
  //  }


InstanceNode::InstanceNode(float x, float y, float z,
                             style::Appearance& edgeAppearance,
                             style::Appearance& faceAppearance) :
  //			     assembly::Instance& instance) :
  geometry::QuadSphere(0.5f, 3, edgeAppearance, faceAppearance)
  //  geometry::Sphere(0.5f, 3, edgeAppearance, faceAppearance)
{
  translate(x, y, z);
  update();

  _offset[0] = 0;
  _offset[1] = 0;
  _offset[2] = 0;

  setSelectable(true);
  //  _techniqueDialog = 0;

  //  _instance = instance;
}


InstanceNode::InstanceNode(assembly::Instance& instance,
                             float x, float y, float z,
                             style::Appearance& edgeAppearance,
                             style::Appearance& faceAppearance) :  
  geometry::QuadSphere(0.5f, 3, edgeAppearance, faceAppearance)
  //geometry::Sphere(0.5f, 3, edgeAppearance, faceAppearance)
{
  _instance = &instance;

  translate(x, y, z);
  update();

  _offset[0] = 0;
  _offset[1] = 0;
  _offset[2] = 0;

  setSelectable(true);
  //  _techniqueDialog = 0;
}


assembly::Instance& InstanceNode::getInstance()
{
  return *_instance;
}


void
InstanceNode::setOffset(float x, float y, float z)
{
  _offset[0] = x;
  _offset[1] = y;
  _offset[2] = z;
}


const float*
InstanceNode::getOffset() const
{
  return _offset;
}


//protolayer::xulcarbon::Dialog* InstanceNode::getTechniqueDialog()
//{
//  return _techniqueDialog;
//}


//void InstanceNode::setTechniqueDialog(xercesc::DOMElement& element)
//{
//  if (_techniqueDialog != 0) {
//  }
//}


}


}
