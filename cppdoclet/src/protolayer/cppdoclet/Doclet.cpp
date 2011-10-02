#include "Doclet.h"


namespace protolayer
{

namespace cppdoclet
{

Doclet::Doclet(Namespace& root, const std::string& outputDir)
{
  _outputDir = outputDir;
  _root = &root;

  _hasClassAnnotationMatch = false;
  _hasAttributeAnnotationMatch = false;
  _hasMethodAnnotationMatch = false;

  prewalk(root);

  createOpeningMacros();
  process(root);
  createClosingMacros();

  std::cout << _outputBuffer << std::endl;
}


void Doclet::createOpeningMacros()
{
  std::string macroName = util::toUpperCase(_className);
  _outputBuffer = "#ifndef " + macroName + "\n";
  _outputBuffer += "#define " + macroName + "\n\n";
}


void Doclet::createClosingMacros()
{
  _outputBuffer += "#endif\n";
}


void Doclet::prewalk(Namespace& instance)
{
  std::string namespaceName = instance.getName();

  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@prototype") || documentation->containsAnnotation("@prototyped")) {
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


void Doclet::prewalk(Include& instance)
{
}


void Doclet::prewalk(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@prototype") ||
	documentation->containsAnnotation("@prototyped")) {
      _hasClassAnnotationMatch = true;
      _className = instance.getName();
      _className += "Prototype";
      _fileName = _outputDir + "/" + _className + "Prototype";
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


void Doclet::prewalk(Attribute& instance)
{
  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@prototype") ||
	documentation->containsAnnotation("@prototyped")) {
      _hasAttributeAnnotationMatch = true;
    }
  }
}


void Doclet::prewalk(Method& instance)
{
  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@prototype") ||
	documentation->containsAnnotation("@prototyped")) {
      _hasMethodAnnotationMatch = true;
    }
  }
}


void Doclet::process(Namespace& instance)
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


void Doclet::process(Include& instance)
{
  _outputBuffer += instance.getSignature() + "\n";
}


void Doclet::process(Class& instance)
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


void Doclet::process(Method& instance)
{
  if (instance.hasDocumentation()) {
    Documentation* documentation = instance.getDocumentation();
    if (documentation->containsAnnotation("@prototype") ||
	documentation->containsAnnotation("@prototyped")) {
      _outputBuffer += instance.getVisibility() + ":\n";
      _outputBuffer += instance.getStrippedSignature() + "\n";
      _outputBuffer += "{\n";
      _outputBuffer += "}\n\n";
    }
  }
}


void Doclet::process(Attribute& instance)
{
  _outputBuffer += instance.getVisibility() + ":\n";
  if (_hasClassAnnotationMatch && _hasAttributeAnnotationMatch && instance.hasDocumentation()) {
    _outputBuffer += instance.getSignature() + ";\n\n";
  } else if(_hasClassAnnotationMatch && !_hasAttributeAnnotationMatch) {
    _outputBuffer += instance.getSignature() + ";\n\n";
  } else if(!_hasClassAnnotationMatch && _hasAttributeAnnotationMatch && instance.hasDocumentation()) {
    _outputBuffer += instance.getSignature() + ";\n\n";
  }

}


}


}
