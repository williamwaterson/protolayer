#include "Type.h"


namespace protolayer
{

namespace cppdoclet
{

Type::Type(const std::string signature)
{
  _signature = util::trim(signature);

  _className = _signature;
  if (isPointer()) {
    util::eraseAll(_className, "*"); 
  } else if (isReference()) {
    util::erase(_className, "&");
  }

  util::erase(_className, "const");

  _className = util::trim(_className);

  if (isTemplate()) {
    extractTemplateParameters();
  }
}


void Type::serialise(std::string& output, const std::string& componentName)
{
}


void Type::extractTemplateParameters()
{
  std::size_t openingPosition = _className.find("<");
  std::size_t closingPosition = _className.find_last_of(">");

  //  std::cout << openingPosition << ":" << closingPosition << std::endl;

  std::string className = _className.substr(0, openingPosition);
  className = util::trim(className);
  //  std::cout << "classname " << className << std::endl;

  std::string arguments = _className.substr(openingPosition + 1, closingPosition - openingPosition - 1);
  arguments = util::trim(arguments);
  //  std::cout << "arguments " << arguments << std::endl;

  if (arguments.find(",") == std::string::npos) {
    _templateParameterTypes[arguments] = new Type(arguments);
  } else {
    throw;
  }

  //  std::cout << "Number of parameters " << _templateParameterTypes.size() << std::endl;
}


const std::string& Type::getSignature() const
{
  return _signature;
}


void Type::propagateScope(const std::string& scope)
{
  _scope = scope;
}


Class& Type::getClass() const
{
  return *_class;
}


bool Type::isTemplate() const
{
  return std::string::npos != _className.find("<");
}


void Type::backtrack()
{
  Scope* scope = 0;
  //  std::cout << "qualified name " << getQualifiedName() << std::endl;
  ////  std::cout << "isTemplate " << isTemplate() << std::endl;
  if (hasParent()) {
    if (util::beginsWith(_className, "::")) {
      ////      std::cout << "forwardFind " << _className << std::endl;
      scope = getParent()->forwardFind(_className);
    } else {
      ////      std::cout << "backwardFind " << _className << std::endl;
      scope = getParent()->reverseFind(_className);
    }
  }

  ////  std::cout << "result " << scope << std::endl;
  if (scope != 0) {
    ////    std::cout << scope->getName() << std::endl;
  }
  ////  std::cout << std::endl;
}


void Type::propagateClasses(const std::map <std::string, Class*>& classes)
{
  std::map <std::string, Class*> possibilities;

  typedef std::map <std::string, Class*>::const_iterator IterType;
  for (IterType iter = classes.begin(); iter != classes.end(); iter++) {
    std::string scopedName = iter->first;
    if (util::contains(scopedName, _className)) {
      possibilities[scopedName] = iter->second;
    }
  }

  //  if (possibilities.size() > 0) {    
  //    _className = possibilities.begin()->first;
  //  }

  /*  if (possibilities.size() == 1) {
    _className = possibilities.begin()->first;

  } else if (possibilities.size() > 1) {
    std::map <std::string, Class*> refined;
    

    std::cout << "Ambiguous class match" << std::endl;
    throw;
  }
  */

  //  std::cout << std::endl << std::endl;
}


void Type::propagateTypedefs(const std::vector <Typedef*>& typedefs)
{
}


bool Type::isConst() const
{
  return util::beginsWith(_signature, "const");
}


bool Type::isPointer() const
{
  return util::endsWith(_signature, "*");
}


bool Type::isReference() const
{
  return util::endsWith(_signature, "&");
}


}


}
