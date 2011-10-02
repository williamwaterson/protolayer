#include "SerialiseDoclet.h"


namespace protolayer
{

namespace cppdoclet
{


SerialiseDoclet::SerialiseDoclet(Dependencies& dependencies)
{
  _component = &(dependencies.getTargetComponent());

  precheck();
  process();
}


void SerialiseDoclet::precheck()
{
  if (!_component->containsAnnotation("@serialise")) {
    std::cout << "No match for annotation @serialise. Skipping..." << std::endl;
    return;
  }

  if (_component->containsMethodAnnotation("@serialise")) {
    throw "@serialise annotations are prohibited for methods";
  }
}


void SerialiseDoclet::process()
{
  process(_component->getTree());
}


void SerialiseDoclet::process(Namespace& instance)
{
  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = instance.getNamespaces().begin(); iter != instance.getNamespaces().end(); iter++) {
    Namespace& next = **iter;
    if (next.containsClasses()) {
      process(next);
    }
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = instance.getClasses().begin(); iter != instance.getClasses().end(); iter++) {
    Class& next = **iter;
    if (_component->getSignature() == next.getComponentName()) {
      process(next);
    }
  }
}


void SerialiseDoclet::process(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (!instance.containsAnnotation("@serialise")) {
    return;
  }

  typedef std::vector <Attribute*>::iterator AttributeIterType;

  if (instance.hasAnnotation("@serialise")) {
    processAll(instance);
    
  } else if (instance.containsAttributeAnnotation("@serialise")) {
    processSelective(instance);
  }
}


void SerialiseDoclet::processAll(Class& instance)
{
  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    process(instance, **iter);
  }
}


void SerialiseDoclet::processSelective(Class& instance)
{
  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    if ((*iter)->hasAnnotation("@serialise")) {
      process(instance, **iter);
    }
  }
}


void SerialiseDoclet::process(Class& instance, Attribute& attribute) {
}


}


}
