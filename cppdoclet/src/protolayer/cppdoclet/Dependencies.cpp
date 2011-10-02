#include "Dependencies.h"


namespace protolayer
{

namespace cppdoclet
{

Dependencies::Dependencies(const std::string& dependenciesFileName = ".cppdoclet")
{
  _dependenciesFileName = util::trim(dependenciesFileName);

  std::string buffer;

  FILE* file = fopen(_dependenciesFileName.c_str(), "r");
  if (file == NULL) {
    throw;
  }

  char c;
  do {
    c = fgetc(file);
    buffer += c;
  } while (c != EOF);

  fclose (file);


  std::string token;
  size_t position = 0;

  bool flag = true;

  while (position != std::string::npos) {
    position = util::next(buffer, position, token);

    if (util::endsWith(token, ".h")) {
      // First entry is the actual source file
      if (flag) {
	_targetFileName = token;
	flag = false;
      }
      _fileNames.push_back(token);
    }
  }

  typedef std::vector <std::string>::iterator IterType;

  std::string fileName;
  for (IterType iter = _fileNames.begin(); iter != _fileNames.end(); iter++) {
    fileName = *iter;
    Component* created =  new Component(fileName, _namespaces);
    _components[fileName] = created;
    if (fileName == _targetFileName) {
      _targetComponent = created;
    }
  }

  typedef std::map <std::string, Component*>::iterator CompIterType;

  for (CompIterType iter = _components.begin(); iter != _components.end(); iter++) {
    Component* component = (*iter).second;
    component->recoverClasses(_classes);
  }

  for (CompIterType iter = _components.begin(); iter != _components.end(); iter++) {
    Component* component = (*iter).second;
    component->propagateClasses(_classes);
  }

  backtrack();
}


void Dependencies::backtrack()
{
  typedef std::map <std::string, Component*>::iterator CompIterType;  
  for (CompIterType iter = _components.begin(); iter != _components.end(); iter++) {
    Component* component = (*iter).second;
    component->backtrack();
  }
}


const std::map <std::string, Component*>& Dependencies::getComponents() const
{
  return _components;
}


const std::map <std::string, Class*>& Dependencies::getClasses() const
{
  return _classes;
}


const std::string& Dependencies::getTargetFileName() const
{
  return _targetFileName;
}


Component& Dependencies::getTargetComponent()
{
  return *_targetComponent;
}


const std::string& Dependencies::getDependenciesFileName() const
{
  return _dependenciesFileName;
}


}


}
