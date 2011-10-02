#include "Naming.h"


namespace protolayer
{

namespace naming
{

int indexOfNextSeparator(std::string& name)
{
  return name.find(':');
}


void eraseSeparators(std::string& name)
{
  int count = countScopes(name);
  for (int i = 0; i < count; i++) {
    int index = indexOfNextSeparator(name);
    name.erase(index);
  }
}


bool hasDanglingScope(const std::string& name)
{
  std::string temp(name);
  temp = util::trim(temp);

  if (temp.length() < 3) {
    return true;
  }

  char separator = ':';
  return temp[0] == separator || temp[temp.length() - 1] == separator;
}


int countScopes(const std::string& name)
{
  unsigned count = 0;
  char separator = ':';
  for (int i = 0; i < name.length(); i++) {
    if (separator == name[i]) {
      count++;
    }
  }

  return count;
}


bool isValidName(const std::string& name)
{
  if (hasDanglingScope(name)) {
    return false;
  }

  return 2 > countScopes(name);
}


bool isValidScope(const std::string& scope)
{
  if (countScopes(scope) > 0) {
    return false;
  }

  return true;
}


bool isScoped(const std::string& name)
{
  std::string temp(name);
  temp = util::trim(temp);

  return 1 == countScopes(name);
}


std::string getScope(const std::string& scopedName)
{
  if (!isValidName(scopedName)) {
    throw "Invalid name";
  }

  if (!isScoped(scopedName)) {
    throw "Supplied name is not scoped";
  }

  std::string result(scopedName);
  int pos = result.find(':', 0);
  return result.substr(0, pos);
}


bool isNumericString(std::string value, int base)
{
  std::string temp(value);
  temp = util::trim(temp);

  std::string scan("0123456789abcdef");

  bool result = true;
  for (int  i = 0; i < temp.length(); i++) {
    char element = temp[i];

    bool flag = false;
    for (int j = 0; j < base; j++) {
      if (element == scan[j]) {
	flag = true;
      }
    }

    if (!flag) {
      result = false;
      break;
    }
  }

  return result;
}


int getScopeId(const std::string& scopedName)
{
  std::string scope = getScope(scopedName);

  if (!isNumericString(scope)) {
    throw "Cannot provide scope Id for non-numeric scope";
  }

  int result = atoi(scope.c_str());
  return result;
}


std::string getUnscopedName(const std::string& scopedName)
{
  if (!isValidName(scopedName)) {
    throw "Invalid name";
  }

  std::string result(scopedName);

  if (isScoped(scopedName)) {
    int index = scopedName.find(':', 0);
    result.erase(0, index + 1);
  }

  return result;
}


std::string constructScopedName(const std::string& scope, const std::string& unscopedName)
{
  //  if (isScoped(unscopedName)) {
  //    throw "Cannot scope already scoped name";
  //}

  //  if (isValidScope(scope)) {
  //  throw "Bad scope format";
  //}

  return scope + ":" + unscopedName;
}


std::string constructScopedName(int domainId, const std::string& unscopedName)
{
  std::string scope = util::itoa(domainId, 10);
  return constructScopedName(scope, unscopedName);
}


}


}
