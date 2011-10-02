#include "PrototypeDoclet.h"


namespace protolayer
{

namespace cppdoclet
{


PrototypeDoclet::PrototypeDoclet(Dependencies& dependencies, const std::string& outputDir)
{
  Component& component = dependencies.getTargetComponent();

  if (!component.containsAnnotation("@prototype")) {
    std::cout << "No match for annotation @prototype. Skipping..." << std::endl;
    return;
  }

  if (component.containsMethodAnnotation("@prototype")) {
    throw "@prototype annotations are prohibited for methods";
  }

  _outputDir = outputDir;
  _component = &component;

  std::string macroName = "TEMP";

  _outputBuffer = "#ifndef " + macroName + "\n";
  _outputBuffer += "#define " + macroName + "\n\n";

  process(_component->getTree(), outputDir);

  _outputBuffer += "#endif\n";

  FILE* file = fopen(_fileName.c_str(), "w");
  if (file == NULL) {
    throw;
  }

  if (file!=NULL) {
    fputs(_outputBuffer.c_str(), file);
    fclose (file);
  }
}


void PrototypeDoclet::process(Namespace& instance, const std::string& outputDir)
{
  if (!_component->isRoot(instance)) {
    _outputBuffer += "namespace " + instance.getName() + "\n";
    _outputBuffer += "{\n";
  }

  typedef std::vector <Include*>::iterator IncludeIterType;
  for (IncludeIterType iter = instance.getIncludes().begin(); iter != instance.getIncludes().end(); iter++) {
    process(**iter, outputDir);
  }
  _outputBuffer += "\n";

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = instance.getNamespaces().begin(); iter != instance.getNamespaces().end(); iter++) {
    Namespace& next = **iter;
    if (next.containsClasses()) {
      std::string nextDir = outputDir + "/" + next.getName();
      if (mkdir(nextDir.c_str(), 0755) == -1) {
	if (errno != EEXIST) {
	  throw std::runtime_error("Unable to create generation directory");
	}
      }

      process(next,nextDir);
    }
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = instance.getClasses().begin(); iter != instance.getClasses().end(); iter++) {
    Class& next = **iter;
    std::string nextDir = outputDir + "/" + next.getName();
    if (_component->getSignature() == next.getComponentName()) {
      process(next, nextDir);
    }
  }

  if (!_component->isRoot(instance)) {
    _outputBuffer += "}\n\n\n";
  }
}


void PrototypeDoclet::process(Include& instance, const std::string& outputDir)
{
  _outputBuffer += instance.getSignature() + "\n";
}


void PrototypeDoclet::process(Class& instance, const std::string& outputDir)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (!instance.containsAnnotation("@prototype")) {
    return;
  }

  _outputBuffer += "class " + instance.getName() + "Prototype" + "\n";
  _outputBuffer += "{\n";

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    process(instance, **iter, outputDir);
  }

  _outputBuffer += "};\n\n\n";

  _fileName = outputDir + "Prototype" + ".h";
}


void PrototypeDoclet::process(Class& instance, Attribute& attribute, const std::string& outputDir)
{
  if (instance.hasAnnotation("@prototype") && !instance.containsAttributeAnnotation("@prototype")) {
    _outputBuffer += attribute.getVisibility() + ":\n";
    _outputBuffer += attribute.getSignature() + ";\n\n";

  } else if (attribute.hasAnnotation("@prototype")) {
    _outputBuffer += attribute.getVisibility() + ":\n";
    _outputBuffer += attribute.getSignature() + ";\n\n";
  } 

}


}


}
