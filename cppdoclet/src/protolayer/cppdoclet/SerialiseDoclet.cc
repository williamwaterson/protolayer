#include "SerialiseDoclet.h"


namespace protolayer
{

namespace cppdoclet
{

SerialiseDoclet::SerialiseDoclet(Dependencies& dependencies, const std::string& outputDir)
{
  Component& component = dependencies.getTargetComponent();

  if (!component.containsAnnotation("@serialise")) {
    std::cout << "No match for annotation @serialise. Skipping..." << std::endl;
    return;
  }

  if (component.containsMethodAnnotation("@serialise")) {
    throw "@serialise annotations are prohibited for methods";
  }

  _outputDir = outputDir;
  _component = &component;

  std::string macroName = "TEMP";

  _outputBuffer = "#ifndef " + macroName + "\n";
  _outputBuffer += "#define " + macroName + "\n\n";

  process(_component->getTree());

  _outputBuffer += "#endif\n";




  //_fileName = _outputDir + "/" + _className + "Serialise";

  //  std::cout << _outputBuffer << std::endl;
}


void SerialiseDoclet::process(Namespace& instance)
{
  if (!_component->isRoot(instance)) {
    _outputBuffer += "namespace " + instance.getName() + "\n";
    _outputBuffer += "{\n";
  } else {
    _outputBuffer += "#include <protolayer/protolayer-iostream.h>\n";
    _outputBuffer += "#include \"TypeService.h\"\n";
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


void SerialiseDoclet::process(Include& instance)
{
  _outputBuffer += instance.getSignature() + "\n";
}


void SerialiseDoclet::process(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (!instance.containsAnnotation("@serialise")) {
    return;
  }

  _outputBuffer += "void encode(iostream::XdrOutputStream& stream, " + instance.getName() + "& instance)\n";
  _outputBuffer += "{\n";
  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    generateReferenceEncoder(instance, **iter);
  }
  _outputBuffer += "}\n\n\n";


  _outputBuffer += "void decode(iostream::XdrInputStream& stream, " + instance.getName() + "& instance)\n";
  _outputBuffer += "{\n";
  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    generateReferenceDecoder(instance, **iter);
  }
  _outputBuffer += "}\n\n\n";


  _outputBuffer += "void encode(iostream::XdrOutputStream& stream, " + instance.getName() + "* instance)\n";
  _outputBuffer += "{\n";
  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    generatePointerEncoder(instance, **iter);
  }
  _outputBuffer += "}\n\n\n";


  _outputBuffer += "void decode(iostream::XdrInputStream& stream, " + instance.getName() + "* instance)\n";
  _outputBuffer += "{\n";
  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = instance.getAttributes().begin(); iter != instance.getAttributes().end(); iter++) {
    generatePointerDecoder(instance, **iter);
  }
  _outputBuffer += "}\n\n\n";


  _outputBuffer += "void decode(iostream::XdrInputStream& stream, std::set <" + instance.getName() + "*>& collection) {\n";
  _outputBuffer += "  int numberOf = 0;\n";
  _outputBuffer += "  for (int i = 0; i < numberOf; ++i) {\n";
  _outputBuffer += "    " + instance.getName() + "* instance = new " + instance.getName() + "();\n";
  _outputBuffer += "    decode(stream, instance);\n";
  _outputBuffer += "    collection.insert(instance);\n";
  _outputBuffer += "  }\n";
  _outputBuffer += "}\n\n\n";


  _outputBuffer += "void encode(iostream::XdrOutputStream& stream, std::set <" + instance.getName() + "*>& collection) {\n";
  _outputBuffer += "  stream.write((int) collection.size());\n";
  _outputBuffer += "  for (std::set <" + instance.getName()  + "*>::iterator iter = collection.begin(); iter != collection.end(); iter++) {\n";
  _outputBuffer += "    encode(stream, *iter);\n";
  _outputBuffer += "  }\n";
  _outputBuffer += "}\n\n\n";
}


void SerialiseDoclet::generateReferenceEncoder(Class& instance, Attribute& attribute)
{
  bool flag = false;

  if (instance.hasAnnotation("@serialise") && !instance.containsAttributeAnnotation("@serialise")) {
    flag = true;
  } else if (attribute.hasAnnotation("@serialise")) {
    flag = true;
  }

  if (flag) {
    if (reflection::isSimpleType(attribute.getType().getSignature())) {
      _outputBuffer += "  stream.write(instance." + attribute.getName() + ");\n";      
    } else {
      _outputBuffer += "  encode(stream, instance." + attribute.getName() + ");\n";
    }
  }
}


void SerialiseDoclet::generateReferenceDecoder(Class& instance, Attribute& attribute)
{
  bool flag = false;

  if (instance.hasAnnotation("@serialise") && !instance.containsAttributeAnnotation("@serialise")) {
    flag = true;
  } else if (attribute.hasAnnotation("@serialise")) {
    flag = true;
  }

  if (flag) {
    if (reflection::isSimpleType(attribute.getType().getSignature())) {
      _outputBuffer += "  stream.read(instance." + attribute.getName() + ");\n";      
    } else {
      _outputBuffer += "  decode(stream, instance." + attribute.getName() + ");\n";
    }
  }
}


void SerialiseDoclet::generatePointerEncoder(Class& instance, Attribute& attribute)
{
  bool flag = false;

  if (instance.hasAnnotation("@serialise") && !instance.containsAttributeAnnotation("@serialise")) {
    flag = true;
  } else if (attribute.hasAnnotation("@serialise")) {
    flag = true;
  }

  if (flag) {
    if (reflection::isSimpleType(attribute.getType().getSignature())) {
      _outputBuffer += "  stream.write(instance->" + attribute.getName() + ");\n";      
    } else {
      _outputBuffer += "  encode(stream, instance->" + attribute.getName() + ");\n";
    }
  }
}


void SerialiseDoclet::generatePointerDecoder(Class& instance, Attribute& attribute)
{
  bool flag = false;

  if (instance.hasAnnotation("@serialise") && !instance.containsAttributeAnnotation("@serialise")) {
    flag = true;
  } else if (attribute.hasAnnotation("@serialise")) {
    flag = true;
  }

  if (flag) {
    if (reflection::isSimpleType(attribute.getType().getSignature())) {
      _outputBuffer += "  stream.read(instance->" + attribute.getName() + ");\n";      
    } else {
      _outputBuffer += "  decode(stream, instance->" + attribute.getName() + ");\n";
    }
  }
}


}


}
