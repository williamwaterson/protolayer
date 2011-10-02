#include "PersistDoclet.h"


namespace protolayer
{

namespace cppdoclet
{

PersistDoclet::PersistDoclet(Dependencies& dependencies, const std::string& outputDir)
{
  Component& component = dependencies.getTargetComponent();

  if (!component.containsAnnotation("@persist")) {
    std::cout << "No match for annotation @persist. Skipping..." << std::endl;
    return;
  }

  if (component.containsMethodAnnotation("@persist")) {
    throw "@persist annotations are prohibited for methods";
  }

  _outputDir = outputDir;
  _component = &component;

  std::string macroName = "TEMP";

  _outputBuffer = "#ifndef " + macroName + "\n";
  _outputBuffer += "#define " + macroName + "\n\n";

  process(_component->getTree());

  _outputBuffer += "#endif\n";

  //_fileName = _outputDir + "/" + _className + "Persist";

  //  std::cout << _outputBuffer << std::endl;
}


void PersistDoclet::process(Namespace& instance)
{
  if (!_component->isRoot(instance)) {
    _outputBuffer += "namespace " + instance.getName() + "\n";
    _outputBuffer += "{\n";
  }

  typedef std::vector <Include*>::iterator IncludeIterType;
  for (IncludeIterType iter = instance.getIncludes().begin(); iter != instance.getIncludes().end(); iter++) {
    process(**iter);
  }
  _outputBuffer += "\n";

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = instance.getNamespaces().begin(); iter != instance.getNamespaces().end(); iter++) {
    process(**iter);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = instance.getClasses().begin(); iter != instance.getClasses().end(); iter++) {
    process(**iter);
  }

  if (!_component->isRoot(instance)) {
    _outputBuffer += "}\n\n\n";
  }
}


void PersistDoclet::process(Include& instance)
{
  _outputBuffer += instance.getSignature() + "\n";
}


void PersistDoclet::process(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (!instance.containsAnnotation("@persist")) {
    return;
  }

  _outputBuffer += "class " + instance.getName() + "Persist" + "\n";
  _outputBuffer += "{\n";

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    process(instance, **iter);
  }

  _outputBuffer += "};\n\n\n";
}


void PersistDoclet::process(Class& instance, Attribute& attribute)
{
  if (instance.hasAnnotation("@persist") && !instance.containsAttributeAnnotation("@persist")) {
    _outputBuffer += attribute.getVisibility() + ":\n";
    _outputBuffer += attribute.getSignature() + ";\n\n";
  } else if (attribute.hasAnnotation("@persist")) {
    _outputBuffer += attribute.getVisibility() + ":\n";
    _outputBuffer += attribute.getSignature() + ";\n\n";
  } 

}


}


}
