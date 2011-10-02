#include "Class.h"


namespace protolayer
{

namespace cppdoclet
{

void Class::backtrack()
{
  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    (*iter)->backtrack();
  }

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = getAttributes().begin(); iter != getAttributes().end(); iter++) {
    (*iter)->backtrack();
  }

  typedef std::vector <Typedef*>::iterator TypedefIterType;
  for (TypedefIterType iter = getTypedefs().begin(); iter != getTypedefs().end(); iter++) {
    (*iter)->backtrack();
  }
}


bool Class::isParsableOf(const std::string& componentName)
{
  return _componentName == componentName;
}


void Class::recoverMethods(std::map <std::string, Method*>& methods)
{
  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    Method* method = *iter;
    methods[method->getName()] = *iter;
  }
}


bool Class::containsParsableOf(const std::string& componentName)
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


std::vector <Parsable*>& Class::getParsables()
{
  return _order;
}


void Class::propagateScope(const std::string& scope)
{
  _scope = scope;
  _scopedName = _scope + _name;

  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    (*iter)->propagateScope(scope);
  }

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = getAttributes().begin(); iter != getAttributes().end(); iter++) {
    (*iter)->propagateScope(scope);
  }

  typedef std::vector <Typedef*>::iterator TypedefIterType;
  for (TypedefIterType iter = getTypedefs().begin(); iter != getTypedefs().end(); iter++) {
    (*iter)->propagateScope(scope);
  }
}


void Class::serialise(std::string& output, const std::string& componentName)
{
  if (_componentName == componentName) {

    if (hasDocumentation()) {
      _documentation->serialise(output, componentName);
    }

    // TODO: Super classes
    output += "class " + _name + "\n";
    output += "{";
    output += "\n";

    typedef std::vector <Typedef*>::iterator TypedefIterType;
    for (TypedefIterType iter = getTypedefs().begin(); iter != getTypedefs().end(); iter++) {
      (*iter)->serialise(output, componentName);
    }

    typedef std::vector <Method*>::iterator MethodIterType;
    for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
      (*iter)->serialise(output, componentName);
    }

    typedef std::vector <Attribute*>::iterator AttributeIterType;
    for (AttributeIterType iter = getAttributes().begin(); iter != getAttributes().end(); iter++) {
      (*iter)->serialise(output, componentName);
    }

    output += "\n";
    output += "};";
    output += "\n";
  }
}


void Class::propagateTypedefs(const std::vector <Typedef*>& typedefs)
{
  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    (*iter)->propagateTypedefs(typedefs);
  }

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = getAttributes().begin(); iter != getAttributes().end(); iter++) {
    (*iter)->propagateTypedefs(typedefs);
  }
}


void Class::propagateClasses(const std::map <std::string, Class*>& classes)
{
  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    (*iter)->propagateClasses(classes);
  }

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = getAttributes().begin(); iter != getAttributes().end(); iter++) {
    (*iter)->propagateClasses(classes);
  }
}


const std::string& Class::getScopedName() const
{
  return _scopedName;
}


std::vector <Typedef*>& Class::getTypedefs()
{
  return _typedefs;
}


bool Class::hasAnnotation(const std::string& name)
{
  bool result = false;

  if (hasDocumentation()) {
    if (getDocumentation()->containsAnnotation(name)) {
      result = true;
    }
  }

  return result;
}


bool Class::containsAnnotation(const std::string& name)
{
  bool flag = false;

  if (hasAnnotation(name)) {
    flag = true;
  }

  if (containsAttributeAnnotation(name)) {
    flag = true;
  }

  if (containsMethodAnnotation(name)) {
    flag = true;
  }

  return flag;
}


