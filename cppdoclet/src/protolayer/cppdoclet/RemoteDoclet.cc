#include "RemoteDoclet.h"


namespace protolayer
{

namespace cppdoclet
{

namespace
{

std::string REMOTE = "@remote";

}


RemoteDoclet::RemoteDoclet(Dependencies& dependencies, const std::string& outputDir)
{
  Component& component = dependencies.getTargetComponent();

  if (!component.containsAnnotation(REMOTE)) {
    std::cout << "No match for annotation @remote. Skipping..." << std::endl;
    return;
  }

  if (component.containsAttributeAnnotation(REMOTE)) {
    throw "@remote annotations are prohibited for attributes";
  }

  // Check serialisation annotations on involved classes

  _outputDir = outputDir;
  _component = &component;

  generateProtocol(component);
  generateClient(component);
  generateService(component);

  //_fileName = _outputDir + "/" + _className + "Remote";

  //  std::cout << _outputBuffer << std::endl;
}


void RemoteDoclet::generateProtocol(Component& component)
{
  generateProtocol(component.getTree());
}


void RemoteDoclet::generateProtocol(Namespace& instance)
{
  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = instance.getNamespaces().begin(); iter != instance.getNamespaces().end(); iter++) {
    generateProtocol(**iter);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = instance.getClasses().begin(); iter != instance.getClasses().end(); iter++) {
    generateProtocol(**iter);
  }
}


void RemoteDoclet::generateProtocol(Class& instance)
{ 
  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = instance.getMethods().begin(); iter != instance.getMethods().end(); iter++) {
    generateProtocol(**iter);
  }
}


void RemoteDoclet::generateProtocol(Method& method)
{
  if (method.isConstructor()) {
    return;
  }

  if (method.isDestructor()) {
    return;
  }

  if (method.isAbstract()) {
    return;
  }

  _clientProtocol[&method] = method.getScopedName();
  _serviceProtocol[method.getScopedName()] = &method;
}


void RemoteDoclet::generateService(Component& component)
{
}


void RemoteDoclet::generateService(Namespace& instance)
{
}


void RemoteDoclet::generateService(Include& instance)
{
}


void RemoteDoclet::generateService(Class& instance)
{
}


void RemoteDoclet::generateService(Class& instance, Method& method)
{
}


void RemoteDoclet::generateClient(Component& instance)
{
  std::string macroName = "TEMP";

  _outputBuffer = "#ifndef " + macroName + "\n";
  _outputBuffer += "#define " + macroName + "\n\n";

  generateClient(instance.getTree());

  _outputBuffer += "#endif\n";
}


void RemoteDoclet::generateClient(Namespace& instance)
{
  if (!_component->isRoot(instance)) {
    _outputBuffer += "namespace " + instance.getName() + "\n";
    _outputBuffer += "{\n";
  }

  typedef std::vector <Include*>::iterator IncludeIterType;
  for (IncludeIterType iter = instance.getIncludes().begin(); iter != instance.getIncludes().end(); iter++) {
    generateClient(**iter);
  }
  _outputBuffer += "\n";

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = instance.getNamespaces().begin(); iter != instance.getNamespaces().end(); iter++) {
    generateClient(**iter);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = instance.getClasses().begin(); iter != instance.getClasses().end(); iter++) {
    generateClient(**iter);
  }

  if (!_component->isRoot(instance)) {
    _outputBuffer += "}\n\n\n";
  }
}


void RemoteDoclet::generateClient(Include& instance)
{
  _outputBuffer += instance.getSignature() + "\n";
}


void RemoteDoclet::generateClient(Class& instance)
{
  if (instance.isForwardDeclaration()) {
    return;
  }

  if (!instance.containsAnnotation(REMOTE)) {
    return;
  }

  _outputBuffer += "class " + instance.getName() + "Client" + "\n";
  _outputBuffer += "{\n";

  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = instance.getMethods().begin(); iter != instance.getMethods().end(); iter++) {
    generateClient(instance, **iter);
  }

  _outputBuffer += "};\n\n\n";
}


void RemoteDoclet::generateClient(Class& instance, Method& method)
{
  if (method.isConstructor()) {
    std::cout << "@remote annotation prohibited for constructors. Skipping constructor" + method.getStrippedSignature() << "." << std::endl;
    return;
  }

  if (instance.hasAnnotation(REMOTE) && !instance.containsMethodAnnotation(REMOTE)) {
    generateClientCall(method);

  } else if (method.hasAnnotation(REMOTE)) {
    generateClientCall(method);
  }
}


void RemoteDoclet::generateClientCall(Method& method) {
  _outputBuffer += method.getVisibility() + ":\n";

  _outputBuffer += method.getStrippedSignature() + " {\n";

  _outputBuffer += "  std::string address(\"127.0.0.1\");\n";
  _outputBuffer += "  net::Socket socket(address, port);\n";
  _outputBuffer += "  iostream::XdrOutputStream& ostream = socket.getXdrOutputStream();\n";

  _outputBuffer += "  ostream.write(messageType);\n";
  _outputBuffer += "  ostream.flush();\n\n";



  _outputBuffer += "  instance.encode(ostream);\n";
  _outputBuffer += "  ostream.flush();\n\n";

  _outputBuffer += "  iostream::XdrInputStream& istream = _socket->getXdrInputStream();\n";

  _outputBuffer += "  int responseType = 0;\n";
  _outputBuffer += "  istream.read(responseType);\n";

  _outputBuffer += "  if (responseType == net::MessageProtocol::ERROR) {\n";
  _outputBuffer += "    throw Exception();\n";
  _outputBuffer += "  } else if (responseType != net::MessageProtocol::REPLY) {\n";
  _outputBuffer += "    throw Exception();\n";
  _outputBuffer += "  }\n";

  _outputBuffer += "}\n\n";  
}


}


}
