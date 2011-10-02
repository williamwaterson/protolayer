#include "Function.h"


namespace protolayer
{

namespace cppdoclet
{

void Function::backtrack()
{
  if (_returnType != 0) {
    _returnType->backtrack();
  }

  typedef std::vector <Argument*>::iterator ArgumentIterType;
  for (ArgumentIterType iter = _arguments.begin(); iter != _arguments.end(); iter++) {
    (*iter)->backtrack();
  }
}


void Function::propagateScope(const std::string& scope)
{
  _scope = scope;
  _scopedName = _scope + _signature;

  if (_returnType != 0) {
    _returnType->propagateScope(scope);
  }

  typedef std::vector <Argument*>::iterator ArgumentIterType;
  for (ArgumentIterType iter = _arguments.begin(); iter != _arguments.end(); iter++) {
    (*iter)->propagateScope(scope);
  }
}


void Function::serialise(std::string& output, const std::string& componentName)
{
  output += _strippedSignature;
  if (isDeclaration()) {
    output += ";\n\n";

  } else {
    output += "\n" + _implementation->getBody();
    output += "\n\n";
  }
}


const std::string& Function::getScopedName() const
{
  return _scopedName;
}


bool Function::isDeclaration() const
{
  return _implementation == 0;
}


bool Function::isDefinition() const
{
  return _implementation != 0;
}


const std::string& Function::getSignature() const
{
  return _signature;
}


const std::string& Function::getRawSignature() const
{
  return _rawSignature;
}


const std::string& Function::getStrippedSignature() const
{
  return _strippedSignature;
}


Function::Function(const std::string& signature) :
  _implementation(0)
{
  _rawSignature = signature;

  std::cout << signature << std::endl;

  _signature = signature;
  std::string inlineStr("inline");
  std::size_t length = inlineStr.length();
  std::size_t position = _signature.find("inline");
  if (position != std::string::npos) {
    _signature.erase(position, length);
  }
  util::trim(_signature);

  }
  util::trim(_signature);

  _strippedSignature = _signature;

  size_t semicolon = _strippedSignature.find(";");
  _strippedSignature.erase(semicolon);

  std::size_t parenBegin = _signature.find('(', 0);
  std::size_t parenEnd = _signature.find(')', 0);

  std::string opening = _signature.substr(0, parenBegin);
  extractOpening(opening);

  std::string arguments = _signature.substr(parenBegin + 1, parenEnd - parenBegin - 1);
  extractArguments(arguments);

  std::size_t throwPosition = _signature.find("throw", parenEnd);
  if (throwPosition != std::string::npos) {
    std::size_t throwParenBegin = _signature.find("(", throwPosition);
    std::size_t throwParenEnd = _signature.find(")", throwPosition);

    std::string exceptions = _signature.substr(throwParenBegin + 1, throwParenEnd - throwParenBegin - 1);
    extractExceptions(exceptions);
  }

  if (_returnTypeName != "") {
    _returnType = new Type(_returnTypeName);
    _returnType->setScope(_returnType->getName(), *this);
    getEncapsulatedScopes()[_returnType->getName()] = _returnType;
    _returnType->setType("type");

  } else {
    _returnType = 0;
  }

