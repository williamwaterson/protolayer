#include "Namespace.h"


namespace protolayer
{

namespace cppdoclet
{

void Namespace::backtrack()
{
  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->backtrack();
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    (*iter)->backtrack();
  }

  typedef std::vector <Typedef*>::iterator TypedefIterType;
  for (TypedefIterType iter = getTypedefs().begin(); iter != getTypedefs().end(); iter++) {
    (*iter)->backtrack();
  }
}


bool Namespace::containsClasses()
{
  bool result = false;

  if (getClasses().size() > 0) {
    result = true;

  } else {
    typedef std::vector <Namespace*>::iterator NamespaceIterType;
    for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
      if (!(*iter)->containsClasses()) {
	result = true;
      }
    }
  }

  return result;
}


void Namespace::recoverMethods(std::map <std::string, Method*>& methods)
{
  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    Method* method = *iter;
    methods[method->getName()] = *iter;
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    (*iter)->recoverMethods(methods);
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->recoverMethods(methods);
  }
}


void Namespace::recoverClasses(std::map <std::string, Class*>& classes)
{
  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    Class* instance = *iter;
    classes[instance->getScopedName()] = *iter;
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->recoverClasses(classes);
  }
}


void Namespace::recoverTypedefs(std::vector <Typedef*>& typedefs)
{
  typedef std::vector <Typedef*>::iterator TypedefIterType;
  TypedefIterType pointer;

  for (TypedefIterType iter = getTypedefs().begin(); iter != getTypedefs().end(); iter++) {
    pointer = std::find(typedefs.begin(), typedefs.end(), *iter);
    if (pointer == typedefs.end()) {  
      typedefs.push_back(*iter);
    }
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->recoverTypedefs(typedefs);
  }
}


Namespace::Namespace(const std::string& buffer, const std::string& componentName, std::map <std::string, Namespace*>& namespaces)
{
  _documentation = 0;
  size_t position = 0;
  std::string scope = "::";
  process(buffer, componentName, position, scope, namespaces);
}


bool Namespace::containsParsableOf(const std::string& componentName)
{
  bool flag = false;

  typedef std::vector <Parsable*>::iterator ParsableIterType;
  for (ParsableIterType iter = getParsables().begin(); iter != getParsables().end(); iter++) {
    if ((*iter)->isParsableOf(componentName)) {
      flag = true;
    }

    if ((*iter)->containsParsableOf(componentName)) {
      flag = true;
    }
  }

  return flag;
}


void Namespace::serialise(std::string& output, const std::string& componentName)
{
  if (containsParsableOf(componentName)) {
    if (_name != "::" && _name != "") {
      output += "namespace " + _name + "\n";
      output += "{";
      output += "\n";
    }

    typedef std::vector <Parsable*>::iterator ParsableIterType;
    for (ParsableIterType iter = getParsables().begin(); iter != getParsables().end(); iter++) {
      (*iter)->serialise(output, componentName);
    }

    if (_name != "::" && _name != "") {
      output += "\n";
      output += "}";
      output += "\n";
    }
  }
}


const std::string& Namespace::getName() const
{
  return _name;
}


bool Namespace::hasDocumentation() const
{
  return _documentation != 0;
}


Documentation* Namespace::getDocumentation()
{
  return _documentation;
}


bool Namespace::containsAnnotation(const std::string& name)
{
  bool flag = false;

  if (containsNamespaceAnnotation(name)) {
    flag = true;
  }

  if (containsClassAnnotation(name)) {
    flag = true;
  }

  if (containsMethodAnnotation(name)) {
    flag = true;
  }

  if (containsAttributeAnnotation(name)) {
    flag = true;
  }

  return flag;
}


