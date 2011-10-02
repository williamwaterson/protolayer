#include "PoolDoclet.h"


namespace protolayer
{

namespace cppdoclet
{

PoolDoclet::PoolDoclet(Namespace& root, const std::string& outputDir)
{
  _outputDir = outputDir;
  _root = &root;

  _hasClassAnnotationMatch = false;
  _hasAttributeAnnotationMatch = false;
  _hasMethodAnnotationMatch = false;

  prewalk(root);

  if (_hasMethodAnnotationMatch) {
    throw "@pool annotations are not permitted on methods";
  }

  createOpeningMacros();
  process(root);
  createClosingMacros();

  std::cout << _outputBuffer << std::endl;
}


void PoolDoclet::createOpeningMacros()
{
  std::string macroName = util::toUpperCase(_className);
  _outputBuffer = "#ifndef " + macroName + "\n";
  _outputBuffer += "#define " + macroName + "\n\n";
}


void PoolDoclet::createClosingMacros()
{
  _outputBuffer += "#endif\n";
}


void PoolDoclet::prewalk(Namespace& instance)
{
  std::string namespaceName = instance.getName();

  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@pool") || documentation->containsAnnotation("@pooled")) {
    }
  }

  typedef std::vector <Include*>::iterator IncludeIterType;
  for (IncludeIterType iter = instance.getIncludes().begin(); iter != instance.getIncludes().end(); iter++) {
    prewalk(**iter);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = instance.getClasses().begin(); iter != instance.getClasses().end(); iter++) {
    prewalk(**iter);
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = instance.getNamespaces().begin(); iter != instance.getNamespaces().end(); iter++) {
    prewalk(**iter);
  }

}


void PoolDoclet::prewalk(Include& instance)
{
}


void PoolDoclet::prewalk(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@pool") ||
	documentation->containsAnnotation("@pooled")) {
      _hasClassAnnotationMatch = true;
      _className = instance.getName();
      _className += "Pool";
      _fileName = _outputDir + "/" + _className + "Pool";
    }
  }

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    prewalk(**iter);
  }

  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = instance.getMethods().begin(); iter != instance.getMethods().end(); iter++) {
    prewalk(**iter);
  }
}


void PoolDoclet::prewalk(Attribute& instance)
{
  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@pool") ||
	documentation->containsAnnotation("@pooled")) {
      _hasAttributeAnnotationMatch = true;
    }
  }
}


void PoolDoclet::prewalk(Method& instance)
{
  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@pool") ||
	documentation->containsAnnotation("@pooled")) {
      _hasMethodAnnotationMatch = true;
    }
  }
}


void PoolDoclet::process(Namespace& instance)
{
  if (&instance != _root) {
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

  if (&instance != _root) {
    _outputBuffer += "}\n\n\n";
  }
}


void PoolDoclet::process(Include& instance)
{
  _outputBuffer += instance.getSignature() + "\n";
}


void PoolDoclet::process(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  _outputBuffer += "class " + _className + "\n";
  _outputBuffer += "{\n";

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    process(**iter);
  }

  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = instance.getMethods().begin(); iter != instance.getMethods().end(); iter++) {
    process(**iter);
  }

  _outputBuffer += "};\n\n\n";
}


}


}