  std::cout << std::endl;
  std::cout << "name " << _name << std::endl;
  std::cout << std::endl;
}


bool Function::isMethod() const
{

}


Function::~Function()
{
  if (_implementation != 0) {
    delete _implementation;
  }
}


Function::Function(const std::string& signature,
		   const std::string& body) :
  _rawSignature(signature),
  _signature(signature)
{
  std::string inlineStr("inline");
  std::size_t length = inlineStr.length();
  std::size_t position = _signature.find("inline");
  if (position != std::string::npos) {
    _signature.erase(position, length);
  }
  util::trim(_signature);

  std::string explicitStr("explicit");
  length = explicitStr.length();
  position = _signature.find("explicit");
  if (position != std::string::npos) {
    _signature.erase(position, length);
  }
  util::trim(_signature);

  std::string virtualStr("virtual");
  length = virtualStr.length();
  position = _signature.find("virtual");
  if (position != std::string::npos) {
    _signature.erase(position, length);
  }
  util::trim(_signature);

  _strippedSignature = _signature;

  size_t semicolon = _strippedSignature.find(";");
  _strippedSignature.erase(semicolon);

  std::size_t parenBegin = _signature.find('(', 0);
  std::size_t parenEnd = _signature.find(')', 0);

  std::string opening = _signature.substr(0, parenBegin);
  extractOpening(opening);

  std::string arguments = _signature.substr(parenBegin + 1, parenEnd - parenBegin - 1);
  extractArguments(arguments);

  std::size_t throwPosition = _signature.find("throw", parenEnd);
  if (throwPosition != std::string::npos) {
    std::size_t throwParenBegin = _signature.find("(", throwPosition);
    std::size_t throwParenEnd = _signature.find(")", throwPosition);

    std::string exceptions = _signature.substr(throwParenBegin + 1, throwParenEnd - throwParenBegin - 1);
    extractExceptions(exceptions);
  }

  if (_returnTypeName != "") {
    _returnType = new Type(_returnTypeName);
    _returnType->setScope(_returnType->getName(), *this);
    getEncapsulatedScopes()[_returnType->getName()] = _returnType;
    _returnType->setType("type");

  } else {
    _returnType = 0;
  }

  _implementation = new Implementation(body);
}


void Function::setImplementation(const std::string& body)
{
  if (_implementation != 0) {
    delete _implementation;
  }

  _implementation = new Implementation(body);
}


const std::string& Function::getReturnTypeName() const
{
  return _returnTypeName;
}


void Function::extractOpening(const std::string& opening)
{
  std::size_t position = 0;
  std::string buffer = " " + opening;

  std::string token;
  if (util::contains(opening, "operator")) {
    std::size_t position = _signature.find("operator", 0);
    _returnTypeName = opening.substr(0, position);
    _name = opening.substr(position);

  } else {
    while (position != std::string::npos) {
      _returnTypeName = _name;
      _name = token;
      position = util::next(buffer, position, token);
    }
  }
}


void Function::extractArguments(const std::string& arguments)
{
  std::size_t lastPosition = 0;
  std::size_t position = 0;
  std::string buffer = " " + arguments;

  std::string token;
  std::string signature;

  for (int i = 0; i < arguments.length(); i++) {
    char ch = arguments.at(i);
    if (ch == ',') {
      Argument* argument = new Argument(signature);
      _arguments.push_back(argument);
      argument->setScope(argument->getName(), *this);
      getEncapsulatedScopes()[argument->getName()] = argument;
      argument->setType("argument");

      signature.clear();
    } else {
      signature += ch;
    }

    if (i == arguments.length() - 1) {
      Argument* argument = new Argument(signature);
      _arguments.push_back(argument);
      argument->setScope(argument->getName(), *this);
      getEncapsulatedScopes()[argument->getName()] = argument;
      argument->setType("argument");
    }
  }
}


void Function::propagateClasses(const std::map <std::string, Class*>& classes) {

  if (_returnType != 0) {
    _returnType->propagateClasses(classes);
  }

  typedef std::vector <Argument*>::iterator ArgumentIterType;
  for (ArgumentIterType iter = _arguments.begin(); iter != _arguments.end(); iter++) {
    (*iter)->propagateClasses(classes);
  }

  typedef std::vector <Type*>::iterator TypeIterType;
  for (TypeIterType iter = _exceptions.begin(); iter != _exceptions.end(); iter++) {
    (*iter)->propagateClasses(classes);
  }
}


void Function::propagateTypedefs(const std::vector <Typedef*>& typedefs)
{
  if (_returnType != 0) {
    _returnType->propagateTypedefs(typedefs);
  }

  typedef std::vector <Argument*>::iterator ArgumentIterType;
  for (ArgumentIterType iter = _arguments.begin(); iter != _arguments.end(); iter++) {
    (*iter)->propagateTypedefs(typedefs);
  }

  typedef std::vector <Type*>::iterator TypeIterType;
  for (TypeIterType iter = _exceptions.begin(); iter != _exceptions.end(); iter++) {
    (*iter)->propagateTypedefs(typedefs);
  }
}


void Function::extractExceptions(const std::string& exceptions)
{
  std::string signature;

  for (int i = 0; i < exceptions.length(); i++) {
    char ch = exceptions.at(i);
    if (ch == ',') {
      Type* type = new Type(signature);
      _exceptions.push_back(type);
      signature.clear();
    } else {
      signature += ch;
    }

    if (i == exceptions.length() - 1) {
      Type* type = new Type(signature);
      _exceptions.push_back(type);
    }
  }
}


}


}