bool Namespace::containsNamespaceAnnotation(const std::string& name)
{
  bool flag = false;

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    if ((*iter)->containsAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


bool Namespace::containsClassAnnotation(const std::string& name)
{
  bool flag = false;

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    if ((*iter)->hasAnnotation(name)) {
      flag = true;
    }
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    if ((*iter)->containsClassAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


bool Namespace::containsMethodAnnotation(const std::string& name)
{
  bool flag = false;

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    if ((*iter)->containsMethodAnnotation(name)) {
      flag = true;
    }
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    if ((*iter)->containsMethodAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


bool Namespace::containsAttributeAnnotation(const std::string& name)
{
  bool flag = false;

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    if ((*iter)->containsAttributeAnnotation(name)) {
      flag = true;
    }
  }

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    if ((*iter)->containsAttributeAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


Namespace::Namespace(const std::string& buffer,
		     const std::string& componentName,
		     size_t& position,
		     const std::string& scope,
		     std::map <std::string, Namespace*>& namespaces)
{
  _documentation = 0;

  std::string token;
  position = util::next(buffer, position, token);

  if (token == "{") {
    _name = "";
    setScope(_name, *this);

  } else {
    _name = token;
    setScope(_name, *this);

    position = util::next(buffer, position, token);
    if (token == "{") {
    } else if (token == ";") {
      return;
    } else {
      throw;
    }
  }

  process(buffer, componentName, position, scope, namespaces);
}


std::vector <Namespace*>& Namespace::getNamespaces()
{
  return _namespaces;
}


std::vector <Parsable*>& Namespace::getParsables()
{
  return _order;
}


std::vector <Macro*>& Namespace::getMacros()
{
  return _macros;
}


std::vector <Include*>& Namespace::getIncludes()
{
  return _includes;
}


std::vector <Class*>& Namespace::getClasses()
{
  return _classes;
}


std::vector <Typedef*>& Namespace::getTypedefs()
{
  return _typedefs;
}


std::vector <Method*>& Namespace::getMethods()
{
  return _nonMemberMethods;
}


void Namespace::propagateScope(const std::string& scope)
{
  std::string nextScope = scope + _name + "::";

  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->propagateScope(nextScope);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    (*iter)->propagateScope(nextScope);
  }

  typedef std::vector <Typedef*>::iterator TypedefIterType;
  for (TypedefIterType iter = getTypedefs().begin(); iter != getTypedefs().end(); iter++) {
    (*iter)->propagateScope(nextScope);
  }
}


void Namespace::propagateTypedefs(const std::vector <Typedef*>& typedefs)
{
  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->propagateTypedefs(typedefs);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    (*iter)->propagateTypedefs(typedefs);
  }  
}


void Namespace::propagateClasses(const std::map <std::string, Class*>& classes)
{
  typedef std::vector <Namespace*>::iterator NamespaceIterType;
  for (NamespaceIterType iter = getNamespaces().begin(); iter != getNamespaces().end(); iter++) {
    (*iter)->propagateClasses(classes);
  }

  typedef std::vector <Class*>::iterator ClassIterType;
  for (ClassIterType iter = getClasses().begin(); iter != getClasses().end(); iter++) {
    (*iter)->propagateClasses(classes);
  }  
}


void Namespace::process(const std::string& buffer,
			const std::string& componentName,
			size_t& position,
			const std::string& scope,
			std::map <std::string, Namespace*>& namespaces)
{
  std::string token;
  std::string signature;

  Documentation* documentation = 0;

  position = util::current(buffer, position, token);
  
  while (position != std::string::npos) {

    if (util::beginsWith(token, "/**")) {
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

      std::size_t docEnd = buffer.find("*/", position);
      std::string docSig = buffer.substr(position, docEnd - position);
      documentation = new Documentation(docSig);
      signature.clear();

      position = docEnd;

    } else if (util::beginsWith(token, "/*")) {
      position = buffer.find_first_of("*/", position);
      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (util::beginsWith(token, "//")) {
      position = buffer.find_first_of("\n", position);
      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (util::beginsWith(token, "using")) {
      position = buffer.find_first_of(";", position);
      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (token == "namespace") {
      signature.clear();

      // Extract the new namespace name to check if a matching namespace of the same name exists
      std::string nameToken;
      util::next(buffer, position, nameToken); // Don't store the returned position as new Namespace requires unmodified buffer position
      std::string scopedNameToken = scope + nameToken + "::";

      if (namespaces.count(scopedNameToken) > 0) {
	namespaces[scopedNameToken]->process(buffer, componentName, position, scopedNameToken, namespaces);

      } else if (nameToken == "{") {
	// Unnamed namespaces inaccessible beyond translation unit so don't append to global namespace map
	Namespace* created = new Namespace(buffer, componentName, position, scopedNameToken, namespaces);
	created->setScope(created->getName(), *this);
	_namespaces.push_back(created);
	getEncapsulatedScopes()[created->getName()] = created;
	created->setType("namespace");

	_order.push_back(created);

      } else {
	Namespace* created = new Namespace(buffer, componentName, position, scopedNameToken, namespaces);
	created->setScope(created->getName(), *this);
	namespaces[scopedNameToken]  = created;
	_namespaces.push_back(created);
	getEncapsulatedScopes()[created->getName()] = created;
	created->setType("namespace");

	_order.push_back(created);
      }

      if (documentation != 0) {
	delete documentation;
      }
      documentation = 0;

    } else if (token == "template") {
      signature.clear();
      while (token != "};") {
	position = util::next(buffer, position, token);
      }
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (token == "typedef") {
      Typedef* created = new Typedef(buffer, componentName, position, documentation);
      _typedefs.push_back(created);
      _order.push_back(created);

      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

      //      position = buffer.find_first_of(";", position);
      //      signature.clear();
      //      if (documentation != 0) {
      //      	delete documentation;
      //      }
      //      documentation = 0;

    } else if (token == "union") {
      position = buffer.find_first_of("};", position);
      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (token == "class") {
      signature.clear();
      Class* created = new Class(buffer, componentName, position, documentation);
      if (created->isForwardDeclaration()) {
	delete created;
	delete documentation;
      } else {
	_classes.push_back(created);
	_order.push_back(created);

	created->setScope(created->getName(), *this);
	getEncapsulatedScopes()[created->getName()] = created;
	created->setType("class");
      }
      documentation = 0;

    } else if (token == "struct") {
      position = buffer.find_first_of("};", position);
      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (token == "extern") {
      position = buffer.find_first_of("}", position);
      signature.clear();
      if (documentation != 0) {
      	delete documentation;
      }
      documentation = 0;

    } else if (util::beginsWith(token, "#")) {

      Macro* created = new Macro(buffer, componentName, position);
      _macros.push_back(created);
      _order.push_back(created);

      if (util::contains(token, "include")) {
	Include* created = new Include(buffer, componentName, position);
	_includes.push_back(created);
      }

      signature.clear();

    } else if (token == "}") {
      return;

    } else if (util::endsWith(token, "{") || token == "{") {

      signature += ";";

      std::string body("{ ");

      bool methodFlag = false;
      if (util::contains(signature, "(")) {
	methodFlag = true;

	int count = 1;
	while (count != 0) {
	  position = util::next(buffer, position, token);
	  body += token + " ";
	  if (token == "{" || util::endsWith(token, "{")) {
	    count++;
	  } else if (token == "}" || util::endsWith(token, "}")) {
	    count--;
	  }
	}
      }

      if (methodFlag) {
	Method* created = new Method("unknown", signature, body, documentation);
	_nonMemberMethods.push_back(created);
	_order.push_back(created);
	documentation = 0;
      }

      signature.clear();

    } else {
      signature += token + " ";

    }

    position = util::next(buffer, position, token);
  }
}


}


}
