#include "MethodDefinition.h"


namespace protolayer
{

namespace cppdoclet
{

void MethodDefinition::propagateScope(const std::string& scope)
{
  _scope = scope;
  _scopedName = _scope + _signature;
  std::cout << _scopedName << std::endl;
}


const std::string& MethodDefinition::getScopedName() const
{
  return _scopedName;
}


bool MethodDefinition::isDeclaration() const
{
  return false;
}


bool MethodDefinition::isConstructor() const
{
  return _returnTypeName == "";
}


bool MethodDefinition::isDefinition() const
{
  return false;
}


bool MethodDefinition::hasDocumentation() const
{
  return _documentation != 0;
}


const std::string& MethodDefinition::getVisibility() const
{
  return _visibility;
}


Documentation* MethodDefinition::getDocumentation()
{
  return _documentation;
}


const std::string& MethodDefinition::getSignature() const
{
  return _signature;
}


const std::string& MethodDefinition::getStrippedSignature() const
{
  return _strippedSignature;
}


bool MethodDefinition::hasAnnotation(const std::string& name)
{
  bool flag = false;
  if (hasDocumentation()) {
    if (_documentation->containsAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


MethodDefinition::MethodDefinition(const std::string& visibility,
	       const std::string& signature,
	       Documentation* documentation)
{
  _documentation = documentation;
  _signature = signature;
  _strippedSignature = _signature;
  _visibility = visibility;

  size_t semicolon = _strippedSignature.find(";");
  _strippedSignature.erase(semicolon);

  std::size_t parenBegin = signature.find('(', 0);
  std::size_t parenEnd = signature.find(')', 0);

  std::string opening = signature.substr(0, parenBegin);
  extractOpening(opening);

  std::string arguments = signature.substr(parenBegin + 1, parenEnd - parenBegin - 1);
  extractArguments(arguments);

  std::size_t throwPosition = signature.find("throw", parenEnd);
  if (throwPosition != std::string::npos) {
    std::size_t throwParenBegin = signature.find("(", throwPosition);
    std::size_t throwParenEnd = signature.find(")", throwPosition);

    std::string exceptions = signature.substr(throwParenBegin + 1, throwParenEnd - throwParenBegin - 1);
    extractExceptions(exceptions);
  }

  std::cout << _returnTypeName << std::endl;
}


const std::string& MethodDefinition::getReturnTypeName() const
{
  return _returnTypeName;
}


void MethodDefinition::extractOpening(const std::string& opening)
{
  std::string methodName;
  
  std::size_t position = 0;
  std::string buffer = " " + opening;

  std::string token;
  while (position != std::string::npos) {
    _returnTypeName = methodName;
    methodName = token;
    position = util::next(buffer, position, token);
  }
}


void MethodDefinition::extractArguments(const std::string& arguments)
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
      signature.clear();
    } else {
      signature += ch;
    }

    if (i == arguments.length() - 1) {
      Argument* argument = new Argument(signature);
      _arguments.push_back(argument);
    }
  }
}


void MethodDefinition::extractExceptions(const std::string& exceptions)
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
