#include "Component.h"


namespace protolayer
{

namespace cppdoclet
{

void Component::serialise(std::string& outputBuffer)
{
  _tree->serialise(outputBuffer, this->getName());
}


void Component::backtrack()
{
  _tree->backtrack();
}


bool Component::containsAnnotation(const std::string& name)
{
  return _tree->containsAnnotation(name);
}


bool Component::containsClassAnnotation(const std::string& name)
{
  return _tree->containsClassAnnotation(name);
}


bool Component::containsMethodAnnotation(const std::string& name)
{
  return _tree->containsMethodAnnotation(name);
}


bool Component::containsAttributeAnnotation(const std::string& name)
{
  return _tree->containsAttributeAnnotation(name);
}


Component::Component(const std::string& signature,
		     std::map <std::string, Namespace*>& namespaces)
{
  _signature = util::trim(signature);
  _name = _signature;

  FILE* file = fopen(_signature.c_str(), "r");
  if (file == NULL) {
    throw;
  }

  char c;

  std::string buffer;

  do {
    c = fgetc(file);
    buffer += c;
  } while (c != EOF);

  fclose (file);

  process(buffer, namespaces);
  fold();
}


Component::Component(const std::string& signature)
{
  std::map <std::string, Namespace*> namespaces;

  _signature = util::trim(signature);
  _name = _signature;

  FILE* file = fopen(_signature.c_str(), "r");
  if (file == NULL) {
    throw;
  }

  char c;

  std::string buffer;

  do {
    c = fgetc(file);
    buffer += c;
  } while (c != EOF);

  fclose (file);

  process(buffer, namespaces);
  fold();
}


void Component::process(std::string& buffer, std::map <std::string, Namespace*>& namespaces)
{
  std::string scope("::");

  if (namespaces.count(scope) > 0) {
    size_t position = 0;
    _tree = namespaces[scope];
    _tree->process(buffer, _signature, position, scope, namespaces);

  } else {
    _tree = new protolayer::cppdoclet::Namespace(buffer, _signature, namespaces);
    namespaces[scope] = _tree;

  }
}


bool Component::isRoot(const Namespace& instance) const
{
  return _tree == &instance;
}


void Component::fold()
{
  std::string scope("::");

  std::cout << std::endl;
  std::cout << "fold called" << std::endl;
  std::cout << std::endl;

  //  _tree->propagateScope(scope);

  //  _tree->recoverTypedefs(_typedefs);
  ///_tree->propagateTypedefs(_typedefs);

  //_tree->recoverClasses(_classes);
}


void Component::recoverClasses(std::map <std::string, Class*>& classes)
{
  _tree->recoverClasses(classes);
}


void Component::recoverMethods(std::map <std::string, Method*>& methods)
{
  _tree->recoverMethods(methods);
}


void Component::propagateClasses(const std::map <std::string, Class*>& classes)
{
  _tree->propagateClasses(classes);
}


std::map <std::string, Class*>& Component::getAllClasses()
{
  return _classes;
}


Namespace& Component::getTree()
{
  return *_tree;
}


const std::string& Component::getName() const
{
  return _name;
}


const std::string& Component::getSignature() const
{
  return _signature;
}


}


}