bool Class::containsMethodAnnotation(const std::string& name)
{
  bool flag = false;

  typedef std::vector <Method*>::iterator MethodIterType;
  for (MethodIterType iter = getMethods().begin(); iter != getMethods().end(); iter++) {
    if ((*iter)->hasAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


bool Class::containsAttributeAnnotation(const std::string& name)
{
  bool flag = false;

  typedef std::vector <Attribute*>::iterator AttributeIterType;
  for (AttributeIterType iter = getAttributes().begin(); iter != getAttributes().end(); iter++) {
    if ((*iter)->hasAnnotation(name)) {
      flag = true;
    }
  }

  return flag;
}


Class::~Class()
{
}


Class::Class(const std::string& buffer,
	     const std::string& componentName,
	     size_t& position,
	     Documentation* documentation)
{
  _componentName = componentName;
  _documentation = documentation;
  _isForwardDeclaration = false;

  std::string token;
  position = util::next(buffer, position, token);
  _name = token;
  if (util::endsWith(_name, ";")) {
    _isForwardDeclaration = true;
    return;
  }

  while (token != "{") {
    position = util::next(buffer, position, token);
    if (position == std::string::npos) {
      throw;
    } else if (util::endsWith(token, ";")) {
      _isForwardDeclaration = true;
      return;
    } else if (token == ";") {
      _isForwardDeclaration = true;
      return;
    }
  }

  Documentation* doc = 0;

  std::string visibility = "private";
  std::string signature;

  while (position != std::string::npos) {
    position = util::next(buffer, position, token);

    if (util::beginsWith(token, "/**")) {
      if (doc != 0) {
      	delete doc;
      }

      std::size_t docEnd = buffer.find("*/", position);
      std::string docSig = buffer.substr(position, docEnd - position);
      doc = new Documentation(docSig);

      signature.clear();

      position = docEnd;

    } else if (util::beginsWith(token, "/*")) {
      position = buffer.find_first_of("*/", position);
      signature.clear();
      if (doc != 0) {
      	delete doc;
      }
      doc = 0;

    } else if (util::beginsWith(token, "//")) {
      position = buffer.find_first_of("\n", position);
      signature.clear();
      if (doc != 0) {
      	delete doc;
      }
      doc = 0;

    } else if (token == "friend") {
      position = buffer.find_first_of(";", position);
      signature.clear();
      if (doc != 0) {
      	delete doc;
      }
      doc = 0;

    } else if (util::contains(token, "private")) {
      visibility = "private";

     } else if (util::contains(token, "protected")) {
      visibility = "protected";

    } else if (util::contains(token, "public")) {
      visibility = "public";

    } else if (token == "};") {
      return;

    } else if (util::endsWith(token, ";")) {
      signature += token;

      bool methodFlag = false;
      if (util::contains(signature, "(")) {
	methodFlag = true;
      }

      if (methodFlag) {
	Method* created = new Method(visibility, signature, doc);
	_methods.push_back(created);
	_order.push_back(created);

	created->setScope(created->getName(), *this);
	getEncapsulatedScopes()[created->getName()] = created;
	created->setType("method");

	doc = 0;

      } else {
	Attribute* created = new Attribute(visibility, signature, doc);
	_attributes.push_back(created);
	_order.push_back(created);

	created->setScope(created->getName(), *this);
	getEncapsulatedScopes()[created->getName()] = created;
	created->setType("attribute");

	doc = 0;

      }

      signature.clear();

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
	Method* created = new Method(visibility, signature, body, doc);
	_methods.push_back(created);
	_order.push_back(created);
	doc = 0;
      }

      signature.clear();

    } else if (token == "private:") {
      signature.clear();

    } else if (token == "public:") {
      signature.clear();

    } else if (token == "protected:") {
      signature.clear();

    } else if (token == "typedef") {
      Typedef* created = new Typedef(buffer, componentName, position, doc);
      _typedefs.push_back(created);
      _order.push_back(created);

      created->setScope(created->getName(), *this);
      getEncapsulatedScopes()[created->getName()] = created;
      created->setType("typedef");

      signature.clear();
      if (doc != 0) {
      	delete doc;
      }
      doc = 0;

    } else {    
      signature += token + " ";
      
    }
  }
}


}


}
